/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_d.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:                                            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created:   by Just'                               #+#    #+#             */
/*   Updated:   by Just'                              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

// ---------------------------------PROTOTYPE--------------------------------
void	ft_print_d(int d, t_flags *flags, const char **format);
void	ft_calculate_d(long d, t_flags *flags, t_decimal *dml);
void	ft_flags_precision_and_null_d(long d, t_flags *flags, t_decimal *dml);
void	ft_flags_next_zero_d(long *d, t_flags *flags, t_decimal *dml);
void	ft_is_negative_d(long *d, t_flags *flags, t_decimal *dml);
// ---------------------------------------------------------------------------

void	ft_print_d(int d, t_flags *flags, const char **format)
{
	t_decimal	dml;

	dml.width = 0;
	dml.spaces = 0;
	dml.len = 0;
	dml.precision = 0;
	ft_calculate_d((long)d, flags, &dml);
	ft_parse_d((long)d, flags, &dml);
	(*format)++;
}

void	ft_calculate_d(long d, t_flags *flags, t_decimal *dml)
{
	dml->len = ft_intlen(d);
	if (d < 0)
		dml->len--;
	dml->width = ft_atoi(flags->s_width);
	dml->precision = ft_atoi(flags->s_precision);
	if (dml->precision > dml->len)
		dml->precision -= dml->len;
	else
		dml->precision = 0;
	dml->spaces = dml->width - (dml->len + dml->precision);
	if (dml->spaces < 0)
		dml->spaces = 0;
	return ;
}

// Functions utils for print_d_next

void	ft_flags_space_and_plus_d(long d, t_flags *flags, t_decimal *dml)
{
	if (flags->space || flags->plus)
	{
		if (d >= 0)
		{
			if (flags->plus)
				write(1, "+", 1);
			else
				write(1, " ", 1);
			flags->count++;
			dml->spaces--;
		}
	}
	return ;
}

void	ft_flags_precision_and_null_d(long d, t_flags *flags, t_decimal *dml)
{
	if (!d && flags->precision && !ft_atoi(flags->s_precision))
	{
		if (dml->width)
		{
			write(1, " ", 1);
			flags->count++;
		}
		flags->count--;
	}
	else
		ft_putnbr((long)d);
	return ;
}

void	ft_is_negative_d(long *d, t_flags *flags, t_decimal *dml)
{
	if (*d < 0)
	{
		*d = -*d;
		write(1, "-", 1);
		flags->count++;
		dml->spaces--;
	}
	return ;
}
