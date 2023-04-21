/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alboudje <alboudje@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 11:49:24 by alboudje          #+#    #+#             */
/*   Updated: 2023/04/20 12:11:59 by alboudje         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog()
{
	std::cout << "Dog: constructor called" << std::endl;
	_type = "Dog";
}

Dog::Dog(const Dog& copy):
	Animal(copy)
{
	std::cout << "Dog: copy constructor called" << std::endl;
}

Dog::~Dog()
{
	std::cout << "Dog: destructor called" << std::endl;
}

Dog&	Dog::operator=(const Dog& copy)
{
	std::cout << "Dog: copy assignment operator called" << std::endl;
	_type = copy._type;
	return (*this);
}

void	Dog::makeSound(void) const
{
	std::cout << "Bark !" << std::endl;
}
