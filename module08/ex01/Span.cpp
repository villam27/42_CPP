/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alboudje <alboudje@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 15:51:02 by alboudje          #+#    #+#             */
/*   Updated: 2023/05/09 15:22:48 by alboudje         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span()
{}

Span::Span(unsigned int size)
{
	_vec.reserve(size);
	_max = size;
}

Span::Span(const Span &copy)
{
	_vec = copy._vec;
	_max = copy._max;
}

Span::~Span()
{}

Span	&Span::operator=(const Span &copy)
{
	_vec = copy._vec;
	_max = copy._max;
	return (*this);
}

void	Span::addNumber(int n)
{
	if (_vec.size() < _max)
		_vec.push_back(n);
	else
		throw std::length_error("Limit exceeded");
}

void	Span::addNumbers(std::vector<int>::iterator begin, std::vector<int>::iterator end)
{
	int i;

	i = std::distance(begin, end);
	if (i > static_cast<int>(_max - _vec.size() + 1))
		throw std::length_error("Not enough space");
	_vec.assign(begin, end);
}

int		Span::shortestSpan(void)
{
	std::vector<int>	tmp;
	int					span = -1;

	if (_vec.size() <= 1)
		throw std::length_error("Not enough elements");
	tmp = _vec;
	std::sort(tmp.begin(), tmp.end());
	for (size_t i = 1; i < tmp.size(); i++)
	{
		if (span == -1 || span > (tmp[i] - tmp[i - 1]))
			span = tmp[i] - tmp[i - 1];
	}
	return (span);
}

int		Span::longestSpan(void)
{
	std::vector<int>::const_iterator	max;
	std::vector<int>::const_iterator	min;
	
	if (_vec.size() <= 1)
		throw std::length_error("Not enough elements");
	max = std::max_element(_vec.begin(), _vec.end());
	min = std::min_element(_vec.begin(), _vec.end());
	return (*max - *min);
}
