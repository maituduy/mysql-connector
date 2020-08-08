#ifndef POCO_EXAMPLES_CONFIG_H
#define POCO_EXAMPLES_CONFIG_H

#include "mysql_connection.h"
#include "mysql_driver.h"

//        sql::Driver *driver;
namespace database {

    struct Connector {
        sql::Driver* driver;
        sql::Connection* connection;

        Connector(sql::Driver* driver, sql::Connection* connection): driver(driver), connection(connection) {}

    };

    Connector createConnection();

    extern const Connector con;

}

#endif //POCO_EXAMPLES_CONFIG_H
