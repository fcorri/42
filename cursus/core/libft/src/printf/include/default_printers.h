/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   default_printers.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcorri <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 16:17:09 by fcorri            #+#    #+#             */
/*   Updated: 2023/03/19 19:46:24 by fcorri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEFAULT_PRINTERS_H
# define DEFAULT_PRINTERS_H

# include "../ft_printf.h"

// ABSTRACT DEFAULT PRINTER

typedef struct default_printer
{
	t_printer	base;
	void		(*ft_init_string_len)(void);
	void		(*ft_build_string_right)(void);
	char		*sub;
	size_t		sub_len;
}	t_default_printer;

typedef struct hex_printer
{
	t_default_printer	default_base;
	char				ch;
}	t_hex_printer;

void	ft_new_default_printer(char *sub, size_t sub_len);

// ABSTRACT EXTENDING DEFAULT PRINTER

void	ft_new_default_num_printer(char *sub, size_t sub_len,
			void (*ft_num_build_string_right)(void));

// VARIOUS CONCRETE PRINTERS

void	ft_new_char_printer(char c);
void	ft_new_string_printer(char *s);
void	ft_new_pointer_printer(uintptr_t a);
void	ft_new_decimal_integer_printer(int di);
void	ft_new_unsigned_printer(unsigned int u);
void	ft_new_hex_printer(unsigned int x, char ch, char *base);
void	ft_new_min_hex_printer(unsigned int x);
void	ft_new_max_hex_printer(unsigned int x);
void	ft_new_percentage_printer(char c);

#endif
