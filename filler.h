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

typedef struct		s_duel
{
	int		**arena;
	int		arena_x;
	int		arena_y;
	int		*weapon;
	char	warrior;
	char	enemy;
}					t_duel;

void				perceive(t_duel *duel, char *sight);

#endif
