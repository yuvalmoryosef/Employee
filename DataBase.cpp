/*
 * DataBase.cpp
 *
 *  Created on: Dec 13, 2018
 *      Author: ise
 */

#include "DataBase.h"

DataBase::DataBase()
{
	numOfEmp = 0;
	sizeOfArr = 3;
	arrEmployee =  new Employee*[sizeOfArr];
}

DataBase::DataBase(const DataBase& otherDataBase) {
	this->numOfEmp = otherDataBase.numOfEmp;
	this->sizeOfArr= otherDataBase.sizeOfArr;
	this->arrEmployee = otherDataBase.arrEmployee;
}

DataBase::~DataBase()
{
	int i;
	for(i=0;i<numOfEmp;i++)
	{
		delete arrEmployee[i];
	}

	delete [] arrEmployee;
}

Employee* DataBase::getEmployee(int id)
{
	for(int i=0;i<numOfEmp;i++)
	{
		if(arrEmployee[i]->getId() == id)
			return arrEmployee[i];
	}
	return NULL;
}

//this function get employee and chek if is already exist.
//if exist - check if there is space in this arr - yes -->add, no--> increase the array and then enter him.
void DataBase::addEmployee(Employee* newEmp)
{

	//check if this employee is already exist.
	Employee* getEmp = getEmployee(newEmp->getId());
	if(getEmp==NULL)//add employee
	{
		Employee* nEmp = new Employee(*newEmp);//create copy
		delete newEmp;//delete origin

		if(numOfEmp==sizeOfArr)
		{
			arrEmployee[numOfEmp] = nEmp;
		}
		else//there is no place in the database.
		{
			int i;
			Employee** temp;
			temp = new Employee*[sizeOfArr*2];
			if (!temp)
				return;
			for (i = 0; i < sizeOfArr; i++)
				temp[i] = arrEmployee[i];

			sizeOfArr*=2;
			delete [] arrEmployee;
			arrEmployee = temp;
			arrEmployee[numOfEmp] = nEmp;
		}
		numOfEmp++;

	}
	else
	{
		cout<<"This employee is already in the database\n\n";
		delete newEmp;
	}
}

void DataBase::removeEmployee(int id)
{
	//check if this employee is already exist.
	Employee* findEmp = getEmployee(id);
	if(findEmp==NULL)//there is no employee with this id
	{
		cout<<"This employee isn't in the database\n\n";
	}
	else
	{
		int place,i;
		//find location of this employee in array
		for(i=0;i<numOfEmp;i++)
		{
			if(arrEmployee[i]->getId() == id){
				place = i;
				break;
			}
		}
		//delete employee
		delete arrEmployee[place];

		//change position in array
		for(i=place;i<numOfEmp-1;i++)//check leak from array
		{
			arrEmployee[i] = arrEmployee[i+1];
		}
		arrEmployee[numOfEmp-1] = NULL;
		numOfEmp--;
	}
}

void DataBase::print()
{
	cout<<"Employees database:\n\n";
	int i;
	for(i=0;i<numOfEmp;i++)
	{
		cout<<*arrEmployee[i]<<endl;
	}
}

