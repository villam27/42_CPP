/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alboudje <alboudje@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 11:37:09 by alboudje          #+#    #+#             */
/*   Updated: 2023/05/12 16:36:09 by alboudje         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(const char *input_file)
{
	_data_file.open("data.csv");
	_input_file.open(input_file);
	if (!_data_file.is_open())
		std::cerr << "data.csv cannot be opened" << std::endl;
	if (!_input_file.is_open())
		std::cerr << input_file << " cannot be opened" << std::endl;
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &copy)
{
	(void)copy;
}

BitcoinExchange::~BitcoinExchange()
{
	if (_data_file.is_open())
		_data_file.close();
	if (_input_file.is_open())
		_input_file.close();
}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &copy)
{
	(void)copy;
	return (*this);
}

std::string		*BitcoinExchange::splitDate(const std::string &date)
{
	std::string			tok_array[3];
	std::string			token;
	std::stringstream	ss;
	size_t				tok_nbr;

	ss << date;
	tok_nbr = 0;
	while (std::getline(ss, token, '-') && tok_nbr < 3)
	{
		std::cout << token << std::endl;
		tok_array[tok_nbr] = token;
		tok_nbr++;
	}
	return (NULL);
}

unsigned int	BitcoinExchange::getDateFromStr(const std::string &date)
{
	(void)date;
	return (0);
}

double			BitcoinExchange::getExchangeRateFromStr(const std::string &rate)
{
	(void)rate;
	return (0);
}

void	BitcoinExchange::insertData(const std::string *tok_array)
{
	splitDate(tok_array[0]);
}

void	BitcoinExchange::parseData(void)
{
	std::string			line;
	std::string			token;
	std::string			tok_array[2];
	std::stringstream	ss;
	size_t				tok_nbr;

	while (std::getline(_data_file, line))
	{
		tok_nbr = 0;
		ss << line;
		while (std::getline(ss, token, ','))
		{
			tok_array[tok_nbr] = token;
			tok_nbr++;
			if (tok_nbr == 3)
				break ;
		}
		if (tok_nbr != 2)
			throw std::ios_base::failure("Parsing error");
		insertData(tok_array);
		ss.clear();
	}
}

void	BitcoinExchange::getExchange(void)
{
	if (!_data_file.is_open() || !_input_file.is_open())
		throw std::ios_base::failure("Files are not opened");
	parseData();
}