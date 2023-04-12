/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alboudje <alboudje@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 13:20:35 by alboudje          #+#    #+#             */
/*   Updated: 2023/04/12 17:19:39 by alboudje         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap()
{
	std::cout << "Constructor Called For FragTrap" << std::endl;
	_hitPoints = 100;
	_energyPoints = 50;
	_attackDamage = 20;
}

FragTrap::FragTrap(const std::string name)
{
	std::cout << "String Constructor Called For FragTrap" << std::endl;
	_name = name;
	_hitPoints = 100;
	_energyPoints = 50;
	_attackDamage = 20;
}

FragTrap::FragTrap(FragTrap const & src) : ClapTrap(src)
{
	std::cout << "Copy Constructor Called For FragTrap" << std::endl;
	*this = src;
}

FragTrap::~FragTrap()
{
	std::cout << "Destructor Called for FragTrap" << std::endl;
}

FragTrap &FragTrap::operator=(FragTrap const &rhs)
{	
	_name = rhs.getName();
	_hitPoints = rhs.getHitPts();
	_energyPoints = rhs.getEnergyPts();
	_attackDamage = rhs.getAttackDam();
	return (*this);
}

void	FragTrap::attack(const std::string &target)
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

void	FragTrap::takeDamage(unsigned int amount)
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

void	FragTrap::beRepaired(unsigned int amount)
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

void	FragTrap::highFivesGuys(void)
{
	std::cout << "FragTrap " << this->_name << " is asking for a high five !" << std::endl;
}
