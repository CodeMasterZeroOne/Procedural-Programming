#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include "Employee.h"

using namespace System::Collections::Generic;
using namespace std;
using namespace System;
using namespace System::IO;

#pragma once
 ref class CSVManipulator
{

private:
	String^ employeeId;
	String^ fName;
	String^ lName;
	String^ role;
	double weeklyHours;
	double weeklyOvertime;
	double weeklyGross;
	double weeklyNet;
	double weeklyTax;
	int weekNumber;

public:
	CSVManipulator() {
	}

	List<Employee^>^ ReadData() {

		ifstream dataFile(".\\payroll.csv");
		string line;
		vector<vector<string>> parsedCsv;

		while (getline(dataFile, line))
		{
			stringstream lineStream(line);
			string cell;
			vector<string> parsedRow;
			int i = 0;

			while (getline(lineStream, cell, ','))
			{
				parsedRow.push_back(cell);
			}

			parsedCsv.push_back(parsedRow);
		}

		List<Employee^>^ employees = gcnew List<Employee^>();

		for (vector<string> line : parsedCsv)
		{
			Employee^ employee = gcnew Employee();
			
			employee->setId(gcnew String(line.at(0).c_str()));
			employee->setFirstName(gcnew String(line.at(1).c_str()));
			employee->setLastName(gcnew String(line.at(2).c_str()));
			employee->setRole(gcnew String(line.at(3).c_str()));
			employee->setRate(::atof(line.at(4).c_str()));
			//employee->setHours(::atof(line.at(5).c_str()));
			//employee->setOvertime(::atof(line.at(6).c_str()));
			//employee->setGross(::atof(line.at(7).c_str()));
			//employee->setNet(::atof(line.at(8).c_str()));
			//employee->setWeeklyTax(::atof(line.at(9).c_str()));
			//employee->setWeekNumber(::atof(line.at(10).c_str()));

			employees->Add(employee);
		}
		
		return employees;
	}

	void SaveData(Employee^ registeredEmployee) {

		String^ fileName = "payrollPaid.csv";
		StreamWriter^ streamWriter = gcnew StreamWriter(fileName, true);

		employeeId = registeredEmployee->getId();
		fName = registeredEmployee->getFirstName();
		lName = registeredEmployee->getLastName();
		role = registeredEmployee->getRole();
		weeklyHours = registeredEmployee->getHours();
		weeklyOvertime = registeredEmployee->getOvertime();
		weeklyGross = registeredEmployee->getGross();
		weeklyNet = registeredEmployee->getNet();
		weeklyTax = registeredEmployee->getWeeklyTax();
		weekNumber = registeredEmployee->getWeekNumber();

		streamWriter->WriteLine(employeeId + "," + fName + "," + lName + "," + role + ","
			+ weeklyHours + "," + weeklyOvertime + "," + weeklyGross + "," + weeklyNet + "," + weeklyTax + "," + weekNumber);
		streamWriter->Close();
	}
};

