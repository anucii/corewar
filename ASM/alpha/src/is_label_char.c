#include "asm.h"

_Bool			is_label_char(char c, char *label_char)
{
	while (*label_char)
	{
		if (c == *label_char)
			return (1);
		label_char += 1;
	}
	return (0);
}
