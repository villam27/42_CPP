/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alboudje <alboudje@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 11:48:27 by alboudje          #+#    #+#             */
/*   Updated: 2023/04/20 12:11:59 by alboudje         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal():
	_type("Abstract Animal")
{
	std::cout << "Animal: constructor called" << std::endl;
}

Animal::Animal(const Animal& copy):
	_type(copy._type)
{
	std::cout << "Animal: copy constructor called" << std::endl;
}

Animal::~Animal()
{
	std::cout << "Animal: destructor called" << std::endl;
}

Animal&	Animal::operator=(const Animal& copy)
{
	std::cout << "Animal: copy assignment operator called" << std::endl;
	_type = copy._type;
	return (*this);
}

void	Animal::setType(const std::string& type)
{
	_type = type;
}

const std::string&	Animal::getType(void) const
{
	return (_type);
}

void	Animal::makeSound(void) const
{
	std::cout << "Bonsoir." << std::endl;
}

