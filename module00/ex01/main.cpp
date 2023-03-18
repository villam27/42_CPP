/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alboudje <alboudje@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 16:00:11 by alboudje          #+#    #+#             */
/*   Updated: 2023/03/18 10:13:19 by alboudje         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <stdlib.h>
#include "Phonebook.hpp"

std::string	get_data(std::string display)
{
	std::string	line;

	while (line.empty())
	{
		std::cout << display << ": ";
		std::cin >> line;
		if (std::cin.eof())
			std::exit(EXIT_SUCCESS);
	}
	return (line);
}

void	new_contact(Phonebook &phonebook)
{
	std::string	contact_data[5];

	contact_data[0] = get_data("First name");
	contact_data[1] = get_data("Last name");
	contact_data[2] = get_data("Nick name");
	contact_data[3] = get_data("Phone number");
	contact_data[4] = get_data("Darkest secret");
	std::cout << contact_data[2] << " ADDED TO THE PHONEBOOK" << std::endl;
	phonebook.add_contact(contact_data[0], contact_data[1], contact_data[2],
						contact_data[3], contact_data[4]);
}

void	search_contact(Phonebook phonebook)
{
	std::string	id;
	int			idn;

	phonebook.show_contact();
	std::cout << "Please enter an id:";
	std::cin >> id;
	if (std::cin.eof())
		std::exit(EXIT_SUCCESS);
	idn = std::atoi(id.c_str());
	phonebook.search_contact(idn);
}

int	main(void)
{
	Phonebook	phonebook;
	std::string	line;

	while (1)
	{
		std::cin >> line;
		if (std::cin.eof())
			break ;
		if (line == "ADD")
			new_contact(phonebook);
		else if (line == "SEARCH")
			search_contact(phonebook);
		else if (line == "EXIT")
			break ;
	}
	return (EXIT_SUCCESS);	
}