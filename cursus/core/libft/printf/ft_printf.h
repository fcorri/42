/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcorri <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 16:17:15 by fcorri            #+#    #+#             */
/*   Updated: 2023/03/22 15:40:14 by fcorri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

// MACRO
# define BASE_D			10
# define BASE_X			16
# define DIGITS_D		"0123456789"
# define DIGITS_X	"0123456789abcdef"
# define DIGITS_XX	"0123456789ABCDEF"

// LIBC HEADERS
# include <stdlib.h>
# include <stdarg.h>
# include <unistd.h>

// OTHER HEADERS
# include "../libft.h"
# include "include/printer.h"
# include "include/default_printers.h"
# include "include/specification.h"
# include "include/utils.h"

// UNIONS
typedef union abstract_printer
{
	t_printer			as_base;
	t_default_printer	as_default_printer;
	t_hex_printer		as_hex_printer;
}	t_default_abstract_printer;

// GLOBAL VARIABLES
extern t_default_abstract_printer		*g_printer;
extern t_printing_specification			*g_specification;
extern va_list							g_ap;

// PROTOTYPES
int	ft_printf(const char *format, ...);

#endif
