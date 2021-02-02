/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youncho <youncho@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/26 19:02:11 by youncho           #+#    #+#             */
/*   Updated: 2021/02/02 16:02:47 by youncho          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	placeholder_init(t_placeholder *state)
{
	state->align = FALSE;
	state->fill = FALSE;
	state->width = FALSE;
	state->precision = FALSE;
	state->specifier = FALSE;
}

void	print_placeholder(char specifier, va_list ap, t_placeholder	*state)
{
	if (specifier == 'c')
		//
	else if (specifier == 's')
		//
	else if (specifier == 'p')
		//
	else if (specifier == 'd')
		//
	else if (specifier == 'i')
		//
	else if (specifier == 'u')
		//
	else if (specifier == 'x')
		//
	else if (specifier == 'X')
		//
	else if (specifier == '%')
		//
}

void	parse_placeholder(const char **format, va_list ap, int *len)
{
	t_placeholder	state;

	(*format)++;
	placeholder_init(&state);
	while (!find_char(**format, SPECIFIER))
	{
		while (!find_char(**format, NONPASS))
			(*format)++;
		parse_flag(format, &state);
		parse_width(format, &state, ap);
		parse_precision(format, &state, ap);
	}
	print_placeholder(*(*format)++, ap, &state);
	printf("\n----------------------\n");
	printf("*   align : %d\n", state.align);
	printf("*   fill : %d\n", state.fill);
	printf("*   width : %d\n", state.width);
	printf("*   precision : %d\n", state.precision);
	//printf("*   specifier : %c\n", state.specifier);
	printf("----------------------\n");
}

int		ft_printf(const char *format, ...)
{
	va_list	ap;
	int		len;

	len = 0;
	va_start(ap, format);
	while (*format)
		if (*format == '%')
			parse_placeholder(&format, ap, &len);
		else
		{
			ft_putchar_fd(*format++, 1);
			len++;
		}
	va_end(ap);
	return (len);
}


int main() {
	ft_printf("hello %*.5d world", 7);
}
