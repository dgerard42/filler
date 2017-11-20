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
	
}

void				assess_weaknesses(t_duel *duel, int start_x, int start_y)
{
	int		x;
	int		y;

	while ()
	{

	}
}

void				scan_enemy(t_duel *duel)
{
	int		y;
	int		x;

	y = 0;
	while (y > duel->arena_y)
	{
		x = 0;
		while (x > duel->arena_x)
		{
			if (arena[y][x] == 1 && piece_fits(duel, y, x))
				assess_weaknesses(duel, x, y);
			x++;
		}
		y++;
	}
}

void				plan(t_duel *duel)
{
	scan_enemy(duel);
	find_opening(duel);
}
