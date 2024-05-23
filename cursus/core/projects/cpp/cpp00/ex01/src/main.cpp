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
	PhoneBook phoneBook;
	std::string cmd;

	while (true)
	{
		std::cout << PROMPT;
		std::getline(std::cin, cmd);
		if (std::cin.eof())
		{
			std::cout << "\n";
			break;
		}
		else if (!cmd.compare("ADD"))
			phoneBook.addContact(Contact::makeContact());
		else if (!cmd.compare("SEARCH"))
		{
			// search for a contact in the phonebook
		}
		else if (!cmd.compare("EXIT"))
			break;
		else
			std::cout << "ERROR: invalid option!\n";
	}
	std::cout << "Goodbye!" << std::endl;
	return (0);
}