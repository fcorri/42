/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcorri <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 16:17:15 by fcorri            #+#    #+#             */
/*   Updated: 2023/04/01 19:05:37 by fcorri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

// MACRO
# define BASE_D		10
# define BASE_X		16
# define DIGITS_D	"0123456789"
# define DIGITS_X	"0123456789abcdef"
# define DIGITS_XX	"0123456789ABCDEF"

// HEADERS
# include <stdlib.h>
# include <stdarg.h>
# include <unistd.h>
# include "../libft/libft.h"

// PROTOTYPES
int	ft_printf(const char *format, ...);

#endif
