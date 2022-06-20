/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelkhad <obelkhad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 11:29:46 by obelkhad          #+#    #+#             */
/*   Updated: 2022/06/20 10:52:02 by obelkhad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXECUTE_H
#define EXECUTE_H

typedef struct s_opr_logic
{
	t_element	*f_cmd;
	t_element	*opr_cmd;
	t_element	*l_cmd;
	int			operator;
	t_element	*parent_r;
	t_element	*parent_l;
} t_opr_logic;

typedef struct s_cmd
{
	char	*cmd;
	char	*cmd_name;
	char	**args;
	int		executable;
} t_cmd;

void	execut(t_list *list, char **envp);
void	expanding(t_element *f_cmd, t_element *l_cmd, char **envp);
char	*get_env_value(char	*env, char **envp);
int		check_env(char	*vrb, char **envp);
void	cmd_execut(t_element *f_cmd, t_element *l_cmd, char **envp,  t_list *heredoc_list);
void	priority_handling(t_element *f_cmd, t_element *l_cmd, char **envp, t_list *heredoc_list);
void	divide_by_last_operator(t_opr_logic *opertor);
void	join_pieces(t_element *f_cmd, t_element *l_cmd);

#endif