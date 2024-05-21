#include "PhoneBook.hpp"

PhoneBook::PhoneBook() {
	_index = 0;
}
PhoneBook::~PhoneBook() {}

void PhoneBook::addContact(Contact &contact)
{
	_contacts[_index++] = contact;
	_index %= 8;
}