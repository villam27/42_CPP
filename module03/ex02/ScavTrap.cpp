/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alboudje <alboudje@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 13:20:35 by alboudje          #+#    #+#             */
/*   Updated: 2023/04/12 17:00:08 by alboudje         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap()
{
	std::cout << "Constructor Called For ScavTrap" << std::endl;
	_hitPoints = 100;
	_energyPoints = 50;
	_attackDamage = 20;
}

ScavTrap::ScavTrap(const std::string name)
{
	std::cout << "String Constructor Called For ScavTrap" << std::endl;
	_name = name;
	_hitPoints = 100;
	_energyPoints = 50;
	_attackDamage = 20;
}

ScavTrap::ScavTrap(ScavTrap const & src) : ClapTrap(src)
{
	std::cout << "Copy Constructor Called For ScavTrap" << std::endl;
	*this = src;
}

ScavTrap::~ScavTrap()
{
	std::cout << "Destructor Called for ScavTrap" << std::endl;
}

ScavTrap &ScavTrap::operator=(ScavTrap const &rhs)
{	
	_name = rhs.getName();
	_hitPoints = rhs.getHitPts();
	_energyPoints = rhs.getEnergyPts();
	_attackDamage = rhs.getAttackDam();
	_gateKeep = rhs._gateKeep;
	return (*this);
}

void	ScavTrap::attack(const std::string &target)
{
	if (_hitPoints == 0)
	{
		std::cout << "ClapTrap " << getName() << " not enough hp" << std::endl;
		return ;
	}
	if (_energyPoints == 0)
	{
		std::cout << "ClapTrap " << getName() << " not enough energy points" << std::endl;
		return ;
	}
	_energyPoints--;
	std::cout << "ClapTrap " << getName() << " attacks " << target << ", causing " << getAttackDam() << " points of damage" << std::endl;
}

void	ScavTrap::takeDamage(unsigned int amount)
{
	if (_hitPoints == 0)
	{
		std::cout << "ClapTrap " << getName() << " is dead" << std::endl;
		return ;
	}
	if (amount > _hitPoints)
		_hitPoints = 0;
	else
		_hitPoints -= amount;
	std::cout << "ClapTrap " << getName() << " take " << amount << " points of damage, his new life is " << getHitPts() << std::endl;
}

void	ScavTrap::beRepaired(unsigned int amount)
{
	if (_hitPoints == 0)
	{
		std::cout << "ClapTrap " << getName() << " not enough hp" << std::endl;
		return ;
	}
	if (_energyPoints == 0)
	{
		std::cout << "ClapTrap " << getName() << " not enough energy points" << std::endl;
		return ;
	}
	_energyPoints--;
	_hitPoints += amount;
	std::cout << "ClapTrap " << getName() << " take repair himself, his new life is " << getHitPts() << std::endl;
}

void	ScavTrap::guardGate(void)
{
	if(!_gateKeep)
	{
		std::cout << "ScavTrap " << _name << " has entered in Gate Keeper mode" << std::endl;
		_gateKeep = true;
		return ;
	}
	std::cout << "ScavTrap " << this->_name << " is already in Gate Keeper mode" << std::endl;
}
