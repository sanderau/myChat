/* Standard C++ includes */
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <cstdlib>

/* my librariers */
#include "ez_mysql.hpp"

int main(int argc, char **argv)
{
	
	/* all the MySQL objects needed to interact with the container */
	try {

		EZ_MySQL db;
	
	} catch(std::string e) {
	
		std::cout << e << std::endl;
		std::cout << "exiting...." << std::endl;
		return 1;
	
	}

	EZ_MySQL db;

	return 0;
}
