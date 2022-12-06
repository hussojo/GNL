/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhusso <jhusso@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 09:16:45 by jhusso            #+#    #+#             */
/*   Updated: 2022/12/06 09:39:51 by jhusso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*read_fd(char *stash, int fd)
{
	char	*buf;
	int		read_bytes;

	buf = (char *)ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (!buf)
		return (NULL);
	read_bytes = 1;
	while (!(ft_strchr(stash, '\n')) && read_bytes != 0)
	{
		read_bytes = read(fd, buf, BUFFER_SIZE);
		if (read_bytes == -1)
		{
			free(buf);
			buf = NULL;
			free(stash);
			stash = NULL;
			return (NULL);
		}
		buf[read_bytes] = '\0';
		stash = strjoin(stash, buf);
	}
	free(buf);
	buf = NULL;
	return (stash);
}

char	*find_line(char *stash)
{
	char	*output;
	int		i;

	i = 0;
	if (!stash[i])
		return (NULL);
	i = ft_strlen(stash);
	while (stash[i] != '\n' && stash[i])
		i++;
	output = ft_calloc(i + 2, sizeof(char));
	if (!output)
		return (NULL);
	i = 0;
	while (stash[i] != '\n' && stash[i])
	{
		output[i] = stash[i];
		i++;
	}
	if (stash[i] == '\n')
		output[i] = '\n';
	output[i + 1] = '\0';
	return (output);
}

char	*prepare_stash(char *stash)
{
	char	*temp;
	int		i;
	int		j;

	i = 0;
	while (stash[i] && stash[i] != '\n')
		i++;
	if (!stash[i])
	{
		free(stash);
		stash = NULL;
		return (NULL);
	}
	temp = ft_calloc(ft_strlen(stash) - i + 1, sizeof (char));
	if (!temp)
		return (NULL);
	i++;
	j = 0;
	while (stash[i])
		temp[j++] = stash[i++];
	temp[j] = '\0';
	free(stash);
	stash = NULL;
	return (temp);
}

char	*get_next_line(int fd)
{
	static char	*stash[OPEN_MAX];
	char		*output;

	if (fd < 0 || read(fd, 0, 0) < 0 || BUFFER_SIZE < 0)
		return (NULL);
	if (!stash[fd])
	{
		stash[fd] = ft_calloc(1, 1);
		if (!stash[fd])
			return (NULL);
		stash[fd][0] = '\0';
	}
	stash[fd] = read_fd(stash[fd], fd);
	if (!stash[fd])
		return (NULL);
	output = find_line(stash[fd]);
	stash[fd] = prepare_stash(stash[fd]);
	return (output);
}
