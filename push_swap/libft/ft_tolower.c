/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alakhida <alakhida@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 02:34:18 by alakhida          #+#    #+#             */
/*   Updated: 2022/10/11 02:37:23 by alakhida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*convert character c "if it was in upper case" to lower case*/
#include "libft.h"

int	ft_tolower(int c)
{
	if (c >= 'A' && c <= 'Z')
		return (c + 32);
	return (c);
}
