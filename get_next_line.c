/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkiticha <nkiticha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/23 17:33:02 by nkiticha          #+#    #+#             */
/*   Updated: 2024/01/22 21:22:09 by nkiticha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <string.h>
# define BUFFER_SIZE 5

size_t	ft_strlen(const char *s)
{
	size_t	cnt;

	cnt = 0;
	while (s[cnt] != '\0')
		cnt++;
	return (cnt);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	len;

	i = 0;
	len = ft_strlen(src);
	if (dstsize == 0)
		return (len);
	if (!dst && !src)
		return (0);
	while (i < dstsize - 1 && src[i] != '\0' && dstsize != 0)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (len);
}

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	len_d;
	size_t	len_s;

	i = 0;
	len_s = ft_strlen(src);
	if (dstsize == 0)
		return (len_s);
	len_d = ft_strlen(dst);
	if (len_d < dstsize)
		len_s += len_d;
	else
		len_s += dstsize;
	while ((i + len_d) < dstsize - 1 && src[i] != '\0')
	{
		dst[i + len_d] = src[i];
		i++;
	}
	dst[i + len_d] = '\0';
	return (len_s);
}
char	*ft_strdup(const char *s1)
{
	size_t		i;
	size_t		len;
	char		*dest;

	i = 0;
	len = ft_strlen(s1);
	dest = (char *)malloc(sizeof(char) * (len + 1));
	if (dest == NULL)
		return (NULL);
	while (i < len)
	{
		dest[i] = s1[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
char	*ft_strchr(const char *s, int c)
{
	size_t		i;
	char		cc;
	char		*ss;

	i = 0;
	cc = (char)c;
	ss = (char *)s;
	while (ss[i] != '\0')
	{
		if (ss[i] == cc)
			return (&ss[i]);
		i++;
	}
	if (ss[i] == cc)
		return (&ss[i]);
	return (NULL);
}
char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	len;
	char	*ss;

	if (s1 == NULL)
		return (ft_strdup(s2));
	if (s2 == NULL)
		return ((char *)s1);
	len = ft_strlen(s1) + ft_strlen(s2) + 1;
	ss = (char *)malloc(sizeof(char) * len);
	if (ss == NULL)
		return (NULL);
	ft_strlcpy(ss, s1, len);
	ft_strlcat(ss, s2, len);
	return (ss);
}

char	*get_next_line(int fd)
{
	char		*result;
	char		*tmp;
	static char		*str;
	char	*keep;
	int			rd;
	static char		*nl;

	// nl = NULL;
	// str = NULL;
	tmp = malloc(BUFFER_SIZE + 1);
	while (!nl)
	{
		if (!tmp)
			return (0);
		rd = read(fd, tmp, BUFFER_SIZE);
		if (rd < 1)
			return (NULL); // leakkkkkkk
		tmp[rd] = '\0';
		str = ft_strjoin(str, tmp);
		// 6789067890abcde
		nl = ft_strchr(str, '\n');
	}
	free(tmp);
	if (!nl)
	{
		result = ft_strdup(str);
		return (result);
	}
	// printf("1= %s--", nl);
	// printf("1str= %s--", str);
	if (nl[1] != '\0')
	{
		// printf("2= %c--", nl[1]);
		result = strndup(str, (ft_strlen(str) - ft_strlen(nl) + 1));
		// printf("2str= %s--", result);
		keep = strdup(nl + 1);
		free(str);
		str = keep;
		// printf("2str= %s", str);
		nl = NULL;
		nl = ft_strchr(str, '\n');
		// printf("%s", nl);
		return (result);
	}
	result = ft_strdup(str);
	free(str);
	// printf("3= %s--", result);
	nl = NULL;
	return (result);
}

int	main(void)
{
	int		fd;
	int		rd;
	char	*str;

	fd = open("testtxt.txt", O_RDONLY);
	printf("==================\n");
	while ((str = get_next_line(fd)))
	{
		printf("%s", str);
		free(str);
	}
	close(fd);
}