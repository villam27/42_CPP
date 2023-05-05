/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConv.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alboudje <alboudje@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 12:27:28 by alboudje          #+#    #+#             */
/*   Updated: 2023/05/05 10:46:31 by alboudje         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConv.hpp"
#include <iostream>
#include <sstream>
#include <climits>

void	ScalarConverter::parsing(const std::string &literal)
{
	char	c;
	int		i;
	float	f;
	double	d;

	if (literal.size() == 0)
		std::cerr << "no literal" << std::endl;
	if (isChar(literal, c))
		printChar(c);
	else if (isInt(literal, i))
		printInt(i);
	else if (isFloat(literal, f))
		printFloat(f, literal);
	else if (isDouble(literal, d))
		printDouble(d, literal);
	else
		std::cerr << "Not a char, int, float or double" << std::endl;
}

void	ScalarConverter::convert(const std::string &literal)
{
	parsing(literal);
}

bool	ScalarConverter::isChar(const std::string &literal, char &c)
{
	if (literal.size() == 1 && !isdigit(literal[0]))
	{
		c = literal[0];
		return (true);
	}
	return (false);
}

bool	ScalarConverter::isInt(const std::string &literal, int &i)
{
	int					num;
	std::stringstream	ss;

	for (size_t i = 0; i < literal.size(); i++)
	{
		if (i == 0 && literal[i] == '-')
			i++;
		if (literal[i] < '0' || literal[i] > '9')
			return (false);
	}
	ss << literal;
	ss >> num;
	i = num;
	return (!ss.fail());
}

bool	isDoubleLimit(const std::string &literal)
{	
	if (literal == "+inf" || literal == "-inf" || literal == "nan")
		return (true);
	return (false);
}

bool	isFloatLimit(const std::string &literal)
{	
	if (literal == "+inff" || literal == "-inff" || literal == "nanf")
		return (true);
	return (false);
}

bool	ScalarConverter::isFloat(const std::string &literal, float &f)
{
	float				num;
	std::stringstream	ss;


	if (literal == "+inff" || literal == "-inff" || literal == "nanf")
		return (true);
	ss << literal;
	ss >> num;
	f = num;
	if (literal[literal.size() - 1] == 'f'  && literal.find(".") != std::string::npos && !ss.fail())
		return (true);
	return (false);
}

bool	ScalarConverter::isDouble(const std::string &literal, double &d)
{
	long double			num;
	std::stringstream	ss;
	bool				point;

	point = false;
	ss << literal;
	ss >> num;
	d = num;
	if (literal == "+inf" || literal == "-inf" || literal == "nan")
		return (true);
	for (size_t i = 0; i < literal.size(); i++)
	{
		if ((i == 0 && literal[i] == '-'))
			i++;
		if ((literal[i] < '0' || literal[i] > '9') && point)
			return (false);
		if (literal[i] == '.')
			point = true;
	}
	if (point && !ss.fail())
		return (true);
	return (false);
}

void	printDispChar(char c)
{	
	if (c <= 31 || c == 127)
		std::cout << "char: " << "Non displayable" << std::endl;
	else
		std::cout << "char: " << c << std::endl;
}

void	printOverFlow(int i)
{	
	if (i == INT_MAX || i == INT_MIN)
		std::cout << "int: " << "Overflow" << std::endl;
	else
		std::cout << "int: " << i << std::endl;
}

void	ScalarConverter::printChar(char &c)
{
	printDispChar(c);
	std::cout << "int: " << static_cast<int>(c) << std::endl;
	std::cout << "float: " << static_cast<float>(c) << "f" << std::endl;
	std::cout << "double: " << static_cast<double>(c) << std::endl;
}

void	ScalarConverter::printInt(int &i)
{
	if (i < 0 || i >= 127)
		std::cout << "char: " << "Impossible" << std::endl;
	else
		printDispChar(static_cast<char>(i));
	std::cout << "int: " << i << std::endl;
	std::cout << "float: " << static_cast<float>(i) << "f" << std::endl;
	std::cout << "double: " << static_cast<double>(i) << std::endl;
}

void	ScalarConverter::printFloat(float &f, const std::string &l)
{
	std::string	doubleLim(l);
	
	doubleLim[doubleLim.size() - 1] = ' ';
	if (f < 0 || f > 255 || isFloatLimit(l))
		std::cout << "char: " << "Impossible" << std::endl;
	else
		printDispChar(static_cast<char>(f));
	if (isFloatLimit(l))
		std::cout << "int: " << "Impossible" << std::endl;
	else
		printOverFlow(static_cast<int>(f));
	if (isFloatLimit(l))
		std::cout << "float: " << l << std::endl;
	else
		std::cout << "float: " << f << "f" << std::endl;
	if (isFloatLimit(l))
		std::cout << "double: " << doubleLim << std::endl;
	else
		std::cout << "double: " << static_cast<double>(f) << std::endl;
}


void	ScalarConverter::printDouble(double &d, const std::string &l)
{
	if (d < 0 || d > 255 || isDoubleLimit(l))
		std::cout << "char: " << "Impossible" << std::endl;
	else
		printDispChar(static_cast<char>(d));
	if (isDoubleLimit(l))
		std::cout << "int: " << "Impossible" << std::endl;
	else
		printOverFlow(static_cast<int>(d));
	if (isDoubleLimit(l))
		std::cout << "float: " << l << "f" << std::endl;
	else
		std::cout << "float: " << static_cast<float>(d) << "f" << std::endl;
	if (isDoubleLimit(l))
		std::cout << "double: " << l << std::endl;
	else
		std::cout << "double: " << d << std::endl;
}
