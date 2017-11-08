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

int					main(void)
{
	t_duel	duel;
	char	*sight;

	while (get_next_line(0, &sight) > 0)
	{
		perceive(&duel, sight);
		// plan(&duel);
		// attack(&duel);
	}
	ft_memdel((void*)sight);
}
