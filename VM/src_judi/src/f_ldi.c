/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_ldi.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdaufin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/13 15:41:16 by jdaufin           #+#    #+#             */
/*   Updated: 2017/12/20 20:10:50 by jdaufin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "judi.h"

static unsigned int ldi_calc(t_proc *proc, unsigned char *mem, int *param,\
		unsigned int (*p_idx)[3])
{
	unsigned int	ret;
	unsigned short	deref[2];
	ssize_t			i;

	i = -1;
	while (++i < 2)
	{
		if (param[i] == T_REG)
			deref[i] = proc->reg[mem[(*p_idx)[i]] - 1];
		else if (param[i] == T_IND)
			deref[i] = chars_to_short(mem, ((*p_idx)[i] \
						+ (chars_to_short(mem, (*p_idx[i])) % IDX_MOD)))\
					% IDX_MOD;
		else
			deref[i] = chars_to_short(mem, (*p_idx)[i]);
	}
	deref[0] = (proc->pc + ((deref[0] + deref[1]) % IDX_MOD)) % MEM_SIZE;
	return (ret = chars_to_int(mem, deref[0]));
}

void	f_ldi(t_proc **proc, unsigned char *mem)
{
	int				*param;
	unsigned int	p_idx[3];
	unsigned int	size;

	if (!(proc && *proc && mem))
		error_vm("f_ldi() called with undue null parameter(s)");
	param = checkocp(&mem[((*proc)->pc + 1) % MEM_SIZE]);
	size = 2 + param_size(((*proc)->pc + 2) % MEM_SIZE, param, 1, &p_idx);
	if (!parse_params(param, &p_idx, mem[(*proc)->pc % MEM_SIZE], mem))
	{
		execute_error(*proc);
		return ;
	}
	(*proc)->reg[mem[p_idx[2]] - 1] = ldi_calc(*proc, mem, param, &p_idx);
	(*proc)->pc = ((*proc)->pc + size) % MEM_SIZE;
	free(param);
}

/*
**	MAINTEST
**	see the four first instructions test_ldi.s to get an explanation
*/

int		main(void)
{
	unsigned char	*mem = ft_memalloc(MEM_SIZE);
	unsigned short	var = 17;
	unsigned short	dir = 1;
	unsigned char	txt[] = {\
		6, 0xa4, 0, 0, 0, 3, 0, 0, 0, 6,\
			0x0b, 0x0a, 0xe4, var >> 8, var, dir >> 8, dir, 3, 3, 0x70,\
			3, 0, 0x3d, 6, 0xa4, 0, 0, 0, 0x10, 0,\
			0, 0, 0x11, 0x10, 6, 0xa4, 0, 0, 0, 0x0a,\
			0, 0, 0, 5, 0x0f, 7, 0xa4, 0, 0, 0,\
			0x18, 0, 0, 0, 0x34, 0x0e, 7, 0xa4, 0, 0,\
			0, 6, 0, 0, 0, 0x2b, 0x0d\
	};
	t_proc			*proc = ft_memalloc(sizeof(t_proc));
	unsigned char	golem[] = {\
		3, 0x50, 1, 7, 2, 0x90, 0, 0, 0, 0x30\
	};
		
	write_on_mem(mem, 0, txt, 68);
	write_on_mem(mem, 2047, golem, 10);
	ft_printf("Initial conditions:\n");
	print_proc(proc);
	print_mem(mem, 128);
	ft_printf("golem @ mem[2047]\n");
	print_mem(&mem[2047], 16);
	ft_printf("-------------------\n\n");

	f_and(&proc, mem);
	print_proc(proc);
	ft_printf("\nldi %u, %%%u, r3\n", var, dir);
	f_ldi(&proc, mem);
	print_proc(proc);
	print_mem(mem, 128);
	ft_printf("golem @ mem[2047]\n");
	print_mem(&mem[2047], 16);
	ft_printf("-------------------\n\n");

	return (0);
}
