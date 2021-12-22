/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsaeed <rsaeed@student.42abudhabi.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/27 11:39:18 by rsaeed            #+#    #+#             */
/*   Updated: 2021/09/29 14:04:33 by rsaeed           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
#include <stdlib.h>

static int	get_size(long n)
{
	int		size;

	size = 1;
	while (n > 9)
	{
		size++;
		n /= 10;
	}
	return (size);
}

static long	get_multiplier(int size)
{
	long	mult;

	mult = 1;
	while (size > 1)
	{
		mult *= 10;
		size--;
	}
	return (mult);
}

static int	check_negative(long *n, char **string, int *i)
{
	int		is_negative;
	int		size;

	is_negative = 0;
	if (*n < 0)
	{
		*n = *n * -1;
		*i = *i + 1;
		is_negative = 1;
	}
	size = get_size(*n);
	if (is_negative)
		size++;
	*string = (char *)malloc(sizeof(char) * (size + 1));
	if (!*string)
		return (0);
	if (is_negative)
	{
		*string[0] = '-';
		return (size - 1);
	}
	return (size);
}

char	*ft_itoa(int n)
{
	char	*string;
	long	multiplier;
	long	copy;
	int		size;
	int		i;

	size = 1;
	i = 0;
	copy = (long)n;
	size = check_negative(&copy, &string, &i);
	if (!string)
		return (0);
	while (size > 0)
	{
		multiplier = get_multiplier(size);
		string[i] = copy / multiplier + '0';
		copy = copy - (multiplier * (string[i] - '0'));
		size--;
		i++;
	}
	string[i] = '\0';
	return (string);
}
