/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcorri <fcorri@student.42firenze.it>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 10:15:58 by fcorri            #+#    #+#             */
/*   Updated: 2024/02/05 10:58:32 by fcorri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 42
#endif

char	*ft_calloc(size_t len)
{
	char	*output;

	output = malloc(sizeof(char) * len);
	if (!output)
		return (NULL);
	for (int i=0; i<len; i++)
		output[i] = 0;
	return (output);
}

char	*get_next_line(int fd)
{
	static char	*static_buffer;
	char		*output;
	char		*buffer;
	ssize_t		bytes_read;

	if (fd < 0 || BUFFER_SIZE <= 0 || (!static_buffer && !(static_buffer = ft_calloc(sizeof(char) * BUFFER_SIZE))))
		return (NULL);
	buffer = ft_calloc(sizeof(char) * BUFFER_SIZE);
	if (!buffer)
		return (NULL);
	while ((bytes_read = read(fd, buffer, BUFFER_SIZE)) > 0)
	{
		
	}
}
