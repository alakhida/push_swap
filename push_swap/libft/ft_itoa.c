/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alakhida <alakhida@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 14:59:37 by alakhida          #+#    #+#             */
/*   Updated: 2022/11/03 23:54:11 by alakhida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


/* Converts an integer to its string representation.
 Handles negative numbers and zero.
 Returns a pointer to the newly allocated string, or NULL if allocation fails.
*/

#include "libft.h"

// Helper function to calculate the length of the string needed for the integer
size_t	get_len(int n)
{
    size_t	len;

    if (n == 0)
        return (1);
    len = 0;
    if (n < 0)
        len++; // For the minus sign
    while (n)
    {
        n /= 10;
        len++;
    }
    return (len);
}

char	*ft_itoa(int n)
{
    size_t		len;
    char		*result;
    long		nbr;

    nbr = n;
    len = get_len(nbr);
    result = (char *)malloc(len + 1);
    if (!result)
        return (NULL);
    result[len] = '\0';
    len--;

    // Handle zero case
    if (nbr == 0)
        result[0] = '0';

    // Handle negative numbers
    if (nbr < 0)
    {
        result[0] = '-';
        nbr = -nbr;
    }

    // Fill in the digits from the end
    while (nbr)
    {
        result[len] = '0' + (nbr % 10);
        nbr = nbr / 10;
        len--;
    }
    return (result);
}