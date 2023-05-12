/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alboudje <alboudje@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 14:44:53 by alboudje          #+#    #+#             */
/*   Updated: 2023/05/10 09:48:07 by alboudje         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
#define SPAN_HPP

#include <stdexcept>
#include <algorithm>
#include <iostream>
#include <vector>
#include <iterator>

class Span
{
	public:
		Span();
		Span(unsigned int size);
		Span(const Span &copy);
		~Span();
		Span	&operator=(const Span &copy);

		void	addNumber(int n);
		void	addNumbers(std::vector<int>::iterator begin, std::vector<int>::iterator end);
		int		shortestSpan(void);
		int		longestSpan(void);

	private:
		std::vector<int>	_vec;
		unsigned int		_max;
};

#endif