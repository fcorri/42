#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>
# include <string.h>

char	*get_next_line(int fd);
char	*ft_strjoin(char **s1, char *s2, size_t b);
char	*ft_strdup(char *s1, size_t br);
size_t	ft_strlen(char *s);
char	*ft_strchr(char *s, char input);
void	ft_init(unsigned long *input, char c, unsigned long *one, size_t *output, size_t *zero);

#endif
