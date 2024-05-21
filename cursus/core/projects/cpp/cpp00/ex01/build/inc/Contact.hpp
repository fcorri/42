/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: filippo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 22:09:41 by filippo           #+#    #+#             */
/*   Updated: 2024/03/05 22:33:53 by filippo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <string>

const class Contact
{
private:
	const std::string _firstName;
	const std::string _lastName;
	const std::string _nickName;
	const std::string _phoneNumber;
	const std::string _darkestSecret;

public:
	Contact
	(
		std::string	_firstName,
		std::string	_lastName,
		std::string	_nickName,
		std::string	_phoneNumber,
		std::string	_darkestSecret
	);

	std::string getFirstName() const;
	std::string getLastName() const;
	std::string getNickName() const;
	std::string getPhoneNumber() const;
	std::string getDarkestSecret() const;
};

#endif
