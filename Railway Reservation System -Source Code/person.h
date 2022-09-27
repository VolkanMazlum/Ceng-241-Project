#pragma once
#include <iostream>
#include <string>
#include "Date.h"
#include "ticket.h"

using namespace std;

class Person {
private:
	string surname;
	string username;
	string password;
	
public:
    static double total_price;
	Date *date = new Date();
	Ticket *ticket = new Ticket();

	Person();
	~Person();
	Person(const Person& obj);

	void setSurname(string surname);
	void setUsername(string username);
	void setPassword(string password);
	
	virtual void  calculate_total_price() ;             //for calculation all value of tickets bought
	virtual void cancel_ticket_price();                  // for substraction the value user want to delete ticket

	double getTotalPrice();
	void setTotalPrice(double total_price);    // for summation with total price and new price.

	void setPrice(double total_price);    //for setting value, by taking substraction the value user want to delete from total price in previous method cancel_ticket_price()

	string getSurname();
	string getUsername();
	string getPassword();


	friend void display(Person& person);
};

class Gazi :public Person {
public:
	void calculate_total_price() override;          // override that , for changing ingradient according to child class
	void cancel_ticket_price() override;
};

class Sehit :public Person {

   
public:
   void calculate_total_price() override;               // override that , for changing ingradient according to child class
   void cancel_ticket_price() override;
};

class Adult :public Person {

public:

	void calculate_total_price() override;                  // override that , for changing ingradient according to child class
	void cancel_ticket_price() override;
};

class Student :public Person {
public:
	void calculate_total_price() override;                   // override that , for changing ingradient according to child class
	void cancel_ticket_price() override;
};

class Disability :public Person{

	
public:
	void calculate_total_price() override;                // override that , for changing ingradient according to child class
	void cancel_ticket_price() override;
};