#include <iostream>
#include <iomanip>
#include "ticket.h"
#include "Date.h"
#include "Discount.h"

using namespace std;

int Ticket::seat_num[4][40] = { 0 };
int Ticket::train_num[4] = { 1,2,3,4 };

Ticket::Ticket() {
	
	this->buy_train_choice = 0;
	this->buy_seat_choice = 0;
	this->res_train_choice = 0;
	this->res_seat_choice = 0;
	control = 0;
	seat_choice = 0;
	train_choice = 0;
}

void Ticket:: reserve() {                                           //for reservation the ticket

	cout << "Which train do you want to reserve : ";
	cin >> res_train_choice;

	if (res_train_choice == 1 || res_train_choice == 2 || res_train_choice == 3 || res_train_choice == 4) {         //for controling there is a train like that
		do {

			cout << "Enter seat number you want : ";
			cin >> res_seat_choice;

			if (seat_num[res_train_choice - 1][res_seat_choice - 1] == 0) {                //for controlling seat it is full or not
				control = 0;
				seat_num[res_train_choice - 1][res_seat_choice - 1] =1;
				cout << "The ticket is reserved." << endl;
				break;
			}
			else {
				control = 1;
				cout << "It is reserved, please try again." << endl;
			}

		} while (control != 0);
	}
	else
		cout << "There is no train like that. " << endl;
}

void Ticket::buy_ticket() {                                                        //for buying ticket

	cout << "Which train do you want to buy : ";
	cin >> buy_train_choice;
	if (buy_train_choice == 1 || buy_train_choice == 2 || buy_train_choice == 3 || buy_train_choice == 4) {   //to control train choice is similar to train in system
		do {

			cout << "Enter seat number you want : ";
			cin >> buy_seat_choice;

			if (seat_num[buy_train_choice - 1][buy_seat_choice - 1] == 0 ||
				(res_train_choice == buy_train_choice && buy_seat_choice == res_seat_choice))  //for controlling both person's choice (it is belongs to person or not) and the ticket person want to buy (it is full or not)
			 {              

					control = 0;
					seat_num[buy_train_choice - 1][buy_seat_choice - 1] = 5;             //5 is the symbol for boughtted ticket
					cout << "The ticket is bought." << endl;
					break;
				
			}
			else {
				control = 1;
				cout << "It is bought or reserved, please try again." << endl;
			}

		} while (control != 0);
	}
	else
		cout << "There is no train like that. " << endl;
}

bool Ticket::cancel_ticket() {                                                           //for cancelling ticket
	cout << "Which seat did you buy or reserve : ";
	cin >> train_choice;
	if (train_choice == 1 || train_choice == 2 || train_choice == 3 || train_choice == 4) {      //to control train choice is similar to train in system

		cout << "Enter seat number you bought or reserved : ";
		cin >> seat_choice;


		if (seat_num[train_choice - 1][seat_choice - 1] == 1 || seat_num[train_choice - 1][seat_choice - 1] == 5) {             //for controlling this ticket user inputted is reserved or bought

			  //to control current choices are similar or not to previous selection in buying and reservating

				if (train_choice == buy_train_choice && seat_choice == buy_seat_choice) {     //to control previous user's train choice and current choice are similar of not for not buying another one ticket belongs to other person
					seat_num[train_choice - 1][seat_choice - 1] = 0;
					if (buy_seat_choice > 0) {
						buy_train_choice = 0;
						buy_seat_choice = 0;
					}
					
					return true;
				}
				else if (train_choice == res_train_choice && seat_choice == res_seat_choice) {
					seat_num[train_choice - 1][seat_choice - 1] = 0;
					if (res_seat_choice > 0) {
						res_train_choice = 0;
						res_seat_choice = 0;
					}
					return true;

				}
			


			else {
				return false;
			}


			return true;
		}
		else {
			cout << "There is no train like that. " << endl;
			return false;
		}
	
	}
}

 void Ticket::display() {
	for (int i = 0; i < 4; i++) {
		cout << setw(5) << right << "Train "<< train_num[i] <<" "<< setw(5) << right << endl ;
		for (int j = 0; j < 40; j++) {
			cout << setw(7) << right << seat_num[i][j] << " " << setw(5) << right;
		}
		cout << endl;
	}
}



