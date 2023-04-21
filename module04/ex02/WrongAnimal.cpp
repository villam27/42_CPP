/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alboudje <alboudje@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 11:51:10 by alboudje          #+#    #+#             */
/*   Updated: 2023/04/20 12:38:31 by alboudje         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal():
	_type("WrongAnimal")
{
	std::cout << "WrongAnimal: constructor called" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal& copy):
	_type(copy._type)
{
	std::cout << "WrongAnimal: copy constructor called" << std::endl;
}

WrongAnimal::~WrongAnimal()
{
	std::cout << "WrongAnimal: destructor called" << std::endl;
}

WrongAnimal&	WrongAnimal::operator=(const WrongAnimal& copy)
{
	std::cout << "WrongAnimal: copy assignment operator called" << std::endl;
	_type = copy._type;
	return (*this);
}

void	WrongAnimal::setType(const std::string& type)
{
	_type = type;
}

const std::string&	WrongAnimal::getType(void) const
{
	return (_type);
}

void	WrongAnimal::makeSound(void) const
{
	std::cout << "Hello !" << std::endl;
}
