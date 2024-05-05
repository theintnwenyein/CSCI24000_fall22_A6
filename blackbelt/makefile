test: main.o cdate.o
	g++ main.o cdate.o -o test

main.o: main.cpp cdate.h
	g++ -c main.cpp

cdate.o: cdate.cpp
	g++ -c cdate.cpp

clean:
	rm *.o
	rm test

run: test
	./test

valgrind: test
	valgrind --leak-check=full ./test
