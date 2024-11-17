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

#define ARGS "|%d|", 34

// --------------------------PROTOTYPE--------------------------
int		ft_printf(const char *format, ...);
void	ft_printf_recall(t_flags *flags, const char **format);
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
			ft_printf_recall(&flags, &format);
			if (*format == '%')
				ft_print_percent(&flags, &format);
			else if (*format == 'c')
				ft_print_c(va_arg(args, int), &flags, &format);
			else if (*format == 's')
				ft_print_s(va_arg(args, char *), &flags, &format);
			else if (*format == 'p')
				ft_print_p(va_arg(args, void *), &flags, &format);
			else if (*format == 'd')
				ft_print_d(va_arg(args, int), &flags, &format);
		}
		else
			ft_print_and_count(&flags, &format);
	}
	va_end(args);
	return (flags.count);
}

void	ft_printf_recall(t_flags *flags, const char **format)
{
	int	i;

	i = 0;
	ft_flags_init(flags);
	while (i < 10)
	{
		ft_flags(flags, format);
		i++;
	}
	return ;
}

void	ft_print_and_count(t_flags *flags, const char **format)
{
	write(1, *format, 1);
	flags->count++;
	(*format)++;
}
/*
int	main(void)
{
	printf("		|true printf, count : %d|", printf(ARGS));
	printf("\n\\n\n");
	printf("		|myft_printf, count : %d|", ft_printf(ARGS));
	printf("\n\\n\n");
	return (0);
}*/
