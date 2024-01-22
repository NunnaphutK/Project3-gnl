#ifndef GET_NEXT_LINE_H
# define BUFFER_SIZE 5

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>

char	*get_next_line(int fd);
char	*ft_strdup(const char *s1);
char	*ft_strchr(const char *s, int c);
char	*ft_strjoin(char const *s1, char const *s2);
size_t	ft_strlen(const char *s);

#endif
