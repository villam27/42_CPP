/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alboudje <alboudje@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 15:34:08 by alboudje          #+#    #+#             */
/*   Updated: 2023/03/18 09:53:37 by alboudje         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"

class Phonebook
{
private:
	Contact	contact_list[8];
	size_t	old_contact_id;
	size_t	total_contact;

public:
	Phonebook();

	void	add_contact(const std::string first_name, const std::string last_name,
						const std::string nick_name, const std::string phone_number,
						const std::string darkest_secret);
	void	search_contact(const int contact_id);
	void	show_contact(void);
};

#endif	//PHONEBOOK_HPP