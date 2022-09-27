#pragma once
#include <iostream>


using namespace std;
class Discount {
private:
	double discount_rate;

public:
	double value;
	int day;
	int year;
	int month;

	Discount();
	void set_value(double value);
	double get_discountRate();              //for getting dicount rate
	void set_discountRate(double rate);
	double get_value();                                  //for taking current value of ticket user bought
	double calculate_price(double rate , double value);    //for calculating value of ticket user bought

};