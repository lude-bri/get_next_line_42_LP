/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lude-bri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 09:33:11 by lude-bri          #+#    #+#             */
/*   Updated: 2024/05/17 09:52:56 by lude-bri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

//Aux functions
// 1. STRCHR
// 2. STRJOIN
// 3. STRLEN

/*STRCHR*/
char	*ft_strchr(char *s, int c)
{
	int			i;
	char		cc;

	i = 0;
	cc = (char)c;
	while (s[i])
	{
		if (s[i] != cc)
			i++;
		else
			return ((char *) &s[i]);
	}
	if (s[i] == cc)
		return ((char *) &s[i]);
	else
		return (NULL);
}

/*STRJOIN*/
char	*ft_strjoin(char *s1, char *s2)
{
	int		i;
	char	*tmp;
	char	*new;

	i = 0;
	if (!*s1)
		*s1 = '\0';
	if (!s1 || !s2)
		return (NULL);
	tmp = s1;
	new = malloc((ft_strlen(s1) + ft_strlen(s2)+ 1) * sizeof(char));
	if (!new)
		return (NULL);
	if (s1)
		while (*s1)
			new[i++] = *s1++;
	while (*s2)
		new[i++] = *s2++;
	new[i] = '\0';
	if (tmp)
		free(tmp);
	return (new);
}

/*STRLEN*/
int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
		i++;
	return (i);
}
