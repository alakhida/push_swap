/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alakhida <alakhida@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/02 11:53:33 by alakhida          #+#    #+#             */
/*   Updated: 2022/10/12 21:45:51 by alakhida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Checks if the given character is alphanumeric.
** Returns 1 if the character is a letter (A-Z, a-z) or a digit (0-9), 0 otherwise.
*/

#include "libft.h"

int	ft_isalnum(int c)
{
    if ((c >= '0' && c <= '9') ||
        (c >= 'A' && c <= 'Z') ||
        (c >= 'a' && c <= 'z'))
        return (1);
    return (0);
}