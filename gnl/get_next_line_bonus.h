/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhusso <jhusso@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 09:19:48 by jhusso            #+#    #+#             */
/*   Updated: 2022/12/06 11:05:16 by jhusso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>

// main file
char	*read_fd(char *stash, int fd);
char	*find_line(char *stash);
char	*prepare_stash(char *stash);
char	*get_next_line(int fd);

// utils
void	ft_bzero(void *s, size_t n);
char	*ft_strchr(const char *s, int c);
int		ft_strlen(const char *s);
char	*strjoin(char *stash, char *buf);
void	*ft_calloc(size_t count, size_t size);

#endif
