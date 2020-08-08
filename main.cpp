/* Standard C++ includes */
#include <stdlib.h>
#include <iostream>

/*
  Include directly the different
  headers from cppconn/ and mysql_driver.h + mysql_util.h
  (and mysql_connection.h). This will reduce your build time!
*/
#include "mysql_connection.h"
#include "mysql_driver.h"

#include <cppconn/driver.h>
#include <cppconn/exception.h>
#include <cppconn/resultset.h>
#include <cppconn/prepared_statement.h>
#include <cppconn/statement.h>
#include <fstream>

#include "Patient.h"

using namespace std;
using namespace database;

int main(void)
{
    Patient patient;
//    std::ifstream inFile("../PatientLevelAttributes.json");
//    Json::Value root;
//    inFile >> root;
//
//    patient.fromJson(root);
//    std::cout << patient.getPatBirthdate();
//    patient.toJson(&root);

    patient.save();
//    patient.save();
//
//    try {
//        sql::Driver *driver;
//        sql::Connection *con;
//        sql::Statement *stmt;
//        sql::ResultSet *res;
//        /* Create a connection */
//        driver = (sql::Driver*) (sql::mysql::get_driver_instance());
//        con = driver->connect("tcp://127.0.0.1:3306", "root", "123456");
//        /* Connect to the MySQL test database */
//        con->setSchema("test");
//
//        sql::PreparedStatement *pStatement;
//
//        pStatement = con->prepareStatement("INSERT INTO Persons(LastName, FirstName, Age) VALUES(?,?,?)");
//        pStatement->setString(1,"a");
//        pStatement->setString(2,"b");
//        pStatement->setInt(3,3);
//
//        pStatement->executeQuery();
//
//        stmt = con->createStatement();
//        res = stmt->executeQuery("SELECT LAST_INSERT_ID()");
//        res->next();
//        std::cout << "PK: " << res->getInt(1);
//
//        delete pStatement;
//        delete con;
//
//    } catch (sql::SQLException &e) {
//        cout << "# ERR: SQLException in " << __FILE__;
//        cout << "# ERR: " << e.what();
//        cout << " (MySQL error code: " << e.getErrorCode();
//        cout << ", SQLState: " << e.getSQLState() << " )" << endl;
//    }
//
//    cout << endl;
//
//    return EXIT_SUCCESS;
}