/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   judi.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdaufin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/11 16:33:12 by jdaufin           #+#    #+#             */
/*   Updated: 2017/12/13 14:53:45 by jdaufin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VM_H
# define VM_H
# include "op.h"

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
	unsigned char	reg[REG_NUMBER];
	unsigned int	pid;
	unsigned int	pc;
	unsigned int	cc;
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
					NONE = -1, LIVE, CHECK,	INCR, RESET
}					t_req;

/*
**	chronos manages a table of the current livestate of each process
**	atropos, which is one of the three Parcae in greek mythology, decides
**	when to put an end to each of the processes life
*/

void				foreach_proc(t_proc **tab, unsigned int max, void (*func)(t_proc **));

unsigned int		timer(t_req request);
unsigned int		new_pid(void);
_Bool				chronos(t_proc *proc, t_req request, unsigned int player);
void				atropos(t_proc **proc_tab, unsigned int max);
void				kill_proc(t_proc *proc);

typedef				void (*t_f_op)(t_proc **, unsigned char *);

typedef struct		s_op
{
	char			*name;
	int				nb_param;
	int				tp_param[3];
	char			op_code;
	int				cycles;
	_Bool			has_ocp;
	_Bool			bool_2;
	t_f_op			func;
}					t_op;

extern t_op			g_op_tab[17];

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

#endif
