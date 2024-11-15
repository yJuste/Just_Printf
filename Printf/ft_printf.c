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

#define ARGS "|hello%-3c|", 'a'

// --------------------------PROTOTYPE-------------------------
int	ft_printf(const char *format, ...);
void	ft_print_and_count(t_flags *flags, const char *format);
// ------------------------------------------------------------

void	ft_print_and_count(t_flags *flags, const char *format)
{
	write(1, format, 1);
	flags->count++;
}

int	ft_printf(const char *format, ...)
{
	t_flags	flags;
	va_list	args;

	flags.count = 0;
	va_start(args, format);
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			ft_flags(&flags, format);
			if (*format == 'c')
				ft_print_c(va_arg(args, int), &flags, format);
			else if (*format == '\0')
				return (flags.count);
			else
				ft_print_and_count(&flags, format);
		}
		else
			ft_print_and_count(&flags, format);
		format++;
	}
	va_end(args);
	return (flags.count);
}

int	main(void)
{
	printf(ARGS);
	printf("\n\\n\n");
	ft_printf(ARGS);
	printf("\n\\n\n");
	return (0);
}
