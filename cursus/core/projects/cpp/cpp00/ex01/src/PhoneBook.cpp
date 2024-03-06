#include "PhoneBook.hpp"

PhoneBook::PhoneBook
(
	Contact	contacts[8]
)
:
_contacts[8](contacts[8])
{
	
}

Contact	PhoneBook::getContacts[8](void) const {
	return _contacts[8];
}

void	PhoneBook::setContacts[8](Contact contacts[8]) {
	_contacts[8] = contacts[8];
}

