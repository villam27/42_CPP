/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alboudje <alboudje@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 14:52:44 by alboudje          #+#    #+#             */
/*   Updated: 2023/04/10 10:30:53 by alboudje         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::Harl()
{
	std::cout << "Harl: created" << std::endl;
}

Harl::~Harl()
{
	std::cout << "Harl: destroyed" << std::endl;
}

int Harl::getLevel(const std::string level)
{
	std::string levels[4] =
	{
		"DEBUG",
		"INFO",
		"WARNING",
		"ERROR"
	};
	for (int i = 0; i < 4; i++)
		if (levels[i].compare(level) == 0)
			return (i);
	return (DEFAULT);
}

void	Harl::complain(const int level)
{
	void (Harl::*func[4])(void)	=
	{
		&Harl::debug,
		&Harl::info,
		&Harl::warning,
		&Harl::error
	};
	for (int i = 0; i < 4; i++)
		if (i >= level)
		{
			(this->*(func[i]))();
			std::cout << std::endl;
		}
}

void	Harl::complainFilter(const std::string level)
{
	int	levelId;

	levelId = this->getLevel(level);
	switch (levelId)
	{
		case DEBUG:
			this->complain(levelId);
			break;
		case INFO:
			this->complain(levelId);
			break;
		case WARNING:
			this->complain(levelId);
			break;
		case ERROR:
			this->complain(levelId);
			break;
		default:
			std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
			break;
	}
}

void Harl::debug(void)
{
	std::cout << "[ DEBUG ]" << std::endl;
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I really do!" << std::endl;
}

void Harl::info(void)
{
	std::cout << "[ INFO ]" << std::endl;
	std::cout << "I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!" << std::endl;
}

void Harl::warning(void)
{
	std::cout << "[ WARNING ]" << std::endl;
	std::cout << "I think I deserve to have some extra bacon for free. I’ve been coming for years whereas you started working here since last month." << std::endl;
}

void Harl::error(void)
{
	std::cout << "[ ERROR ]" << std::endl;
	std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
}