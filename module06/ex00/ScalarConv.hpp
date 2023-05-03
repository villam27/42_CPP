/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConv.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alboudje <alboudje@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 12:07:51 by alboudje          #+#    #+#             */
/*   Updated: 2023/05/03 16:10:58 by alboudje         ###   ########.fr       */
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
		static bool	isChar(const std::string &literal);
		static bool	isInt(const std::string &literal);
		static bool	isFloat(const std::string &literal);
		static bool	isDouble(const std::string &literal);

	public:
		static void	convert(const std::string &literal);
};

#endif //SCALAR_CONV_HPP