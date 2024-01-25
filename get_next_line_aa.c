/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_aa.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkiticha <nkiticha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/23 17:33:02 by nkiticha          #+#    #+#             */
/*   Updated: 2024/01/25 22:08:12 by nkiticha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_test(t_gnl *g, int mode) //ft_free ft_findnl
{
	if (mode == 1)
	{
		free(g->str);
		g->str = NULL;
		return (NULL);
	}
	else
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
	return (NULL);
}

// char	*ft_free(t_gnl *g)
// {
// 	free(g->str);
// 	g->str = NULL;
// 	return (NULL);
// }

char	*ft_nonl(t_gnl *g)
{
	if (g->str == NULL)
		return (NULL);
	g->result = ft_strndup(g->str, ft_strlen(g->str));
	if (!g->result)
		return (ft_test(g, 1));
	ft_test(g, 1);
	return (g->result);
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
		return (NULL);
	}
	while (!g.nl)
	{
		g.rd = read(fd, g.tmp, BUFFER_SIZE);
		if (g.rd < 1)
			break ;
		if (!ft_test(&g, 2))
			return (NULL);
		g.nl = ft_strchr(g.str, '\n');
	}
	free(g.tmp);
	if (g.rd < 0)
		return (ft_test(&g, 1));
	if (!g.nl)
		return (ft_nonl(&g));
	if (g.str != NULL && g.nl[1] != '\0')
	{
		g.result = ft_strndup(g.str, (ft_strlen(g.str) - ft_strlen(g.nl) + 1));
		if (!g.result)
			return (ft_test(&g, 1));
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
	ft_test(&g, 1);
	return (g.result);
}
