
#include "ft_printf.h"

//void signOrSpace(t_pfstruct *data)
//{
//	if (data->fs.sign)
//	{
//		data->pfreturn += write(1, &data->fs.sign, 1);
//		data->fs.wid -= 1;
//	}
//	else if (data->fs.flag.space)
//	{
//		data->pfreturn += write(1, " ", 1);
//		data->fs.wid -= 1;
//	}
//}

void printFloat4(t_pfstruct *data)
{
	if (data->fs.wid > 0)
	{
		signOrSpace(data);
		data->pfreturn += ft_putstrcount(data->fs.fnl);
		data->fs.wid -= ft_strlen(data->fs.fnl);
		data->pfreturn += writeChars(data->fs.wid, ' ');
	}
	else
	{
		data->fs.wid = md(data->fs.wid);
		signOrSpace(data);
		data->pfreturn += ft_putstrcount(data->fs.fnl);
		data->fs.wid += ft_strlen(data->fs.fnl);
		data->pfreturn += writeChars(md(data->fs.wid), ' ');
	}
}

void printFloat3(t_pfstruct *data)
{
	if (data->fs.flag.zero)
	{
		signOrSpace(data);
		data->pfreturn += writeChars(data->fs.wid - \
			(int)ft_strlen(data->fs.fnl), '0');
		data->pfreturn += ft_putstrcount(data->fs.fnl);
	}
	else
	{
		if (data->fs.flag.space && !data->fs.sign)
		{
			data->pfreturn += write(1, " ", 1);
			data->fs.wid -= 1;
		}
		data->pfreturn = writeChars(data->fs.wid - \
			ft_strlen(data->fs.fnl) - (data->fs.sign ? 1 : 0), ' ');
		if (data->fs.sign)
		{
			data->pfreturn += write(1, &data->fs.sign, 1);
			data->fs.wid -= 1;
		}
		data->pfreturn += ft_putstrcount(data->fs.fnl);
	}
}

void printFloat2(t_pfstruct *data)
{
	precisionZero(data);
	if (data->fs.wid == 0)
	{
		if (data->fs.sign)
			data->pfreturn += write(1, &data->fs.sign, 1);
		else if (data->fs.flag.space)
			data->pfreturn += write(1, " ", 1);
		data->pfreturn += ft_putstrcount(data->fs.fnl);
	} else
	{
		if (data->fs.flag.minus || data->fs.wid < 0)
			printFloat4(data);
		else
			printFloat3(data);
	}
}

//void printFloat2(t_pfstruct *data)
//{
//
//
//
//}