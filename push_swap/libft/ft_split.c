/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alakhida <alakhida@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 16:29:08 by alakhida          #+#    #+#             */
/*   Updated: 2022/10/26 14:52:30 by alakhida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Splits the string 's' into an array of strings using the delimiter 'c'.
   Returns a NULL-terminated array of newly allocated strings.
   If allocation fails, returns NULL. */

#include "libft.h"

// Skips delimiter characters starting from index b
static size_t	schar(const char *s, char c, size_t b)
{
    while (s[b] && s[b] == c)
        b++;
    return (b);
}

// Finds the end index of a word (not delimiter) starting from index l
static size_t	echar(const char *s, char c, size_t l)
{
    while (s[l] && s[l] != c)
        l++;
    return (l);
}

// Counts the number of words separated by delimiter c in string s
static size_t	count(char const *s, char c)
{
    size_t		i;
    size_t		b;
    size_t		cnt;

    i = 0;
    cnt = 0;
    while (i < ft_strlen(s))
    {
        i = schar(s, c, i);
        b = echar(s, c, i);
        if (i < b)
            cnt++;
        i = b;
    }
    return (cnt);
}

// Fills the result array with substrings split by delimiter c
static void	split(char **r, char const *s, char c)
{
    size_t	cnt;
    size_t	i;
    size_t	b;

    i = 0;
    cnt = 0;
    while (s[i])
    {
        i = schar(s, c, i);
        b = echar(s, c, i);
        if (i < b)
            r[cnt++] = ft_substr(s, i, (b - i));
        i = b;
    }
    r[cnt] = NULL;
}

// Main split function
char	**ft_split(char const *s, char c)
{
    char	**rslt;

    if (!s)
        return (NULL);
    rslt = (char **)malloc(sizeof(char *) * (count(s, c) + 1));
    if (!rslt)
        return (NULL);
    split(rslt, s, c);
    return (rslt);
}