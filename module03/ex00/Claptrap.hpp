#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <iostream>
#include <string>

class Claptrap
{

	public:

		Claptrap();
		Claptrap(const std::string name);
		Claptrap( Claptrap const & src );
		~Claptrap();

		Claptrap &	operator=( Claptrap const & rhs );

		void		attack(const std::string &target);
		void		takeDamage(unsigned int amount);
		void		beRepaired(unsigned int amount);

		std::string	getName(void) const;
		unsigned	getHitPts(void) const;
		unsigned	getEnergyPts(void) const;
		unsigned	getAttackDam(void) const;

	private:
		std::string			_name;
		unsigned			_hitPoints;
		unsigned			_energyPoints;
		unsigned			_attackDamage;
};

#endif //CLAPTRAP_H 