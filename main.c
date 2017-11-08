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

void				check_perceptions(t_duel *duel)
{
	int x;
	int y;

	x = 0;
	y = 0;
	ft_putstr("_______DEBUGGER OUTPUT:_______\n");
	ft_putstr("WEAPON:\n");
	while ()
}


int					main(void)
{
	t_duel	duel;
	char	*sight;

	while (get_next_line(0, &sight) > 0)
	{
		perceive(&duel, sight);
		check_perceptions(&duel);
		// plan(&duel);
		// attack(&duel);
	}
	ft_memdel((void**)&sight); //double check that you have to **& here
}
