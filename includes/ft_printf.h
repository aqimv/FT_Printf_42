
#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include "libft.h"

# define SYMBOLSINFLAG "1234567890. +-*%cdifosuxXpn"
# define FLAGS "%cdifosuxXpn"

typedef struct		s_fstring
{
	char flag;
	int width;
	int accuracy;
	int size;
	char type;
}					t_fstring;

typedef struct		s_pfstruct
{
	va_list args;
    char *str;
    int pfreturn;
    t_fstring *fs;
}					t_pfstruct;

int		ft_printf(const char *format, ...);

#endif
