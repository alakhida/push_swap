/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alakhida <alakhida@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 02:29:38 by alakhida          #+#    #+#             */
/*   Updated: 2022/10/11 02:33:28 by alakhida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*convert character c "if it was in lowercase to uppercase"*/
#include "libft.h"

int	ft_toupper(int c)
{
	if (c >= 'a' && c <= 'z')
		return (c - 32);
	return (c);
}
