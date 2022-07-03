/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelkhad <obelkhad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 14:49:39 by nerraou           #+#    #+#             */
/*   Updated: 2022/07/01 19:38:39 by obelkhad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

static int set_string(const char *str, t_list *list)
{
	int len;
	len = set_d_string(str, list);
	if (len == -1)
		len = set_s_string(str, list);
	return (len);
}

static int set_symboles(const char *str, t_list *list)
{
	int len;

	len = 0;
	len = set_l_parenth(str, list);
	if (len == -1)
		len = set_r_parenth(str, list);
	if (len == -1)
		len = set_or(str, list);
	if (len == -1)
		len = set_and(str, list);
	if (len == -1)
		len = set_dless(str, list);
	if (len == -1)
		len = set_dgreat(str, list);
	if (len == -1)
		len = set_great(str, list);
	if (len == -1)
		len = set_less(str, list);
	if (len == -1)
		len = set_pipe(str, list);
	return (len);
}

void lexer(const char *str, t_list *list)
{
	int i;
	int len;

	i = 0;
	while (str[i])
	{
		i += ft_skip_spaces(str + i);
		len = set_string(str + i, list);
		if (len == -1)
			len = set_symboles(str + i, list);
		if (len == -1)
		{
			len = set_newline(str + i, list);
			if (len != -1)
				break;
		}
		if (len == -1)
			len = set_word(str + i, list);
		if (str[i] && len == -1)
			i++;
		else if (str[i])
			i += len;
	}
}
