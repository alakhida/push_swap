/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alakhida <alakhida@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 22:46:38 by alakhida          #+#    #+#             */
/*   Updated: 2023/04/13 21:48:34 by alakhida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Allocates and returns a new string, which is the result of the concatenation
** of 's1' and 's2'. The memory for the new string is obtained with malloc.
** If 's1' is NULL, it is treated as an empty string.
** The original 's1' is freed after joining.
** Returns the new string, or NULL if allocation fails.
*/

#include "libft.h"

char	*ft_strjoin(char *s1, char *s2)
{
	char	*r;
	size_t	i;
	size_t	j;

	i = 0;
	if (!s1 && !s2)
		return (NULL);
	if (!s1)
	{
		s1 = malloc(1);
		s1[0] = '\0';
	}
	r = ft_calloc(ft_strlen(s1) + ft_strlen(s2) + 1, 1);
	if (r == NULL)
		return (NULL);
	while (s1[i])
	{
		r[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j])
		r[i++] = s2[j++];
	free(s1);
	return (r);
}
