/*
 * Employee.h
 *
 *  Created on: Dec 12, 2018
 *      Author: ise
 */

#ifndef EMPLOYEE_H_
#define EMPLOYEE_H_

#include <iostream>
#include <string>
#include <cstring>
using namespace std;

class Employee
{
private:
	char* name;
	int id;
	double salary;

public:
	static int countEmployee;
	//default:
	Employee();
	virtual ~Employee();
	//constructor:
	Employee(char* name, int id, double salary);
	//copy constructor:
	Employee(const Employee& other);
	//set:
	bool setName(char* name);
	bool setId(int id);
	bool setSalery(double salary);
	//get:
	char*  getName();
	int getId();
	double getSalary();

	int planOfficeParty();
	void print()const;

	//operator:
	bool operator==(const Employee& other)const;
	bool operator>(const Employee& other)const;
	Employee& operator=(const Employee& other);
	Employee operator+(const Employee& other);
	Employee& operator++();
	Employee operator++(int x);
	Employee& operator+=(const Employee& other);
	friend ostream& operator<<(ostream& out, const Employee& e);
};

#endif /* EMPLOYEE_H_ */
