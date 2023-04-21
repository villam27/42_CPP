/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alboudje <alboudje@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 11:49:00 by alboudje          #+#    #+#             */
/*   Updated: 2023/04/20 12:11:59 by alboudje         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat()
{
	std::cout << "Cat: constructor called" << std::endl;
	_type = "Cat";
}

Cat::Cat(const Cat& copy):
	Animal(copy)
{
	std::cout << "Cat: copy constructor called" << std::endl;
}

Cat::~Cat()
{
	std::cout << "Cat: destructor called" << std::endl;
}

Cat&	Cat::operator=(const Cat& copy)
{
	std::cout << "Cat: copy assignment operator called" << std::endl;
	_type = copy._type;
	return (*this);
}

void	Cat::makeSound(void) const
{
	std::cout << "Meow Meow !" << std::endl;
}
