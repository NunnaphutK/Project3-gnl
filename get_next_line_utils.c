/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkiticha <nkiticha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 18:14:08 by nkiticha          #+#    #+#             */
/*   Updated: 2024/01/25 14:42:29 by nkiticha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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
		return (ft_strndup(s2, ft_strlen(s2)));
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

char	*ft_strndup(const char *s1, int n)
{
	size_t		i;
	size_t		nn;
	char		*dest;

	nn = (size_t)n;
	i = 0;
	dest = (char *)malloc(sizeof(char) * (nn + 1));
	if (dest == NULL)
		return (NULL);
	while (i < nn)
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
