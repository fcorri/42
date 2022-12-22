#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>
# include <string.h>

char	*get_next_line(int fd, size_t buffer_size);
char	*ft_strjoin(char **s1, char *s2);
char	*ft_strdup(char *s1);

#endif
