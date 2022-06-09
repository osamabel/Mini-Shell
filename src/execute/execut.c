/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execut.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelkhad <obelkhad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 11:07:11 by obelkhad          #+#    #+#             */
/*   Updated: 2022/06/09 16:53:39 by obelkhad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	execut(t_list *list, char **envp)
{
	t_element *elm;
    t_token *token;
    int i;

    i = 0;

    elm = list->head;
	expanding(list, envp);

	// cmd = expand_cmd(cmd, envp);

	// cmds = elem_new(cmd);
	// pipe_parse(cmd, &cmds);
	// fork_processes(cmds, envp);
	// free(cmd);
	// check_empty_line();
	while (elm)
    {
        token = (t_token *)elm->content;
        printf("(%d) [ %s ] [%d]\n", i,token->value, token->type);
        elm = elm->next;
    }
}