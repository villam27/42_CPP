/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alboudje <alboudje@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 16:18:06 by alboudje          #+#    #+#             */
/*   Updated: 2023/03/18 09:56:47 by alboudje         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact(const std::string first_name, const std::string last_name,
				const std::string nick_name, const std::string phone_number,
				const std::string darkest_secret)
{
	this->first_name = first_name;
	this->last_name = last_name;
	this->nick_name = nick_name;
	this->phone_number = phone_number;
	this->darkest_secret = darkest_secret;
}

const std::string	Contact::get_first_name(size_t size)
{
	std::string	result;

	if (size >= this->first_name.size() || size == 0)
		return (this->first_name);
	else
	{
		for (size_t i = 0; i < 9; i++)
			result.push_back(this->first_name.at(i));
		result.push_back('.');
	}
	return (result);
}

const std::string	Contact::get_last_name(size_t size)
{
	std::string	result;

	if (size >= this->last_name.size() || size == 0)
		return (this->last_name);
	else
	{
		for (size_t i = 0; i < 9; i++)
			result.push_back(this->last_name.at(i));
		result.push_back('.');
	}
	return (result);
}

const std::string	Contact::get_nick_name(size_t size)
{
	std::string	result;

	if (size >= this->nick_name.size() || size == 0)
		return (this->nick_name);
	else
	{
		for (size_t i = 0; i < 9; i++)
			result.push_back(this->nick_name.at(i));
		result.push_back('.');
	}
	return (result);
}

const std::string	Contact::get_phone_number(void)
{
	return (this->phone_number);	
}

const std::string	Contact::get_darkest_secret(void)
{
	return (this->darkest_secret);	
}
