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
	ssize_t	i = -1;
	short	tgt;

	if (!(proc && mem) || (pos < 0))
		return ;
	tgt = (pos + 1) % MEMSIZE;
	printf("[pid : %hd] @ %hd (pc)\n", proc->pid, proc->pc);
	printf("reg[%d] = %d\n", mem[tgt] % REG_MAX, (proc->reg)[mem[tgt] % REG_MAX]);
	(proc->reg)[mem[tgt] % REG_MAX]= mem[pos % MEMSIZE];
	proc->carry = 1;
	i = -1;
	printf("Store operation : ");
	printf("reg[%d] = %d\n", mem[tgt] % REG_MAX,\
			(proc->reg)[mem[tgt] % REG_MAX]);
}

void	add(t_proc *proc, unsigned char *mem, short pos)
{
	short	tgt;

	if (!(proc && mem) || (pos < 0))
		return ;
	tgt = mem[(pos + 2) % MEMSIZE] % REG_MAX;
	printf("[pid : %hd] @ %hd (pc)\n", proc->pid, proc->pc);
	printf("reg[%d] = %d\n", tgt, (proc->reg)[tgt]);
	(proc->reg)[tgt] = (proc->reg)[mem[pos % MEMSIZE] % REG_MAX]\
													+ (proc->reg)[mem[(pos + 1) % MEMSIZE] % REG_MAX];
	printf("Addition : ");
	printf("%d + %d = %d @ reg[%d]\n", (proc->reg)[mem[pos % MEMSIZE] % REG_MAX],\
			(proc->reg)[mem[(pos + 1) % MEMSIZE] % REG_MAX], (proc->reg)[tgt], tgt);
	proc->carry = 1;
}

void	write(t_proc *proc, unsigned char *mem, short pos)
{
	short	tgt;

	if (!(proc && mem) || (pos < 0))
		return ;
	printf("[pid : %hd] @ %hd (pc)\n", proc->pid, proc->pc);
	tgt = (proc->pc + mem[(pos + 1) % MEMSIZE]) % MEMSIZE;
	printf("mem[%d] = %d & reg[%d] = %d\n", tgt, mem[tgt],\
			(pos % MEMSIZE) % REG_MAX,\
			(proc->reg)[mem[pos % MEMSIZE] % REG_MAX]);
	mem[tgt] = (proc->reg)[mem[pos % MEMSIZE] % REG_MAX];
	printf("Write operation : ");
	printf("mem[%d] = %d\n", tgt, mem[tgt]);
	proc->carry = 1;
}
