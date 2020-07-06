
#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include "libft.h"

# define SYMBOLSINFS "1234567890.+-#* lhjztL"
# define TYPESPF "%cdifosuxXpn"
# define FLAGSPF "+#0 -"

typedef struct		s_fstring
{
	char *finalstr;
	char *str;
	char *flag;
	int width;
	int accuracy;
	char *size;
	char type;
}					t_fstring;

typedef struct		s_pfstruct
{
	va_list args;
    char *str;
    int pfreturn;
    t_fstring fs;
}					t_pfstruct;

int		ft_printf(const char *format, ...);
//t_fstring *fs_init();
//t_pfstruct *pf_init();
void setFlag(t_pfstruct *data, char ch);
void setSize(t_pfstruct *data, char ch);
void setWidth(t_pfstruct *data, char ch);
void setAccuracy(t_pfstruct *data, char ch);

#endif
