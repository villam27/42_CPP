/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alboudje <alboudje@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 15:25:02 by alboudje          #+#    #+#             */
/*   Updated: 2023/03/30 10:19:32 by alboudje         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "zombie.hpp"

Zombie::Zombie(const std::string name)
{
	this->_name = name;
	std::cout << _name << ": created" << std::endl;
}

Zombie::~Zombie()
{
	std::cout << _name << ": destroyed" << std::endl;
}

void	Zombie::announce()
{
	std::cout << _name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

void	Zombie::setName(const std::string name)
{
	this->_name = name;
}