/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_test.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbaudet <hbaudet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 13:44:55 by hbaudet           #+#    #+#             */
/*   Updated: 2019/10/30 09:47:38 by hbaudet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "get_next_line_bonus.h"
#include "get_next_line.h"


int	main(int ac, char *av[])		//test bonus
{
	char	bis[] = "this is a string";
	char	*line;
	int		fd[ac + 1];
	int		i;
	int		j;
	int		gnl;
	char	**ptr;

	j = 1;
	i = 1;
	if (!(line = malloc(sizeof(char) * 18)))
		return (-1);
	ptr = &line;
	line = ft_strncpy_gnl(line, bis, 17);
	if (ac == 1)
	{
		while ((gnl = (get_next_line(0, ptr))) == 1)
			printf("%s%d\n", line, gnl);
		printf("%s%d", line, gnl);
	}
	else if (ac == 2)
	{
		if (!(fd[i] = open(av[i], O_RDONLY)))
			return (-1);
		while ((gnl = (get_next_line(fd[i], ptr))) == 1)
			printf("%d%s\n", gnl, line);
		printf("%d%s", gnl, line);
	}
	else
	{
		while (i < ac)
		{
			if (!(fd[i] = open(av[i], O_RDONLY)))
				return (-1);
			i++;
		}
		while (j < 5)
		{
			printf("line %d of all files :\n", j);
			i = 1;
			while (i < ac)
			{
				gnl = get_next_line(fd[i], &line);
				printf("%d%s\n", gnl, line);
				i++;
			}
			printf("\n\n");
			j++;
		}
		i = 1;
		while (i < ac)
		{
			printf("End of %s\n", av[i]);
			while ((gnl = (get_next_line(fd[i], ptr))))
				printf("%d%s\n", gnl, line);
			printf("%d%s", gnl, line);
			close(fd[i]);
			i++;
			printf("-------------\n\n");
		}
		free(line);
	}
	return (0);
}
