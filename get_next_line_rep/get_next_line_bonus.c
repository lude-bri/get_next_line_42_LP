/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lude-bri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 09:32:43 by lude-bri          #+#    #+#             */
/*   Updated: 2024/05/17 11:01:02 by lude-bri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

/*1.get_next_line */
char	*get_next_line(int fd)
{
	char			*line;
	static char		*raw_line[MAX_FD];

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!raw_line[fd])
	{
		raw_line[fd] = malloc(1);
		raw_line[fd][0] = '\0';
	}
	raw_line[fd] = fill_line(fd, raw_line[fd]);
	if (!raw_line[fd])
		return (NULL);
	line = line_to_clean(raw_line[fd]);
	raw_line[fd] = get_rest(raw_line[fd]);
	return (line);
}

/*2. fill_line */
char	*fill_line(int fd, char *raw)
{
	char	*buffer;
	int		bytes_read;

	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	bytes_read = 1;
	while (bytes_read != 0)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read <= 0)
		{
			free(buffer);
			if (raw)
				return (raw);
			free(raw);
			return (NULL);
		}
		buffer[bytes_read] = '\0';
		raw = ft_strjoin(raw, buffer);
		if (ft_strchr(raw, '\n'))
			break ;
	}
	free(buffer);
	return (raw);
}

/*3. line_to_clean */
char	*line_to_clean(char *raw)
{
	int		i;
	char	*line;

	i = 0;
	if (!*raw)
		return (NULL);
	while (raw[i] != '\0' && raw[i] != '\n')
		i++;
	line = malloc(sizeof(char) * (i + 2));
	if (!line)
		return (NULL);
	i = 0;
	while (raw[i] != '\0' && raw[i] != '\n')
	{
		line[i] = raw[i];
		i++;
	}
	if (raw[i] == '\n')
	{
		line[i] = raw[i];
		i++;
	}
	line[i] = '\0';
	return (line);
}

/*4. get_rest */
char	*get_rest(char *raw)
{
	int		i;
	int		j;
	char	*rest;

	i = 0;
	while (raw[i] != '\0' && raw[i] != '\n')
		i++;
	if (!raw[i])
	{
		free(raw);
		return (NULL);
	}
	rest = malloc(sizeof(char) * (ft_strlen(raw) - i + 1));
	if (!rest)
		return (NULL);
	i++;
	j = 0;
	while (raw[i])
		rest[j++] = raw[i++];
	free(raw);
	rest[j] = '\0';
	return (rest);
}
