/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:                                            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created:   by Just'                               #+#    #+#             */
/*   Updated:   by Just'                              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

#define ARGS "|%23c   Hello|", '+'

// --------------------------PROTOTYPE--------------------------
int		ft_printf(const char *format, ...);
void	ft_print_and_count(t_flags *flags, const char **format);
// -------------------------------------------------------------

int	ft_printf(const char *format, ...)
{
	t_flags		flags;
	va_list		args;

	flags.count = 0;
	va_start(args, format);
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			ft_flags_init(&flags);
			ft_flags(&flags, &format);
			ft_flags(&flags, &format);
			ft_flags(&flags, &format);
			if (*format == '%')
				ft_print_percent(&flags, &format);
			else if (*format == 'c')
				ft_print_c(va_arg(args, int), &flags, &format);
		}
		else
			ft_print_and_count(&flags, &format);
	}
	va_end(args);
	return (flags.count);
}

void	ft_print_and_count(t_flags *flags, const char **format)
{
	write(1, *format, 1);
	flags->count++;
	(*format)++;
}

int	main(void)
{
	printf("		|count : %d|", printf(ARGS));
	printf("\n\\n\n");
	printf("		|count : %d|", ft_printf(ARGS));
	printf("\n\\n\n");
	return (0);
}
