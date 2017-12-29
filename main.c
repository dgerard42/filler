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
	ft_printf("\nREWARD FOR MOVE = %d\n", duel->move[2]);
	ft_printf("\nWARRIOR = %c, ENEMY = %c\n", duel->warrior, duel->enemy);
	ft_putstr("ARENA:\n");
	ft_printf("ARENA_X = %d, ARENA_Y = %d\n", duel->arena_x, duel->arena_y);
	while (y < duel->arena_y)
	{
		x = 0;
		while (x < duel->arena_x)
		{
			ft_putnbr(duel->arena[y][x]);
			ft_putchar(',');
			x++;
		}
		y++;
		ft_putchar('\n');
	}
	ft_putstr("WEAPON:\n");
	y = 0;
	while (y < duel->weapon[0][0])
	{
		x = 0;
		while (x < duel->weapon[0][1])
		{
			ft_putnbr(duel->weapon[y][x]);
			x++;
		}
		y++;
		ft_putchar('\n');
	}
}

void				begin(t_duel *duel)
{
	duel->arena = NULL;
	duel->weapon = NULL;
	duel->risk = ft_intarraynew(7);
	duel->move = ft_intarraynew(3);
	// duel->turn = 0;
}

// void				wait_cycle(t_duel *duel, char *sight)
// {
// 	int line_number;
//
// 	line_number = duel->arena_y + (duel->weapon[0][0] - 1) + 5;
// 	while (line_number > 0)
// 	{
// 		get_next_line(duel->fd, &sight);
// 		line_number--;
// 	}
// 	duel->turn = 1;
// }

int					read_test_file(void) //for early in development
{
	int fd;

	fd = open("resources/test_outputs/output_9.txt", O_RDONLY);
	return(fd);
}

int					main(void)
{
	t_duel	duel;
	char	*sight;
	int		weapon_y;

	sight = NULL;
	duel.fd = read_test_file();
	// duel.fd = STDIN_FILENO;
	begin(&duel);
	get_next_line(duel.fd, &sight);
	if (sight[0] == '$' && sight[1] == '$' && sight[2] == '$')
	{
		duel.enemy = (sight[10] == '2') ? 'O' : 'X';
		duel.warrior = (sight[10] == '2') ? 'X' : 'O';
	}
	perceive(&duel, sight);
	ft_memdel((void**)&sight);
	ft_2dfreearray((void**)duel.arena, duel.arena_y); //clear it all out here
	weapon_y = duel.weapon[0][0];
	ft_2dfreearray((void**)duel.weapon, weapon_y);
	ft_memdel((void**)&duel.move);
	ft_memdel((void**)&duel.risk);
	close(duel.fd); //again, rm at end
}
