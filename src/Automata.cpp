#include "Automata.h"
#include <string>
using namespace std;

STATES Automata::on() {
	if (State == OFF)
	{
		State = WAIT;
		return State;
	}
	else return State;
}


STATES Automata::off()
{
	if (State != OFF || State != COOK) //если уже выключен, то не выключаем еще раз 
	{
		if (cash != 0)
		{
			cout << "Your change: " << cash << endl;
			cash = 0;
		}
		State = OFF;
		ch = 0;
		cout << "Turning off the machine..\n";
		return State;
	}

	return State;
}

STATES Automata::coin(int a) {
	switch (State) {

	case (WAIT):
		State = ACCEPT;
		cash = a;
		cout << "Balance: " << cash << endl;
		return State;

	case (OFF):
		State = ACCEPT;
		cash = a;
		cout << "Balance: " << cash << endl;
		return State;

	case (ACCEPT):
		cash = cash + a;
		cout << "Balance: " << cash << endl;
		return State;

	case (CHECK):
		cash = cash + a;
		cout << "Balance: " << cash << endl;
		State = CHECK;
		choice(ch);
		return State;

	default:
		return State;
	}
}

STATES Automata::choice(int a) {
	switch (State) {
	case(ACCEPT):
		ch = a - 1;
		State = CHECK;
		
	case(CHECK):
		if (cash < prices[ch])
		{
			cout << "\nNot enough money..\n";
		}
		else cook();
		return State;

	default:
		return State;
	}
}

void Automata::printMenu() {
	int size = sizeof(prices) / sizeof(int);
	for (int i = 0; i < size; i++)
		cout << menu[i] << " - " << prices[i] << endl;
}

void Automata::printState()
{
	switch (State) {

	case(WAIT):
		cout << "WAITING...\n";
	case (OFF):
		cout << "OFF\n";
	case (ACCEPT):
		cout << "MONEY ACCEPT\n";
	case (COOK):
		cout << "COOKING...\n";

	default:
		break;
	}
}

STATES Automata::cancel() {
	switch (State)
	{
	case (OFF):
		cout << "Machine is off, can not cancel\n";
		return State;
	case (COOK):
		cout << "Can not cancel, wait until drink will be cooked\n";
	case (WAIT):
		return State;
	default:
		State = WAIT;
		cout << "Your change: " << cash << endl;
		cash = 0;
		ch = 0;
		return State;
	}
}

STATES Automata::cook()
{
	State = COOK;
	cout << menu[ch] << endl;
	printState();
	finish();
	return State;
}

STATES Automata::finish() {
	State = WAIT;
	cout << "Your change: " << cash - prices[ch] << endl;
	cash = 0;
	ch = 0;
	cout << "Thank you, have a good day! \n";
	return State;
}

Automata::Automata() {
	cash = 0;
	State = OFF;
	ch = 0;
}
