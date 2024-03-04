/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcorri <fcorri@student.42firenze.it>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 13:01:36 by fcorri            #+#    #+#             */
/*   Updated: 2024/03/04 16:55:11 by fcorri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int	main(int argc, char **argv)
{
	if (argc == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	else
		for (int i = 1; i < argc; i++)
		{
			int j = 0;
			for (char c=argv[i][j]; c; c=argv[i][++j])
				std::cout << (char) std::toupper(c);
		}
	std::cout << std::endl;
	return 0;
}
