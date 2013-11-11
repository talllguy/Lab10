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
public:
	// default constructor
	Stock();
	// constructor
	Stock (string,string,double,double);
	// destructor
	~Stock();

	string getSymbol() const;
	string getName() const;
	double getPCP() const; //PCP = Previous Closing Price
	double getCP() const;

	double changePercent();

private:
	string symbol;
	string name;
	double previousClosingPrice;
	double currentPrice;

};
Stock::Stock()
{
	currentPrice = 0;
	previousClosingPrice = 0;
}
	
Stock::Stock(string symbolInput, string nameInput, double previousClosingPriceInput, double currentPriceInput)
{
	symbol = symbolInput;
	name = nameInput;
	previousClosingPrice = previousClosingPriceInput;
	currentPrice = currentPriceInput;
}

Stock::~Stock()
{

}

string Stock::getSymbol() const
{
	return symbol;
}

string Stock::getName() const
{
	return name;
}

double Stock::getPCP() const
{
	return previousClosingPrice;
}

double Stock::getCP() const
{
	return currentPrice;
}

double Stock::changePercent()
{
	return (((getCP() - getPCP()) / getPCP()) * 100);
}


int main()
	{
		string symbolInput, nameInput;
		int previousClosingPriceInput, currentPriceInput;
		
		cout << "Enter the stock symbol: ";
		cin >> symbolInput;
		cout << "Enter the stock name: ";
		cin >> nameInput;
		cout << "Enter the previous price: ";
		cin >> previousClosingPriceInput;
		cout << "Enter the current price: ";
		cin >> currentPriceInput;

		Stock example1(symbolInput,nameInput,previousClosingPriceInput,currentPriceInput);

		cout << endl << "The price change percentage of stock " << example1.getSymbol()
			<< " - " << example1.getName() << " is " << example1.changePercent() << "%\n";
		
		
		return 0;
	}

// example: class constructor
