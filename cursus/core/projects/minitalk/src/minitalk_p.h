/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk_p.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcorri <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 18:06:13 by fcorri            #+#    #+#             */
/*   Updated: 2023/05/18 17:46:14 by fcorri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_P_H
# define MINITALK_P_H

# define UL	unsigned long

# include <signal.h>
# include <errno.h>
# include "libft/libft.h"
# include "printf/ft_printf.h"

int	ft_error(char *with_message, int argc, char **argv);

#endif
