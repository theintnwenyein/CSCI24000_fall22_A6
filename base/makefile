test: main.o cstudent.o caddress.o cdate.o
		g++ main.o cstudent.o caddress.o cdate.o -o test
		
main.o: main.cpp cstudent.h caddress.h cdate.h students.dat fullReport.txt shortReport.txt
		g++ -c main.cpp
cstudent.o: cstudent.cpp caddress.h cdate.h
		g++ -c cstudent.cpp
caddress.o: caddress.cpp 
		g++ -c caddress.cpp
cdate.o: cdate.cpp
		g++ -c cdate.cpp

clean:
		rm *.o
		rm test
run: test
		./test
valgrind: test
		valgrind --leak-check=full ./test
