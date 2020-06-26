
#include "ft_printf.h"

static int parsformat2(char *flag, t_pfstruct *data)
{
	//while ()
	write(1, flag, 1);
	data->pfreturn++;
	return 0;
}

static int parsformat(t_pfstruct *data)
{
	int p;

	p = 0;
	while (data->str[p])
	{
		if (data->str[p] && data->str[p] != '%')
		{
			data->pfreturn += write(1, &data->str[p], 1);
			p++;
		}
		else if (data->str[++p])
		{
			parsformat2(&data->str[p], data);
		}
	}
	return data->pfreturn;
}

static t_pfstruct *pf_init()
{
	t_pfstruct *pf;

	pf = (t_pfstruct*)malloc(sizeof(t_pfstruct));
	pf->pfreturn = 0;
	return (pf);
}

int		ft_printf(const char *format, ...)
{
	va_list args;
	int result;
	t_pfstruct *data;

	va_start(args, format);
	data = pf_init();
	data->str = (char *)format;

	result = parsformat(data);

	return (result);
}