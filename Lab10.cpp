/***************************************************************************
COSC 501
Elliott Plack
Lab 10
6 NOV 2013                                                  Due 11 NOV 2013
Problem:	Use a class to calculate price-change percentage of a given
			stock, like Google (GOOG)
Algorithm:	Class with four variables and constructors, etc. Also four
			functions. All input and output in main function, and no use of
			custom headers.
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

	// accessing functions
	string getSymbol() const;
	string getName() const;
	double getPCP() const; //PCP = Previous Closing Price
	double getCP() const;

	// calculation function
	double changePercent();

private:
	// private variables
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

double Stock::changePercent() // simple math, so the return does it
{
	return (((getCP() - getPCP()) / getPCP()) * 100);
}


int main()
{
	string symbolInput, nameInput;
	int previousClosingPriceInput, currentPriceInput;
		
	// get inputs
	cout << "Enter the stock symbol: ";
	cin >> symbolInput;
	cout << "Enter the stock name: ";
	cin >> nameInput;
	cout << "Enter the previous price: ";
	while ((!(cin >> previousClosingPriceInput))) //detects errors in input
	{ 
		cin.clear();     // Clear the error flags 
		cin.ignore(100, '\n');    // Remove unwanted characters from buffer 
		cout << "\aInput Error. Please enter a number only.\n"
			 << "Enter the previous price: ";// if error, sound the alarm
	}
	cout << "Enter the current price: ";
		while ((!(cin >> currentPriceInput))) //detects errors in input
	{ 
		cin.clear();     // Clear the error flags 
		cin.ignore(100, '\n');    // Remove unwanted characters from buffer 
		cout << "\aInput Error. Please enter a number only.\n" // if error, sound the alarm
			 << "Enter the current price: ";
	}

	// creates object example1 of type Stock (class) with inputs
	Stock example1(symbolInput,nameInput,previousClosingPriceInput,currentPriceInput);

	// for output formats
	cout.setf(ios::fixed); 
	cout.setf(ios::showpoint); 
	cout.precision(2);

	// output
	cout << endl << "The price change percentage of stock " << example1.getSymbol()
		<< " - " << example1.getName() << " is " << example1.changePercent() << "%\n";
		
	return 0;
}