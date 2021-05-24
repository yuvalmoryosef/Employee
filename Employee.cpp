/*
 * Employee.cpp
 *
 *  Created on: Dec 12, 2018
 *      Author: ise
 */

#include "Employee.h"
using namespace std;

int Employee:: countEmployee;

//default:
Employee::Employee()
{
	// TODO Auto-generated constructor stub
	name = (char*)"Name";
	id = 0;
	salary = 0;
	countEmployee++;
}


Employee::~Employee()
{
	// TODO Auto-generated destructor stub
	delete [] name;
	countEmployee--;

}
//constructor:
Employee::Employee(char* name, int id, double salary)
{
	this->name = NULL;
	setName(name);
	setId(id);
	setSalery(salary);

	countEmployee++;
}
//copy constructor:
Employee::Employee(const Employee& other)
{
	setName(other.name);
	setId(other.id);
	setSalery(other.salary);
	countEmployee++;

}
//set:
bool Employee:: setName(char* newName)
{
	if (newName==NULL)
		return false;
	char* temp;
	temp = new char[strlen(newName) + 1];
	if (temp==NULL)
		return false;
	strcpy(temp, newName);

	this->name = temp;
	return true;
}

bool Employee:: setId(int id)
{
	if(id >= 0)
	{
		this->id = id;
		return true;
	}
	return false;
}
bool Employee:: setSalery(double salary)
{
	if(salary >= 0)
	{
		this->salary=salary;
		return true;
	}
	return false;

}
//get:
char*  Employee:: getName()
{
	return this->name;
}
int Employee:: getId()
{
	return this->id;
}
double Employee:: getSalary()
{
	return this->salary;
}

int Employee:: planOfficeParty()
{
	return countEmployee*10;
}
void Employee:: print() const
{
	cout<<"Name:"<<this->name<<endl;
	cout<<"ID:"<<this->id<<endl;
	cout<<"Salary:"<<this->salary<<endl;
}
//operator:
bool Employee:: operator==(const Employee& other)const
								{
	return this->id == other.id;
								}
bool Employee:: operator>(const Employee& other)const
{
	return (this->salary > other.salary);
}
Employee& Employee:: operator=(const Employee& other)
{
	char* temp = new char[strlen(other.name)+1];
	strcpy(temp,other.name);
	delete []name;
	this->name = temp;

	return *this;
}
Employee Employee:: operator+(const Employee& other)//to check about const outside like meir
{
	this->salary += other.salary;
	return *this;
}
Employee& Employee:: operator++()
		{
	this->salary += 100;
	return *this;
		}
Employee Employee:: operator++(int x)
		{
	Employee temp(*this);
	this->salary += 100;
	return temp;
		}
Employee& Employee:: operator+=(const Employee& other)
		{
	if (other.name==NULL)
		return *this;
	char* temp;
	int tempSize = (int)strlen(other.name) + (int)strlen(this->name)+1;
	temp = new char[tempSize];
	if (temp==NULL)
		return *this;
	int i;
	for (i=0; i < (int) strlen(this->name);i++)
	{
		temp[i] = this->name[i];
	}

	for (; i< tempSize;i++)
	{
		temp[i] = other.name[i-strlen(this->name)];
	}

	delete []name;
	this->name = temp;
	return *this;
		}


ostream& operator<<(ostream& out, const Employee& e)
{
	e.print();
	return out;
}


