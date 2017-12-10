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
	if (duel->arena[check_y][check_x] > -1)
		return (duel->arena[check_y][check_x]);
	else
		return (0);
}

int				check_shape(t_duel *duel, t_move *move) //cycle through the rest of the piece and check fit & score
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
					if ((anchor_inc = check_fit(duel, move, move->weapon_x - x, move->weapon_y - y)) != 0)
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

int					find_opening(t_duel *duel, int map_x, int map_y) //cycle through 1s in the weapon as potential anchors to the map spots
{
	t_move	move;
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
				move.weapon_x = x;
				move.weapon_y = y;
				move.map_x = map_x;
				move.map_y = map_y;
				move.ones = 0;
				if ((anchor_score = check_shape(duel, &move)) != 0)
				{
					duel->move[0] = move.map_x - move.weapon_x;
					duel->move[1] = move.map_y - move.weapon_y;
					return (anchor_score);
				}
			}
			x++;
		}
		y++;
	}
	return (0);
	//the way this function is written will not test multiple possible alignements
	//of the same piece on the same anchor
}

void				attack(t_duel *duel) //find an open spot on the edge of my colonized space
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
				if ((anchor_score = find_opening(duel, x, y)) != 0 && duel->move[2] > anchor_score)
					duel->move[2] = anchor_score;
			x++;
		}
		y++;
	}
	ft_printf("[%d, %d]\n", duel->move[1], duel->move[0]);
}
