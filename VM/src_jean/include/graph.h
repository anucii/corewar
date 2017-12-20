/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graph.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgonthie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/13 14:42:51 by jgonthie          #+#    #+#             */
/*   Updated: 2017/12/13 15:03:59 by jgonthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GRAPH_H
# define GRAPH_H

# include "op.h"
# include "./libft/include/libft.h"
# include <ncurses.h>

# define HEIGHT_WIN 64
# define WIDTH_WIN 244

typedef struct		s_win
{
	int				x;
	int				y;
	int				width;
	int				height;
}					t_win;

void				start_ncurses(void);
void				error(char *s);
WINDOW				*new_win(t_win *coor);
void				destroy_win(WINDOW *win);
void				init_coor(t_win *coor);
void				draw_menu(WINDOW *win, t_win *coor, t_proc *proc);
void				draw_arena(WINDOW *win);

#endif
