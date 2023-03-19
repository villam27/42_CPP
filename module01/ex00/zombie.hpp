/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alboudje <alboudje@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 15:22:16 by alboudje          #+#    #+#             */
/*   Updated: 2023/03/18 15:46:02 by alboudje         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <string>
#include <iostream>

class Zombie
{
private:
	std::string	_name;

public:
	Zombie(const std::string name);
	Zombie();
	~Zombie();

	void	announce(void);
};

void 	randomChump(std::string name);
Zombie* newZombie(std::string name);

#endif //ZOMBIE_HPP