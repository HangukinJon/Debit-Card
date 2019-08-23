#include <iostream>
#include <iomanip>
#include "DebitCard.h"

using namespace std;

DebitCard::DebitCard()
{
	totalTransactions = 0;
	totalDeposits = 0;
	accountBalance = 0;
}

DebitCard::~DebitCard()
{

}

double DebitCard::Deposit(double deposit)
{
	accountBalance += deposit;
	totalDeposits += deposit;
	return accountBalance;
}

double DebitCard::PostTransaction(int idNumber, std::string date, std::string description, double amount)
{
	Transaction temp(idNumber, date, description, amount);
	transactions.push_back(temp);
	++totalTransactions;
	accountBalance -= amount;
	
	return accountBalance;
}

bool DebitCard::ClearTransaction(int idNumber)
{
	for (int i=0; i < totalTransactions; i++)
	{
		if (transactions.at(i).idNumber == idNumber) {
			transactions.at(i).cleared = true;
			return true;
		}
	}
	return false;
}

void DebitCard::DisplayActivity()
{
	cout << fixed;
	cout << setprecision(2);
	cout << "total transactions: " << totalTransactions << "\ntotal deposits: $" << totalDeposits << "\naccount balance: $" << accountBalance << endl;
	cout << "\nList of cleared transactions:\n";
	for (int i = 0; i < totalTransactions; i++)
	{
		if (transactions.at(i).cleared == true)
		{
			cout << transactions.at(i).date << "\t$" << transactions.at(i).amount << "\t" << transactions.at(i).description << endl;
		}
	}

	std::cout << "\nList of pending transactions:\n";
	for (int i = 0; i < totalTransactions; i++)
	{
		if (transactions.at(i).cleared == false)
		{
			std::cout << transactions.at(i).date << "\t$" << transactions.at(i).amount << "\t" << transactions.at(i).description << endl;
		}
	}



}


