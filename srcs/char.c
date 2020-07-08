
#include "ft_printf.h"

void printChar(t_pfstruct *data)
{
	int width;
	unsigned char ch;

	ch = (unsigned char)va_arg(data->args, int);
	if (data->fs.width && !data->fs.flag.minus)
	{
		width = data->fs.width - 1;
		if (data->fs.flag.zero)
			data->pfreturn += writeChars(width, '0'); //нужно??
		else
			data->pfreturn += writeChars(width, ' ');
		data->pfreturn += write(1, &ch, 1);
	}
	else if (data->fs.width && data->fs.flag.minus)
	{
		data->pfreturn += write(1, &ch, 1);
		width = data->fs.width - 1;
		if (data->fs.flag.zero)
			data->pfreturn += writeChars(width, '0');
		else
			data->pfreturn += writeChars(width, ' ');
	}
	else
		data->pfreturn += write(1, &ch, 1);
}