/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alakhida <alakhida@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 22:44:31 by alakhida          #+#    #+#             */
/*   Updated: 2022/11/03 23:12:38 by alakhida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Allocates memory for an array of 'count' elements of 'size' bytes each,
** and initializes all bytes in the allocated storage to zero.
** Returns a pointer to the allocated memory, or NULL if allocation fails.
*/

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
    char	*dst;
    size_t	total;
    size_t	i;

    total = count * size;
    dst = malloc(total);
    if (!dst)
        return (NULL);
    i = 0;
    while (i < total)
    {
        dst[i] = 0;
        i++;
    }
    return ((void *)dst);
}