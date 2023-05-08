/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alboudje <alboudje@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 14:44:53 by alboudje          #+#    #+#             */
/*   Updated: 2023/05/06 15:39:01 by alboudje         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
#define ITER_HPP

template <typename T>
void print_i(T &i)
{
	std::cout << i << std::endl;
}

template <typename T, typename F>
void iter(T array, const unsigned size, F func)
{
	if (!array)
		return ;
	for (unsigned i = 0; i < size; i++)
	{
		func(array[i]);
	}
}

#endif