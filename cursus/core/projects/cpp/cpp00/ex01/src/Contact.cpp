#include "Contact.hpp"

Contact::Contact() {}
Contact::~Contact() {}

Contact::Contact
(
	std::string	firstName,
	std::string	lastName,
	std::string	nickname,
	std::string	phoneNumber,
	std::string	darkestSecret
)
:
_firstName(firstName),
_lastName(lastName),
_nickname(nickname),
_phoneNumber(phoneNumber),
_darkestSecret(darkestSecret)
{
	
}

std::string	Contact::getFirstName(void) const {
	return _firstName;
}

std::string	Contact::getLastName(void) const {
	return _lastName;
}

std::string	Contact::getNickname(void) const {
	return _nickname;
}

std::string	Contact::getPhoneNumber(void) const {
	return _phoneNumber;
}

std::string	Contact::getDarkestSecret(void) const {
	return _darkestSecret;
}