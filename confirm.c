/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   confirm.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgerard <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/18 00:37:15 by dgerard           #+#    #+#             */
/*   Updated: 2018/01/18 00:37:16 by dgerard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int				check_fit(t_duel *duel, t_move *move, int delta_x, int delta_y)
{
	int	check_x;
	int	check_y;

	check_x = move->map_x + delta_x;
	check_y = move->map_y + delta_y;
	if (check_x < 0 || (check_x > duel->arena_x - 1) || check_y < 0 ||
			(check_y > duel->arena_y - 1))
		return (0);
	if (delta_x == 0 && delta_y == 0 && duel->arena[check_y][check_x] == -42)
		return (42);
	else if (duel->arena[check_y][check_x] > -1)
		return (duel->arena[check_y][check_x]);
	else
		return (0);
}

int				anchor_inc_get(t_duel *duel, t_move *move, int anchor_score)
{
	int anchor_inc;

	while (duel->start_x < duel->weapon[0][1] && move->ones < duel->weapon[0][2])
	{
		if (duel->weapon[duel->start_y][duel->start_x] == 1)
		{
			if ((anchor_inc = check_fit(duel, move, duel->start_x -
					move->weapon_x, duel->start_y - move->weapon_y)) != 0)
				anchor_score += anchor_inc;
			else
				return (0);
			move->ones++;
		}
		duel->start_x++;
	}
	return (anchor_score);
}

int				check_shape(t_duel *duel, t_move *move)
{
	int		anchor_score;
	bool	reset;

	anchor_score = 0;
	reset = false;
	while (move->ones < duel->weapon[0][2])
	{
		duel->start_y = (reset == true) ? 1 : duel->start_y;
		while (duel->start_y < duel->weapon[0][0] && move->ones < duel->weapon[0][2])
		{
			duel->start_x = (reset == true) ? 0 : duel->start_x;
			if ((anchor_score = anchor_inc_get(duel, move, anchor_score)) == 0)
				return (0);
			reset = true;
			duel->start_y++;
		}
	}
	return (anchor_score);
}
