
#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include "libft.h"
#include <stdio.h> // убрать нахой

# define SYMBOLSINFS "1234567890.+-#* lhjztL"
# define TYPESPF "%cdifosuxXpn"
# define FLAGSPF "+#0 -"
# define WIDTHANDACCURACY "0123456789*"
# define SIZEPF "lhjztL"

typedef struct		s_size
{
	int				l;
	int				ll;
	int				h;
	int				hh;
	int				j;
	int				z;
	int				t;
	int				bigL;

}					t_size;

typedef struct		s_flags
{
	int				zero;
	int				minus;
	int				plus;
	int				space;
	int				sharp;
}					t_flags;

typedef struct		s_fstring
{
	char			*fnl;
	char			*str;
	t_flags			flag;
	int				wid;
	int				precision;
	t_size			size;
	char			type;
	char			sign;
	int				prZ;
}					t_fstring;

typedef struct		s_pfstruct
{
					va_list args;
					char *str;
					int pfreturn;
					t_fstring fs;
}					t_pfstruct;

int					ft_printf(const char *format, ...);
int					setFlag(t_pfstruct *data, char ch);
int					setSize(t_pfstruct *data, int *i);
int					setWidth(t_pfstruct *data, char ch);
int					setPrecision(t_pfstruct *data, char ch);
void				printInt(t_pfstruct *data);
void				printChar(t_pfstruct *data);
void				printString(t_pfstruct *data);
void				printPercent(t_pfstruct *data);
void				printUnsignedInt(t_pfstruct *data);
void				printOctal(t_pfstruct *data);
void				printHex(t_pfstruct *data);
void				printPointer(t_pfstruct *data);

int					writeChars(int i, char ch);
char				*ft_itoa_base(uintmax_t num, uintmax_t not);
void				precisionZero(t_pfstruct *data);
int					ft_putstrcount(char const *s);
int					md(int i);

void				deinit(t_pfstruct *data);
void				pf_init(t_pfstruct *data);

#endif
