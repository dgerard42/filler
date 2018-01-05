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
// void				assess_weaknesses(t_duel *duel, int start_x, int start_y) //assign the correct number to the map spot
// {
// 	int		x;
// 	int		y;
//
// 	x = start_x;
// 	y = start_y;
// 	while (y < duel->arena_y && duel->risk[0] == 0)
// 		if (duel->arena[y][x] == -1 || duel->arena[y++][x] == -2) //make sure incing here
// 			duel->risk[0] = (duel->arena[y][x] == -2) ? y - start_y + 3 : y - start_y + 1; //+3 to favor recent growth, +1 to make sure that loop is exited
// 	if (duel->risk[0] == 0)
// 		duel->risk[0] = duel->arena_y;
// 	x = start_x;
// 	y = start_y;
// 	while (y >= 0 && duel->risk[4] == 0)
// 		if (duel->arena[y][x] == -1 || duel->arena[y--][x] == -2)
// 			duel->risk[4] = (duel->arena[y][x] == -2) ? start_y - y + 3 : start_y - y + 1;
// 	if (duel->risk[4] == 0)
// 		duel->risk[4] = duel->arena_y;
// 	x = start_x;
// 	y = start_y;
// 	while (x < duel->arena_x && duel->risk[2] == 0)
// 		if (duel->arena[y][x] == -1 || duel->arena[y][x++] == -2)
// 			duel->risk[2] = (duel->arena[y][x] == -2) ? x - start_x + 3 : x - start_x + 1;
// 	if (duel->risk[2] == 0)
// 		duel->risk[2] = duel->arena_x;
// 	x = start_x;
// 	y = start_y;
// 	while (x >= 0 && duel->risk[6] == 0)
// 		if (duel->arena[y][x] == -1 || duel->arena[y][x--] == -2)
// 			duel->risk[6] = (duel->arena[y][x] == -2) ? start_x - x + 3 : start_x - x + 1;
// 	if (duel->risk[6] == 0)
// 		duel->risk[6] = duel->arena_x;
// 	x = start_x;
// 	y = start_y;
// 	while (y < duel->arena_y && x < duel->arena_x && duel->risk[1] == 0)
// 		if (duel->arena[y][x] == -1 || duel->arena[y++][x++] == -2)
// 			duel->risk[1] = (duel->arena[y][x] == -2) ? y - start_y + 3 : y - start_y + 1;
// 	if (duel->risk[1] == 0)
// 		duel->risk[1] = duel->arena_y;
// 	x = start_x;
// 	y = start_y;
// 	while (y >= 0 && x < duel->arena_x && duel->risk[3] == 0)
// 		if (duel->arena[y][x] == -1 || duel->arena[y--][x++] == -2)
// 			duel->risk[3] = (duel->arena[y][x] == -2) ? x - start_x + 3 : x - start_x + 1;
// 	if (duel->risk[3] == 0)
// 		duel->risk[3] = duel->arena_x;
// 	x = start_x;
// 	y = start_y;
// 	while (y >= 0 && x >= 0 && duel->risk[5] == 0)
// 		if (duel->arena[y][x] == -1 || duel->arena[y--][x--] == -2)
// 			duel->risk[5] = (duel->arena[y][x] == -2) ? start_x - x + 3 : start_x - x + 1;
// 	if (duel->risk[5] == 0)
// 		duel->risk[5] = duel->arena_x;
// 	x = start_x;
// 	y = start_y;
// 	while (y < duel->arena_y && x >= 0 && duel->risk[7] == 0)
// 		if (duel->arena[y][x] == -1 || duel->arena[y++][x--] == -2)
// 			duel->risk[7] = (duel->arena[y][x] == -2) ? y - start_y + 3 : y - start_y + 1;
// 	if (duel->risk[7] == 0)
// 		duel->risk[7] = duel->arena_y;
// }


void				score_map_x(t_duel *duel, int x_inc, int y_inc, int risk_index)
{
	int			x;
	int 		y;

	x = duel->start_x;
	y = duel->start_y;
	while (y >= 0 && x >= 0 && y < duel->arena_y && x < duel->arena_x)
	{
		if (duel->arena[y][x] == -1 || duel->arena[y][x] == -2)
			duel->risk[risk_index] = (duel->arena[y][x] == -2) ? y - duel->start_x + 3 : y - duel->start_x + 1;
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
		if (duel->arena[y][x] == -1 || duel->arena[y][x] == -2)
			duel->risk[risk_index] = (duel->arena[y][x] == -2) ? y - duel->start_y + 3 : y - duel->start_y + 1;
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

void				plan(t_duel *duel)// go through the map, and if not colonized by me, re-assess number
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
