#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <string.h>

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

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	len;
	char	*ss;

	if (s1 == NULL)
		return (ft_strdup(s2));
	len = ft_strlen(s1) + ft_strlen(s2) + 1;
	ss = (char *)malloc(sizeof(char) * len);
	if (ss == NULL)
		return (NULL);
	
	ft_strlcpy(ss, s1, len);
	ft_strlcat(ss, s2, len);
	return (ss);
}

char	*ft_strjoin2(char const *s1, char const *s2)
{
	size_t	len;
	char	*ss;
	char	*ss_ptr;

	if (s1 == NULL)
		return (ft_strdup(s2));
	len = ft_strlen(s1) + ft_strlen(s2) + 1;
	ss = (char *)malloc(sizeof(char) * len);
	if (ss == NULL)
		return (NULL);
	ss_ptr = ss;
	while (*s1)
	    *ss++ = *s1++;
	while (*s2)
	    *ss++ = *s2++;
	*ss = '\0';
	return (ss_ptr);
}

int main(void)
{
    printf("\nTest de ft_strjoin\n");
    printf("====================\n");
	printf("abcdef : %s\n",	ft_strjoin2("abc", "def"));
	printf("abc : %s\n", ft_strjoin2("", "abc"));
	printf("abc : %s\n", ft_strjoin2("abc", ""));
	printf("'' : %s\n", ft_strjoin2("", ""));
}