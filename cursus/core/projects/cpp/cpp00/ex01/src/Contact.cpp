/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcorri <fcorri@student.42firenze.it>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 19:02:33 by fcorri            #+#    #+#             */
/*   Updated: 2024/03/05 18:06:42 by fcorri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "copyOfContact.hpp"
#include <iostream>

Contact::Contact
	(
		std::string firstName,
		std::string lastName,
		std::string nickName,
		std::string phoneNumber,
		std::string darkestSecret
	)
	:
	_firstName(firstName),
	_lastName(lastName),
	_nickName(nickName),
	_phoneNumber(phoneNumber),
	_darkestSecret(darkestSecret)
	{
		std::cout << _firstName + " " + _lastName + " " + _nickName + " " + _phoneNumber + " " + _darkestSecret << std::endl;
	}
