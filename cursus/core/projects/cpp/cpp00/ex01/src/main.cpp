/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: filippo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 19:17:32 by filippo           #+#    #+#             */
/*   Updated: 2024/03/06 19:18:50 by filippo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include <iostream>

#define PROMPT "Please type one of the following options: ADD, SEARCH, EXIT: "

int main()
{
	PhoneBook	phoneBook;
	std::string cmd;

	for (int i = 0; i < 10; i++) {
		Contact *newContact = Contact::makeContact("Random", "Contact", "random", "987654321", "random secret");
		phoneBook.addContact(newContact);
	}
	phoneBook.deleteContacts();
	return (0);

	do
	{
		std::cout << PROMPT;
		std::getline(std::cin, cmd);
		if (cmd.compare("ADD"))
		{
			// create contact and add it to the phonebook, if input is valid
		}
		else if (cmd.compare("SEARCH"))
		{
			// search for a contact in the phonebook
		}
		else
			std::cout << "ERROR: invalid option!";
	} while (cmd.compare("EXIT"));
	
	return (0);
}