/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit_by_substring.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juazouz <juazouz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/29 19:27:54 by juazouz           #+#    #+#             */
/*   Updated: 2018/10/29 19:27:54 by juazouz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		get_word_len(char *str, char *delimiter)
{
	char	*substr;

	substr = ft_strstr(str, delimiter);
	if (substr == NULL)
		return (ft_strlen(str));
	return (substr - str);
}

static int		get_word_count(char *str, char *delimiter)
{
	int word_len;
	int n;
	int i;

	n = 0;
	i = 0;
	while (str[i] != '\0')
	{
		word_len = get_word_len(str, delimiter);
		if (word_len > 0)
		{
			n++;
			i += word_len;
		}
		else
		{
			i++;
		}
	}
	return (i);
}

static int		try_create_word(char *str, char *delimiter, char **word, int *word_len)
{
	*word_len = get_word_len(str, delimiter);
	if (*word_len > 0)
	{
		// malloc control here
		*word = malloc((*word_len) + 1);
		ft_strncpy(*word, str, (*word_len));
		*((*word) + (*word_len)) = '\0';
		return (1);
	}
	return (0);
}

char			**ft_strsplit_by_substring(char *str, char *delimiter)
{
	int		i;
	int		word_count;
	int		word_len;
	char	**result;

	word_count = get_word_count(str, delimiter);
	result = malloc(sizeof(char*) * (word_count + 1));
	if (result == NULL)
		return (NULL);
	i = 0;
	word_count = 0;
	while (str[i] != '\0')
	{
		if (try_create_word(&str[i], delimiter, &result[word_count], &word_len))
		{
			word_count++;
			i += word_len;
		}
		else
			i++;
	}
	result[word_count] = 0;
	return (result);
}
