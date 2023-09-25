/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-nei <aben-nei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/16 18:22:48 by mel-yous          #+#    #+#             */
/*   Updated: 2023/09/25 18:42:49 by aben-nei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static void	move_rotate(t_data *data)
{
	if (data->flags->move_up)
		move_up(data);
	if (data->flags->move_down)
		move_down(data);
	if (data->flags->move_left)
		move_left(data);
	if (data->flags->move_right)
		move_right(data);
	if (data->flags->rotate_left)
		rotate_left(data);
	if (data->flags->rotate_right)
		rotate_right(data);
}

static void	move_player_helper(t_data *data)
{
	t_flags	*flags;

	flags = data->flags;
	clear_window_draw(data);
	if (data->player->weapon == SNIPER)
		sniper_mode(data);
	else if (data->player->weapon == KNIFE)
		knife_animation(data);
	else if (data->player->weapon == PISTOL)
	{
		mlx_put_image_to_window(data->mlx->mlx_ptr,
			data->mlx->win_ptr, data->bullet_icon, 0, 0);
		pistol_animation(data);
	}
	flags->redraw_scene = false;
	flags->switch_weapon = false;
	flags->reload_pistol = false;
}

int	move_player(t_data *data)
{
	t_flags	*flags;
	int		i;

	flags = data->flags;
	move_rotate(data);
	if (data->player->hit_wall && !data->player->already_hit)
	{
		play_sound("./sound/wallhit.wav");
		data->player->already_hit = true;
	}
	if (flags->redraw_scene || flags->knife_shoot
		|| flags->pistol_shoot || flags->switch_weapon || flags->reload_pistol)
		move_player_helper(data);
	if (data->door->door_distance > 40
		&& !data->doors[data->index_door].open_door)
	{
		i = -1;
		while (++i < data->num_door)
			data->doors[i].open_door = 1;
	}
	return (0);
}
