/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhanitra <rhanitra@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 10:37:29 by rhanitra          #+#    #+#             */
/*   Updated: 2024/08/15 10:38:12 by rhanitra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

size_t	ft_strlen(const char *str);
size_t	check_new_line(char *buffer);
size_t	check_back_slash_n(const char *s, int c);

char	*putline(char *readed_line);
char	*putlast(char *readed_line);
char	*ft_strjoin_gnl(char *old_str, char *buffer, size_t size);
char	*read_line(int fd, int *check, char *buffer, char *readed_line);
char	*get_next_line(int fd);

#endif
