#include "Discount.h"

#include <iostream>

using namespace std;
Discount::Discount() : value{ 0 }, discount_rate{ 0.1 }, day{ 1 }, month{ 1 }, year{ 1 }{

}



double Discount::get_discountRate() { 
	return ( this->discount_rate ) ;
}


void Discount::set_discountRate(double rate) {
	discount_rate = rate;
}

double Discount::get_value() {                              //to take value of user's ticket user bought
	return(value);
}
void Discount::set_value( double value ) {                              //to take value of user's ticket user bought
	this->value = value;
}

double Discount::calculate_price(double rate, double value) {            //for applying discount to price according to user class

	set_discountRate(rate);
	this->value= value - (value * rate);

	return(this->value);

}
