/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isnumb.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaze <tmaze@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/17 15:00:23 by tmaze             #+#    #+#             */
/*   Updated: 2019/07/12 12:09:41 by tmaze            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isnumb(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if ((i == 0 && str[i] != '-' && str[i] != '+' && !ft_isdigit(str[i]))
			|| (i != 0 && !ft_isdigit(str[i])))
			return (0);
		i++;
	}
	return (1);
}
