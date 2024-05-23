#include "Contact.hpp"
#include <iostream>

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

std::string	getInput(std::string field) {
	std::string input = "";

	while (input.empty()) {
		std::cout << "Enter " << field << ": ";
		std::getline(std::cin, input);
		if (input.empty())
			std::cout << "ERROR: " << field << " cannot be empty!\n";
		else
			break;
	};

	return input;
}

Contact* Contact::makeContact() {
	std::string	firstName = "";
	std::string	lastName = "";
	std::string	nickname = "";
	std::string	phoneNumber = "";
	std::string	darkestSecret = "";

	firstName = getInput("first name");
	lastName = getInput("last name");
	nickname = getInput("nickname");
	phoneNumber = getInput("phone number");
	darkestSecret = getInput("darkest secret");
	return new Contact(firstName, lastName, nickname, phoneNumber, darkestSecret);
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