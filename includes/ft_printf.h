
#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include "libft.h"

# define FLAGSPF "1234567890. +-*%cdifosuxXpn"

typedef struct		s_pfstruct
{
    char *str;
    int pfreturn;
}					t_pfstruct;

int		ft_printf(const char *format, ...);

#endif
