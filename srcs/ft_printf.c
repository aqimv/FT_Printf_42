
#include "ft_printf.h"
#include <stdio.h>

static int pars_fs(char *flag, t_pfstruct *data)
{
//	char *check;
//
//	check = *flag;
	printf("!!!");
//	ft_putchar(**flag);
	flag+=4;
//	ft_putchar(**flag);

//	while (!ft_strchr(FLAGS, **flag))
//	{
//		if (!**flag || !ft_strchr(SYMBOLSINFLAG, **flag))
//			return 0;
//		flag++;
//	}
	//while ()

//	ft_putstr(flag);
//	write(1, flag, 1);
	data->pfreturn++;
	return 0;
}

static int parsformat(t_pfstruct *data)
{
	char *p;

	p = &data->str[0];
	while (*p)
	{
		if (*p && *p != '%')
		{
			data->pfreturn += write(1, p, 1);
//			if
//			printf("%s", p);
			//ft_putchar('!');
			p++;
		}
		else if (p++)
		{
			//ft_putchar('?');
			data->pfreturn += pars_fs(p, data);
			//ft_putchar('?');
		}
	}
	return data->pfreturn;
}

t_fstring *fs_init()
{
	t_fstring *fs;

	fs = (t_fstring*)malloc(sizeof(t_fstring));
	fs->width = 0;
	fs->accuracy = 0;
	fs->size = 0;
	return (fs);
}

static t_pfstruct *pf_init()
{
	t_pfstruct *pf;

	pf = (t_pfstruct*)malloc(sizeof(t_pfstruct));
	pf->pfreturn = 0;
	pf->fs = fs_init();
	return (pf);
}

int		ft_printf(const char *format, ...)
{
	int result;
	t_pfstruct *data;

	data = pf_init();
	va_start(data->args, format);
	data->str = (char *)format;

	result = parsformat(data);

	return (result);
}