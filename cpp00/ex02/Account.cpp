/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skarayil <skarayil@student.42kocaeli>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/02 23:09:57 by skarayil          #+#    #+#             */
/*   Updated: 2026/05/05 16:21:47 by skarayil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <ctime>
#include <iostream>

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

int Account::getNbAccounts(void) { return (Account::_nbAccounts); }
int Account::getTotalAmount(void) { return (Account::_totalAmount); }
int Account::getNbDeposits(void) { return (Account::_totalNbDeposits); }
int Account::getNbWithdrawals(void) { return (Account::_totalNbWithdrawals); }

void Account::_displayTimestamp(void)
{
    struct tm		*t;
    std::time_t		rawTime;
    std::time(&rawTime);
    t = std::localtime(&rawTime);
    std::cout << "[" << t->tm_year + 1900;
    if (t->tm_mon + 1 < 10) std::cout << "0";
	std::cout << t->tm_mon + 1;
    if (t->tm_mday < 10) std::cout << "0";
    std::cout << t->tm_mday << "_";
    if (t->tm_hour < 10) std::cout << "0";
    std::cout << t->tm_hour;
    if (t->tm_min < 10) std::cout << "0";
    std::cout << t->tm_min;
    if (t->tm_sec < 10) std::cout << "0";
    std::cout << t->tm_sec << "] ";
}

Account::Account(void) : _accountIndex(Account::_nbAccounts), _amount(0),
	_nbDeposits(0), _nbWithdrawals(0)
{
	Account::_nbAccounts++;
	Account::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";amount:" << this->_amount << ";created\n";
}

Account::Account(int initial_deposit) : _accountIndex(Account::_nbAccounts),
	_amount(initial_deposit), _nbDeposits(0), _nbWithdrawals(0)
{
	Account::_totalAmount += initial_deposit;
	Account::_nbAccounts++;
	Account::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";amount:" << this->_amount << ";created\n";
}

Account::~Account(void)
{
	Account::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";amount:" << this->_amount << ";closed\n";
}

void Account::displayAccountsInfos(void)
{
	Account::_displayTimestamp();
	std::cout << "accounts:" << Account::getNbAccounts() << ";"
				<< "total:" << Account::getTotalAmount() << ";"
				<< "deposits:" << Account::getNbDeposits() << ";"
				<< "withdrawals:" << Account::getNbWithdrawals() << "\n";
}

void Account::displayStatus(void) const
{
	Account::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";"
				<< "amount:" << this->_amount << ";"
				<< "deposits:" << this->_nbDeposits << ";"
				<< "withdrawals:" << this->_nbWithdrawals << "\n";
}

void Account::makeDeposit(int deposit)
{
	Account::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";p_amount:" << this->_amount << ";deposit:" << deposit << ";";
	this->_amount += deposit;
	this->_nbDeposits++;
	Account::_totalAmount += deposit;
	Account::_totalNbDeposits++;
	std::cout << "amount:" << this->_amount << ";nb_deposits:" << this->_nbDeposits << "\n";
}

bool Account::makeWithdrawal(int withdrawal)
{
	bool		isValidTransaction;
	Account::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";p_amount:" << this->_amount << ";withdrawal:";
	isValidTransaction = (this->_amount >= withdrawal);
	if (isValidTransaction)
	{
		this->_amount -= withdrawal;
		this->_nbWithdrawals++;
		Account::_totalAmount -= withdrawal;
		Account::_totalNbWithdrawals++;
		std::cout << withdrawal << ";amount:" << this->_amount << ";nb_withdrawals:" << this->_nbWithdrawals << "\n";
	}
	else std::cout << "refused\n";
	return (isValidTransaction);
}

int Account::checkAmount(void) const { return (this->_amount); }