/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: filippo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 19:19:52 by filippo           #+#    #+#             */
/*   Updated: 2024/03/06 19:32:31 by filippo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

class PhoneBook
{
	private:
		Contact	_contacts[8];

	public:
		PhoneBook
		(
			Contact	_contacts[8]
		);

		Contact	getContacts[8](void) const;

		void	setContacts[8](Contact contacts[8]);
};

#endif
