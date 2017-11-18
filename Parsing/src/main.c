#include "ft_multi_split.h"

int     main(int argc, char **argv)
{
    char    **tokens;
    char    *line;
    int     count_words;
    int     ret;
    int     fd;
    int     index;

    line = NULL;
    count_words = 0;
    ret = 0;
    fd = 0;
    if (argc != 2)
        ft_printf("Bad usage\n");
    else
    {
        fd = open(argv[1], O_RDONLY);
        if (fd == -1)
        {
            ft_printf("Ft. Open() Failed\n");
            return (0);
        }
        while ((ret = get_next_line(fd, &line)) == 1)
        {
            if ((count_words = ft_multi_split(&tokens, line)) != 0)
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
            ft_strdel(&line);
        }
        if (ret == -1)
            ft_printf("Ft. Read() Failed\n");
    }
    return (0);
}
