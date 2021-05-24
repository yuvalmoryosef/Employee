ex4: main.o Employee.o DataBase.o
	g++ main.o Employee.o DataBase.o -o ex4
DataBase.o: DataBase.cpp DataBase.h Employee.h
	g++ -c DataBase.cpp
Employee.o: Employee.cpp Employee.h
	g++ -c Employee.cpp
main.o: main.cpp Employee.h DataBase.h
	g++ -c main.cpp
clean:
	rm -f *.o
