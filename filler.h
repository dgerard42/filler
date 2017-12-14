/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgerard <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 17:17:37 by dgerard           #+#    #+#             */
/*   Updated: 2017/11/07 17:17:38 by dgerard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H

# include "libft/libft.h"
# include "printf/ft_printf.h"
# include <fcntl.h> //rm in the final version, using for open

typedef struct		s_duel
{
	int		**arena;
	int		arena_x;
	int		arena_y;
	int		**weapon;
	char	warrior;
	char	enemy;
	int		*move; //3 ints, x, y, and score
	int		*risk; //initialize at -1 for all numbers b/c 0 can be valid value, 7 ints
	int		fd;		//rm in the final version
	int		turn; //use this to determine turn? 0 = not mine 1 = mine 2 = FIN
}					t_duel;

typedef	struct		s_move
{
	int		map_x;
	int		map_y;
	int		weapon_x;
	int		weapon_y;
	int		ones;
}					t_move;

void				perceive(t_duel *duel, char *sight);
void				plan(t_duel *duel);
void				attack(t_duel *duel);

#endif
