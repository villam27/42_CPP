/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alboudje <alboudje@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 12:47:26 by alboudje          #+#    #+#             */
/*   Updated: 2023/04/12 09:54:31 by alboudje         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>
#include <cmath>

const int	Fixed::_fractional = 8;

Fixed::Fixed()
{
	_raw = 0;
	//std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &copy)
{
	//std::cout << "Copy constructor called" << std::endl;
	setRawBits(copy.getRawBits());
}

Fixed::Fixed(const int raw)
{
	//std::cout << "Int constructor called" << std::endl;
	_raw = (raw << _fractional);
}

Fixed::Fixed(const float raw)
{
	//std::cout << "Float constructor called" << std::endl;
	_raw = static_cast<int>(roundf(raw * GET_DECIMAL(_fractional)));
}

Fixed::~Fixed()
{
	//std::cout << "Destructor called" << std::endl;
}

Fixed &Fixed::operator = (const Fixed &copy)
{	
	//std::cout << "Copy assignment operator called" << std::endl;
	setRawBits(copy.getRawBits());
	return (*this);
}

bool	Fixed::operator>(const Fixed &fixed)
{
	return (_raw > fixed._raw);
}

bool	Fixed::operator<(const Fixed &fixed)
{
	
	return (_raw < fixed._raw);
}

bool	Fixed::operator>=(const Fixed &fixed)
{
	return (_raw >= fixed._raw);
}

bool	Fixed::operator<=(const Fixed &fixed)
{
	return (_raw <= fixed._raw);
}

bool	Fixed::operator==(const Fixed &fixed)
{
	return (_raw == fixed._raw);
}

bool	Fixed::operator!=(const Fixed &fixed)
{
	return (_raw != fixed._raw);
}

Fixed	Fixed::operator+(const Fixed &fixed)
{
	Fixed	value(toFloat() * fixed.toFloat());

	return (value);
}

Fixed	Fixed::operator-(const Fixed &fixed)
{
	Fixed	value(toFloat() * fixed.toFloat());

	return (value);
}

Fixed	Fixed::operator*(const Fixed &fixed)
{
	Fixed	value(toFloat() * fixed.toFloat());

	return (value);
}

Fixed	Fixed::operator/(const Fixed &fixed)
{
	Fixed	value(toFloat() * fixed.toFloat());

	return (value);
}

Fixed	&Fixed::operator++()
{
	_raw++;
	return (*this);
}

Fixed	&Fixed::operator--()
{
	_raw--;
	return (*this);
}

Fixed	Fixed::operator++(int)
{
	Fixed	value(*this);
	_raw++;

	return (value);
}

Fixed	Fixed::operator--(int)
{
	Fixed	value(*this);
	_raw--;

	return (value);	
}

const Fixed	Fixed::min(const Fixed &nbr1, const Fixed &nbr2)
{
    if (nbr1.getRawBits() < nbr2.getRawBits())
        return (nbr1);
    else
        return (nbr2);
}

Fixed	Fixed::min(Fixed &nbr1, Fixed &nbr2)
{
    if (nbr1.getRawBits() < nbr2.getRawBits())
        return (nbr1);
    else
        return (nbr2);
}

const Fixed	Fixed::max(const Fixed &nbr1, const Fixed &nbr2)
{
    if (nbr1.getRawBits() > nbr2.getRawBits())
        return (nbr1);
    else
        return (nbr2);
}

Fixed	Fixed::max(Fixed &nbr1, Fixed &nbr2)
{
	if (nbr1.getRawBits() > nbr2.getRawBits())
	    return (nbr1);
	else
	    return (nbr2);
}

float	Fixed::toFloat(void) const
{
	return (static_cast<float>(_raw) / GET_DECIMAL(_fractional));
}

int	Fixed::toInt(void) const
{
	return (_raw >> _fractional);
}

int	Fixed::getRawBits(void) const
{
	//std::cout << "getRawBits member function called" << std::endl;
	return (_raw);
}

void	Fixed::setRawBits(int const raw)
{
	_raw = raw;
}

std::ostream	&operator << (std::ostream &output, const Fixed &fixed)
{
	output << fixed.toFloat();
	return (output);
}