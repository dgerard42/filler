/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgerard <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 17:15:41 by dgerard           #+#    #+#             */
/*   Updated: 2017/11/07 17:15:44 by dgerard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "filler.h"

void				begin(t_duel *duel)
{
	duel->arena = NULL;
	duel->weapon = NULL;
	duel->risk = ft_intarraynew(7);
	duel->move = ft_intarraynew(3);
}

int					main(void)
{
	t_duel	duel;
	char	*sight;

	sight = NULL;
	begin(&duel);
	get_next_line(STDIN_FILENO, &sight);
	if (sight[0] == '$' && sight[1] == '$' && sight[2] == '$')
	{
		duel.enemy = (sight[10] == '2') ? 'O' : 'X';
		duel.warrior = (sight[10] == '2') ? 'X' : 'O';
	}
	ft_memdel((void**)&sight);
	perceive(&duel, sight);
	ft_2dfreearray((void**)duel.arena, duel.arena_y);
	ft_memdel((void**)&duel.move);
	ft_memdel((void**)&duel.risk);
	close(STDIN_FILENO);
}
