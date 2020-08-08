#ifndef POCO_EXAMPLES_QUERYFUNCTOR_H
#define POCO_EXAMPLES_QUERYFUNCTOR_H

#include <string>
#include <iostream>
#include <type_traits>

#include "Type.h"
#include <cppconn/prepared_statement.h>

namespace functor {
    template< class T >
    using decay_t = typename std::decay<T>::type;

    template <class X>
    struct SaveFunctor
    {
        sql::PreparedStatement *pStatement;
        X *obj;

        SaveFunctor(sql::PreparedStatement *pStatement, X *obj): pStatement(pStatement), obj(obj) {

        }

        template<typename T>
        void operator () (const T& t, std::size_t index, bool last) {
            using ColumnType = decay_t<decltype(obj->*(t.member))>;
            std::cout << index;
            Util::set(obj->*(t.member));
            std::cout << obj->*(t.member);

//            if (std::is_same<ColumnType, std::string>::value)
//                pStatement->setString(index +1, static_cast<std::string>(obj->*(t.member)));
//            else if (std::is_same<ColumnType, std::uint64_t>::value) {
//                Util::getValue(obj->*(t.member));
//                pStatement->setUInt64(index +1, 9);
//            }
//            else if (std::is_same<ColumnType, Type::DateTime>::value)
//                pStatement->setString(index +1, ((Type::DateTime)(obj->*(t.member))).asString());
//            else if (std::is_same<ColumnType, Type::Blob>::value)
//                pStatement->setString(index +1, ((Type::Blob)(obj->*(t.member))).asString());
//            else
//                std::cerr << "Type Invalid\n";
        }
    };

    template <class X>
    struct CreateInsertQuery {
        std::string query;
        std::string valueStr;

        CreateInsertQuery() {
            query = "INSERT INTO " + std::string(X::tableName) + "(";
            valueStr = "VALUES(";
        }

        template<typename T>
        void operator () (const T& t, std::size_t index, bool last) {
            query += std::string(t.colName) + ",";
            valueStr += "?,";

            if (last) {
                query.pop_back();
                query += ")";

                valueStr.pop_back();
                valueStr += ")";

                query += " " + valueStr;
            }

        }
    };

    template <class X>
    struct FromJsonFunctor {
        X *obj;
        Json::Value jsonVal;

        FromJsonFunctor(X *obj, Json::Value& jsonVal): obj(obj), jsonVal(jsonVal) {}

        template<typename T>
        void operator () (const T& t, std::size_t index, bool last) {
            using ColumnType = decay_t<decltype(obj->*(t.member))>;

//            if (std::is_same<ColumnType, std::string>::value)
//                obj->*(t.member) = jsonVal[t.jsonKey].asString();
//            else if (std::is_same<ColumnType, std::uint64_t>::value)
//                obj->*(t.member) = std::atoi(jsonVal[t.jsonKey].asCString());
//            else if (std::is_same<ColumnType, Type::DateTime>::value)
//                obj->*(t.member) = {jsonVal[t.jsonKey].asString()};
//            else if (std::is_same<ColumnType, Type::Blob>::value)
//                obj->*(t.member) = {jsonVal[t.jsonKey].asString()};
//            else
//                std::cerr << "Type Invalid\n";
        }

    };

    template <class X>
    struct ToJsonFunctor {
        X *obj;
        Json::Value *jsonVal;

        ToJsonFunctor(X *obj, Json::Value *jsonVal): obj(obj), jsonVal(jsonVal) {}

        template<typename T>
        void operator () (const T& t, std::size_t index, bool last) {
//            using ColumnType = decay_t<decltype(obj->*(t.member))>;
//
//            if (std::is_same<ColumnType, std::string>::value)
//                (*jsonVal)[t.jsonKey] = obj->*(t.member);
//            else if (std::is_same<ColumnType, std::uint64_t>::value)
//                (*jsonVal)[t.jsonKey] = std::string(obj->*(t.member));
//            else if (std::is_same<ColumnType, Type::DateTime>::value)
//                (*jsonVal)[t.jsonKey] = ((Type::DateTime)(obj->*(t.member))).asString();
//            else if (std::is_same<ColumnType, Type::Blob>::value)
//                (*jsonVal)[t.jsonKey] = ((Type::Blob)(obj->*(t.member))).asString();
//            else
//                std::cerr << "Type Invalid\n";
        }

    };
}

#endif //POCO_EXAMPLES_QUERYFUNCTOR_H
