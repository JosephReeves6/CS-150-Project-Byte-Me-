

#include <stdlib.h>
#include <iostream>
/*
  Include directly the different
  headers from cppconn/ and mysql_driver.h + mysql_util.h
  (and mysql_connection.h). This will reduce your build time!
*/
#include "mysql_connection.h"

#include <cppconn/driver.h>
#include <cppconn/exception.h>
#include <cppconn/resultset.h>
#include <cppconn/statement.h>

using namespace std;

int main(void)
{
cout << endl;
cout << "Running 'SELECT 'MySQL!' » AS _message'..." << endl;

try {
  sql::Driver *driver;
  sql::Connection *con;
  sql::Statement *stmt;
  sql::ResultSet *res;

  /* Create a connection */
  driver = get_driver_instance();
  con = driver->connect("tcp://127.0.0.1:3306", "root", "root");
  /* Connect to the MySQL test database */
  con->setSchema("DB1");

  stmt = con->createStatement();
  res = stmt->executeQuery("SELECT * from Drivers ORDER BY ID ASC");
  //get result set metadata
  sql::ResultSetMetaData *res_meta = res -> getMetaData();
  int columns = res_meta -> getColumnCount();

//    <Driver ID="1" Type="normal" Size="0" Pass="abcd1"/>

  while (res->next()) {
    // You can use either numeric offsets...
    //cout << "id = " << res->getInt(1); // getInt(1) returns the first column
    // ... or column names for accessing results.
    // The latter is recommended.
    cout << ", ID = '" << res->getString("ID") << "'" ;
    cout << ", Type = '" << res->getString("Type") << "'" ;
    cout << ", Size = '" << res->getString("Size") << "'" ;
    cout << ", Pass = '" << res->getString("Pass") << "'" <<endl;

  }


/*  while (res->next()) {
     Access column data by index, 1-indexed
    for (int i = 1; i <= columns; i++) {
      cout << res->getString(i) << " | " ;
    }
    cout << endl;
  }*/

  delete res;
  delete stmt;
  delete con;

} catch (sql::SQLException &e) {
  cout << "# ERR: SQLException in " << __FILE__;
  //cout << "(" << __FUNCTION__ << ") on line " » << __LINE__ << endl;
  cout << "# ERR: " << e.what();
  cout << " (MySQL error code: " << e.getErrorCode();
  cout << ", SQLState: " << e.getSQLState() << " )" << endl;
}

cout << endl;

return EXIT_SUCCESS;
}
