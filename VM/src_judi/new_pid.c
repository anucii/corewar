/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_pid.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdaufin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/13 14:32:37 by jdaufin           #+#    #+#             */
/*   Updated: 2017/12/13 14:54:29 by jdaufin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "judi.h"

unsigned int	new_pid(void)
{
	static unsigned int	ret = 0;

	return (ret++);
}

/*test

#include <stdio.h>

int		main(void)
{
	ssize_t	i = -1;
	while (++i < 10)
		printf("%zu : new_pid() = %u\n", i, new_pid());
	return (0);
}
*/
