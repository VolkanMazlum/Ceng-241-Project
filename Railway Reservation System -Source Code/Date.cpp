#include "Date.h"

#include <iostream>

using namespace std;

void Date::set_day(int day) {

	this->day = day;
}
int Date::get_day() {

	return day;
}
void Date::set_year(int year) {

	this->year = year;
}
int Date::get_year() {

	return year;
}
void Date::set_month(int month) {

	this->month = month;

}
int Date::get_month() {

	return month;

}
Date::Date() : month{ 0 }, day{ 0 }, year{ 0 } {

}
Date::Date(int day, int mon, int year) : day{ day }, month{ mon }, year{ year } {

	
}

void Date::set_date(int day, int mon, int year){

		this->day = day;
		this->month = mon;
		this->year = year;

}
Date::Date(const Date& date) {

	//cout << "copy of date " << endl;
	discount_user = date.discount_user;            //shallow copy
	month = date.month;
	day = date.day;
	year = date.year;
	
}
bool Date::work_time() {  //eger tarih pazar gününe denk gelirse false döndürecek
	int last_two = year % 1000;
	int x = last_two / 4 + day + 5 + last_two + mont[month - 1];
	int a = x % 7;
	if (a == 0)
		return false;
	else
		return true;
	
}
