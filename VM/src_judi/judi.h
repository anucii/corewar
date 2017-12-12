/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   judi.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdaufin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/11 16:33:12 by jdaufin           #+#    #+#             */
/*   Updated: 2017/12/12 16:51:01 by jdaufin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VM_H
# define VM_H
# include "op.h"
typedef				s_proc	t_proc;

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
}					t_life;

typedef	struct		s_proc
{
	_Bool			carry;
	t_life			life;
	unsigned char	reg[REG_NUMBER];
	unsigned int	pid;
	unsigned int	pc;
	unsigned int	cc;
	t_proc			*children;
};

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

void				foreach_proc(t_proc **tab, void (*func)(t_proc **));

void				timer(void);
_Bool				chronos(t_proc *proc, t_req request);
void				atropos(t_proc **proc_tab);
void				kill_proc(t_proc *proc);

typedef				void (*t_f_op)(t_proc **, unsigned char *);

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
