#include "calc.h"

_Bool	execute(unsigned char *mem, t_proc *proc)
{
	short	pos;
	short	i = 0;

	if (!(mem && proc))
		return (0);
	pos = proc->pc;
	while (g_op_tab[i].name && (g_op_tab[i].opcode != mem[pos]))
			++i;
	if (!g_op_tab[i].name)
		return (0);
	g_op_tab[i].func(proc, mem, (pos + 1) % MEMSIZE);
	proc->pc = (proc->pc + 1 + g_op_tab[i].nb_param) % MEMSIZE;
	return (1);
}
