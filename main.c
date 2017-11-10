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

void				check_perceptions(t_duel *duel) //debug function
{
	int x;
	int y;

	y = 0;
	ft_putstr("_______DEBUGGER OUTPUT:_______\n");
	ft_printf("\nWARRIOR = %c, ENEMY = %c\n", duel->warrior, duel->enemy);
	ft_putstr("ARENA:\n");
	ft_printf("ARENA_X = %d, ARENA_Y = %d\n", duel->arena_x, duel->arena_y);
	while (y < duel->arena_y)
	{
		x = 0;
		while (x < duel->arena_x)
		{
			ft_putnbr(duel->arena[y][x]);
			x++;
		}
		y++;
		ft_putchar('\n');
	}
	ft_putstr("WEAPON:\n");
	x = duel->weapon[0];
	y = duel->weapon[1];
	x = (x * y) + 2;
	y = 0;
	while (y < x)
	{
		ft_putnbr(duel->weapon[y]);
		y++;
	}
}

int					read_test_file(void) //for early in development
{
	int fd;

	fd = open("resources/test_outputs/output_1.txt", O_RDONLY);
	return(fd);
}

void				begin(t_duel *duel)
{
	duel->arena = NULL;
	duel->weapon = NULL;
}

int					main(void)
{
	t_duel	duel;
	char	*sight;

	sight = NULL;
	duel.fd = read_test_file();
	begin(&duel); //might be unnessary later, try w/o
	while (get_next_line(duel.fd, &sight) > 0)
	{
		perceive(&duel, sight);
		// plan(&duel);
		// attack(&duel);
	}
	check_perceptions(&duel);
	ft_memdel((void**)&sight); //double check that you have to **& here
	//free other shit from the struct here eventually
	close(duel.fd); //again, rm at end
}
