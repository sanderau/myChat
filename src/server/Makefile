make: mysql.o 
	g++ -Wall -g -I/usr/include/cppconn -O ez_mysql.o server.cpp -L/usr/lib/ -lmysqlcppconn -o start
	make RemoveO

mysql.o: ez_mysql.cpp ez_mysql.hpp
	g++ -Wall -c -g -I/usr/include/cppconn -O ez_mysql.cpp ez_mysql.hpp -L/usr/lib/ -lmysqlcppconn

clean:
	rm start *.o *.gch

RemoveO:
	rm *.o *.gch
