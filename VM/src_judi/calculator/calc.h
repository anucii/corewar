#ifndef CALC_H
# define CALC_H

# include <stdio.h>
# include <stdlib.h>

# define MEMSIZE 64
# define REG_NUM 16
# define REG_MAX ((REG_NUM) - 1) 
# define MAX_PROC 3

typedef struct		s_proc
{
	short			pid;
	short			pc;
	unsigned char	reg[REG_NUM];
	_Bool			carry;
}					t_proc;

typedef void		(*t_func)(t_proc *proc, unsigned char *, short);

typedef struct		s_op
{
	char			*name;
	unsigned char	opcode;
	unsigned char	nb_param;
	t_func			func;
}					t_op;

extern t_op			g_op_tab[];

unsigned char		**memory(void);
_Bool				calc(t_proc **procs);
_Bool				cycle(unsigned char **mem, t_proc **procs);
_Bool				execute(unsigned char *mem, t_proc *proc);
void				disp_mem(unsigned char *mem);

void				store(t_proc *proc, unsigned char *mem, short pos);
void				add(t_proc *proc, unsigned char *mem, short pos);
void				write(t_proc *proc, unsigned char *mem, short pos);

#endif
