/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alakhida <alakhida@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 21:34:09 by alakhida          #+#    #+#             */
/*   Updated: 2022/10/18 01:39:22 by alakhida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*The  strnstr() function locates the first occurrence of the null-terminated string little in
  the string big, where not more than len characters are searched.  Characters that appear af‐
  ter a ‘\0’ character are not searched.
*/

#include "libft.h"

char	*ft_strnstr(const char *h, const char *n, size_t l)
{
	size_t		i;
	char		*bptr;
	char		*lptr;

	if (!*n)
		return ((char *)h);
	while (l-- && *h)
	{
		if (*h == *n)
		{
			i = l;
			bptr = (char *)h + 1;
			lptr = (char *)n + 1;
			while (i-- && *bptr && *lptr && *lptr == *bptr)
			{
				++lptr;
				++bptr;
			}
			if (*lptr == '\0')
				return ((char *)h);
		}
		h++;
	}
	return (NULL);
}
