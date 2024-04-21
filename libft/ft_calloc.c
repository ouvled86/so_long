/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouel-bou <ouel-bou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 23:35:51 by ouel-bou          #+#    #+#             */
/*   Updated: 2023/11/15 06:03:37 by ouel-bou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	char	*ptr;
	size_t	i;

	i = 0;
	if ((int)count < 0 && (int)size < 0)
		return (NULL);
	ptr = malloc(size * count);
	if (!ptr)
		return (NULL);
	while (i < (size * count))
	{
		ptr[i] = 0;
		i++;
	}
	return (ptr);
}
