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
	// ft_printf("MALLOC 0\n");//label every malloc
	duel->risk = ft_intarraynew(7);
	// ft_printf("MALLOC 1\n");//label every malloc
	duel->move = ft_intarraynew(3);
}

int					read_test_file(t_duel *duel) //for early in development
{
	int fd;

	// fd = open("resources/test_outputs/output_5.txt", O_RDONLY);
	fd = STDIN_FILENO;
	duel->log_file = open("log_files/log_0.txt", O_CREAT | O_WRONLY | O_TRUNC);
	dprintf(duel->log_file, "LOG FILE WORKS 42\n");
	dprintf(duel->log_file, ".      OOOOOOOOOOOOOOOO     \n    OO..***.......***.....OO         .   +\n    OO.....***********........OO\n  OO......**********...........OO        +      .    .\n OO.........****...*............OO\n  O............**.................O      +    .\n O...........*******.............O                +\n  O..........*********............O\n OO.........********............OO        .     .\n  OO.........*****.............OO    +               +\n   OO........***.............OO               +\n +   OO.......**...........OO      .\n   .     OOOOOOOOOOOOOOOO                             +\n");
	return(fd);
}

int					main(void)
{
	t_duel	duel;
	char	*sight;
	// int		weapon_y;

	sight = NULL;
	duel.fd = read_test_file(&duel);
	begin(&duel);
	// ft_printf("MALLOC 2\n");//label every malloc
	get_next_line(duel.fd, &sight);
	if (sight[0] == '$' && sight[1] == '$' && sight[2] == '$')
	{
		duel.enemy = (sight[10] == '2') ? 'O' : 'X';
		duel.warrior = (sight[10] == '2') ? 'X' : 'O';
	}
	dprintf(duel.log_file, "uve read the enemy and warrior\n");
	ft_memdel((void**)&sight); //added in during gnl memory management fix push
	perceive(&duel, sight);
	ft_2dfreearray((void**)duel.arena, duel.arena_y);
	ft_memdel((void**)&duel.move);
	ft_memdel((void**)&duel.risk);
	close(duel.fd); //again, rm at end
}
