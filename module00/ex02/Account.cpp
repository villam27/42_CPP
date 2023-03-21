/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alboudje <alboudje@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 11:27:36 by alboudje          #+#    #+#             */
/*   Updated: 2023/03/21 09:51:41 by alboudje         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <iostream>
#include <ctime>

int	Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;

void	Account::_displayTimestamp(void)
{
	std::time_t time;
	char time_str[100];

	std::time(&time);
	std::strftime(time_str, 100, "[%Y%m%d_%H%M%S] ", std::localtime(&time));
	std::cout << time_str;
}

int	Account::getNbAccounts(void)
{
	return (_nbAccounts);
}

int	Account::getTotalAmount(void)
{
	return (_totalAmount);
}

int	Account::getNbDeposits(void)
{
	return (_totalNbDeposits);
}

int	Account::getNbWithdrawals(void)
{
	return (_totalNbWithdrawals);
}

void	Account::displayAccountsInfos(void)
{
	_displayTimestamp();
	std::cout << "accounts:" << _nbAccounts << ";total:" << _totalAmount
			<< ";deposits:" << _totalNbDeposits << ";withdrawals:" << _totalNbWithdrawals << std::endl;
}

Account::Account(int initial_deposit)
{
	this->_displayTimestamp();
	this->_accountIndex = _nbAccounts;
	this->_amount = initial_deposit;
	this->_nbDeposits = 0;
	this->_nbWithdrawals = 0;
	this->_nbAccounts++;
	this->_totalAmount += initial_deposit;
	std::cout << "index:" << this->_accountIndex << ";amount:" << this->_amount << ";created" << std::endl;
}

Account::~Account(void)
{
	this->_displayTimestamp();
	this->_totalAmount -= _amount;
	this->_nbAccounts--;
	std::cout << "index:" << this->_accountIndex << ";amount:" << this->_amount << ";closed" << std::endl;
}

void	Account::makeDeposit(int deposit)
{
	int	prev_amount;

	this->_displayTimestamp();
	prev_amount = this->_amount;
	this->_totalNbDeposits++;
	this->_totalAmount += deposit;
	this->_amount += deposit;
	this->_nbDeposits++;
	std::cout << "index:" << this->_accountIndex << ";p_amount:" << prev_amount << ";deposit:" << deposit
			<< ";amount:" << this->_amount << ";nb_deposits:" << this->_nbDeposits << std::endl;	
}

bool	Account::makeWithdrawal(int withdrawal)
{
	int prev_amount;

	this->_displayTimestamp();
	prev_amount = this->_amount;
	if (this->_amount < withdrawal)
	{
		std::cout << "index:" << this->_accountIndex << ";p_amount:" << prev_amount << ";withdrawal:refused" << std::endl;
		return (false);
	}
	this->_amount -= withdrawal;
	this->_nbWithdrawals++;
	this->_totalNbWithdrawals++;
	this->_totalAmount -= withdrawal;
	std::cout << "index:" << this->_accountIndex << ";p_amount:" << prev_amount << ";withdrawal:" << withdrawal
			  << ";amount:" << this->_amount << ";nb_withdrawals:" << this->_nbWithdrawals << std::endl;
	return (true);
}

int		Account::checkAmount(void) const
{
	return (this->_amount);	
}

void	Account::displayStatus(void) const
{
	this->_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";amount:" << this->_amount << ";deposits:" << this->_nbDeposits
		  	<< ";withdrawals:" << this->_nbWithdrawals << std::endl;
}
