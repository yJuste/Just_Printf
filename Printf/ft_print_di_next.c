/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_di_next.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:                                            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created:   by Just'                               #+#    #+#             */
/*   Updated:   by Just'                              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

// -----------------------------PROTOTYPE-----------------------------
void	ft_parse_d(long d, t_flags *flags, t_decimal *dml);
void	ft_flags_minus_d(long d, t_flags *flags, t_decimal *dml);
void	ft_parse_next_d(long d, t_flags *flags, t_decimal *dml);
void	ft_flags_next_zero_d(long *d, t_flags *flags, t_decimal *dml);
void	ft_parse_next_2_d(long *d, t_flags *flags, t_decimal *dml);
// -------------------------------------------------------------------

void	ft_parse_d(long d, t_flags *flags, t_decimal *dml)
{
	if (flags->minus)
		ft_flags_minus_d(d, flags, dml);
	else
		ft_parse_next_d(d, flags, dml);
	return ;
}

void	ft_flags_minus_d(long d, t_flags *flags, t_decimal *dml)
{
	ft_neg_space_plus_d(&d, flags, dml);
	while (dml->precision-- > 0)
	{
		write(1, "0", 1);
		flags->count++;
	}
	ft_print_and_null_d(d, flags, dml);
	flags->count += ft_intlen(d);
	if (flags->plus || flags->space)
		dml->spaces += 1;
	while (dml->spaces-- > 0)
	{
		write(1, " ", 1);
		flags->count++;
	}
	return ;
}

void	ft_parse_next_d(long d, t_flags *flags, t_decimal *dml)
{
	if (flags->zero)
		ft_flags_next_zero_d(&d, flags, dml);
	else
		ft_parse_next_2_d(&d, flags, dml);
	while (dml->precision-- > 0)
	{
		write(1, "0", 1);
		flags->count++;
	}
	ft_print_and_null_d(d, flags, dml);
	flags->count += ft_intlen(d);
	return ;
}

void	ft_flags_next_zero_d(long *d, t_flags *flags, t_decimal *dml)
{
	if (!flags->precision || flags->star_ds == 1)
		ft_neg_space_plus_d(d, flags, dml);
	if (flags->precision)
	{
		if (*d < 0)
			dml->spaces--;
	}
	if (flags->plus == 1 || flags->space == 1)
	{
		if (!flags->precision)
			dml->spaces++;
		if (*d <= 0 && flags->precision && ft_atoi(flags->s_width) > 1)
			dml->spaces++;
	}
	while (dml->spaces-- > 0)
	{
		if (flags->precision && !flags->star_ds)
			write(1, " ", 1);
		else
			write(1, "0", 1);
		flags->count++;
	}
	if (flags->precision && !flags->star_ds)
		ft_neg_space_plus_d(d, flags, dml);
	return ;
}

void	ft_parse_next_2_d(long *d, t_flags *flags, t_decimal *dml)
{
	if (*d < 0 && !flags->plus && !flags->space)
		dml->spaces--;
	while (dml->spaces-- > 0)
	{
		write(1, " ", 1);
		flags->count++;
	}
	if (*d == 0 && flags->width > 0)
	{
		if (flags->precision == 1 && ft_atoi(flags->s_precision) == 0)
		{
			if (ft_atoi(flags->s_width) != 1)
			{
				write(1, " ", 1);
				flags->count++;
				dml->zero = 1;
			}
		}
	}
	ft_neg_space_plus_d(d, flags, dml);
	return ;
}