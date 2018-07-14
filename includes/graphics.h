/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphics.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jagarcia <mrodrigu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/13 05:11:58 by jagarcia          #+#    #+#             */
/*   Updated: 2018/07/14 11:05:18 by jagarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GRAPHICS_H
#define GRAPHICS_H
#define SDL_MAIN_HANDLED
#include "../SDL2_files/SDL2_srcs/include/SDL.h"
#include "../SDL2_files/SDL2_TTF_srcs/SDL_ttf.h"

#define MODE_SDL 1
#define MODE_TTF 0
#define SCREEN_W 674
#define SCREEN_H 286
#define SCREEN_SCALE 1.2
#define SCREEN_NAME "Corewar"
#define LEFT_BORDER 0.357
#define BOTTOM_BORDER 0.033
#define UPPER_BORDER 0.033
#define RIGHT_BORDER 0.0180

typedef struct s_sdl {
	SDL_bool running;
	struct {
		int w;
		int h;
		const char *name;
		SDL_Window *window;
		SDL_Renderer *Renderer;
	} screen;
	TTF_Font *font[1];
	SDL_Rect *square;
} t_sdl;

void		ft_ini_graphics(t_sdl **Graph, int flags);
void		ft_quit_graphics(t_sdl *Graph);
void		ft_SDL_error(char *str, int mode);
void		ft_ini_interface(t_sdl *Graph);
void		ft_ini_board(t_sdl *Graph);
#endif
