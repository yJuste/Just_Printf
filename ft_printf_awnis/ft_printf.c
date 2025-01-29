/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adichou <adichou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 21:14:00 by adichou           #+#    #+#             */
/*   Updated: 2025/01/04 22:41:27 by adichou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	argtypes_to_str(const char *format, char *argtypes)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (format[i] != '\0')
	{
		if (format[i] == '%' && format[i + 1] != '\0' && format[i - 1] != '%')
		{
			argtypes[j] = format[i + 1];
			j ++;
		}
		i ++;
	}
}

void	printargfr(va_list *args, char c, int *count)
{
	if (c == 'd' || c == 'i')
		*count += ft_putnbr(va_arg(*args, int));
	else if (c == 's')
		*count += ft_putstr(va_arg(*args, char *));
	else if (c == 'c')
		*count += ft_putchar(va_arg(*args, int));
	else if (c == 'X')
		*count += ft_puthex_hub(va_arg(*args, int), 'X');
	else if (c == 'x')
		*count += ft_puthex_hub(va_arg(*args, int), 'x');
	else if (c == 'u')
		*count += ft_putnbr_unsigned(va_arg(*args, int));
	else if (c == 'p')
		*count += ft_put_ptr(va_arg(*args, void *));
	else if (c == '%')
		*count += ft_putchar('%');
}

int	is_type(char c)
{
	if (c == 'd')
		return (1);
	else if (c == 'i')
		return (1);
	else if (c == 's')
		return (1);
	else if (c == 'c')
		return (1);
	else if (c == 'X')
		return (1);
	else if (c == 'x')
		return (1);
	else if (c == 'u')
		return (1);
	else if (c == 'p')
		return (1);
	else if (c == '%')
		return (1);
	else
		return (0);
}

void	print_arg(const char *format, va_list *args, int *count)
{
	int	i;

	i = 0;
	while (format[i] != '\0')
	{
		while (format[i] != '%' && format[i] != '\0')
		{
			ft_putchar(format[i]);
			(*count)++;
			i ++;
		}
		if (format[i] != '\0' && format[i] == '%')
		{
			i ++;
			printargfr(args, format[i], count);
			if (is_type(format[i]) == 1)
				i ++;
		}
		else
			break ;
	}
}

int	ft_printf(const char *format, ...)
{
	int		count;
	va_list	args;

	count = 0;
	va_start(args, format);
	print_arg(format, &args, &count);
	va_end(args);
	return (count);
}

/*
# define MAC " %x %X", 16, 255
int main(void)
{
	printf("%d\n", ft_printf(MAC));
	printf("\n");
	printf("%d\n", printf(MAC));
}*/
