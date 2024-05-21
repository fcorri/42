#include "Contact.hpp"

Contact::Contact() {}
Contact::~Contact() {}

Contact::Contact
(
	std::string	firstName,
	std::string	lastName,
	std::string	nickName,
	std::string	phoneNumber,
	std::string	darkestSecret
)
:
_firstName(firstName),
_lastName(lastName),
_nickName(nickName),
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

std::string	Contact::getNickName(void) const {
	return _nickName;
}

std::string	Contact::getPhoneNumber(void) const {
	return _phoneNumber;
}

std::string	Contact::getDarkestSecret(void) const {
	return _darkestSecret;
}