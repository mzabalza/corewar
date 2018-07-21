/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   core_zjmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzabalza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/15 05:25:36 by mzabalza          #+#    #+#             */
/*   Updated: 2018/07/21 19:00:27 by mrodrigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static 	int charge_short(int size, t_arena *arena, int pc_pos)
{
	int 	i;
	char	param[size];

	i = 0;
	while(i < size)
	{
		param[size - 1 - i] = arena->board[(pc_pos + i) % MEM_SIZE].mem;
		i++;
	}
	print_memory(param, size, size, 1);
	exit(1);
	return (*((unsigned short *)param));
}

void	core_zjmp(t_player *player, t_pc *pc, t_arena *arena)
{
	unsigned short index;

	// pc->carry = 1;
	if (pc->carry == 1)
	{
		index = charge_short(2, arena,  (((pc->pc) + 1) % MEM_SIZE));
		pc->pc = ft_mod(pc->pc + (short)index, MEM_SIZE);
	}
	else
		pc->pc = (pc->pc + 1 + 2) % MEM_SIZE;//zjmp + D2
}
