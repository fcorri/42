/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcorri <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 16:17:35 by fcorri            #+#    #+#             */
/*   Updated: 2023/03/20 18:32:08 by fcorri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# define BIG_TYPE	long int

int	ft_atoi_decorator(char **p_input, size_t index);
int	ft_digits(BIG_TYPE num, int base);

#endif
