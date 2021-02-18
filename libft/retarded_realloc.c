#include "libft.h"

void        *retarded_realloc(void *p0, size_t size0, size_t size1)
{
    void        *p1;

    if (!p0)
        return (NULL);
    if (!(p1 = malloc(size1)))
    {
        free(p0);
        return (NULL);
    }
    ft_memcpy(p1, p0, size0 < size1 ? size0 : size1);
    free(p0);
    return (p1);
}