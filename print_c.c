/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_c.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youncho <youncho@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/02 16:13:49 by youncho           #+#    #+#             */
/*   Updated: 2021/02/03 10:36:04 by youncho          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		print_c(t_placeholder *state, char c)
{
	int	len;

	len = 0;
	if (state->align)
	{
		ft_putchar_fd(c, 1);
		state->fill = FALSE;
	}
	while (++len < state->width)
		ft_putchar_fd(state->fill ? '0' : ' ', 1);
	if (!state->align)
		ft_putchar_fd(c, 1);
	return (len);
}

int		print_s(t_placeholder *state, char *str)
{
	int len;
	int slen;

	if (!str)
		str = "(null)";
	if (state->precision != -1)
		str = ft_substr(str, 0, state->precision);
	len = ft_strlen(str) - 1;
	if (state->align)
	{
		ft_putstr_fd(str, 1);
		state->fill = FALSE;
	}
	while (++len < state->width)
		ft_putchar_fd(state->fill ? '0' : ' ', 1);
	if (!state->align)
		ft_putstr_fd(str, 1);
	return (len);
}
