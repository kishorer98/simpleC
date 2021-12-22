/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsaeed <rsaeed@student.42abudhabi.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 12:25:56 by rsaeed            #+#    #+#             */
/*   Updated: 2021/10/06 14:12:16 by rsaeed           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t				i;
	unsigned char		*a;
	const unsigned char	*b;

	i = 0;
	if (dst == NULL && src == NULL)
		return (NULL);
	a = (unsigned char *)dst;
	b = (const unsigned char *)src;
	if (b < a)
	{
		i++;
		while (i <= len)
		{
			a[len - i] = b[len - i];
			i++;
		}
	}
	else
		ft_memcpy(a, b, len);
	return (dst);
}
