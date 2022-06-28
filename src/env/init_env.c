/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_env.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelkhad <obelkhad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 17:02:03 by nerraou           #+#    #+#             */
/*   Updated: 2022/06/28 15:08:41 by obelkhad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

t_list *init_env(char *env_arr[])
{
	t_list *env_list;
	t_env *env;
	int i;

	env_list = list_new();
	i = 0;
	while (env_arr[i])
	{
		env = new_env(env_arr[i]);
		add_back(env_list, env);
		i++;
	}
	return (env_list);
}