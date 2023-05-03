/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConv.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alboudje <alboudje@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 12:27:28 by alboudje          #+#    #+#             */
/*   Updated: 2023/05/03 16:51:20 by alboudje         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConv.hpp"
#include <iostream>
#include <sstream>

void	ScalarConverter::parsing(const std::string &literal)
{
	if (literal.size() == 0)
		std::cerr << "no literal" << std::endl;
	std::cout << "is int " << isInt(literal) << std::endl; 
	std::cout << "is char " << isChar(literal) << std::endl; 
	std::cout << "is float " << isFloat(literal) << std::endl; 
	std::cout << "is double " << isDouble(literal) << std::endl; 
}

void	ScalarConverter::convert(const std::string &literal)
{
	parsing(literal);
}

bool	ScalarConverter::isChar(const std::string &literal)
{
	if (literal.size() == 1)
		return (true);
	return (false);
}

bool	ScalarConverter::isInt(const std::string &literal)
{
	int					num;
	std::stringstream	ss;

	if (literal == "+inf" || literal == "-inf")
		return (true);
	for (size_t i = 0; i < literal.size(); i++)
	{
		if (i == 0 && literal[i] == '-')
			i++;
		if (literal[i] < '0' || literal[i] > '9')
			return (false);
	}
	ss << literal;
	ss >> num;
	return (!ss.fail());
}

bool	ScalarConverter::isFloat(const std::string &literal)
{
	float				num;
	std::stringstream	ss;


	if (literal == "+inff" || literal == "-inff")
		return (true);
	ss << literal;
	ss >> num;
	if (literal[literal.size() - 1] == 'f'  && literal.find(".") != std::string::npos && ss.fail() == false)
		return (true);
	return (false);
}

bool	ScalarConverter::isDouble(const std::string &literal)
{
	float				num;
	std::stringstream	ss;
	bool				point;

	point = false;
	ss << literal;
	ss >> num;
	for (size_t i = 0; i < literal.size(); i++)
	{
		if ((i == 0 && literal[i] == '-'))
			i++;
		if (literal[i] == '.')
			point = true;
		if ((literal[i] < '0' || literal[i] > '9') && point)
			return (false);
	}
	if (point && ss.fail() == false)
		return (true);
	return (false);
}