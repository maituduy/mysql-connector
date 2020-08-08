#ifndef POCO_EXAMPLES_TYPE_H
#define POCO_EXAMPLES_TYPE_H

#include <string>
#include "boost/variant.hpp"

template<typename Class, typename T>
struct Property
{
    constexpr Property(T Class::*aMember, const char *_jsonKey, const char *_colName) :
            member{aMember}, jsonKey{_jsonKey}, colName(_colName)
    {}

    T Class::*member;
    const char *jsonKey;
    const char *colName;

};

namespace Type {
    struct Blob {
        std::string data;

        Blob() {};

        Blob(const std::string &data): data(data) {};

        std::string asString() {
            return data;
        }
    };

    struct DateTime {
        std::string data;

        DateTime (){};

        DateTime(const std::string &data): data(data) {};

        std::string asString() {
            return data;
        }
    };

    using ColumnType = boost::variant<std::uint64_t, std::string, DateTime, Blob>;
}


#endif //POCO_EXAMPLES_TYPE_H
