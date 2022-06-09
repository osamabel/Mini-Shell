/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expanding.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelkhad <obelkhad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 14:11:17 by obelkhad          #+#    #+#             */
/*   Updated: 2022/06/09 18:57:57 by obelkhad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	dollar_handling(t_list *list, char **envp)
{
	(void) envp;
	t_element	*elm;
	t_token		*token;
	char		*buffer;
	int			i;
	int			j;

	buffer = NULL;
	elm = list->head;
	while (elm)
	{
		token = (t_token *)elm->content;
		i = 0;
		while (token->value[i] && token->value[i] != '$')
			i++;
		if (token->value[i] == '$' && token->value[i + 1])
		{
			i++;
			if (token->type == 2)
				return ;
			if (token->type == 1 || !token->type)
			{
				j = i;
				while (ft_isalnum(token->value[j]))
					j++;
			}
		}

		elm = elm->next;
	}
}

void	expanding(t_list *list, char **envp)
{
	dollar_handling(list, envp);
}