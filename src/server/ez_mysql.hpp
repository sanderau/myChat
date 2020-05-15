/* Standard C++ includes */
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <cstdlib>

/*
  Include directly the different
  headers from cppconn/ and mysql_driver.h + mysql_util.h
  (and mysql_connection.h). This will reduce your build time!
*/
/* MySQL Libraries */
#include "mysql_connection.h"

#include <cppconn/driver.h>
#include <cppconn/exception.h>
#include <cppconn/resultset.h>
#include <cppconn/statement.h>



#ifndef EZ_MYSQL_HPP
#define EZ_MYSQL_HPP

class EZ_MySQL {

public:
	// two constructors, one if the call provides the password, the other if it doesn't and we check env variables
	EZ_MySQL();
	EZ_MySQL(const char *root_pass);
	// destructor
	~EZ_MySQL();

	//getters
	bool does_user_exist(std::string);

	//setters

private:
	/* Driver, connection, statement, query */
	sql::Driver *driver; // driver, which allows us to talk to MySQL db
	sql::Connection *con; // connection, the actual connection to our specific MySQL instance
	

};

#endif
