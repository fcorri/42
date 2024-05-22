#include "PhoneBook.hpp"

PhoneBook::PhoneBook() : _index(0) {
	// ask oracle if pointers are initialized NULL
	for (size_t i = 0; i < LEN ; i++)
		_contacts[i] = NULL;
}
PhoneBook::~PhoneBook() {}

void PhoneBook::addContact(Contact *contact)
{
	if (!contact)
		return ;
	if (_contacts[_index])
		delete _contacts[_index];
	_contacts[_index] = contact;
	_index = (_index + 1) % LEN;
}

void PhoneBook::deleteContacts() {
	for (size_t i = 0; i < LEN ; i++)
		delete _contacts[i];
}