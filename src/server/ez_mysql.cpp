#include "ez_mysql.hpp"

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


EZ_MySQL::EZ_MySQL() {
	/*
	* function name: constructor
	* description: initializes connection to MySQL db used for application
	* parameters: n/a
	* returns: will throw exception if something goes wrong
	*/

	/* will check to see if the env var for the mysql root password exists. If it doesn't it will throw exc and exit  */
	if( std::getenv("ROOT_PASS") == NULL ) {
		throw std::string( "missing root password in env vars. expecting: ROOT_PASS" );
		return;
	}

	const char *root_pass = std::getenv("ROOT_PASS"); // root password for MySQL


	/* attempt connection at MySQL db */
	try {
	/* create the connection to the MySQL container */
	this->driver = get_driver_instance();
	this->con  = (this->driver)->connect("tcp://127.0.0.1:3306", "root", root_pass);

	/* connect to the MySQL test database */
	(this->con)->setSchema("myChat");
	
	} catch (sql::SQLException &e) {

		/* print error and throw exception */
  		std::cout << "# ERR: SQLException in " << __FILE__;
  		std::cout << "(" << __FUNCTION__ << ") on line " << __LINE__ << std::endl;
  		std::cout << "# ERR: " << e.what();
  		std::cout << " (MySQL error code: " << e.getErrorCode();
  		std::cout << ", SQLState: " << e.getSQLState() << " )" << std::endl;

		throw std::string("Error connecting to MySQL");

		return;
	}



}

EZ_MySQL::EZ_MySQL(const char *root_pass) {
	/*
	* function name: constructor
	* description: initializes connection to MySQL db used for application
	* parameters: the root password to the MySQL db
	* returns: will throw exception if something goes wrong.
	*/


	try {
	/* create the connection to the MySQL container */
	this->driver = get_driver_instance();
	this->con = (this->driver)->connect("tcp://127.0.0.1:3306", "root", root_pass);

	/* connect to the MySQL test database */
	(this->con)->setSchema("myChat");
	
	} catch (sql::SQLException &e) {
  		std::cout << "# ERR: SQLException in " << __FILE__;
  		std::cout << "(" << __FUNCTION__ << ") on line " << __LINE__ << std::endl;
  		std::cout << "# ERR: " << e.what();
  		std::cout << " (MySQL error code: " << e.getErrorCode();
  		std::cout << ", SQLState: " << e.getSQLState() << " )" << std::endl;
		return;
	}


}

EZ_MySQL::~EZ_MySQL() {
//	delete this->driver;
//	delete this->con;
}


bool EZ_MySQL::does_user_exist(std::string username)
{
	/*
	* name: does_user_exist
	* description: Used to check if a user exists already in the databse.
	* parameters: string username - the username you would like to check
	* return: true if the user exists, false if they does not
	*/

	std::string query = "SELECT EXISTS(SELECT * from users where username like \"%";
	query += username;
	query += "%\");";


	sql::Statement *stmt = (this->con)->createStatement();
	sql::ResultSet *res = stmt->executeQuery(query);
	
	while(res->next()) {
		if( res->getString(1) == "1") {
			return true;
		} else {
			return false;
		}
	}

	return false;
}
