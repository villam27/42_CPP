/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alboudje <alboudje@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 10:21:10 by alboudje          #+#    #+#             */
/*   Updated: 2023/03/30 10:31:18 by alboudje         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(const std::string type)
{
	this->_type = type;
	std::cout << _type << ": created" << std::endl;	
}

Weapon::~Weapon()
{
	std::cout << _type << ": destroyed" << std::endl;
}

std::string	Weapon::getType()
{
	return (this->_type);
}

void	Weapon::setType(const std::string type)
{
	this->_type = type;
}