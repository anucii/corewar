/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_ld.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdaufin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/13 15:36:05 by jdaufin           #+#    #+#             */
/*   Updated: 2018/02/05 09:59:22 by jpallard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

/*
**	get_val() is called only if the first parameter is well typed, so the 
**	alternative is between T_DIR and T_IND, the indirect parameter is handled
**	within the else statement
*/

static unsigned int	get_val(int p_type, unsigned char *mem, t_proc *p,\
		unsigned int i)
{
	unsigned int	val;
	unsigned int	deref;

	if (p_type == T_DIR)
		val = chars_to_int(mem, i, 1);
	else
	{
		deref = (p->pc + (chars_to_short(mem, i, 1) % IDX_MOD))\
				% MEM_SIZE;
		val = chars_to_int(mem, deref, 1);
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

void				f_ld(t_proc **proc, unsigned char *mem)
{
	int				*param;
	unsigned int	p_idx[3];
	unsigned int	size;
	int				val;

	if (!(proc && *proc && mem))
		error_vm("f_ld : undue null parameter(s) received");
 	param = checkocp(&mem[((*proc)->pc + 1) % MEM_SIZE], 2);
	size = 2 + param_size(((*proc)->pc + 2) % MEM_SIZE, param, 0, &p_idx);
	if (!parse_params(param, &p_idx, 2, mem))
		return (execute_error(*proc, param, size));
	val = get_val(param[0], mem, (*proc), p_idx[0]);
	(*proc)->reg[mem[p_idx[1]] - 1] = val;
	(*proc)->carry = val ? 0 : 1;
	(*proc)->pc += size;
	free(param);
}

/*
 * MAINTEST

int		main(void)
{
	unsigned char	*mem = ft_memalloc(MEM_SIZE);
	unsigned char	var[2] ;
	unsigned short	var_val = 551;
	var[0] = var_val >> 8;
	var[1] = var_val;
	unsigned char	txt[] = {\
		6, 0xa4, 0, 0, 0, 3, 0, 0, 0, 6,\
				  0x0b, 0x02, 0xd0, var[0], var[1], 3, 3, 0x70,\
				  3, 0, 0x3d, 6, 0xa4, 0, 0, 0, 0x10, 0,\
				  0, 0, 0x11, 0x10, 6, 0xa4, 0, 0, 0, 0x0a,\
				  0, 0, 0, 5, 0x0f, 7, 0xa4, 0, 0, 0,\
				  0x18, 0, 0, 7, 0xf5, 0x0e, 7, 0xa4, 0, 0,\
				  0, 6, 0, 0, 0, 0x34, 0x0d\
	}; 

	//only the ten first bytes of golems binary are copied here
	unsigned char	golem[] = {\
		3, 0x50, 1,\
			7, 2, 0x90, 0, 0, 0, 0x30, 0x10, 2, 0x90,\
			1, 0, 0, 0, 2, 0x0b, 0x68, 2, 0, 0x26,\
			0, 0, 0x0b, 0x68, 7, 0, 0x1f, 0, 1, 0x0b,\
			0x68, 2, 0, 0, 0, 0x60, 0x0b, 0x68, 7, 0,\
			0, 0, 0x5a, 3, 0x70, 2, 0, 0x2a, 3, 0x70,\
			3, 0, 0x2b, 0x10, 0x40, 0x10, 0x10, 0x40, 0x10, 0x10,\
			0x40, 0x10, 1, 0, 0, 0, 2\
	};

	//unsigned char	*test = ft_memalloc(32);
	t_proc			*proc = ft_memalloc(sizeof(t_proc));
		
	write_on_mem(mem, 0, txt, 66);
	write_on_mem(mem, 2048, golem, 60);
	//ft_memset(test, 42, 31);
	//write_on_mem(mem, 511, test, 31);
	ft_printf("Initial conditions:\n");
	print_proc(proc);
	print_mem(mem, 68);
	ft_printf("-------------------\n\n");

	ft_printf("lld %hu, r3\n", var_val);
	f_and(&proc, mem);
	f_ld(&proc, mem);
	f_st(&proc, mem);
	print_proc(proc);
	print_mem(mem, 68);
	ft_printf("golem @ mem[%d]\n", 2048);
	print_mem(&mem[2048], 64);
	ft_printf("-------------------\n\n");

	return (0);
}
*/
/*
**	Maintest
**	to test : make -C .. 

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
