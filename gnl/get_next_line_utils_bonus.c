/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhusso <jhusso@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 09:20:00 by jhusso            #+#    #+#             */
/*   Updated: 2022/12/06 11:03:05 by jhusso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

void	ft_bzero(void *s, size_t n)
{
	while (n-- > 0)
		*((char *)(s + n)) = 0;
}

char	*ft_strchr(const char *s, int c)
{
	while (*s != '\0')
	{
		if (*s == (char)c)
			return ((char *)s);
		s++;
	}
	if (c == '\0')
		return ((char *)s);
	return (NULL);
}

int	ft_strlen(const char *s)
{
	int	count;

	count = 0;
	if (s == 0 || !s)
		count = 0;
	if (*s)
	{
		while (s[count] != '\0')
			count++;
	}
	return (count);
}

char	*strjoin(char *stash, char *buf)
{
	char	*r;
	int		i;
	int		j;
	int		len;

	if (!buf)
		return (0);
	len = ft_strlen(stash) + ft_strlen(buf);
	r = (char *)malloc(sizeof(char) * (len + 1));
	if (!r)
		return (NULL);
	i = 0;
	while (stash[i])
	{
		r[i] = stash[i];
		i++;
	}
	j = 0;
	while (buf[j])
		r[i++] = buf[j++];
	r[len] = '\0';
	free (stash);
	stash = NULL;
	return (r);
}

void	*ft_calloc(size_t count, size_t size)
{
	void	*ptr;

	if (count == 0 || size == 0)
	{
		ptr = malloc(1);
		if (!ptr)
			return (NULL);
		return (ptr);
	}
	if (count * size / size != count)
		return (NULL);
	ptr = (char *)malloc(count * size);
	if (!ptr)
		return (NULL);
	ft_bzero(ptr, (size * count));
	return (ptr);
}
