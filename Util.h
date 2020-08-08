#ifndef POCO_EXAMPLES_UTIL_H
#define POCO_EXAMPLES_UTIL_H

#include <iostream>
#include "Type.h"

namespace Util {

    template<typename Class, typename T>
    constexpr auto property(T Class::*aMember, const char *_jsonKey, const char *_colName) -> decltype(Property<Class, T>{aMember, _jsonKey, _colName}) {
        return Property<Class, T>{aMember, _jsonKey, _colName};
    }

    template<size_t I = 0, typename Func, typename ...Ts>
    typename std::enable_if<I == sizeof...(Ts)>::type
    for_each_in_tuple(const std::tuple<Ts...> &, Func &func) {}

    template<size_t I = 0, typename Func, typename ...Ts>
    typename std::enable_if<I < sizeof...(Ts)>::type
    for_each_in_tuple(const std::tuple<Ts...> & tpl, Func &func)
    {
        func(std::get<I>(tpl), I, I == sizeof...(Ts) - 1);
        for_each_in_tuple<I + 1>(tpl,func);
    }

    template<size_t I = 0, typename Func, typename ...Ts>
    typename std::enable_if<I == sizeof...(Ts)>::type
    for_each_in_tuple(const std::tuple<Ts...> &, Func &&func) {}

    template<size_t I = 0, typename Func, typename ...Ts>
    typename std::enable_if<I < sizeof...(Ts)>::type
    for_each_in_tuple(const std::tuple<Ts...> & tpl, Func &&func)
    {
        func(std::get<I>(tpl), I, I == sizeof...(Ts) - 1);
        for_each_in_tuple<I + 1>(tpl,func);
    }

    template<typename ...Ts>
    std::size_t size(const std::tuple<Ts...> & tpl) {
        return sizeof...(Ts);
    }

//    std::string format_date(const std::string &date) {
//        std::string res = date;
//        res.insert(4,"-");
//        res.insert(7,"-");
//        return res;
//    }
//
//    std::string format_time(const std::string &time) {
//        std::string res = time;
//        res.insert(2,":");
//        res.insert(5,":");
//        return res;
//    }

    template < typename T, typename std::enable_if< std::is_same<T,std::uint64_t>::value, void** >::type = nullptr >
    T set(T value) {
        std::cout << "uint";
        std::cout << "Hello " << value;
        std::uint64_t v = value;
        std::cout << "\n gia " << v ;
        return v;
    }

    template < typename T, typename std::enable_if< std::is_same<T,std::string>::value, void** >::type = nullptr >
    T set(T value) {
        std::cout << "str";
        std::string stringValue_ = value;
        return stringValue_;
    }

    template < typename T, typename std::enable_if< std::is_same<T,Type::DateTime>::value, void** >::type = nullptr >
    T set(T value) {
        std::cout << "datetime";
        std::string stringValue_ = value;
        return stringValue_;
    }

    template < typename T, typename std::enable_if< std::is_same<T,Type::Blob>::value, void** >::type = nullptr >
    T set(T value) {
        std::cout << "blob";
        std::string stringValue_ = value;
        return stringValue_;
    }
    std::uint64_t getLastInsertID();
}

#endif //POCO_EXAMPLES_UTIL_H
