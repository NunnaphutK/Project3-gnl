/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkiticha <nkiticha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 18:14:08 by nkiticha          #+#    #+#             */
/*   Updated: 2024/01/23 18:14:09 by nkiticha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

// ft_strndup
// check leak memory (valgrind --leak-check=full)
// if rd < 1 (NULL) ไม่งั้นจะติดลูปตอนอ่าน main

// nl = NULL;
// str = NULL;
// printf("1= %s--", nl);
// printf("1str= %s--", str);
// printf("2= %c--", nl[1]);
// printf("2str= %s--", result);
// printf("2str= %s", str);
// printf("%s", nl);
// printf("3= %s--", result);

size_t	ft_strlen(const char *s)
{
	size_t	cnt;

	cnt = 0;
	while (s[cnt] != '\0')
		cnt++;
	return (cnt);
}

char	*ft_strjoin(char const *s1, char const *s2)
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
