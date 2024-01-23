/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkiticha <nkiticha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/23 17:33:02 by nkiticha          #+#    #+#             */
/*   Updated: 2024/01/23 22:05:11 by nkiticha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"


#include <stdio.h>
#include <string.h>

char	*get_next_line(int fd)
{
	char			*result;
	char			*tmp;
	char			*strnew;
	static char		*str;
	char			*keep;
	int				rd;
	static char		*nl;

	tmp = malloc(BUFFER_SIZE + 1);
	if (!tmp)
		return (0);
	while (!nl)
	{
		rd = read(fd, tmp, BUFFER_SIZE);
		if (rd < 1)
			break ;
		tmp[rd] = '\0';
		strnew = ft_strjoin(str, tmp);
		if (!strnew)
		{
			free(tmp);
			free(str);
			str = NULL;
			return (NULL);
		}
		free(str);
		str = strnew;
		nl = ft_strchr(str, '\n');
	}
	free(tmp);
	if (rd < 0)
	{
		free(str);
		str = NULL;
		return (NULL);
	}
	if (!nl)
	{
		if (str == NULL)
			return (NULL);
		result = ft_strndup(str, ft_strlen(str));
		if (!result)
		{
			free(str);
			str = NULL;
			return (NULL);
		}
		free(str);
		str = NULL;
		return (result);
	}
	if (nl[1] != '\0')
	{
		result = ft_strndup(str, (ft_strlen(str) - ft_strlen(nl) + 1));
		if (!result)
		{
			free(str);
			str = NULL;
			return (NULL);
		}
		keep = ft_strndup((nl + 1), ft_strlen(ft_strchr(str, '\n') + 1));
		free(str);
		str = keep;
		nl = NULL;
		nl = ft_strchr(str, '\n');
		return (result);
	}
	result = ft_strndup(str, ft_strlen(str));
	nl = NULL;
	if (str == NULL)
		return (NULL);
	free(str);
	str = NULL;
	return (result);
}