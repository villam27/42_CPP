#ifndef ClapTrap_HPP
#define ClapTrap_HPP

#include <iostream>
#include <string>

class ClapTrap
{

	public:

		ClapTrap();
		ClapTrap(const std::string name);
		ClapTrap( ClapTrap const & src );
		~ClapTrap();

		ClapTrap &	operator=( ClapTrap const & rhs );

		void		attack(const std::string &target);
		void		takeDamage(unsigned int amount);
		void		beRepaired(unsigned int amount);

		std::string	getName(void) const;
		unsigned	getHitPts(void) const;
		unsigned	getEnergyPts(void) const;
		unsigned	getAttackDam(void) const;

	protected:
		std::string			_name;
		unsigned			_hitPoints;
		unsigned			_energyPoints;
		unsigned			_attackDamage;
};

#endif //ClapTrap_H 