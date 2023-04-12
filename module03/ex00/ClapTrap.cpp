#include "ClapTrap.hpp"

ClapTrap::ClapTrap()
{
	std::cout << "Constructor Called For ClapTrap" << std::endl;
	_hitPoints = 10;
	_energyPoints = 10;
	_attackDamage = 10;
}

ClapTrap::ClapTrap(const std::string name) : _name(name)
{
	std::cout << "String Constructor Called For ClapTrap" << std::endl;
	_hitPoints = 10;
	_energyPoints = 10;
	_attackDamage = 10;
}

ClapTrap::ClapTrap(const ClapTrap &src)
{
	std::cout << "Copy Constructor Called For ClapTrap" << std::endl;
	*this = src;
}

ClapTrap::~ClapTrap()
{
	std::cout << "Destructor Called for ClapTrap" << std::endl;
}

ClapTrap &	ClapTrap::operator=(ClapTrap const &rhs)
{
	_name = rhs.getName();
	_hitPoints = rhs.getHitPts();
	_energyPoints = rhs.getEnergyPts();
	_attackDamage = rhs.getAttackDam();
	return (*this);
}

void	ClapTrap::attack(const std::string &target)
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

void	ClapTrap::takeDamage(unsigned int amount)
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

void	ClapTrap::beRepaired(unsigned int amout)
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
	_hitPoints += amout;
	std::cout << "ClapTrap " << getName() << " take repair himself, his new life is " << getHitPts() << std::endl;
}

std::string	ClapTrap::getName(void) const
{
	return (_name);
}

unsigned	ClapTrap::getHitPts(void) const
{
	return (_hitPoints);
}

unsigned	ClapTrap::getEnergyPts(void) const
{
	return (_energyPoints);
}

unsigned	ClapTrap::getAttackDam(void) const
{
	return (_attackDamage);
}