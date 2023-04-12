/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alboudje <alboudje@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 16:00:11 by alboudje          #+#    #+#             */
/*   Updated: 2023/04/12 16:16:24 by alboudje         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int	main(void)
{
	ClapTrap	test1("test1");
	ClapTrap	test2("test2");

	test1.attack(test2.getName());
	test2.takeDamage(test1.getAttackDam());
	test2.beRepaired(10);
	test1.attack(test2.getName());
	test2.takeDamage(test1.getAttackDam());
	test2.beRepaired(1);
	test2.beRepaired(1);
	test2.beRepaired(1);
	test2.beRepaired(1);
	test2.beRepaired(1);
	test2.beRepaired(1);
	test2.beRepaired(1);
	test1.attack(test2.getName());
	test2.takeDamage(test1.getAttackDam());
	test2.beRepaired(1);
	test2.beRepaired(1);
	test2.beRepaired(1);
	test2.beRepaired(1);
	test2.beRepaired(1);
	test2.beRepaired(1);
	test1.attack(test2.getName());
	test2.takeDamage(test1.getAttackDam());
	test1.attack(test2.getName());
	test2.takeDamage(test1.getAttackDam());
	test1.attack(test2.getName());
	test2.takeDamage(test1.getAttackDam());
	test1.attack(test2.getName());
	test2.takeDamage(test1.getAttackDam());
	test1.attack(test2.getName());
	test2.takeDamage(test1.getAttackDam());
	test1.attack(test2.getName());
	test2.takeDamage(test1.getAttackDam());
	test1.attack(test2.getName());
	test2.takeDamage(test1.getAttackDam());
	test1.attack(test2.getName());
	test2.takeDamage(test1.getAttackDam());
	test1.attack(test2.getName());
	test2.takeDamage(test1.getAttackDam());	
	return (0);
}