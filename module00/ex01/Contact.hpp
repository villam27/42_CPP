/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alboudje <alboudje@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 16:08:28 by alboudje          #+#    #+#             */
/*   Updated: 2023/03/18 09:56:32 by alboudje         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <string>

class Contact
{
private:
	std::string	first_name;
	std::string	last_name;
	std::string	nick_name;
	std::string	phone_number;
	std::string	darkest_secret;

public:
	Contact() {};
	Contact(const std::string first_name, const std::string last_name,
			const std::string nick_name, const std::string phone_number,
			const std::string darkest_secret);

	const std::string	get_first_name(size_t size = 0);
	const std::string	get_last_name(size_t size = 0);
	const std::string	get_nick_name(size_t size = 0);
	const std::string	get_phone_number(void);
	const std::string	get_darkest_secret(void);
};

#endif	//CONTACT_HPP