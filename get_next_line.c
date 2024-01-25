/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkiticha <nkiticha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/23 17:33:02 by nkiticha          #+#    #+#             */
/*   Updated: 2024/01/25 23:16:47 by nkiticha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_mix(t_gnl *g, int mode)
{
	if (mode == 1)
	{
		free(g->str);
		g->str = NULL;
		return (NULL);
	}
	else if (mode == 2)
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
	g->str = NULL;
	g->nl = NULL;
	return (NULL);
}

char	*ft_nonl(t_gnl *g, int part)
{
	if (part == 1)
	{
		if (g->str == NULL)
			return (NULL);
		g->result = ft_strndup(g->str, ft_strlen(g->str));
		if (!g->result)
			return (ft_mix(g, 1));
		ft_mix(g, 1);
		return (g->result);
	}
	else
	{
		g->result = ft_strndup(g->str, ft_strlen(g->str));
		g->nl = NULL;
		ft_mix(g, 1);
	}
	return (NULL);
}

char	*ft_nlstr(t_gnl *g)
{
	g->result = ft_strndup(g->str, (ft_strlen(g->str) - ft_strlen(g->nl) + 1));
	if (!g->result)
		return (ft_mix(g, 1));
	g->keep = ft_strndup((g->nl + 1), ft_strlen(ft_strchr(g->str, '\n') + 1));
	free(g->str);
	g->str = g->keep;
	if (g->str)
		g->nl = ft_strchr(g->str, '\n');
	return (g->result);
}

char	*test(t_gnl *g)
{
	if (g->str)
		free(g->str);
	return (ft_mix(g, 3));
}

char	*get_next_line(int fd)
{
	static t_gnl	g;

	g.tmp = (char *)malloc(BUFFER_SIZE + 1);
	if (!g.tmp)
		return (test(&g));
	while (!g.nl)
	{
		g.rd = read(fd, g.tmp, BUFFER_SIZE);
		if (g.rd < 1)
			break ;
		if (!ft_mix(&g, 2))
			return (NULL);
		g.nl = ft_strchr(g.str, '\n');
	}
	free(g.tmp);
	if (g.rd < 0)
		return (ft_mix(&g, 1));
	if (!g.nl)
		return (ft_nonl(&g, 1));
	if (g.str != NULL && g.nl[1] != '\0')
		return (ft_nlstr(&g));
	if (g.str == NULL)
		return (ft_mix(&g, 3));
	ft_nonl(&g, 2);
	return (g.result);
}
