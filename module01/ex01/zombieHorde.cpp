/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alboudje <alboudje@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 15:43:47 by alboudje          #+#    #+#             */
/*   Updated: 2023/03/18 15:51:43 by alboudje         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "zombie.hpp"

Zombie*	zombieHorde(int N, std::string name)
{
	Zombie	*zombies = new Zombie[N];
	if (!zombies)
		return (NULL);
	for (int i = 0; i < N; i++)
		zombies[i].setName(name);
	return (zombies);
}