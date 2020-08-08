#ifndef POCO_EXAMPLES_TABLE_H
#define POCO_EXAMPLES_TABLE_H

#include <string>
#include <tuple>
#include <boost/variant.hpp>
#include <boost/algorithm/string.hpp>
#include <iostream>
#include "Type.h"

template <class X>
class Table {

public:
    std::tuple<Property<X,Type::ColumnType>*> properties;
    const static std::string tableName;
};

#endif //POCO_EXAMPLES_TABLE_H
