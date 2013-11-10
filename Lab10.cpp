/***************************************************************************
COSC 501
Elliott Plack
Lab 10
6 NOV 2013                                                  Due 11 NOV 2013
Problem:	Use a class to calculate price-change percentage of a given
			stock, like Google (GOOG)
Algorithm:	
***************************************************************************/

#include <iostream>
#include <string>
using namespace std;


class Stock
{
	string symbol;
	string name;
	int previousClosingPrice;
	int currentPrice;
public:
	Stock (string,string,double,double); // constructor
	int readPrice(int,int);
	float changePercent() {return ((currentPrice-previousClosingPrice)/previousClosingPrice);}
};

Stock::Stock(string a, string b,double c,double d)
	{
		symbol = a;
		name = b;
		previousClosingPrice = c;
		currentPrice = d;
	}

int main()
	{
		string symbol, name;
		int previousClosingPrice, currentPrice;
		
		cout << "Enter the stock symbol: ";
		cin >> symbol;
		cout << "Enter the stock name: ";
		cin >> name;
		cout << "Enter the previous price: ";
		cin >> previousClosingPrice;
		cout << "Enter the current price: ";
		cin >> currentPrice;

		Stock go(symbol,name,previousClosingPrice,currentPrice);

		
		
		return 0;
	}

// example: class constructor
