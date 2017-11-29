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

void				piece_fits(t_duel *duel, int start_x, int start_y)
{
	int	x;
	int	y;

	int *anchor;
	while (y )
}

void				traverse_weapon(t_duel *duel, int start_x, int start_y)
{
	int		x;
	int		y;

	y = 1;
	while (y < duel->weapon[0][0])
	{
		x = 0;
		while (x < duel->weapon[0][1])
		{
			if (duel->weapon[y][x] == 1)
			x++;
		}
		y++;
	}
}

void				find_opening()
{

}

void				assess_weaknesses(t_duel *duel, int start_x, int start_y) //assign the correct number to the map spot
{
	//inc y up x same
	//inc y down x same
	//inc x up y same
	//inc x down y same
	//inc x up y up
	//inc x down y down
	//inc x up y down
	//inc x down y up
	int		x;
	int		y;

	x = start_x;
	y = start_y;
	while (y < duel->arena_y && duel->risk[0] == 0)
		if (duel->arena[y][x] == -1 || duel->arena[y++][x] == -2) //make sure incing here
			duel->risk[0] = (duel->arena[y][x] == -2) ? y - start_y + 3 : y - start_y + 1; //+3 to favor recent growth, +1 to make sure that loop is exited
	x = start_x;
	y = start_y;
	while (y < duel->arena_y && duel->risk[4] == 0)
		if (duel->arena[y][x] == -1 || duel->arena[y--][x] == -2)
			duel->risk[4] = (duel->arena[y][x] == -2) ? start_y - y + 3 : start_y - y + 1;
	x = start_x;
	y = start_y;
	while (x < duel->arena_x && duel->risk[2] == 0)
		if (duel->arena[y][x] == -1 || duel->arena[y][x++] == -2)
			duel->risk[2] = (duel->arena[y][x] == -2) ? x - start_x + 3 : x - start_x + 1;
	x = start_x;
	y = start_y;
	while (x < duel->arena_x && duel->risk[6] == 0)
		if (duel->arena[y][x] == -1 || duel->arena[y][x--] == -2)
			duel->risk[6] = (duel->arena[y][x] == -2) ? start_x - x + 3 : start_x - x + 1;
	x = start_x;
	y = start_y;
	while (y < duel->arena_y && x < duel->arena_x && duel->risk[1] == 0)
		if (duel->arena[y][x] == -1 || duel->arena[y++][x++] == -2)
			duel->risk[1] = (duel->arena[y][x] == -2) ? y - start_y + 3 : y - start_y + 1;
	x = start_x;
	y = start_y;
	while (y < duel->arena_y && x < duel->arena_x && duel->risk[3] == 0)
		if (duel->arena[y][x] == -1 || duel->arena[y--][x++] == -2)
			duel->risk[3] = (duel->arena[y][x] == -2) ? x - start_x + 3 : x - start_x + 1;
	x = start_x;
	y = start_y;
	while (y < duel->arena_y && x < duel->arena_x && duel->risk[5] == 0)
		if (duel->arena[y][x] == -1 || duel->arena[y--][x--] == -2)
			duel->risk[5] = (duel->arena[y][x] == -2) ? start_x - x + 3 : start_x - x + 1;
	x = start_x;
	y = start_y;
	while (y < duel->arena_y && x < duel->arena_x && duel->risk[7] == 0)
		if (duel->arena[y][x] == -1 || duel->arena[y++][x--] == -2)
			duel->risk[7] = (duel->arena[y][x] == -2) ? y - start_y + 3 : y - start_y + 1;
}

void				scan_enemy(t_duel *duel)// go through the map, and if not colonized by me, re-assess number
{
	int		y;
	int		x;
	int		i;

	y = 0;
	while (y > duel->arena_y)
	{
		x = 0;
		while (x > duel->arena_x)
		{
			if (arena[y][x] > -1)
			{
				//reinitialize here for risk
				i = 0;
				assess_weaknesses(duel, x, y);
				while (i < 8)
				{
					risk[i] =
				}
			}
			x++;
		}
		y++;
	}
}

void				plan(t_duel *duel)
{
	//malloc here for risk
	scan_enemy(duel);
	find_opening(duel); //look for the lowest number where you can place a piece and save coords for attack in move int array
}
