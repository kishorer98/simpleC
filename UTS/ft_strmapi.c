/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsaeed <rsaeed@student.42abudhabi.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/27 11:40:15 by rsaeed            #+#    #+#             */
/*   Updated: 2021/09/29 14:08:52 by rsaeed           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
#include <stdlib.h>

char	*ft_strmapi(const char *s, char (*f)(unsigned int, char))
{
	int		i;
	int		size;
	char	*string;

	if (!s)
		return (0);
	size = ft_strlen(s);
	string = (char *)malloc(sizeof(char) * (size + 1));
	if (!string)
		return (0);
	i = 0;
	while (s[i] != '\0')
	{
		string[i] = f(i, s[i]);
		i++;
	}
	string[i] = '\0';
	return (string);
}
