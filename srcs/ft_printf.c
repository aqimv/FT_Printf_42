
#include "ft_printf.h"

static int parsformat2(char *flag, t_pfstruct *data)
{
	char *check;

	check = flag;
	//if (!ft_strchr(FLAGS, flag)
	while (check && !ft_strchr(FLAGS, check))
		check++;
	if (!check)
		return 0;

//	ft_putstr(flag);
//	write(1, flag, 1);
//	data->pfreturn++;
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
			data->pfreturn += parsformat2(&data->str[p], data);
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
	int result;
	t_pfstruct *data;

	data = pf_init();
	va_start(data->args, format);
	data->str = (char *)format;

	result = parsformat(data);

	return (result);
}