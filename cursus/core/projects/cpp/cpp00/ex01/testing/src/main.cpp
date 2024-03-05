/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcorri <fcorri@student.42firenze.it>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 20:09:59 by fcorri            #+#    #+#             */
/*   Updated: 2024/03/06 00:55:14 by filippo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"
#include <iostream>

int main(void)
{
	Contact me("Filippo", "Corri", "pippi", "3662214272", "SONO FOLLEEEEE!!!");

	std::cout << me.getFirstName();
	me.setFirstName("Gaia");
	std::cout << " -> " << me.getFirstName() << std::endl;

	std::cout << me.getLastName();
	me.setLastName("Strambi");
	std::cout << " -> " << me.getLastName() << std::endl;

	std::cout << me.getNickName();
	me.setNickName("mutti");
	std::cout << " -> " << me.getNickName() << std::endl;

	std::cout << me.getPhoneNumber();
	me.setPhoneNumber("3346006602");
	std::cout << " -> " << me.getPhoneNumber() << std::endl;

	std::cout << me.getDarkestSecret();
	me.setDarkestSecret("IDK");
	std::cout << " -> " << me.getDarkestSecret() << std::endl;

	return (0);
}

