/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alboudje <alboudje@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 10:33:36 by alboudje          #+#    #+#             */
/*   Updated: 2023/03/30 14:51:07 by alboudje         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
#define HUMANA_HPP

#include "Weapon.hpp"
#include <string>
#include <iostream>

class HumanA
{
private:
	std::string _name;
	Weapon		&_weapon;

public:
	HumanA(const std::string name, Weapon &weapon);
	~HumanA();

	void attack(void);
};

#endif //HUMANA_HPP