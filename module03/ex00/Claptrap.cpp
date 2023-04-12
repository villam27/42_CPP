#include "Claptrap.hpp"

Claptrap::Claptrap()
{	
	_hitPoints = 10;
	_energyPoints = 10;
	_attackDamage = 10;
}

Claptrap::Claptrap(const std::string name) : _name(name)
{
	_hitPoints = 10;
	_energyPoints = 10;
	_attackDamage = 10;
}

Claptrap::Claptrap(const Claptrap &src)
{
	*this = src;
}

Claptrap::~Claptrap()
{
}

Claptrap &	Claptrap::operator=(Claptrap const &rhs)
{
	_name = rhs.getName();
	_hitPoints = rhs.getHitPts();
	_energyPoints = rhs.getEnergyPts();
	_attackDamage = rhs.getAttackDam();
	return (*this);
}

void	Claptrap::attack(const std::string &target)
{
	if (_energyPoints == 0)
	{
		std::cout << "Claptrap " << getName() << " not enough energy points" << std::endl;
		return ;
	}
	_energyPoints--;
	std::cout << "Claptrap " << getName() << " attacks " << target << ", causing " << getAttackDam() << " points of damage" << std::endl;
}

void	Claptrap::takeDamage(unsigned int amount)
{
	if (_hitPoints == 0)
	{
		std::cout << "Claptrap " << getName() << " is dead" << std::endl;
		return ;
	}
	if (amount > _hitPoints)
		_hitPoints = 0;
	else
		_hitPoints -= amount;
	std::cout << "Claptrap " << getName() << " take " << amount << " points of damage, his new life is " << getHitPts() << std::endl;
}

void	Claptrap::beRepaired(unsigned int amout)
{
	if (_energyPoints == 0)
	{
		std::cout << "Claptrap " << getName() << " not enough energy points" << std::endl;
		return ;
	}
	_energyPoints--;
	_hitPoints += amout;
	std::cout << "Claptrap " << getName() << " take repair himself, his new life is " << getHitPts() << std::endl;
}

std::string	Claptrap::getName(void) const
{
	return (_name);
}

unsigned	Claptrap::getHitPts(void) const
{
	return (_hitPoints);
}

unsigned	Claptrap::getEnergyPts(void) const
{
	return (_energyPoints);
}

unsigned	Claptrap::getAttackDam(void) const
{
	return (_attackDamage);
}