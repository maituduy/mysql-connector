cmake_minimum_required(VERSION 3.17)
project(poco_examples)

set(CMAKE_CXX_STANDARD 11)
include_directories(mysql-connector/include boost_1_73_0 jsoncpp/include)
add_executable(poco_examples main.cpp Patient.cpp Patient.h Type.h Table.h Config.cpp Config.h Util.h Property.h QueryFunctor.h)

find_library(MYSQLCONN mysqlcppconn mysqlcppconn-static HINTS mysql-connector/lib)
find_library(JSONCPP jsoncpp HINTS jsoncpp/lib)
target_link_libraries(poco_examples ${MYSQLCONN} ${JSONCPP})