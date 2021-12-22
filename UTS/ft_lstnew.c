/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsaeed <rsaeed@student.42abudhabi.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/27 11:45:48 by rsaeed            #+#    #+#             */
/*   Updated: 2021/10/06 10:42:08 by rsaeed           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

t_list	*ft_lstnew(void *content)
{
	t_list		*list;

	list = (t_list *)malloc(sizeof(*list));
	if (list == NULL)
		return (NULL);
	list->next = NULL;
	list->content = content;
	return (list);
}
