/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_placeholder.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youncho <youncho@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/02 16:13:49 by youncho           #+#    #+#             */
/*   Updated: 2021/02/10 23:58:07 by youncho          ###   ########.fr       */
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



int		print_p(t_placeholder *state, ULL ptr)
{
	int		len;
	char	*str;
	int		plen;

	str = get_base_str(ptr, BASE16L);
	len = ft_strlen(str) + 1;
	plen = state->precision - (len - 1);
	plen = plen < 0 ? 0 : plen;
	while (!state->align && ++len < state->width)
		ft_putchar_fd(' ', 1);
	ft_putstr_fd("0x", 1);
	while (state->fill && !state->align && ++len < state->width)
		ft_putchar_fd('0', 1);
	while (plen--)
	{
		ft_putchar_fd('0', 1);
		len++;
	}
	ft_putstr_fd(str, 1);
	while (state->align && ++len < state->width)
		ft_putchar_fd(' ', 1);
	free(str);
	return (len);
}

int		print_ux(t_placeholder *state, ULL num, char *base)
{
	int		len;
	char	*str;
	int		plen;

	str = get_base_str(num, base);
	len = ft_strlen(str) - 1;
	plen = state->precision - (len + 1);
	plen = plen < 0 ? 0 : plen;
	while (!state->align && ++len < state->width - plen)
		ft_putchar_fd(state->fill ? '0' : ' ', 1);
	while (plen--)
		ft_putchar_fd('0', 1 && len++);
	ft_putstr_fd(str, 1);
	while (state->align && ++len < state->width)
		ft_putchar_fd(' ', 1);
	free(str);
	return (len);
}

int		print_di(t_placeholder *state, LL num)
{
	int		len;
	char	*str;
	int		plen;

	len = num < 0 ? 1 : 0;
	str = get_base_str(num < 0 ? -num : num, BASE10);
	plen = state->precision - ft_strlen(str);
	plen = plen < 0 ? 0 : plen;
	len += ft_strlen(str);
	while (!state->align && len < state->width - plen)
		ft_putchar_fd(state->fill ? '0' : ' ', 1 && ++len);
	if (num < 0)
		ft_putchar_fd('-', 1);
	while (plen--)
		ft_putchar_fd('0', 1 && ++len);
	ft_putstr_fd(str, 1);
	while (state->align && len < state->width)
		ft_putchar_fd(' ', 1 && ++len);
	free(str);
	return (len);
}

