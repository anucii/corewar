/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_ld.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdaufin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/13 15:36:05 by jdaufin           #+#    #+#             */
/*   Updated: 2017/12/15 19:31:00 by jdaufin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "judi.h"

/*
**	get_val() is called only if the first parameter is well typed, so the 
**	alternative is between T_DIR and T_IND, the indirect parameter is handled
**	within the else statement
*/

static int	get_val(int p_type, unsigned char *mem, unsigned int pc,\
		unsigned int i)
{
	int				val;
	unsigned int	deref;

	if (p_type == T_DIR)
		val = chars_to_int(mem, i);
	else
	{
		deref = (pc + (unsigned int)(chars_to_short(mem, i) % IDX_MOD))\
				% MEM_SIZE;
		val = (int)chars_to_int(mem, deref);
	}
	return (val);
}

/*
**	f_ld() checks the fitness between the types stored in the OCP and the
**	ld instruction prototype (see g_op_tab[]) and then operates.
**	NB : no need to call a modulo MEM_SIZE on the values stored in p_idx[], 
**	the job of taking this constraint into account is done by the param_size()
**	function.
*/

void	f_ld(t_proc **proc, unsigned char *mem)
{
	int				*param;
	unsigned int	p_idx[3];
	unsigned int	size;
	int				val;

	if (!(proc && *proc && mem))
		error_vm("f_ld : undue null parameter(s) received");
	param = checkocp(&mem[((*proc)->pc + 1) % MEM_SIZE]);
	if (!((param[0] & g_op_tab[1].tp_param[0])\
				&& (param[1] & g_op_tab[1].tp_param[1]) && (param[2] == 0)))
	{
		execute_error(*proc);
		return ;
	}
	size = 2 + param_size(((*proc)->pc + 2) % MEM_SIZE, param, 0, &p_idx);
	val = get_val(param[0], mem, (*proc)->pc, p_idx[0]);
	if (mem[p_idx[1]] > REG_NUMBER)
	{
		execute_error(*proc);
		return ;
	}
	(*proc)->reg[mem[p_idx[1]] - 1] = val;
	(*proc)->pc += size;
	free(param);
}

/*
**	Maintest
**	to test : make -C .. 

static void	print_mem(unsigned char *mem, ssize_t max)
{
	ssize_t 		i = -1;

	if (!mem)
		return ;
	while (++i < max)
		ft_printf("%02hx%c", mem[i], (i + 1) % 8 ? ' ' : '\n');
	ft_printf("\n");
}

static void	print_proc(t_proc *proc)
{
	ssize_t	i = -1;
	if (!proc)
		return ;
	ft_printf("%s[pid:%3u] @ pc:%u)\n", proc->name, proc->pid, proc->pc);
	ft_printf("Registers:\n");
	while (++i < REG_NUMBER)
		ft_printf("[(%03zu) = %u]%c", i, proc->reg[i], (i + 1) % 4 ? ' ' : '\n');
	ft_printf("\n");
}

int	main(void)
{
	unsigned char	mem[] = {
		2, 208, 0, 5, 1,	//ld 5, r1 (OCP : 208)
		2, 144, 0, 0, 0, 7, 2,	//ld %7, r2 (OCP : 144)
	};
	t_proc			*proc = ft_memalloc(sizeof(t_proc));
	
	proc->name = "test_ld";
	
	ft_printf("Initial states\n");
	ft_printf("--------------\n");
	print_mem(mem, 12);
	print_proc(proc);
	
	ft_printf("First call to ld\n");
	ft_printf("----------------\n");
	f_ld(&proc, mem);
	print_mem(mem, 12);
	print_proc(proc);
	
	ft_printf("Second call to ld\n");
	ft_printf("----------------\n");
	f_ld(&proc, mem);
	print_mem(mem, 12);
	print_proc(proc);
	
	return (0);
}
*/
