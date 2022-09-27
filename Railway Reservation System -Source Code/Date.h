#pragma once

#include <iostream>
#include "Discount.h"

using namespace std;

class Date {
private:
	int mont[12] = { 1,4,4,0,2,5,0,3,6,1,4,6 };
	int day;
	int year;
	int month;

public:
	Discount discount_user;                 //to access discount class
	Date();
	void set_date(int, int, int);
	void set_day(int day);
	int get_day();
	void set_year(int year);
	int get_year();
	void set_month(int month);
	int get_month();
	Date(const Date& date);
	bool work_time();
	Date(int, int, int);
};