#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>
# include <string.h>

char	*get_next_line(int fd);
char	*ft_strchr(char *s, char input);
size_t	ft_strlen(char *s);
char	*ft_strdup(char *s1, size_t br);
char	*ft_strjoin(char **s1, char *s2, size_t b);

#endif
