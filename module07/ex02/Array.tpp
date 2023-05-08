/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alboudje <alboudje@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 10:46:43 by alboudje          #+#    #+#             */
/*   Updated: 2023/05/08 13:59:39 by alboudje         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_TPP
#define ARRAY_TPP

#include "Array.hpp"

template <typename T>
Array<T>::Array() : _size(0), _array(NULL)
{}

template <typename T>
Array<T>::Array(unsigned int s) : _size(s)
{
	_array = new(std::nothrow) T[s];
	if (!_array)
		_size = 0;
}

template <typename T>
Array<T>::Array(Array<T> &copy) : _size(0), _array(NULL)
{
	*this = copy;
}

template <typename T>
Array<T> &Array<T>::operator=(Array<T> &copy)
{
	if (_array)
		delete[] _array;
	std::cerr << "here" << std::endl;
	_array = new(std::nothrow) T[copy._size];
	if (!_array)
		_size = 0;
	else
		_size = copy._size;
	for (unsigned i = 0; i < copy._size; i++)
		_array[i] = copy._array[i];
	return (*this);
}

template <typename T>
T &Array<T>::operator[](unsigned int i)
{
	if (i >= _size)
		throw std::out_of_range("Array: Index out of bounds");
	return (_array[i]);
}

template <typename T>
Array<T>::~Array()
{
	if (_array)
		delete [] _array;
}

template <typename T>
unsigned int Array<T>::size() const
{
	return (_size);
}

#endif //ARRAY_TPP