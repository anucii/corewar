#include "calc.h"

/*
 * Parameter pos is the index of the first parameter,
 * in other terms, the index folowing the address pointed
 * by the current value of the program counter (pc)
 */

t_op	g_op_tab[] = {\
	{"store", 1, 2, &store},\
	{"add", 2, 3, &add},\
	{"write", 3, 2, &write},\
	{NULL, 0, 0, NULL}\
};

void	store(t_proc *proc, unsigned char *mem, short pos)
{
	if (!(proc && mem) || (pos < 0))
		return ;
	proc->reg[mem[(pos + 1) % MEMSIZE] % (1 + REG_NUM)] = mem[pos % MEMSIZE];
	proc->carry = 1;
}

void	add(t_proc *proc, unsigned char *mem, short pos)
{
	if (!(proc && mem) || (pos < 0))
		return ;
	proc->reg[mem[(pos + 2) % MEMSIZE] % REG_NUM] = proc->reg[mem[pos % MEMSIZE] % REG_NUM]\
													+ proc->reg[mem[(pos + 1) % MEMSIZE] % REG_NUM];
	proc->carry = 1;
}

void	write(t_proc *proc, unsigned char *mem, short pos)
{
	short	tgt;

	if (!(proc && mem) || (pos < 0))
		return ;
	tgt = (proc->pc + mem[(pos + 1) % MEMSIZE]) % MEMSIZE;
	mem[tgt] = proc->reg[mem[pos %MEMSIZE]];
	proc->carry = 1;
}
