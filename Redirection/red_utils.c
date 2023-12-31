/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   red_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkmon <gkmon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 08:06:19 by gkmon             #+#    #+#             */
/*   Updated: 2023/06/19 14:03:01 by gkmon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	ft_strlen_without(char *str, char *set)
{
	int	i;
	int	len;

	i = 0;
	len = 0;
	while (str[i])
	{
		if (!ft_in(str[i], set))
			len++;
		i++;
	}
	return (len);
}

char	*ft_null_to_str(char *ptr)
{
	if (!ptr)
		ptr = ft_strdup("");
	return (ptr);
}

int	ft_fill_red(t_shell *shell)
{
	int	i;

	i = 0;
	while (i < shell->n_cmds)
	{
		shell->red.infiles[i] = ft_null_to_str(shell->red.infiles[i]);
		if (!shell->red.infiles[i])
			ft_die(shell, 1, 12);
		shell->red.outfiles[i] = ft_null_to_str(shell->red.outfiles[i]);
		if (!shell->red.outfiles[i])
			ft_die(shell, 1, 12);
		shell->red.afiles[i] = ft_null_to_str(shell->red.afiles[i]);
		if (!shell->red.afiles[i])
			ft_die(shell, 1, 12);
		i++;
	}
	return (0);
}

int	ft_intab(char *str, char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		if (!ft_strcmp(str, tab[i]))
			return (1);
		i++;
	}
	return (0);
}
