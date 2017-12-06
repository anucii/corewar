#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <stdlib.h>

void					bigendian(unsigned int *i, unsigned short *s)
{
	if (i != 0)
	{
		*i = ((*i >> 24) & 0xff)
			| ((*i << 8) & 0xff0000)
			| ((*i >> 8) & 0xff00)
			| ((*i << 24) & 0xff000000);
	}
	if (s != 0)
		*s = (*s >> 8) | (*s << 8);
}

int		main(void)
{
	int				fd;
	unsigned int	magic = 0xea83f3;
	char			*err = "Error : could not open \'random_bin\'";

	if ((fd = open("random_bin", O_RDWR)) < 0)
	{
		write(2, err, strlen(err));
		exit(EXIT_FAILURE);
	}
	bigendian(&magic, NULL);
	write(fd, &magic, sizeof(unsigned int));
	return (close(fd) ? -1 : 0);
}
