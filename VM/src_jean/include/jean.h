/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgonthie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/13 14:15:12 by jgonthie          #+#    #+#             */
/*   Updated: 2017/12/16 14:32:01 by jgonthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VM_H
# define VM_H

# include "op.h"
# include "./libft/include/libft.h"
# include <fcntl.h>
# include <ncurses.h>

# define HEIGHT_WIN 78
# define WIDTH_WIN 235
# define BORDER_ARENA_X 195
# define BORDER_ARENA_Y 67
# define MENU 1
# define COREWAR 2

typedef struct		s_proc
{
	_Bool			carry;
	unsigned int	reg[REG_NUMBER];
	unsigned int	pc;
	char			*name;
	int				color;
	struct s_proc	*children;
}					t_proc;

typedef struct		s_win
{
	WINDOW			*win;
	int				x;
	int				y;
}					t_win;

void				checkheader(t_proc **proc, int *tab, char **argv, int argc);
unsigned char		*load_champ(int *tab, short nb, t_proc **p);
void				littleendian(unsigned int *i);

void				start_ncurses(t_win *win, t_proc **proc);
void				error(char *s);
void				new_win(t_win *window, int put);
void				destroy_win(t_win *window);
void				init_coor(t_win *window);
void				draw_corewar(t_win *window, t_proc **proc);
void				draw_arena(t_win *window, unsigned char *arena);
void				put_menu(t_win *window);

#endif
