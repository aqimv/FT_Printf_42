
#include "ft_printf.h"

static int parsformat(t_pfstruct *data)
{
	//int result;
	int p;

	p = 0;
	while (data->str[p])
	{
		ft_putchar(data->str[p]);
		p++;
	}
	return p;
}

static t_pfstruct *pf_init()
{
	t_pfstruct *pf;

	pf = (t_pfstruct*)malloc(sizeof(t_pfstruct));
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