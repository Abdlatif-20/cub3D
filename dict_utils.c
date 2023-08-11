/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dict_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-yous <mel-yous@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 18:15:50 by mel-yous          #+#    #+#             */
/*   Updated: 2023/08/07 18:15:55 by mel-yous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char	*get_key_value(char *str, short option, t_garbage **heap)
{
	int		i;
	char	*sub;

	i = 0;
	while (str[i] && str[i] != ' ')
		i++;
	if (option == 0)
	{
		sub = ft_substr(str, 0, i);
		return (add_to_garbage(heap, sub), sub);
	}
	else
	{
		while (str[i] && str[i] == ' ')
			i++;
		sub = ft_substr(str, i, ft_strlen(str));
		return (add_to_garbage(heap, sub), sub);
	}
}