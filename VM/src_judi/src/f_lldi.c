/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_lldi.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdaufin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/13 15:43:20 by jdaufin           #+#    #+#             */
/*   Updated: 2017/12/20 14:57:56 by jdaufin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "judi.h"

static unsigned int lldi_calc(t_proc *proc, unsigned char *mem, int *param,\
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
		//else if (param[i] == T_IND)
		//	deref[i] = chars_to_short(mem, (proc->pc + chars_to_short(mem,\
		//					(*p_idx)[i])));
		else if (param[i] == T_IND)
			deref[i] = (chars_to_short(mem, (*p_idx)[i]) - 2) % MEM_SIZE;
		else
			deref[i] = chars_to_short(mem, (*p_idx)[i])//\
					  // + (param[i] == T_DIR ? 0 : proc->pc);
		ft_printf("deref[%zu] = %hu\n", i, deref[i]);//dbg
		ft_printf("proc->pc = %u\n", proc->pc);
	}
	deref[0] = (proc->pc + deref[0] + deref[1]);
	ft_printf("deref sum = %hu\n", deref[0]);//dbg
	return (ret = chars_to_int(mem, deref[0]));
}

void	f_lldi(t_proc **proc, unsigned char *mem)
{
	int				*param;
	unsigned int	p_idx[3];
	unsigned int	size;

	if (!(proc && *proc && mem))
		error_vm("f_lldi() called with undue null parameter(s)");
	param = checkocp(&mem[((*proc)->pc + 1) % MEM_SIZE]);
	size = 2 + param_size(((*proc)->pc + 2) % MEM_SIZE, param, 1, &p_idx);
	if (!parse_params(param, &p_idx, mem[(*proc)->pc % MEM_SIZE], mem))
	{
		execute_error(*proc);
		return ;
	}
	(*proc)->reg[mem[p_idx[2]] - 1] = lldi_calc(*proc, mem, param, &p_idx);
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
	/*unsigned char	txt[] = {\
		2, 144, 0, 0, 15, 235, 2,\
			14, 164, 255, 252, 0, 0, 3,\
			14, 228, 255, 252, 0, 0,  16,\
			14, 84, 2, 3, 4\
	};
	unsigned char	txt[] = {\
		2, 144, 0, 0, 15, 235, 2,\
			14, 228, 0, 2, 0, 0, 3,\
			14, 228, 0, 3, 0, 0,  16,\
			14, 84, 2, 3, 4\
	};*/
	unsigned char txt[] = {\
		0x6, 0xa4, 0, 0, 
	//unsigned char	*test = ft_memalloc(32);
	t_proc			*proc = ft_memalloc(sizeof(t_proc));
		
	write_on_mem(mem, 0, txt, 26);
	//ft_memset(test, 42, 31);
	//write_on_mem(mem, 511, test, 31);
	ft_printf("Initial conditions:\n");
	print_proc(proc);
	print_mem(mem, 32);
	ft_printf("-------------------\n\n");
/*
	ft_printf("ld %%4075, r2\n");
	f_ld(&proc, mem);
	print_proc(proc);
	print_mem(mem, 32);
	ft_printf("-------------------\n\n");

	//ft_printf("lldi  %%-4, %%0, r3\n");
	ft_printf("lldi  4, %%0, r3\n");
	f_lldi(&proc, mem);
	print_proc(proc);
	print_mem(mem, 32);
	ft_printf("-------------------\n\n");

	//ft_printf("lldi -4, %%0, r16\n");
	ft_printf("lldi  %%4, %%0, r3\n");
	f_lldi(&proc, mem);
	print_proc(proc);
	print_mem(mem, 32);
	ft_printf("-------------------\n\n");

	ft_printf("lldi r2, r3, r4\n");
	f_lldi(&proc, mem);
	print_proc(proc);
	print_mem(mem, 32);
	ft_printf("-------------------\n\n");
*/
	ft_printf("lldi r2, r3, r4\n");
	f_and(&proc, mem);
	f_lldi(&proc, mem);
	print_proc(proc);
	print_mem(mem, 32);
	ft_printf("-------------------\n\n");

	return (0);
}
