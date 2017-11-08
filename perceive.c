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

void				observe_arena(t_duel *duel, char *sight)
{

}

void				learn_weapon(t_duel *duel, char *sight)
{
	if (duel->weapon != NULL)

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
	else if (ft_strstr(sight, "Piece"))
		learn_weapon(duel, sight);
	else if (ft_strstr(sight, "Plateau"))
		observe_arena(duel, sight);
}
