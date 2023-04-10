/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alboudje <alboudje@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 12:47:26 by alboudje          #+#    #+#             */
/*   Updated: 2023/04/10 13:19:12 by alboudje         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>

Fixed::Fixed()
{
	_raw = 0;
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &copy)
{
	std::cout << "Copy constructor called" << std::endl;
	setRawBits(copy.getRawBits());
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

Fixed &Fixed::operator = (const Fixed &copy)
{	
	std::cout << "Copy assignment operator called" << std::endl;
	setRawBits(copy.getRawBits());
	return (*this);
}


int	Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return (_raw);
}

void	Fixed::setRawBits(int const raw)
{
	_raw = raw;
}
