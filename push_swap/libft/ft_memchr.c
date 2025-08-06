/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alakhida <alakhida@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 23:42:40 by alakhida          #+#    #+#             */
/*   Updated: 2022/10/17 23:45:53 by alakhida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*Scans the initial n bytes of the memory area pointed to by s
for the first occurrence of the character c.
Returns a pointer to the matching byte, or NULL if the character does not occur.
*/

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
    size_t			i;
    unsigned char	*ps;

    ps = (unsigned char *)s;
    i = 0;
    while (i < n)
    {
        if (*ps == (unsigned char)c)
            return ((void *)ps);
        ps++;
        i++;
    }
    return (NULL);
}