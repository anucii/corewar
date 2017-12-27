/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_lld.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdaufin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/13 15:42:56 by jdaufin           #+#    #+#             */
/*   Updated: 2017/12/27 19:52:06 by jdaufin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "judi.h"

static unsigned int	get_val(int p_type, unsigned char *mem, unsigned int pc,\
		unsigned int i)
{
	unsigned int	val;
	unsigned int	deref;

	if (p_type == T_DIR)
		val = chars_to_int(mem, i, 1);
	else
	{
		deref = (pc + (unsigned int)chars_to_short(mem, i, 1)) % MEM_SIZE;
		val = chars_to_short(mem, deref, 1);
		if (val > SHRT_MAX)
			val |= (USHRT_MAX << 16);
	}
	return (val);
}

void				f_lld(t_proc **proc, unsigned char *mem)
{
	int				*param;
	unsigned int	p_idx[3];
	unsigned int	size;
	unsigned int	val;

	if (!(proc && *proc && mem))
		error_vm("f_lld : undue null parameter(s) received");
	param = checkocp(&mem[((*proc)->pc + 1) % MEM_SIZE]);
	if (!((param[0] & g_op_tab[12].tp_param[0])\
				&& (param[1] & g_op_tab[12].tp_param[1]) && (param[2] == 0)))
	{
		execute_error(*proc);
		return ;
	}
	size = 2 + param_size(((*proc)->pc + 2) % MEM_SIZE, param, 0, &p_idx);
	val = get_val(param[0], mem, (*proc)->pc, p_idx[0]);
	if ((!mem[p_idx[1]]) || (mem[p_idx[1]] > REG_NUMBER))
	{
		execute_error(*proc);
		return ;
	}
	(*proc)->reg[mem[p_idx[1]] - 1] = val;
	(*proc)->pc += size;
	free(param);
}

/*
 * MAINTEST

int		main(void)
{
	unsigned char	*mem = ft_memalloc(MEM_SIZE);
	unsigned char	var[2] ;
	unsigned short	var_val = 2049;
	var[0] = var_val >> 8;
	var[1] = var_val;
	unsigned char	txt[] = {\
		6, 0xa4, 0, 0, 0, 3, 0, 0, 0, 6,\
				  0x0b, 0x0d, 0xd0, var[0], var[1], 3, 3, 0x70,\
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
	f_lld(&proc, mem);
	f_st(&proc, mem);
	print_proc(proc);
	print_mem(mem, 68);
	ft_printf("golem @ mem[%d]\n", 2048);
	print_mem(&mem[2048], 64);
	ft_printf("-------------------\n\n");

	return (0);
}
*/
