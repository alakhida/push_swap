/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alakhida <alakhida@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 14:09:58 by alakhida          #+#    #+#             */
/*   Updated: 2022/11/04 01:02:34 by alakhida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*
** Applies the function 'f' to each character of the string 's' to create a new string,
** passing its index as the first argument and the character as the second.
** Returns the new string created by successive applications of 'f'.
** Returns NULL if allocation fails or if 's' or 'f' is NULL.
*/
#include "libft.h"

char	*ft_strmapi(char const *s, char (*f) (unsigned int, char))
{
	size_t				i;
	size_t				len;
	char				*result;

	i = 0;
	if (!s || !f)
		return (0);
	len = ft_strlen(s);
	result = (char *)malloc(sizeof(char) * (len + 1));
	if (!result)
		return (0);
	while (i < len)
	{
		result[i] = f(i, s[i]);
		i++;
	}
	result[i] = '\0';
	return (result);
}

// char f(unsigned int  x, char f)
// {
// 	return('r');
// }
// int main()
// {
// 	char *r  = ft_strmapi("ayoub", f);
// 	printf("%s\n", r);
// }