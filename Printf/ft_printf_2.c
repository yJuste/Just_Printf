/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:                                            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created:   by Just'                               #+#    #+#             */
/*   Updated:   by Just'                              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

// -------------------------------PROTOTYPE------------------------------
void	ft_flags(va_list *args, t_flags *flags, const char **format);
void	ft_flags_args(int arg, t_flags *flags, const char **format);
void	ft_flags_next(t_flags *flags, const char **format, int i, int k);
void	ft_flags_next_2(t_flags *flags, const char **format, int i);
void	ft_flags_init(t_flags *flags, t_decimal *dml);
void	ft_flags_next_3(t_flags *flags, char *format, int i, int k);
// ----------------------------------------------------------------------

void	ft_flags(va_list *args, t_flags *flags, const char **format)
{
	if (**format == '0' && !flags->zero)
		ft_flags_next_2(flags, format, 1);
	else if (**format == ' ')
		ft_flags_next_2(flags, format, 2);
	else if (**format == '+')
		ft_flags_next_2(flags, format, 3);
	else if (**format == '-')
		ft_flags_next_2(flags, format, 4);
	else if (**format == '#')
		ft_flags_next_2(flags, format, 5);
	else if (**format >= '0' && **format <= '9')
		ft_flags_next(flags, format, 6, 0);
	else if (**format == '.')
		ft_flags_next(flags, format, 7, 0);
	else if (**format == '*')
		ft_flags_args(va_arg(*args, int), flags, format);
	return ;
}

void	ft_flags_args(int arg, t_flags *flags, const char **format)
{
	char	nbr[15];

	nbr[0] = '\0';
	ft_itoa_stack(arg, nbr);
	if (flags->precision)
	{
		if (arg < 0)
			flags->star_ds = 1;
		ft_flags_next_3(flags, nbr, 7, 0);
	}
	else
	{
		if (arg < 0)
			flags->star_ds = 2;
		ft_flags_next_3(flags, nbr, 6, 0);
	}
	(*format)++;
	return ;
}

void	ft_flags_next_3(t_flags *flags, char *format, int i, int k)
{
	if (i == 6)
	{
		flags->width = 1;
		while (*format >= '0' && *format <= '9')
		{
			flags->s_width[k++] = *format;
			format++;
		}
		flags->s_width[k] = '\0';
		return ;
	}
	if (i == 7)
	{
		while (*format >= '0' && *format <= '9')
		{
			flags->s_precision[k++] = *format;
			format++;
		}
		flags->s_precision[k] = '\0';
		return ;
	}
}

void	ft_flags_next(t_flags *flags, const char **format, int i, int k)
{
	if (i == 6)
	{
		flags->width = 1;
		while (**format >= '0' && **format <= '9')
		{
			flags->s_width[k++] = **format;
			(*format)++;
		}
		flags->s_width[k] = '\0';
		return ;
	}
	if (i == 7)
	{
		flags->precision = 1;
		(*format)++;
		while (**format >= '0' && **format <= '9')
		{
			flags->s_precision[k++] = **format;
			(*format)++;
		}
		flags->s_precision[k] = '\0';
		return ;
	}
}

void	ft_flags_next_2(t_flags *flags, const char **format, int i)
{
	if (i == 1)
		flags->zero = 1;
	else if (i == 2)
	{
		flags->space = 1;
		while (**format == ' ')
			(*format)++;
		return ;
	}
	else if (i == 3)
		flags->plus = 1;
	else if (i == 4)
		flags->minus = 1;
	else if (i == 5)
		flags->hashtag = 1;
	(*format)++;
}

void	ft_flags_init(t_flags *flags, t_decimal *dml)
{
	size_t		i;

	i = 0;
	flags->minus = 0;
	flags->zero = 0;
	flags->precision = 0;
	flags->space = 0;
	flags->hashtag = 0;
	flags->plus = 0;
	flags->width = 0;
	flags->star_ds = 0;
	dml->len = 0;
	dml->width = 0;
	dml->spaces = 0;
	dml->precision = 0;
	dml->hex = 0;
	dml->neg = 0;
	while (i < 20)
	{
		flags->s_width[i] = '\0';
		flags->s_precision[i] = '\0';
		i++;
	}
	return ;
}
