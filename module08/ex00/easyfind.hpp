/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alboudje <alboudje@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 14:44:53 by alboudje          #+#    #+#             */
/*   Updated: 2023/05/08 15:02:09 by alboudje         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASY_FIND_HPP
#define EASY_FIND_HPP

#include <stdexcept>
#include <algorithm>
#include <iostream>

template<typename T>
void	easyfind(T &t, int num)
{
	typename T::const_iterator	it;

	it = std::find(t.begin(), t.end(), num);
	if (it == t.end())
		throw std::logic_error("EasyFind: number not found");
}

#endif