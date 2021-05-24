/*
 * DataBase.h
 *
 *  Created on: Dec 13, 2018
 *      Author: ise
 */

#ifndef DATABASE_H_
#define DATABASE_H_

#include "Employee.h"
#include <iostream>
#include <cstring>
using namespace std;

class DataBase {
private:
	Employee** arrEmployee;
	int numOfEmp;
	int sizeOfArr;
public:
	DataBase();
	DataBase(const DataBase& );
	virtual ~DataBase();
	Employee* getEmployee(int);
	void addEmployee(Employee*);
	void removeEmployee(int);
	void print();
};

#endif /* DATABASE_H_ */
