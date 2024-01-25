/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkiticha <nkiticha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/23 17:33:02 by nkiticha          #+#    #+#             */
/*   Updated: 2024/01/25 21:21:43 by nkiticha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*test(t_gnl *g)
{
	g->tmp[g->rd] = '\0';
	g->strnew = ft_strjoin(g->str, g->tmp);
	if (!g->strnew)
	{
		free(g->tmp);
		free(g->str);
		g->str = NULL;
		return (NULL);
	}
	free(g->str);
	g->str = g->strnew;
	return (g->str);
}

char	*ft_free(t_gnl *g)
{
	free(g->str);
	g->str = NULL;
	return (NULL);
}

char	*get_next_line(int fd)
{
	static t_gnl	g;

	g.tmp = (char *)malloc(BUFFER_SIZE + 1);
	if (!g.tmp)
	{
		if (g.str)
			free(g.str);
		g.str = NULL;
		g.nl = NULL;
		return (0);
	}
	while (!g.nl)
	{
		g.rd = read(fd, g.tmp, BUFFER_SIZE);
		if (g.rd < 1)
			break ;
		if (!test(&g))
			return (NULL);
		g.nl = ft_strchr(g.str, '\n');
	}
	free(g.tmp);
	if (g.rd < 0)
		return (ft_free(&g));
	if (!g.nl)
	{
		if (g.str == NULL)
			return (NULL);
		g.result = ft_strndup(g.str, ft_strlen(g.str));
		if (!g.result)
			ft_free(&g);
		free(g.str);
		g.str = NULL;
		return (g.result);
	}
	if (g.str != NULL && g.nl[1] != '\0')
	{
		g.result = ft_strndup(g.str, (ft_strlen(g.str) - ft_strlen(g.nl) + 1));
		if (!g.result)
		{
			free(g.str);
			g.str = NULL;
			return (NULL);
		}
		g.keep = ft_strndup((g.nl + 1), ft_strlen(ft_strchr(g.str, '\n') + 1));
		free(g.str);
		g.str = g.keep;
		if (g.str)
			g.nl = ft_strchr(g.str, '\n');
		return (g.result);
	}
	if (g.str == NULL)
	{
		g.nl = NULL;
		return (NULL);
	}
	g.result = ft_strndup(g.str, ft_strlen(g.str));
	g.nl = NULL;
	free(g.str);
	g.str = NULL;
	return (g.result);
}
