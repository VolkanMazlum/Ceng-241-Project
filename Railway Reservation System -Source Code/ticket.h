#pragma once
#include <iostream>

using namespace std;

    
class Ticket {
public:
	static int seat_num[4][40];         //it is train has 4 carriage and each one has 40 seat
	static int train_num[4];
	
	Ticket();
	int res_train_choice;
	int res_seat_choice;

	int buy_train_choice;           //choice for buying ticket in which train
	int buy_seat_choice;            //  choice for buying ticket has which seat number

	int train_choice;
	int seat_choice;

	int control;

	void reserve();
	void buy_ticket();
	bool cancel_ticket();
	 void display();


};
