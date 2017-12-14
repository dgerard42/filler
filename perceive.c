/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   perceive.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgerard <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 17:17:56 by dgerard           #+#    #+#             */
/*   Updated: 2017/11/07 17:17:58 by dgerard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "filler.h"

void				watch_enemy(t_duel *duel, char *sight)
{
	int x;
	int	y;

	y = 0;
	while (y < duel->arena_y)
	{
		x = 0;
		while (x < duel->arena_x)
		{
			if (sight[x + 4] == '.')
				duel->arena[y][x] = 0;
			else if (sight[x + 4] == duel->enemy)
				duel->arena[y][x] = -2;
			else if (sight[x + 4] == ft_tolower(duel->enemy))
				duel->arena[y][x] = -1;
			else if (sight[x + 4] == duel->warrior || ft_tolower(duel->warrior))
				duel->arena[y][x] = -42;
			//make these elifs more or less detailed depending on what your algorithim eventually needs
			x++;
		}
		y++;
		if (y < duel->arena_y)
			get_next_line(duel->fd, &sight);
	}
}

void				observe_arena(t_duel *duel, char *sight)
{
	while (!(ft_isdigit(*sight)))
		sight++;
	duel->arena_y = ft_atoi(sight);
	while (ft_isdigit(*sight))
		sight++;
	sight++;
	//do you need to make both ++ here, or only one?
	duel->arena_x = ft_atoi(sight);
	duel->arena = ft_2dintarray(duel->arena_y, duel->arena_x);
	//make sure x & ys arent reversed
	//you might have to reset the pointer at the end of this?
	//maybe have a pseudo null termintor number, or use zero for that purpose?
}

void				learn_weapon(t_duel *duel, char *sight)
{
	int	weapon_x;
	int	weapon_y;
	int	pieces;

	pieces = 0;
	if (duel->weapon != NULL)
		ft_memdel((void**)&duel->weapon);
	while (!(ft_isdigit(*sight)))
		sight++;
	weapon_y = ft_atoi(sight);
	while (ft_isdigit(*sight))
		sight++;
	sight++;
	weapon_x = ft_atoi(sight);
	duel->weapon = ft_2dintarray(weapon_y + 1, weapon_x);
	duel->weapon[0][0] = weapon_y + 1;
	duel->weapon[0][1] = weapon_x;
	weapon_y = 1;
	while (weapon_y < duel->weapon[0][0])
	{
		weapon_x = 0;
		get_next_line(duel->fd, &sight);
		while (weapon_x < duel->weapon[0][1])
		{
			duel->weapon[weapon_y][weapon_x] = (*sight == '*') ? 1 : 0;
			pieces = (duel->weapon[weapon_y][weapon_x] == 1) ? pieces + 1 : pieces;
			weapon_x++;
			sight++;
			//compact here when working
		}
		weapon_y++;
	}
	duel->weapon[0][2] = pieces;
}

void				acquire_target(t_duel *duel, char *sight)
{
	if (!(ft_strstr(sight, "dgerard.filler")))
	{
		duel->enemy = 'O';
		duel->warrior = 'X';
	}
	else
	{
		duel->enemy = 'X';
		duel->warrior = 'O';
	}
}

void				perceive(t_duel *duel, char *sight)
{
	bool keep_looking;

	keep_looking = true;
	while (get_next_line(duel->fd, &sight) > 0 && keep_looking == true)
	{
		if (duel->enemy != 'O' && duel->enemy != 'X' && ft_strstr(sight, "p1"))
		{
			acquire_target(duel, sight);
			if (duel->warrior == 'O')
				duel->turn = 1;
		}
		else if (ft_strstr(sight, "Piece"))
		{
			learn_weapon(duel, sight);
			keep_looking = false;
		}
		else if (duel->arena == NULL && ft_strstr(sight, "Plateau"))
			observe_arena(duel, sight);
		else if (ft_strstr(sight, "000") && duel->turn == 1)
			watch_enemy(duel, sight);
		else if (ft_strstr(sight, "fin"))
			duel->turn = 2;
	}
}
