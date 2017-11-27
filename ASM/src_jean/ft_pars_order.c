#include "JEAAAAAAAAAAAAN.h"

_Bool    ft_pars_order(t_order *order, t_file file)
{
	char    **tokens;
	int     count_words;
	int     index;

	count_words = ft_multi_split(&tokens, file.line);
	if ((count_words = ft_multi_split(&tokens, file.line)) != 0)
	{
		ft_printf("count_words = %d: ", count_words);
		index = -1;
		while (++index < count_words)
		{
			if (index + 1 == count_words)
				ft_printf("[%s]\n", tokens[index]);
			else
				ft_printf("[%s] ", tokens[index]);
		}
	}
	order->op_code = 1;
	if (!parse_params(tokens, count_words, order, 1))
		exit(0);
//		return (0);
	exit(0);
	return (1);
}
