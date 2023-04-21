/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alboudje <alboudje@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 11:51:22 by alboudje          #+#    #+#             */
/*   Updated: 2023/04/20 12:11:59 by alboudje         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat()
{
	std::cout << "WrongCat: constructor called" << std::endl;
	_type = "WrongCat";
}

WrongCat::WrongCat(const WrongCat& copy):
	WrongAnimal(copy)
{
	std::cout << "WrongCat: copy constructor called" << std::endl;
}

WrongCat::~WrongCat()
{
	std::cout << "WrongCat: destructor called" << std::endl;
}

WrongCat&	WrongCat::operator=(const WrongCat& copy)
{
	std::cout << "WrongCat: copy assignment operator called" << std::endl;
	_type = copy._type;
	return (*this);
}

void	WrongCat::makeSound(void) const
{
	std::cout << "Bark Bark !" << std::endl;
}
