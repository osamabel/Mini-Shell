/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shlvl.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelkhad <obelkhad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 11:26:11 by obelkhad          #+#    #+#             */
/*   Updated: 2022/06/09 18:56:41 by obelkhad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*get_env_value(char	*env, char **envp, int *i)
{
	int j;

	if (i)
	{
		*i = 0;
		while (envp && envp[*i] && ft_strncmp(env, envp[*i], ft_strlen(env)))
			(*i)++;
		if (envp[*i])
			return (envp[*i] + ft_strlen(env));
	}
	else
	{
		j = 0;
		while (envp && envp[j] && ft_strncmp(env, envp[j], ft_strlen(env)))
			(j)++;
		if (envp[*i])
			return (envp[j] + ft_strlen(env));
	}
	return (env);
}

void	update_shlvl(char **envp)
{
	int	i;
	int	lvl;

	i = 0;
	while (envp && envp[i])
	{
		envp[i] = ft_strdup(envp[i]);
		i++;
	}
	lvl = ft_atoi(get_env_value("SHLVL=", envp, &i));
	lvl++;
	free(envp[i]);
	envp[i] = ft_strdup(ft_strjoin("SHLVL=", ft_itoa(lvl)));
}