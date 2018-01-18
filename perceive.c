/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   perceive.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgerard <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 17:17:56 by dgerard           #+#    #+#             */
/*   Updated: 2018/01/17 21:25:02 by dgerard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void			watch_enemy(t_duel *duel, char *sight)
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
			else if (sight[x + 4] == duel->warrior || ft_tolower(duel->warrior))
				duel->arena[y][x] = -42;
			x++;
		}
		y++;
		if (y < duel->arena_y)
		{
			ft_memdel((void**)&sight);
			get_next_line(STDIN_FILENO, &sight);
		}
	}
	ft_memdel((void**)&sight);
}

void			observe_arena(t_duel *duel, char *sight)
{
	char	*sight_tmp;

	sight_tmp = sight;
	while (!(ft_isdigit(*sight)))
		sight++;
	duel->arena_y = ft_atoi(sight);
	while (ft_isdigit(*sight))
		sight++;
	sight++;
	duel->arena_x = ft_atoi(sight);
	duel->arena = ft_2dintarray(duel->arena_y, duel->arena_x);
	ft_memdel((void**)&sight_tmp);
}

void			learn_weap_coords(t_duel *duel, char *sight, t_move *move)
{
	char	*sight_tmp;

	sight_tmp = sight;
	while (!(ft_isdigit(*sight_tmp)))
		sight_tmp++;
	move->weapon_y = ft_atoi(sight_tmp);
	while (ft_isdigit(*sight_tmp))
		sight_tmp++;
	sight_tmp++;
	move->weapon_x = ft_atoi(sight_tmp);
	move->weapon_x = ft_atoi(sight_tmp);
	duel->weapon = ft_2dintarray(move->weapon_y + 1, move->weapon_x);
	duel->weapon[0][0] = move->weapon_y + 1;
	duel->weapon[0][1] = move->weapon_x;
	ft_memdel((void**)&sight);
}

void			learn_weapon(t_duel *duel, char *sight)
{
	t_move	move;
	int		pieces;
	char	*sight_tmp;

	pieces = 0;
	learn_weap_coords(duel, sight, &move);
	move.weapon_y = 1;
	while (move.weapon_y < duel->weapon[0][0])
	{
		move.weapon_x = 0;
		get_next_line(STDIN_FILENO, &sight);
		sight_tmp = sight;
		while (move.weapon_x < duel->weapon[0][1])
		{
			duel->weapon[move.weapon_y][move.weapon_x] =
				(*sight_tmp == '*') ? 1 : 0;
			pieces = (duel->weapon[move.weapon_y][move.weapon_x] == 1) ?
				pieces + 1 : pieces;
			move.weapon_x++;
			sight_tmp++;
		}
		move.weapon_y++;
		ft_memdel((void**)&sight);
	}
	duel->weapon[0][2] = pieces;
}

void			perceive(t_duel *duel, char *sight)
{
	int		weapon_y;

	while (get_next_line(STDIN_FILENO, &sight) > 0)
	{
		if (ft_strstr(sight, "Plateau") && duel->arena == NULL)
			observe_arena(duel, sight);
		else if (ft_strstr(sight, "000"))
			watch_enemy(duel, sight);
		else if (ft_strstr(sight, "Piece"))
		{
			learn_weapon(duel, sight);
			plan(duel);
			attack(duel);
			weapon_y = duel->weapon[0][0];
			ft_2dfreearray((void**)duel->weapon, weapon_y);
		}
		else
			ft_memdel((void**)&sight);
	}
}
