#include "asm.h"

/*
static void put_tab(char *s)
{
	char	**tab;
	int		count_words;
	int     index;

	if ((count_words = multi_split(&tab, s)) != 0)
		{
			ft_printf("count_words = %d: ", count_words);
			index = -1;
			while (++index < count_words)
			{
				if (index + 1 == count_words)
					ft_printf("[%s]\n", tab[index]);
				else
					ft_printf("[%s] ", tab[index]);
			}
		}
}
*/

_Bool    pars_order(t_order *order, t_file file)
{
	char    **tokens;
	int     count_words;

	tokens = NULL;
	if ((count_words = multi_split(&tokens, file.line)) == 0)
		return (0);
	if (!(parse_instr(tokens, count_words, order)))
	{
		free_doublechar(tokens, count_words);
		return (0);
	}
	free_doublechar(tokens, count_words);
//	ft_printf("count_words : %d\n", count_words);
//	if (!(parse_params(tokens, count_words, order, ret)))
	//	return (0);
	return (1);
}
