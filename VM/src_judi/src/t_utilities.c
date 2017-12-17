#include "judi.h"

void	print_mem(unsigned char *mem, ssize_t max)
{
	ssize_t 		i = -1;

	if (!mem)
		return ;
	while (++i < max)
		ft_printf("%02hx%c", mem[i], (i + 1) % 8 ? ' ' : '\n');
	ft_printf("\n");
}

void	print_proc(t_proc *proc)
{
	ssize_t	i = -1;
	if (!proc)
		return ;
	ft_printf("%s[pid:%3u] @ pc:%u)\n", proc->name, proc->pid, proc->pc);
	ft_printf("Registers:\n");
	while (++i < REG_NUMBER)
		ft_printf("[(%03zu) = %u]%c", i, proc->reg[i], (i + 1) % 4 ? ' ' : '\n');
	ft_printf("\n");
	ft_printf("Life status : %s - last live : %04u - player declared : %4u\n",\
			proc->life.status ? "alive" : "dead", proc->life.last, proc->life.player);
}

void	write_on_mem(unsigned char *mem, unsigned short begin, unsigned char *txt, unsigned short len)
{
	unsigned short	i = 0;

	if (!(mem && txt))
		return ;
	while ((i < MEM_SIZE) && (i < len))
	{
		mem[(begin + i) % MEM_SIZE] = txt[i];
		i++;
	}
}
