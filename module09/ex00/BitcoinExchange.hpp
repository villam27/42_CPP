/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alboudje <alboudje@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 10:53:09 by alboudje          #+#    #+#             */
/*   Updated: 2023/05/15 13:10:19 by alboudje         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOIN_EXCHANGE_HPP
#define BITCOIN_EXCHANGE_HPP

#define	INVALID_DATE	-1
#define	HEADER_DATE		-2
#define	VALID_DATE(YEAR, MONTH, DAY) (10000 * (YEAR) + 100 * (MONTH) + (DAY))

#include <fstream>
#include <cstdlib>
#include <sstream>
#include <stdexcept>
#include <iostream>
#include <map>

class BitcoinExchange
{
private:
	BitcoinExchange();
	std::ifstream					_data_file;
	std::ifstream					_input_file;
	std::map<unsigned int, double>	_map_data;
	bool							_date_check;

	int				getDateFormat(const std::string *date_array);
	bool			checkDate(const std::string &date, std::string *date_array);
	unsigned int	getDateFromStr(const std::string &date);
	double			getExchangeRateFromStr(const std::string &rate);
	void			insertData(const std::string *tok_array);
	void			parseData(void);

public:
	BitcoinExchange(const char *input_file);
	BitcoinExchange(const BitcoinExchange &copy);
	~BitcoinExchange();

	BitcoinExchange &operator=(const BitcoinExchange &copy);
	
	void	getExchange(void);
};

#endif //BITCOIN_EXCHANGE_HPP