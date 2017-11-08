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
	while (!(ft_strstr(sight, "000")))
		get_next_line(duel, &sight);
	while (y < duel->arena_y)
	{
		x = 4;
		while (x < duel->arena_x)
		{
			if (sight[x] == '.')
				duel->arena[y][x] = 0;
			else if (sight[x] == duel->enemy)
				duel->arena[y][x] = -1;
			else if (sight[x] == ft_tolower(duel->enemy))
				duel->arena[y][x] = -2;
			else if (sight[x] == duel->warrior || ft_tolower(duel->warrior))
				duel->arena[y][x] = 1;
			//make these elifs more or less detailed depending on what your algorithim eventually needs
			x++;
		}
		y++;
		get_next_line(duel, &sight);
	}
}

void				observe_arena(t_duel *duel, char *sight)
{
	while (!(ft_isdigit(*sight++])))
	duel->arena_x = ft_atoi(*sight);
	while (ft_isdigit(*sight) || *sight++ == ' '))
	//do you need to make both ++ here, or only one?
	duel->arena_y = ft_atoi(*sight);
	duel->arena = ft_2dintarraynew(duel->arena_y, duel->arena_x);
	//make sure x & ys arent reversed
	//you might have to reset the pointer at the end of this?
	//maybe have a pseudo null termintor number, or use zero for that purpose?
}

void				learn_weapon(t_duel *duel, char *sight)
{
	int	weapon_x;
	int	weapon_y;
	int	i;

	i = 2;
	if (duel->weapon != NULL)
		ft_memdel((void**)&sight);
	while (!(ft_isdigit(*sight++)))
	weapon_y = ft_atoi(*sight);
	while (ft_isdigit(*sight) || *sight++ == ' '))
	//do you need to make both ++ here, or only one?
	weapon_x = ft_atoi(*sight);
	//again, ya might have to reset sight here
	duel->weapon = ft_intarraynew((weapon_x * weapon_y) + 2);
	duel->weapon[0] = weapon_y;
	duel->weapon[1]  = weapon_x;
	while (weapon_y > 0)
	{
		get_next_line(0, &sight);
		while (*sight != '\0')
			duel->weapon[i++] = (*sight == '*') ? 1 : 0;
			//check i here for off by one
		weapon_y--;
	}
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
 	if (duel->enemy != 'O' && duel->enemy != 'X' && ft_strstr(sight, "p1"))
		acquire_target(duel, sight);
	else if (duel->arena != NULL && ft_strstr(sight, "Plateau"))
		watch_enemy(duel, sight);
	else if (duel->arena == NULL && ft_strstr(sight, "Plateau"))
		observe_arena(duel, sight);
	else if (ft_strstr(sight, "Piece"))
		learn_weapon(duel, sight);
}
