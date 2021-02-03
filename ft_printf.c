/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youncho <youncho@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/26 19:02:11 by youncho           #+#    #+#             */
/*   Updated: 2021/02/03 10:37:36 by youncho          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	placeholder_init(t_placeholder *state)
{
	state->align = FALSE;
	state->fill = FALSE;
	state->width = FALSE;
	state->precision = -1;
}

int		print_placeholder(char specifier, va_list ap, t_placeholder *state)
{
	if (specifier == 'c')
		return (print_c(state, va_arg(ap, int)));
	else if (specifier == 's')
		return (print_s(state, va_arg(ap, char*)));
	else if (specifier == 'p')
		return (0);
	else if (specifier == 'd' || specifier == 'i')
		return (0);
	else if (specifier == 'u')
		return (0);
	else if (specifier == 'x')
		return (0);
	else if (specifier == 'X')
		return (0);
	else if (specifier == '%')
		return (print_c(state, '%'));
	return (0);
}

void	parse_placeholder(const char **format, va_list ap, int *len)
{
	t_placeholder	state;

	(*format)++;
	placeholder_init(&state);
	while (**format && !find_char(**format, SPECIFIER))
	{
		while (**format && !find_char(**format, NONPASS))
			(*format)++;
		parse_flag(format, &state);
		parse_width(format, &state, ap);
		parse_precision(format, &state, ap);
	}
	//print_placeholder(*(*format)++, ap, &state);
	if (**format)
		*len += print_placeholder(*(*format)++, ap, &state);
	//printf("\n----------------------\n");printf("*   align : %d\n", state.align);printf("*   fill : %d\n", state.fill);printf("*   width : %d\n", state.width);printf("*   precision : %d\n", state.precision);printf("----------------------\n");
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
	#define STR	0
	#define test1	"hello %.7%s", STR
	#define test2	"hello %.%s", STR
	#define test3	"hello %2%s", STR
	#define test4	"hello %010%s", STR
	#define test5	"hello %q0qq.%s", STR
	#define test6	"hello %.0  %s", STR
	#define test7	"hello %0.2%s", STR
	#define test8	"hello %0-3--.%s", STR
	#define test9	"hello %0-.%s", STR




	printf("\n----------1---------\n");
	printf("|\nreturn : %d\n", ft_printf(test1));
	printf("|\nreturn : %d", printf(test1));
	printf("\n----------2---------\n");
	printf("|\nreturn : %d\n", ft_printf(test2));
	printf("|\nreturn : %d", printf(test2));
	printf("\n----------3---------\n");
	printf("|\nreturn : %d\n", ft_printf(test3));
	printf("|\nreturn : %d", printf(test3));
	printf("\n----------4---------\n");
	printf("|\nreturn : %d\n", ft_printf(test4));
	printf("|\nreturn : %d", printf(test4));
	printf("\n----------5---------\n");
	printf("|\nreturn : %d\n", ft_printf(test5));
	printf("|\nreturn : %d", printf(test5));
	printf("\n----------6---------\n");
	printf("|\nreturn : %d\n", ft_printf(test6));
	printf("|\nreturn : %d", printf(test6));
	printf("\n----------7---------\n");
	printf("|\nreturn : %d\n", ft_printf(test7));
	printf("|\nreturn : %d", printf(test7));
	printf("\n----------8---------\n");
	printf("|\nreturn : %d\n", ft_printf(test8));
	printf("|\nreturn : %d", printf(test8));
	printf("\n----------9---------\n");
	printf("|\nreturn : %d\n", ft_printf(test9));
	printf("|\nreturn : %d", printf(test9));
}
