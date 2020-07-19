
#include "ft_printf.h"

char      *mul(char *s1)
{
	int       i;
	char   *result;
	int       carry;
	int       mul;

	carry = 0;
	result = ft_strnew(0);
	i = ft_strlen(s1) - 1;
	while (i >= 0)
	{
		mul = ((s1[i] - '0') * 5) + carry;
		if (mul >= 10)
		{
			carry = mul / 10;
			mul = mul - (carry * 10);
		}
		else
			carry = 0;
		result = ft_strjoin(ft_itoa(mul), result);
		i = i - 1;
	}
	if (carry)
		result = ft_strjoin(ft_itoa(carry), result);
	return result;
}

char      *multOnHalf(char *s1)
{
	int       i;
	char   *result;
	char   *str;

	result = mul(s1);
	i = ft_strlen(s1);
	if (((int)ft_strlen(result) < (i + 1)) && (i != 1))
	{
		str = (char *)malloc(sizeof(char) * (i - ft_strlen(result) + 2));
		str[i - ft_strlen(result) + 2] = '\0';
		ft_memset(str, '0', i - ft_strlen(result) + 1);
		result = ft_strjoin(str, result);
	}
	return result;
}

int          ft_abs(int a, int b)
{
	if (a > b)
		return (a - b);
	else
		return (b - a);
}

char      *power2(int pow)
{
	char   *ans;

	pow--;
	ans = "5";
	while (pow != 0)
	{
		ans = multOnHalf(ans);
		pow--;
	}
	return ans;
}
