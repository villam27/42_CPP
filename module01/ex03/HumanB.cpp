/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alboudje <alboudje@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 10:35:42 by alboudje          #+#    #+#             */
/*   Updated: 2023/03/30 11:07:56 by alboudje         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(const std::string name)
{
	this->_name = name;
	this->_weapon = NULL;
	std::cout << this->_name << ": created" << std::endl;
}

HumanB::~HumanB()
{
	std::cout << this->_name << ": destroyed" << std::endl;
}

void HumanB::attack()
{
	if (!this->_weapon)
		std::cout << this->_name << " cannot attack" << std::endl;
	else
		std::cout << this->_name << " attacks with their " << this->_weapon->getType() << std::endl;
}

void	HumanB::setWeapon(Weapon &weapon)
{
	this->_weapon = &weapon;	
}