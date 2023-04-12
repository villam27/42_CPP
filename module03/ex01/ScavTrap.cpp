/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alboudje <alboudje@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 13:20:35 by alboudje          #+#    #+#             */
/*   Updated: 2023/04/12 13:39:23 by alboudje         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap()
{
	std::cout << "ScavTrap constructor Called" << std::endl;
	_hitPoints = 100;
	_energyPoints = 50;
	_attackDamage = 20;
}

ScavTrap::ScavTrap(const std::string name)
{
	std::cout << "ScavTrap constructor Called" << std::endl;
	_name = name;
	_hitPoints = 100;
	_energyPoints = 50;
	_attackDamage = 20;
}

ScavTrap::ScavTrap(ScavTrap const & src) : ClapTrap(src)
{
	std::cout << "ScavTrap constructor Called" << std::endl;
	*this = src;
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap destructor Called" << std::endl;
}

ScavTrap &ScavTrap::operator=(ScavTrap const &rhs)
{	
	_name = rhs.getName();
	_hitPoints = rhs.getHitPts();
	_energyPoints = rhs.getEnergyPts();
	_attackDamage = rhs.getAttackDam();
	return (*this);
}

void	ScavTrap::attack(const std::string &target)
{
	if (_energyPoints == 0)
	{
		std::cout << "ScavTrap " << getName() << " not enough energy points" << std::endl;
		return ;
	}
	_energyPoints--;
	std::cout << "ScavTrap " << getName() << " attacks " << target << ", causing " << getAttackDam() << " points of damage" << std::endl;
}

void	ScavTrap::takeDamage(unsigned int amount)
{
	if (_hitPoints == 0)
	{
		std::cout << "ScavTrap " << getName() << " is dead" << std::endl;
		return ;
	}
	if (amount > _hitPoints)
		_hitPoints = 0;
	else
		_hitPoints -= amount;
	std::cout << "ScavTrap " << getName() << " take " << amount << " points of damage, his new life is " << getHitPts() << std::endl;
}

void	ScavTrap::beRepaired(unsigned int amount)
{
if (_energyPoints == 0)
	{
		std::cout << "ScavTrap " << getName() << " not enough energy points" << std::endl;
		return ;
	}
	_energyPoints--;
	_hitPoints += amount;
	std::cout << "ScavTrap " << getName() << " take repair himself, his new life is " << getHitPts() << std::endl;
}
