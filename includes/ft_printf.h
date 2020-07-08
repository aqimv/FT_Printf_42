
#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include "libft.h"

# define SYMBOLSINFS "1234567890.+-#* lhjztL"
# define TYPESPF "%cdifosuxXpn"
# define FLAGSPF "+#0 -"
# define WIDTHANDACCURACY "0123456789"
# define SIZEPF "lhjztL"

typedef struct		s_size
{
	int l;
	int ll;
	int h_size;
	int hh;
	int j;
	int z;
	int t;
	int bigL;
}					t_size;

typedef struct		s_flags
{
	int zero;
	int minus;
	int plus;
	int space;
	int sharp;
}					t_flags;

typedef struct		s_fstring
{
//	char *finalstr;
	char *str;
	t_flags flag;
	int width;
	int accuracy;
	t_size size;
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
void	pf_init(t_pfstruct *data);
int		setFlag(t_pfstruct *data, char ch);
int		setSize(t_pfstruct *data, int *i);
int		setWidth(t_pfstruct *data, char ch);
int		setAccuracy(t_pfstruct *data, char ch);
void	printInt(t_pfstruct *data);
void	printChar(t_pfstruct *data);
int writeChars(int i, char ch);

#endif
