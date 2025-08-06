/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alakhida <alakhida@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 18:08:07 by alakhida          #+#    #+#             */
/*   Updated: 2022/10/10 22:15:02 by alakhida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/** Checks if the given character is an alphabetic letter (A-Z or a-z).
** Returns 1 if true, 0 otherwise.
*/

#include "libft.h"

int	ft_isalpha(int c)
{
    if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'))
        return (1);
    return (0);
}