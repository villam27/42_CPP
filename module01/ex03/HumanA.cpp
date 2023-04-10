/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alboudje <alboudje@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 10:35:42 by alboudje          #+#    #+#             */
/*   Updated: 2023/04/10 10:17:40 by alboudje         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA(const std::string name, Weapon &weapon) : _weapon(weapon)
{
	this->_name = name;
	std::cout << this->_name << ": created" << std::endl;
}

HumanA::~HumanA()
{
	std::cout << this->_name << ": destroyed" << std::endl;
}

void HumanA::attack()
{
	std::cout << this->_name << " attacks with their " << this->_weapon.getType() << std::endl;
}