/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alboudje <alboudje@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 11:37:09 by alboudje          #+#    #+#             */
/*   Updated: 2023/05/15 15:42:01 by alboudje         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(const char *input_file)
{
	_date_check = false;
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

int	BitcoinExchange::getDateFormat(const std::string *date_array)
{
	int					year;
	int					month;
	int					day;
	std::stringstream	ss;
	
	if (date_array[0] == "date")
		return (HEADER_DATE);
	ss << date_array[0];
	ss >> year;
	if (ss.fail() || (year < 0 || year > 9999))
		return (INVALID_DATE);
	ss.clear();
	ss << date_array[1];
	ss >> month;
	if (ss.fail() || (month < 0 || month > 12))
		return (INVALID_DATE);	
	ss.clear();
	ss << date_array[2];
	ss >> day;
	if (ss.fail() || (day < 0 || day > 31))
		return (INVALID_DATE);
	return (VALID_DATE(year, month, day));
}

bool	BitcoinExchange::checkDate(const std::string &date, std::string *date_array)
{
	std::string			token;
	std::stringstream	ss;
	size_t				tok_nbr;

	ss << date;
	tok_nbr = 0;
	while (std::getline(ss, token, '-'))
	{
		date_array[tok_nbr] = token;
		tok_nbr++;
		if (tok_nbr == 4)
			break ;
	}
	if (token == "date" && _date_check == false)
		_date_check = true;
	else if (tok_nbr != 3)
		return (false);
	return (true);
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
	std::string			date_array[3];
	static	unsigned	line = 0;
	int					date = 0;
	double				ex_rate = 0;

	line++;
	//std::cerr << "LINE: " << line << std::endl;
	if (checkDate(tok_array[0], date_array) == false)
		throw std::ios_base::failure("Date parsing error");
	date = getDateFormat(date_array);
	if (date == INVALID_DATE)
		throw std::ios_base::failure("Date format error");
	else if (date == HEADER_DATE)
		return ;
	ex_rate = std::strtod(tok_array[1].c_str(), NULL);
	_map_data.insert(std::pair<unsigned int, double>(static_cast<unsigned int>(date), ex_rate));
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

ErrorLevel	BitcoinExchange::setErrorLvl(size_t &tok_nbr)
{
	std::stringstream	ss;

	if (tok_nbr == 3)
		return (PARSING_ERROR);
	if (_current_parsing_date == false)
		return (DATE_ERROR);
	if (_current_date == INVALID_DATE)
		return (FORMAT_ERROR);
	if (_current_value > 1000)
		return (OVERFLOW);
	if (_current_value < 0)
		return (UNDERFLOW);
	return (NO_ERROR);
}

void	BitcoinExchange::displayWithError(std::string *tok_array)
{
	std::string									err_str[5] =
	{
		"parsing error",
		"parsing error on date",
		std::string("bad input => ") + tok_array[0],
		"too large number",
		"not a positive number"
	};
	std::map<unsigned int, double>::iterator	rate;
	bool										print_rate;
	
	print_rate = true;
	if (_current_err_lvl == NO_ERROR)
	{
		rate = _map_data.lower_bound(_current_date);
		if (rate == _map_data.begin() && static_cast<unsigned>(_current_date) != rate->first)
			print_rate = false;
		if (print_rate)
			std::cout << tok_array[0] << " => " << tok_array[1] << " = " << rate->second * _current_value << std::endl;
		else
			std::cerr << "Error: first date known is " << _map_data.begin()->first << std::endl;
	}
	else
		std::cerr  << "Error: " << err_str[_current_err_lvl - 1] << "." << std::endl;
}

void	BitcoinExchange::displayInputData(void)
{	
	std::string			line;
	std::string			token;
	std::string			tok_array[2];
	std::string			date_array[3];
	std::stringstream	ss;
	size_t				tok_nbr;

	while (std::getline(_input_file, line))
	{
		tok_nbr = 0;
		ss << line;
		while (std::getline(ss, token, '|'))
		{
			//std::cout << token << std::endl;
			tok_array[tok_nbr] = token;
			tok_nbr++;
			if (tok_nbr == 3)
				break ;
		}
		_current_parsing_date = checkDate(tok_array[0], date_array);
		_current_date = getDateFormat(date_array);
		_current_value = std::strtod(tok_array[1].c_str(), NULL);
		_current_err_lvl = setErrorLvl(tok_nbr);
		displayWithError(tok_array);
		ss.clear();
	}
}

void	BitcoinExchange::getExchange(void)
{
	if (!_data_file.is_open() || !_input_file.is_open())
		throw std::ios_base::failure("Files are not opened");
	parseData();
	displayInputData();
}