#include "../includes/ft_solve.h"

char	*ft_itoa(int n)
{
	int		tmp;
	int		len;
	char	*ret;

	tmp = n;
	len = 0;
	ret = NULL;
	while (tmp)
	{
		len++;
		tmp /= 10;
	}
	if (n == 0)
		len = 1;
	if (!(ret = (char *)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	ret[len] = '\0';
	if (n == 0)
		ret[0] = '0';
	else
	{
		while (--len >=0 && n)
		{
			ret[len] = (n % 10) + '0';
			n /= 10;
		}
	}
	return (ret);
}

int		ft_isnum(char c)
{
	if (c >= '0' || c <= '9')
		return (1);
	return (0);
}

int		ft_islower(char c)
{
	if (c >= 'a' && c <= 'z')
		return (1);
	return (0);
}

int		ft_issign(char c, char compare)
{
	if (c == compare)
		return (1);
	return (0);
}

int		ft_strlen(const char *str)
{
	int		len;

	if (!str)
		return (0);
	len = 0;
	while (*str)
	{
		len++;
		str++;
	}
	return (len);
}