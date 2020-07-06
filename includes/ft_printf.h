
#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include "libft.h"

# define SYMBOLSINFS "1234567890.+-#* lhjztL"
# define TYPESPF "%cdifosuxXpn"
# define FLAGSPF "+#0 -"
# define WIDTHANDACCURACY "0123456789"
# define SIZEPF "lhjztL"

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
void pf_init(t_pfstruct *data);
int setFlag(t_pfstruct *data, char ch);
int setSize(t_pfstruct *data, char ch);
int setWidth(t_pfstruct *data, char ch);
int setAccuracy(t_pfstruct *data, char ch);

#endif
