#pragma once

#include <iostream>
#include <string.h>
#include "states.h"

using namespace std;

class Automata {
private:
	int cash, ch;
	string menu[4] = { "tea", "coffee with milk", "cappuccino", "espresso" };
	int prices[4] = { 15, 20, 30, 25 };
	STATES State; // переменная для хранения состояния

	void printMenu();
	STATES cook();
	STATES finish();


public:
	Automata(); // конструктор
	STATES on();
	STATES off();
	STATES coin(int a);
	STATES choice(int a);
	STATES cancel();
	void printState();
};
