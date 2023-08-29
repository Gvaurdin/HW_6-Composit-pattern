#pragma once
#include <iostream>

using namespace std;

class CurrencyConverter;
class Tourist_ticket
{
protected:
	string destination;
	string begin_date;
	int duration;
	double price;
public:
	Tourist_ticket() { ; }
	Tourist_ticket(const string& dest, const string& start, int dur, double prc)
		: destination(dest), begin_date(start), duration(dur), price(prc) {}
    string getDestination() { return destination;}
    string getStartDate() { return begin_date;}
    int getDuration() { return duration;}
	double getPrice() { return price;}
    friend ostream& operator << (ostream& os, Tourist_ticket& ticket);
	void ShowInfo(const CurrencyConverter* converter);
};


int SelectCurrency();
CurrencyConverter* Get_Mode(int& mode);
void menu();

