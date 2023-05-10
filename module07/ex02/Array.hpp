/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alboudje <alboudje@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 14:44:53 by alboudje          #+#    #+#             */
/*   Updated: 2023/05/10 09:26:42 by alboudje         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <stdexcept>

template <typename T>
class Array
{
	public:
		Array();
		Array(unsigned int);
		Array(Array<T> &copy);
		Array<T> &operator=(Array<T> &copy);
		~Array();
		
		T &operator[](unsigned int);

		unsigned int size() const;

	private:
		unsigned int	_size;
		T 				*_array;
};

#endif //ARRAY_HPP