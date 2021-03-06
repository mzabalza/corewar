/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   realloc_pc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzabalza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/17 12:37:40 by mzabalza          #+#    #+#             */
/*   Updated: 2018/08/07 17:26:15 by mrodrigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

t_pc	*realloc_pc(t_pc *pc, const unsigned int nb_pc)
{
	t_pc *new_pc;

	if (!(new_pc = (t_pc *)malloc(sizeof(t_pc) * (nb_pc + 20))))
		ft_error("malloc failed");
	//habria que inicializar todo a zero mejor no?
	//new_pc[0] = {0};
	//mejor eso o ft_memset()
	ft_memcpy(new_pc, pc, sizeof(t_pc) * nb_pc);
	free(pc);
	return (new_pc);
}
