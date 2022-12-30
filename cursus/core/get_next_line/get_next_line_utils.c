#include "get_next_line.h"

void	ft_init(unsigned long *input, char c, unsigned long *one)
{
	unsigned long	word;

	word = c | (c << 8);
	word |= (word << 16);
	if (sizeof(unsigned long) > 4)
		word |= ((word << 16) << 16);
	*input = word;
	word = 0x01010101L;
	if (sizeof(unsigned long) > 4)
		word |= ((word << 16) << 16);
	*one = word;
}

void	ft_checkword(char *src, unsigned long input, unsigned long one, char **output)
{
		unsigned long	word;

        word = (*(unsigned long *)src) ^ input;
        word = ((word - one) & ~word) & (one << 7); 
        if (word != 0)
        {
            *output = src;
            while (**output != (char) input)
                (*output)++;
        }
}

char	*ft_strdup(char *s, size_t len)
{
	char	*output;
	size_t	index;

	output = malloc(len + 1);
	if (!output)
		return (NULL);
	index = -1;
	while (++index < len)
		output[index] = s[index];
	output[index] = '\0';
	return (output);
}

char	*ft_strjoin(char **s1, char *s2, size_t br)
{
	char	*output;
	size_t	len1;
	size_t	index;

	if (!*s1)
		output = ft_strdup(s2, br);
	else
	{
		len1 = ft_strchr(*s1, '\0') - *s1;
		output = malloc(len1 + br + 1);
		if (!output)
			return (NULL);
		index = -1;
		while (++index < len1)
			output[index] = (*s1)[index];
		index = -1;
		while (++index < br)
			output[len1 + index] = s2[index];
		output[len1 + index] = '\0';
		free(*s1);
	}
	*s1 = output;
	return (output);
}
