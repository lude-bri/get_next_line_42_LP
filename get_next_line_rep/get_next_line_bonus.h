/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lude-bri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 09:33:42 by lude-bri          #+#    #+#             */
/*   Updated: 2024/05/17 10:00:25 by lude-bri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*DEFINING LIBRARY*/

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

/*DEFINING BUFFER_SIZE*/
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

# define MAX_FD 1024

/*LIBRARIES INCLUDE*/

# include <stdio.h>
# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>

/*FUNCTIONS*/

/*get_next_line functions*/

char	*get_next_line(int fd);
char	*fill_line(int fd, char *raw);
char	*line_to_clean(char *raw);
char	*get_rest(char *raw);

/*Aux functions*/

char	*ft_strchr(char *str, int c);
char	*ft_strjoin(char *s1, char *s2);
int		ft_strlen(char *str);

#endif
