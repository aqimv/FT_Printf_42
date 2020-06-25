
#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include "libft.h"

typedef struct		s_pfstruct
{
    char *str;
}					t_pfstruct;

int		ft_printf(const char *format, ...);

#endif
