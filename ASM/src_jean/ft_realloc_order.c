#include "JEAAAAAAAAAAAAN.h"

void ft_realloc_order(t_order **order, int *size)
{
    *size += 1;
    if ((*order = realloc(*order, sizeof(t_order) * (*size * SIZE_STRUCT))) == NULL)
        ft_error("Ft. Realloc Failed\n");
}
