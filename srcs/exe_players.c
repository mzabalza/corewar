/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exe_players.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzabalza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/10 18:05:59 by mzabalza          #+#    #+#             */
/*   Updated: 2018/08/17 12:53:01 by mrodrigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static void			exe_pc(t_pc *pc, t_arena *arena, t_data *data)
{
	unsigned char op_nb;

	op_nb = (arena->board[pc->pc % MEM_SIZE].mem) - 1;
	if (pc->wait_cycles > 1)
	{
		pc->wait_cycles--;
		return ;
	}
	else if (pc->wait_cycles == 1)
	{
		pc->wait_cycles--;
//		ft_printf("executing.. %d\n", op_nb);
			// data->func[op_nb](player, pc, arena, data);
			data->func[pc->op](pc, arena, data);
	}
	else
	{
		if (op_nb <= 15)
		{
			pc->wait_cycles = (data->op[op_nb].mana) - 1;
			pc->op = op_nb;
		}
		else
			pc->pc = (pc->pc + 1) % MEM_SIZE;
	}
}

static int			pause_button(t_data *data, t_sdl *Graph, unsigned int pause)
{
	SDL_Surface *button;
	int			rtn;
	int			i;
	char		*pixel;
	int			pitch;

	if (pause)
		button = data->mods->pause_surf[0];
	else
		button = data->mods->pause_surf[1];
	SDL_LockTexture(Graph->info_text, &(SDL_Rect){Graph->square_info->w - button->w - 10, 100, button->w, button->h}, (void **)&pixel, &pitch);
	SDL_LockSurface(button);
	i = -1;
	while (++i < button->h)
		memcpy(pixel + i * pitch, button->pixels + i * button->pitch, button->pitch);
	SDL_UnlockSurface(button);
	SDL_UnlockTexture(Graph->info_text);
	return (pause ? 0 : 0x1);
}

void 				exe_players(t_data *data)
{
	unsigned int k;
	unsigned int t;
	SDL_Event	event;

	data->i = 0;

	fill_r1(data);
//	print_board(data, data->arena->board);
	while(data->cycle_to_die > 0 && data->mods->running)
	{
//		data->mods->pause = 1;
		// write(1, "\x1b[H\x1b[2J", 7);
		// ft_putnbr(data->cycle_to_die);
//		ft_printf("cycle_to_die = %i\n",data->cycle_to_die);
//		if (data->cycle_to_die <= 0)
//			data->mods->running = 0;
		t = 0;
		while (t < data->cycle_to_die && data->mods->running)
		{
			data->mods->step = 0;
			// if (data->cycle_to_die <= 0)
			// 	break;
			// usleep(10);
			while (SDL_PollEvent(&event) && data->mods->visual)
			{
				if (event.type == SDL_QUIT)
					data->mods->running = 0;
				else if (event.type == SDL_KEYDOWN)
				{
					if (event.key.keysym.sym == SDLK_ESCAPE)
						data->mods->running = SDL_FALSE;
					else if (event.key.keysym.sym == SDLK_SPACE)
						data->mods->pause = pause_button(data, data->arena->Graph, data->mods->pause);
					else if (event.key.keysym.sym == SDLK_RIGHT)
						data->mods->step = 1;
					else if (event.key.keysym.sym == SDLK_i)
						data->mods->info = data->mods->info ? 0 : 1;
				}
//				else if (event.type == SDL_KEYUP)
//					if (event.key.keysym.sym == SDLK_RIGHT)
//						data->mods->step = 0;
			}
			// usleep(100);
			if (!data->mods->pause || data->mods->step)
			{
//				j = 0;
//				while(j < data->n_players)
//				{

				k = data->nb_pc;
				while (k)
				{
//					ft_printf("pc live: %u\npc active: %u\ncycle to die: %d\n", data->pc[k - 1].live, data->pc[k - 1].active, data->nb_cycles);
					// exe_pc((data->players) + j, (data->players[j].pc) + k - 1, data->arena, data);
					if (data->pc[k - 1].active)
						exe_pc((data->pc) + k - 1, data->arena, data); //TODO ejecutamos el turno cycle to die
					k--;
				}
//					j++;
//				}
				t++;
				data->nb_cycles++;
			}
			if (data->mods->visual)
			{
				ft_board_to_screen(data->arena->Graph, data->arena->board, data);
				ft_update_info(data->arena->Graph, data, t - 1);
				ft_set_back_to_front(data->arena->Graph, data);
			}
//				 if (data->nb_cycles == 801)
//					 data->mods->pause = 0x1;
				// 	exit(1);
//			}
		}
		check_live_count(data);
	}
	check_winner(data->players, data->n_players);
}
