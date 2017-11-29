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
	while (y < duel->arena_y && duel->risk[0] == -1)
		if (duel->arena[y][x] == -1 || duel->arena[y++][x] == -2) //make sure this incs correctly
			duel->risk[0] = (duel->arena[y][x] == -2) ? y - start_y + 2 : y - start_y; //+2 to favor recent growth
	x = start_x;
	y = start_y;
	while (y < duel->arena_y && duel->risk[4] == -1)
		if (duel->arena[y][x] == -1 || duel->arena[y--][x] == -2)
			duel->risk[0] = (duel->arena[y][x] == -2) ? start_y - y + 2 : start_y - y;
	x = start_x;
	y = start_y;
	while (x < duel->arena_x && duel->risk[2] == -1)
		if (duel->arena[y][x] == -1 || duel->arena[y++][x] == -2) //make sure this incs correctly
			duel->risk[0] = (duel->arena[y][x] == -2) ? y - start_y + 2 : y - start_y; //+2 to favor recent growth

}

void				scan_enemy(t_duel *duel)// go through the map, and if not colonized by me, re-assess number
{
	int		y;
	int		x;

	y = 0;
	while (y > duel->arena_y)
	{
		x = 0;
		while (x > duel->arena_x)
		{
			if (arena[y][x] > -1)
				assess_weaknesses(duel, x, y);
			x++;
		}
		y++;
	}
}

void				plan(t_duel *duel)
{
	scan_enemy(duel);
	find_opening(duel); //look for the lowest number where you can place a piece and save coords for attack in move int array
}
