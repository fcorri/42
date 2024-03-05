#include "Contact.hpp"

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

	void	Contact::setFirstName(std::string firstName) {
		_firstName = firstName;
	}

	void	Contact::setLastName(std::string lastName) {
		_lastName = lastName;
	}

	void	Contact::setNickName(std::string nickName) {
		_nickName = nickName;
	}

	void	Contact::setPhoneNumber(std::string phoneNumber) {
		_phoneNumber = phoneNumber;
	}

	void	Contact::setDarkestSecret(std::string darkestSecret) {
		_darkestSecret = darkestSecret;
	}

