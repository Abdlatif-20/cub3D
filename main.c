/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-nei <aben-nei@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 14:46:12 by aben-nei          #+#    #+#             */
/*   Updated: 2023/08/01 17:46:00 by aben-nei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	main(int ac, char **av)
{
	char	**map;

	map = NULL;
	map = (char **)malloc(lenght_of_map(av[1]) * sizeof(char *));
	if (!map)
		return (0);
	if (ac == 2)
	{
		check_name_of_map(av[1], ".cub");
		fill_map(av[1], map);
		check_map_is_valid(map);
	for(int i = 0;map[i]; i++)
		printf("%s\n", map[i]);
	}
	else
		printf("Wrong Argument\n");
	return (0);
}