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

int main(void)
{
	PhoneBook	phoneBook;

	for (int i = 0; i < 10; i++) {
		Contact *newContact = Contact::makeContact("Random", "Contact", "random", "987654321", "random secret");
		phoneBook.addContact(newContact);
	}
	phoneBook.deleteContacts();
	return (0);
}

