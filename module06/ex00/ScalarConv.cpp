/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConv.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alboudje <alboudje@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 12:27:28 by alboudje          #+#    #+#             */
/*   Updated: 2023/05/03 16:10:33 by alboudje         ###   ########.fr       */
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

	ss << literal;
	ss >> num;
	return (!ss.fail());
}

bool	ScalarConverter::isFloat(const std::string &literal)
{
	float				num;
	std::stringstream	ss;

	ss << literal;
	ss >> num;
	if (literal[literal.size() - 1] == 'f' && ss.fail() == false)
		return (true);
	return (false);
}

/*bool	ScalarConverter::isDouble(const std::string &literal)
{
	(void)literal;
}*/