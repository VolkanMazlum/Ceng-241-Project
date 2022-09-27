#include <iostream>
#include <string>
#include "person.h"
using namespace std;



Person::Person() : surname{ "Unknown" }, username{ "Unknown" }, password{ "Unknown" }{
	Date* date = new Date();
	Ticket* ticket = new Ticket();
}

Person::Person(const Person& obj) {

	Ticket *ticket = obj.ticket;
	Date * date = obj.date;
	
	delete obj.ticket;    // for avoiding 2 object our program have 
	delete obj.date;
}
Person::~Person() {

	delete ticket;
	delete date;
}


void Person::setSurname(string surname) {
	this->surname = surname;
}
void Person::setUsername(string username) {
	this->username = username;
}
void Person::setPassword(string password) {
	this->password = password;
}


string Person::getSurname() {
	return this->surname;
}
string Person::getUsername() {
	return this->username;
}
string Person::getPassword() {
	return this->password;
}


void display(Person &person) {
	cout << "Surname : " << person.getSurname() << endl;
	cout << "Username : " << person.getUsername() << endl;
}

double Person::total_price{ 0 };

double Person::getTotalPrice() {
	return total_price;
}

void Person::setTotalPrice(double price) {          // for summation with total price and new price.
	total_price = price + total_price;
}

void Person::setPrice(double price) {                   //for setting value, by taking substraction the value user want 
	total_price =  price;                               // to delete from total price in previous method cancel_ticket_price()
}

void Person::calculate_total_price() {

	double price = date->discount_user.calculate_price(0 , 100);

	setTotalPrice(price);
}

void Adult::calculate_total_price() {

	double price = date->discount_user.calculate_price(0 , 100);
	setTotalPrice(price);
}
void  Student::calculate_total_price() {

	double price = date->discount_user.calculate_price(0.5 , 100);

	setTotalPrice(price);
}
void  Disability::calculate_total_price() {

	double price = date->discount_user.calculate_price(0.7, 100);
	setTotalPrice(price);
}
void  Sehit::calculate_total_price() {

	double price = date->discount_user.calculate_price(1 , 100);
	setTotalPrice(price);
}
void  Gazi::calculate_total_price() {

	double price = date->discount_user.calculate_price(1, 100);
	
	setTotalPrice(price);
}

void Person::cancel_ticket_price(){

	double value = getTotalPrice(); 
	value = value - date->discount_user.get_value() ;
	date->discount_user.set_value(0);
	setPrice(value);

}
void Adult::cancel_ticket_price() {
	double value = getTotalPrice();
	value = value - 100;
	date->discount_user.set_value(0);
	setPrice(value);
}
void Student::cancel_ticket_price() {
	double value = getTotalPrice();
	value = value - 50;
	date->discount_user.set_value(0);
	setPrice(value);
}
void Sehit::cancel_ticket_price() {
	double value = getTotalPrice();
	value = value - 0;
	date->discount_user.set_value(0);
	setPrice(value);
}
void Disability::cancel_ticket_price() {
	double value = getTotalPrice();
	value = value - 30;
	date->discount_user.set_value(0);
	setPrice(value);
}
void Gazi::cancel_ticket_price() {

	double value = getTotalPrice();
	value = value - 0;
	date->discount_user.set_value(0);
	setPrice(value);
}