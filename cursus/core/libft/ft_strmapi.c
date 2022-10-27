#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*output;
	unsigned int	index;
	char			c;

	output = malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (!output)
		return (NULL);
	index = 0;
	c = s[index];
	while (c)
	{
		output[index] = f(index, c);
		c = s[++index];
	}
	output[index] = '\0';
	return (output);
}
