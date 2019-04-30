#include <string>
#pragma once

using namespace System;

ref class Employee
{
private:
	// Employee ID,First Name,Last Name,Role,Hourly Rate,Weekly Hours,Weekly Overtime,Weekly Gross,Weekly Net,Weekly Tax
	String^ employeeId;
	String^ fName;
	String^ lName;
	String^ role;
	double hourlyRate;
	double weeklyHours;
	double weeklyOvertime;
	double weeklyGross;
	double weeklyNet;
	double weeklyTax;
	const double tax = 0.23;
	int weekNumber;

public:

	Employee() {

	}

	String^ getId() {
		return employeeId;
	}
	void setId(String^ id) {
		employeeId = id;
	}

	String^ getFirstName() {
		return fName;
	}
	void setFirstName(String^ firstName) {
		fName = firstName;
	}

	String^ getLastName() {
		return lName;
	}
	void setLastName(String^ lastName) {
		lName = lastName;
	}

	String^ getRole() {
		return role;
	}
	void setRole(String^ empRole) {
		role = empRole;
	}

	double getRate() {
		return hourlyRate;
	}
	void setRate(double rate) {
		hourlyRate = rate;
	}

	double getHours() {
		return weeklyHours;
	}
	void setHours(double hours) {
		weeklyHours = hours;
	}

	double getOvertime() {
		return weeklyOvertime;
	}
	void setOvertime(double overtime) {
		weeklyOvertime = overtime;
	}

	double getGross() {
		return weeklyGross;
	}
	void setGross(double gross) {
		weeklyGross = gross;
	}

	double getNet() {
		return weeklyNet;
	}
	void setNet(double net) {
		weeklyNet = net;
	}

	double getWeeklyTax() {
		return weeklyTax;
	}

	void setWeeklyTax(double weeklyT) {
		weeklyTax = weeklyT;
	}

	double getTax() {
		return tax;
	}

	int getWeekNumber() {
		return weekNumber;
	}

	void setWeekNumber(int week) {
		weekNumber = week;
	}
};