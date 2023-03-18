/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alboudje <alboudje@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 17:01:51 by alboudje          #+#    #+#             */
/*   Updated: 2023/03/18 11:00:10 by alboudje         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Phonebook.hpp"
#include <iostream>
#include <iomanip>

Phonebook::Phonebook()
{
	this->old_contact_id = 0;
	this->total_contact = 0;
}

void	Phonebook::add_contact(const std::string first_name, const std::string last_name,
							const std::string nick_name, const std::string phone_number,
							const std::string darkest_secret)
{
	if (this->total_contact < 8)
	{
		this->contact_list[this->total_contact] = Contact(first_name, last_name,
														nick_name, phone_number,
														darkest_secret);
		this->total_contact++;
	}
	else
	{
		this->contact_list[this->old_contact_id] = Contact(first_name, last_name,
													nick_name, phone_number,
													darkest_secret);	
		if (this->old_contact_id == 7)
			this->old_contact_id = 0;
		else
			this->old_contact_id++;
	}
}

void	Phonebook::search_contact(const int contact_id)
{
	if (contact_id < 0 || contact_id >= static_cast<int>(this->total_contact))
	{
		std::cerr << "Not a valid id" << std::endl;
		return ;
	}
	std::cout << "First Name: " << this->contact_list[contact_id].get_first_name() << std::endl;
	std::cout << "Last Name: " << this->contact_list[contact_id].get_last_name() << std::endl;
	std::cout << "Nick Name: " << this->contact_list[contact_id].get_nick_name() << std::endl;
	std::cout << "Phone number: " << this->contact_list[contact_id].get_phone_number() << std::endl;
	std::cout << "Darkest secret: " << this->contact_list[contact_id].get_darkest_secret() << std::endl;
}

void	Phonebook::show_contact(void)
{
	std::cout << "|  index   |  first   |   last   |   nick   |" << std::endl;
	for (size_t i = 0; i < this->total_contact; i++)
	{
		std::cout << '|';
		std::cout << std::setw(10) << i << '|';
		std::cout << std::setw(10) << this->contact_list[i].get_first_name(10) << '|';
		std::cout << std::setw(10) << this->contact_list[i].get_last_name(10) << '|';
		std::cout << std::setw(10) << this->contact_list[i].get_nick_name(10) << '|';
		std::cout << std::endl;
	}
}