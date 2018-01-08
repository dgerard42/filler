/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   attack.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgerard <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/15 15:31:02 by dgerard           #+#    #+#             */
/*   Updated: 2017/11/15 15:31:04 by dgerard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "filler.h"

int				check_fit(t_duel *duel, t_move *move, int delta_x, int delta_y) //check map score or fit for given coords
{
	int	check_x;
	int	check_y;

	check_x = move->map_x + delta_x;
	check_y = move->map_y + delta_y;
	if (check_x < 0 || (check_x > duel->arena_x - 1) || check_y < 0 || (check_y > duel->arena_y - 1))
		return (0);
	if (delta_x == 0 && delta_y == 0 && duel->arena[check_y][check_x] == -42)
		return (42);
	else if (duel->arena[check_y][check_x] > -1)
		return (duel->arena[check_y][check_x]);
	else
		return (0);
}

int				check_shape(t_duel *duel, t_move *move)
{
	int		x;
	int		y;
	int		anchor_score;
	bool	reset;
	int		anchor_inc;

	anchor_score = 0;
	reset = false;
	x = move->weapon_x;
	y = move->weapon_y;
	while (move->ones < duel->weapon[0][2])
	{
		if (reset == true)
			y = 1;
		while (y < duel->weapon[0][0] && move->ones < duel->weapon[0][2])
		{
			if (reset == true)
				x = 0;
			while (x < duel->weapon[0][1] && move->ones < duel->weapon[0][2])
			{
				if (duel->weapon[y][x] == 1)
				{
					if ((anchor_inc = check_fit(duel, move, x - move->weapon_x, y - move->weapon_y)) != 0)
						anchor_score += anchor_inc;
					else
						return (0);
					move->ones++;
				}
				x++;
				reset = true;
			}
			y++;
		}
	}
	return(anchor_score);
}

int					find_opening(t_duel *duel, int map_x, int map_y)
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
				move.ones = 0;
				if ((anchor_score = check_shape(duel, &move)) != 0 && duel->move[2] > anchor_score)
				{
					duel->move[0] = move.map_x - move.weapon_x;
					duel->move[1] = move.map_y - (move.weapon_y - 1);
				}
			}
			x++;
		}
		y++;
	}
	return (anchor_score);
}

int					check_adj(t_duel *duel, int x, int y)
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

void				attack(t_duel *duel)
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
				if ((anchor_score = find_opening(duel, x, y)) != 0 && duel->move[2] >= anchor_score)
					duel->move[2] = anchor_score;
			x++;
		}
		y++;
	}
	ft_printf("%d %d\n", duel->move[1], duel->move[0]);
}
