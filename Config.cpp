#include "Config.h"
namespace database {
    Connector createConnection() {
        sql::Driver *driver;
        sql::Connection *connection;

        driver = (sql::Driver*) (sql::mysql::get_driver_instance());
        connection = driver->connect("tcp://127.0.0.1:3306", "root", "123456");
        /* Connect to the MySQL test database */
        connection->setSchema("vrpacs");
        return {driver, connection};
    }

    const Connector con = database::createConnection();
}
