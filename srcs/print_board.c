/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_board.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrodrigu <mrodrigu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/09 23:21:36 by mrodrigu          #+#    #+#             */
/*   Updated: 2018/07/14 01:59:26 by mrodrigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static void	print_player_status(t_player *players, t_data *data)
{
	int i;
	int ply_nb;

	// ft_putnbr(data->n_players);
	// exit(1);
	i = 0;
	while(i < data->n_players)
	{
		ply_nb = players[i].player_nb;
		if (ply_nb < 0)
			invert_bytes(&ply_nb, sizeof(int));
		ft_putstr(data->palete[(int)players[i].id + 1]);
		ft_printf("Player nb: %d, name:%s, lives: %d, last live %d\n"
			, ply_nb, players[i].name, players[i].live_counter, players[i].last_live);
		print_memory(&(players[i].player_nb), 4, 4, 1);
		ft_putchar('\n');
		ft_putstr("\033[0m ");
		i++;
	}
}

static void	print_pcs(t_player *players, const unsigned int nb_players, size_t i, int j)
{
	unsigned int 	k;
	unsigned int 	t;

	k = 0;
	while (k < nb_players)
	{
		t = 0;
		while (t < players[k].nb_pc)
		{
			if (players[k].pc[t].pc == (i + j))
				ft_putstr("\033[48;5;2m");
			t++;
		}
		k++;
	}
}

void		print_board(t_data *data, t_board *board)
{
	size_t			i;
	int 			j;
	char 			*hexa;

	hexa = "0123456789abcdef";
	i = 0;
	while (i < MEM_SIZE)
	{
		j = 0;
		while (j < 64)
		{
			ft_putstr(data->palete[(int)board[i + j].id]);
			print_pcs(data->players, data->n_players, i, j);
			ft_putchar(hexa[board[i + j].mem / 16]); //%16?
			ft_putchar(hexa[board[i + j].mem % 16]);
			ft_putstr("\033[0m ");
			j++;
		}
		ft_putchar('\n');
		i += 64;
	}

	ft_putstr("\n\nNumber of cycles: ");
	ft_putnbr(data->nb_cycles);
	ft_putchar('\n');
	print_player_status(data->players, data);
}
