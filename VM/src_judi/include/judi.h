/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   judi.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdaufin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/11 16:33:12 by jdaufin           #+#    #+#             */
/*   Updated: 2017/12/15 15:17:43 by jdaufin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VM_H
# define VM_H
# include "op.h"
# include "libft.h"
# include "libftprintf.h"
# include <stdlib.h>
# include <fcntl.h>
# include <limits.h>

/*
**	Structure specific fields
**	- life : a structure with a boolean (status) that handles the life 
**	status of each process which is initialized to 0, and is set to 1
**	by the 'live' instruction, and an unsigned int that keeps the cycle
**	number of the last live call.
**	- cc : cycles counter
**	- pid : unique process ID
**	- reg : registers stored in unibytes array (unsigned char)
*/

typedef struct		s_life
{
	_Bool			status;
	unsigned int	last;
	unsigned int	player;
}					t_life;

typedef	struct		s_proc
{
	_Bool			carry;
	t_life			life;
	unsigned int	reg[REG_NUMBER];
	unsigned int	pid;
	unsigned int	pc;
	unsigned int	cc;
	char			*name;
//	t_champ			champ;
	struct s_proc	*children;
}					t_proc;


/*
**	REQUESTS enumeration for chronos function :
**	- LIVE : declaring a process as alive
**	- CHECK : getting the live status of a function
*/

typedef enum		e_req
{
					NONE = -1, LIVE, CHECK,	INCR, DECR, RESET
}					t_req;

/*
**	chronos manages a table of the current livestate of each process
**	atropos, which is one of the three Parcae in greek mythology, decides
**	when to put an end to each of the processes life
*/

void				foreach_proc(t_proc **tab, unsigned int max, void (*func)(t_proc **));

unsigned int		timer(t_req request);
unsigned int		deadline(t_req request);
unsigned int		nbr_live(t_req request);

unsigned int		new_pid(void);
_Bool				chronos(t_proc *proc, t_req request, unsigned int player);
void				atropos(t_proc **proc_tab, unsigned int max);
void				kill_proc(t_proc **ptr_proc);

unsigned int		new_player(void);
void				checkheader(int fd, t_proc **p, unsigned int player);
void				init_proc(t_proc **p, int fd, unsigned int player);
void				littleendian(unsigned int *i);
unsigned char		*load_champ(int *tab, short nb, t_proc **p);
void				run(unsigned char *mem, t_proc **p);
void				execute_order(unsigned char *mem, t_proc *p);
void				error_vm(char *s);
void				execute_error(t_proc *proc);
void				reinit_life_status(t_proc *proc);
int					*checkocp(unsigned char *mem);
unsigned int		param_size(unsigned int p_first, int *params,\
		_Bool dir_as_addr, int (*p_idx)[3]);

typedef				void (*t_f_op)(t_proc **, unsigned char *);

typedef struct		s_op
{
	char			*name;
	int				nb_param;
	int				tp_param[3];
	char			op_code;
	int				cycles;
	char			*description;
	_Bool			has_ocp;
	_Bool			bool_2;
	t_f_op			func;
}					t_op;

extern t_op			g_op_tab[17];
extern unsigned int	g_n_players;

void				f_live(t_proc **proc, unsigned char *mem);
void				f_ld(t_proc **proc, unsigned char *mem);
void				f_st(t_proc **proc, unsigned char *mem);
void				f_add(t_proc **proc, unsigned char *mem);
void				f_sub(t_proc **proc, unsigned char *mem);
void				f_and(t_proc **proc, unsigned char *mem);
void				f_or(t_proc **proc, unsigned char *mem);
void				f_xor(t_proc **proc, unsigned char *mem);
void				f_zjmp(t_proc **proc, unsigned char *mem);
void				f_ldi(t_proc **proc, unsigned char *mem);
void				f_sti(t_proc **proc, unsigned char *mem);
void				f_fork(t_proc **proc, unsigned char *mem);
void				f_lld(t_proc **proc, unsigned char *mem);
void				f_lldi(t_proc **proc, unsigned char *mem);
void				f_lfork(t_proc **proc, unsigned char *mem);
void				f_aff(t_proc **proc, unsigned char *mem);

unsigned int		chars_to_int(unsigned char *mem, unsigned int index);
unsigned short		chars_to_short(unsigned char *mem, unsigned int index);

#endif
