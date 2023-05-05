/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConv.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alboudje <alboudje@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 12:07:51 by alboudje          #+#    #+#             */
/*   Updated: 2023/05/04 15:23:55 by alboudje         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALAR_CONV_HPP
#define SCALAR_CONV_HPP

#include <string>

class ScalarConverter
{
	private:
		ScalarConverter();
		static void	parsing(const std::string &literal);
		static bool	isChar(const std::string &literal, char &c);
		static bool	isInt(const std::string &literal, int &i);
		static bool	isFloat(const std::string &literal, float &f);
		static bool	isDouble(const std::string &literal, double &d);
		static void	printChar(char &c);
		static void	printInt(int &i);
		static void	printFloat(float &f, const std::string &l);
		static void	printDouble(double &d, const std::string &l);

	public:
		static void	convert(const std::string &literal);
};

#endif //SCALAR_CONV_HPP