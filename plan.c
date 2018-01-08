/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plan.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgerard <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 20:40:20 by dgerard           #+#    #+#             */
/*   Updated: 2017/11/09 20:40:22 by dgerard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "filler.h"

void				score_map_x(t_duel *duel, int x_inc, int y_inc, int risk_index)
{
	int			x;
	int 		y;

	x = duel->start_x;
	y = duel->start_y;
	while (y >= 0 && x >= 0 && y < duel->arena_y && x < duel->arena_x)
	{
		if (duel->arena[y][x] == -2)
			duel->risk[risk_index] = x - duel->start_x + 1;
		else if (duel->arena[y][x] == -42)
			duel->risk[risk_index] = duel->arena_x * 2;
		if (duel->arena[y][x] < 0)
			break;
		y += y_inc;
		x += x_inc;
	}
	if (duel->risk[risk_index] == 0)
		duel->risk[risk_index] = duel->arena_x;
}

void				score_map_y(t_duel *duel, int x_inc, int y_inc, int risk_index)
{
	int			x;
	int 		y;

	x = duel->start_x;
	y = duel->start_y;
	while (y >= 0 && x >= 0 && y < duel->arena_y && x < duel->arena_x)
	{
		if (duel->arena[y][x] == -2)
			duel->risk[risk_index] = y - duel->start_y + 1;
		else if (duel->arena[y][x] == -42)
			duel->risk[risk_index] = duel->arena_y * 2;
		if (duel->arena[y][x] < 0)
			break;
		y += y_inc;
		x += x_inc;
	}
	if (duel->risk[risk_index] == 0)
		duel->risk[risk_index] = duel->arena_y;
}

void				assess_weaknesses(t_duel *duel)
{
	score_map_y(duel, 0 , 1, 0);
	score_map_x(duel, 1 , 0, 2);
	score_map_y(duel, 0 , -1, 4);
	score_map_x(duel, -1 , 0, 6);
	score_map_x(duel, 1 , 1, 1);
	score_map_y(duel, -1 , -1, 5);
	score_map_y(duel, -1 , 1, 7);
	score_map_x(duel, 1 , -1, 3);
}

void				plan(t_duel *duel)
{
	int		y;
	int		x;
	int		i;

	y = 0;
	while (y < duel->arena_y)
	{
		x = 0;
		while (x < duel->arena_x)
		{
			if (duel->arena[y][x] > -1)
			{
				i = 0;
				while (i < 8)
					duel->risk[i++] = 0;
				i = 0;
				duel->start_x = x;
				duel->start_y = y;
				assess_weaknesses(duel);
				while (i < 8)
					duel->arena[y][x] += duel->risk[i++];
			}
			x++;
		}
		y++;
	}
}
