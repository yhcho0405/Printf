/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youncho <youncho@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/28 17:10:17 by youncho           #+#    #+#             */
/*   Updated: 2021/01/31 16:13:23 by youncho          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		find_char(char c, const char *set)
{
	while (*set)
	{
		if (c == *set)
			return (TRUE);
		set++;
	}
	return (FALSE);
}

void	parse_flag(const char **format, t_placeholder *state)
{
	if (**format == '-')
		state->align = TRUE;
	else if (**format == '0')
		state->fill = TRUE;
	else
		return ;
	(*format)++;
}

void	parse_width(const char **format, t_placeholder *state, va_list ap)
{
	if (**format == '*')
	{
		state->width = va_arg(ap, int);
		(*format)++;
	}
	else if (ft_isdigit(**format))
	{
		state->width = ft_atoi(*format);
		while (ft_isdigit(**format))
			(*format)++;
	}
}

void	parse_precision(const char **format, t_placeholder *state, va_list ap)
{
	if (**format != '.')
		return ;
	(*format)++;
	if (**format == '*')
	{
		state->precision = va_arg(ap, int);
		(*format)++;
	}
	else if (ft_isdigit(**format))
	{
		state->precision = ft_atoi(*format);
		while (ft_isdigit(**format))
			(*format)++;
	}
}
