/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   attack.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgerard <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/15 15:31:02 by dgerard           #+#    #+#             */
/*   Updated: 2018/01/17 21:35:25 by dgerard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int				set_values(t_duel *duel, t_move *move, int anchor_score)
{
	move->ones = 0;
	duel->start_x = move->weapon_x;
	duel->start_y = move->weapon_y;
	if ((anchor_score = check_shape(duel, move)) != 0 &&
		duel->move[2] > anchor_score)
	{
		duel->move[0] = move->map_x - move->weapon_x;
		duel->move[1] = move->map_y - (move->weapon_y - 1);
	}
	return (anchor_score);
}

int				find_opening(t_duel *duel, int map_x, int map_y)
{
	t_move	move;
	int		x;
	int		y;
	int		anchor_score;

	y = 1;
	anchor_score = 0;
	while (y < duel->weapon[0][0])
	{
		x = 0;
		while (x < duel->weapon[0][1])
		{
			if (duel->weapon[y][x] == 1)
			{
				move.weapon_x = x;
				move.weapon_y = y;
				move.map_x = map_x;
				move.map_y = map_y;
				anchor_score = set_values(duel, &move, anchor_score);
			}
			x++;
		}
		y++;
	}
	return (anchor_score);
}

int				check_adj(t_duel *duel, int x, int y)
{
	if (x + 1 < duel->arena_x)
		if (duel->arena[y][x + 1] > -1)
			return (1);
	if (y + 1 < duel->arena_y)
		if (duel->arena[y + 1][x] > -1)
			return (1);
	if (x - 1 > 0)
		if (duel->arena[y][x - 1] > -1)
			return (1);
	if (y - 1 > 0)
		if (duel->arena[y - 1][x] > -1)
			return (1);
	return (0);
}

void			attack(t_duel *duel)
{
	int		y;
	int		x;
	int		anchor_score;

	y = 0;
	duel->move[2] = 2147483647;
	while (y < duel->arena_y)
	{
		x = 0;
		while (x < duel->arena_x)
		{
			if (duel->arena[y][x] == -42 && check_adj(duel, x, y))
				if ((anchor_score = find_opening(duel, x, y)) != 0 &&
						duel->move[2] >= anchor_score)
					duel->move[2] = anchor_score;
			x++;
		}
		y++;
	}
	ft_printf("%d %d\n", duel->move[1], duel->move[0]);
}
