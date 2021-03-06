/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wildcard.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nerraou <nerraou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 08:54:05 by obelkhad          #+#    #+#             */
/*   Updated: 2022/07/05 15:36:32 by nerraou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

bool	**allocat_lookup(bool	**lookup, int n, int m)
{
	int	i;

	i = 0;
	lookup = (bool **)malloc(sizeof(bool *) * (n + 1));
	while (i <= n)
	{
		lookup[i] = (bool *)malloc(sizeof(bool) * (m + 1));
		ft_memset(lookup[i], false, sizeof(lookup[i]));
		i++;
	}
	lookup[0][0] = true;
	return (lookup);
}

bool	wildcard_match(char *file, char *pattern, int n, int m)
{
	int		i;
	int		j;
	bool	**lookup;

	j = 0;
	lookup = NULL;
	lookup = allocat_lookup(lookup, n, m);
	while (++j <= m)
	{
		if (pattern[j - 1] == '*')
			lookup[0][j] = lookup[0][j - 1];
	}
	i = 0;
	while (++i <= n)
	{
		j = 0;
		while (++j <= m)
		{
			if (file[i - 1] == pattern[j - 1])
				lookup[i][j] = lookup[i - 1][j - 1];
			else if (pattern[j - 1] == '*')
				lookup[i][j] = (lookup[i][j - 1] || lookup[i - 1][j]);
		}
	}
	return (free_lookup(lookup, n, m));
}

void	join_files(t_wild *match, char *dire_name, t_element *elm, int *i)
{
	t_token		*token;
	char		*holder;
	bool		wild;

	token = (t_token *)elm->content;
	token->type = T_WILDCARD;
	wild = wildcard_match(dire_name, token->value, ft_strlen(dire_name), \
	ft_strlen(token->value));
	if ((wild && dire_name[0] != '.') || (wild && token->value[0] == '.'))
	{
		*i = 1;
		if (match->all_matches)
		{
			match->holder = ft_strdup(match->all_matches);
			free(match->all_matches);
		}
		holder = ft_strdup(dire_name);
		match->file = ft_strjoin(holder, " ");
		free (holder);
		match->all_matches = ft_strjoin(match->holder, match->file);
		if (match->holder)
			free(match->holder);
		if (match->file)
			free(match->file);
	}
}

void	update_free(t_element *elm, t_wild *match, int i)
{
	update_element(elm, match, i);
	free(match->all_matches);
}

void	wildcard_expand(t_element *l_cmd, t_token *token, t_element *elm)
{
	struct dirent	*dire;
	t_wild			match;
	int				i;
	DIR				*dir;

	i = 0;
	while (elm && elm->prev != l_cmd)
	{
		token = (t_token *)elm->content;
		if (is_wildcard(elm) > -1 && token->type == T_WORD && dir)
		{
			dir = opendir(".");
			dire = readdir(dir);
			init_wild(&match);
			while (dire)
			{
				join_files(&match, dire->d_name, elm, &i);
				dire = readdir(dir);
			}
			update_free(elm, &match, i);
			closedir(dir);
		}
		elm = elm->next;
	}
}
