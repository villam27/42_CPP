/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alboudje <alboudje@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 10:33:36 by alboudje          #+#    #+#             */
/*   Updated: 2023/03/30 14:51:01 by alboudje         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
#define HUMANB_HPP

#include "Weapon.hpp"
#include <string>
#include <iostream>

class HumanB
{
private:
	std::string _name;
	Weapon		*_weapon;

public:
	HumanB(const std::string name);
	~HumanB();

	void	attack(void);
	void	setWeapon(Weapon &weapon);
};

#endif //HUMANB_HPP