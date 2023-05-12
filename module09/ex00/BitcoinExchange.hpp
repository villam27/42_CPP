/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alboudje <alboudje@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 10:53:09 by alboudje          #+#    #+#             */
/*   Updated: 2023/05/12 16:15:49 by alboudje         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOIN_EXCHANGE_HPP
#define BITCOIN_EXCHANGE_HPP

#include <fstream>
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

	std::string		*splitDate(const std::string &date);
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