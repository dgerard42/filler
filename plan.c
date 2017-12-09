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

int				check_fit(t_duel *duel, t_move *move, int delta_x, int delta_y)
{
	int	check_x;
	int	check_y;

	check_x = move->map_x + delta_x;
	check_y = move->map_y + delta_y;
	if (duel->arena[check_y][check_x] > -1)
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
					if (anchor_inc = check_fit(duel, move, move->weapon_x - x, move->weapon_y - y) != 0)
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

int					anchor_weapon(t_duel *duel, int map_x, int map_y)
{
	t_move	*move;
	int		x;
	int		y;
	int		anchor_score;

	y = 1;
	while (y < duel->weapon[0][0])
	{
		x = 0;
		while (x < duel->weapon[0][1])
		{
			if (duel->weapon[y][x] == 1)
			{
				move->weapon_x = x;
				move->weapon_y = y;
				move->map_x = map_x;
				move->map_y = map_y;
				move->ones = 0;
				if ((anchor_score = check_shape(duel, move)) != 0)
					return (anchor_score);
			}
			x++;
		}
		y++;
	}
	return (0);
	//the way this function is written will not test multiple possible configutations
	//of the same piece on the same anchor
}

void				find_opening(t_duel *duel)
{
	int		y;
	int		x;
	int		anchor_score;

	y = 0;
	while (y > duel->arena_y)
	{
		x = 0;
		while (x > duel->arena_x)
		{
			if (duel->arena[y][x] == -42 && (duel->arena[y][x + 1] > -1 ||
					duel->arena[y][x - 1] > -1 || duel->arena[y - 1][x] > -1 ||
						duel->arena[y + 1][x] > -1))
				if ((anchor_score = anchor_weapon(duel, x, y)) != 0 && duel->move[2] > anchor_score)
					duel->move[2] = anchor_score;
			x++;
		}
		y++;
	}
}

//VVVV compress this shit. Eventually. VVVVV
void				assess_weaknesses(t_duel *duel, int start_x, int start_y) //assign the correct number to the map spot
{
	int		x;
	int		y;

	x = start_x;
	y = start_y;
	while (y < duel->arena_y && duel->risk[0] == 0)
		if (duel->arena[y][x] == -1 || duel->arena[y++][x] == -2) //make sure incing here
			duel->risk[0] = (duel->arena[y][x] == -2) ? y - start_y + 3 : y - start_y + 1; //+3 to favor recent growth, +1 to make sure that loop is exited
	if (duel->risk[0] == 0)
		duel->risk[0] = duel->arena_y;
	x = start_x;
	y = start_y;
	while (y < duel->arena_y && duel->risk[4] == 0)
		if (duel->arena[y][x] == -1 || duel->arena[y--][x] == -2)
			duel->risk[4] = (duel->arena[y][x] == -2) ? start_y - y + 3 : start_y - y + 1;
	if (duel->risk[4] == 0)
		duel->risk[4] = duel->arena_y;
	x = start_x;
	y = start_y;
	while (x < duel->arena_x && duel->risk[2] == 0)
		if (duel->arena[y][x] == -1 || duel->arena[y][x++] == -2)
			duel->risk[2] = (duel->arena[y][x] == -2) ? x - start_x + 3 : x - start_x + 1;
	if (duel->risk[2] == 0)
		duel->risk[2] = duel->arena_x;
	x = start_x;
	y = start_y;
	while (x < duel->arena_x && duel->risk[6] == 0)
		if (duel->arena[y][x] == -1 || duel->arena[y][x--] == -2)
			duel->risk[6] = (duel->arena[y][x] == -2) ? start_x - x + 3 : start_x - x + 1;
	if (duel->risk[6] == 0)
		duel->risk[6] = duel->arena_x;
	x = start_x;
	y = start_y;
	while (y < duel->arena_y && x < duel->arena_x && duel->risk[1] == 0)
		if (duel->arena[y][x] == -1 || duel->arena[y++][x++] == -2)
			duel->risk[1] = (duel->arena[y][x] == -2) ? y - start_y + 3 : y - start_y + 1;
	if (duel->risk[1] == 0)
		duel->risk[1] = duel->arena_y;
	x = start_x;
	y = start_y;
	while (y < duel->arena_y && x < duel->arena_x && duel->risk[3] == 0)
		if (duel->arena[y][x] == -1 || duel->arena[y--][x++] == -2)
			duel->risk[3] = (duel->arena[y][x] == -2) ? x - start_x + 3 : x - start_x + 1;
	if (duel->risk[3] == 0)
		duel->risk[3] = duel->arena_x;
	x = start_x;
	y = start_y;
	while (y < duel->arena_y && x < duel->arena_x && duel->risk[5] == 0)
		if (duel->arena[y][x] == -1 || duel->arena[y--][x--] == -2)
			duel->risk[5] = (duel->arena[y][x] == -2) ? start_x - x + 3 : start_x - x + 1;
	if (duel->risk[5] == 0)
		duel->risk[5] = duel->arena_x;
	x = start_x;
	y = start_y;
	while (y < duel->arena_y && x < duel->arena_x && duel->risk[7] == 0)
		if (duel->arena[y][x] == -1 || duel->arena[y++][x--] == -2)
			duel->risk[7] = (duel->arena[y][x] == -2) ? y - start_y + 3 : y - start_y + 1;
	if (duel->risk[7] == 0)
		duel->risk[7] = duel->arena_y;
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
			if (duel->arena[y][x] > -1)
			{
				i = 0;
				while (i < 8)
					duel->risk[i++] = 0;
				i = 0;
				assess_weaknesses(duel, x, y);
				while (i < 8)
					duel->arena[y][x] += duel->risk[i++];
			}
			x++;
		}
		y++;
	}
}

void				plan(t_duel *duel)
{
	//malloc here for risk
	//malloc for move
	scan_enemy(duel);
	find_opening(duel); //look for the lowest number where you can place a piece and save coords for attack in move int array
}
