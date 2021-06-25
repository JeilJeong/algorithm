#include "../includes/ft_solve.h"

char	*ft_parse_file(char *str)
{
	int		i;
	int		len;

	if (!str)
		return (NULL);
	len = ft_strlen(str);
	i = 0;
	while (ft_islower(str[i]) && i < len)
		i++;
	if (i < len)
	{
		free(str);
		str = NULL;
		return (NULL);
	}
	return (str);
}

char	*ft_parse_version(char *str)
{
	int		len;
	char	*cpy_str;

	if (!str)
		return (NULL);
	len = ft_strlen(str);
	// version 검사
	if (len > 3)
	{
		if ((ft_isnum(str[len - 1]) && (ft_issign(str[len - 2], 'v') && (ft_issign(str[len - 3], '_')))))
		{
			// cpy_str 공간 할당
			if (!(cpy_str = (char *)malloc(sizeof(char) * (len - 2))))
			{
				// printf("	version: %s\n", str);
				free(str);
				str = NULL;
				return (NULL);
			}
			cpy_str[len - 3] = '\0';
			// version 분리 후 cpy_str에 복사
			cpy_str = ft_memcpy(cpy_str, str, len - 3);			
		}
		else
			return (str);
	}
	else
		return (str);
	free(str);
	str = NULL;
	return (cpy_str);
}

char	*ft_parse_directory(char *str)
{
	int		i;
	int		len;
	int		start;
	int		slash_cnt;
	char	*cpy_str;

	if (!str)
		return (NULL);
	len = ft_strlen(str);
	i = len - 1;
	while (i >= 0 && str[i] != '/')
		i--;
	// directory 0단계 이하이거나 파일명이 없을 때 return 검사
	if (i < 0 || str[len - 1] == '/')
	{
		free(str);
		str = NULL;
		return (NULL);
	}
	// directory 10단계 이상일 때 return 검사
	slash_cnt = 0;
	start = i;
	while (slash_cnt < 12 && i >= 0)
	{
		if (str[i] == '/')
			slash_cnt++;
		i--;
	}
	if (slash_cnt > 11)
	{
		free(str);
		str = NULL;
		return (NULL);
	}
	// cpy_str 공간 할당
	if (!(cpy_str = (char *)malloc(sizeof(char) * (len - start))))
	{
		free(str);
		str = NULL;
		return (NULL);
	}
	cpy_str[len - start - 1] = '\0';
	// directory 분리 후 파일명 복사
	cpy_str = ft_memcpy(cpy_str, &str[start + 1], len - start - 1);
	free(str);
	str = NULL;
	return (cpy_str);
}

char	*ft_parse_extension(const char *str)
{
	int		len;
	char	*cpy_str;

	if (!str)
		return (NULL);
	len = ft_strlen(str);
	// 확장자 분리 & 검사
	if (!(ft_islower(str[len - 1]) || !(ft_issign(str[len - 2], '.'))))
	{
		return (NULL);
	}
	len -= 2;
	// cpy_str 공간 할당
	if (!(cpy_str = (char *)malloc(sizeof(char) *((len) + 1))))
		return (NULL);
	cpy_str[len] = '\0';
	// str을 cpy_str로 복사
	if (!(cpy_str = ft_memcpy(cpy_str, str, len)))
		return (NULL);
	return (cpy_str);
}