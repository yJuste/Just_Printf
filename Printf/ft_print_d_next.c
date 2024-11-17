/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_d_next.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:                                            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created:   by Just'                               #+#    #+#             */
/*   Updated:   by Just'                              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

// -------------------------------PROTOTYPE-------------------------------
void	ft_parse_d(long d, t_flags *flags, t_decimal *dml);
void	ft_flags_minus_d(long d, t_flags *flags, t_decimal *dml);
void	ft_parse_next_d(long d, t_flags *flags, t_decimal *dml);
void	ft_parse_next_2_d(long *d, t_flags *flags, t_decimal *dml);
void	ft_flags_space_and_plus_d(long d, t_flags *flags, t_decimal *dml);
// -----------------------------------------------------------------------

void	ft_parse_d(long d, t_flags *flags, t_decimal *dml)
{
	if (flags->minus)
		ft_flags_minus_d(d, flags, dml);
	else
		ft_parse_next_d(d, flags, dml);
}

void	ft_flags_minus_d(long d, t_flags *flags, t_decimal *dml)
{
	ft_flags_space_and_plus_d(d, flags, dml);
	if (d < 0)
	{
		d = -d;
		write(1, "-", 1);
		flags->count++;
		dml->spaces--;
	}
	while (dml->precision-- > 0)
	{
		write(1, "0", 1);
		flags->count++;
	}
	ft_putnbr((long)d);
	flags->count += ft_intlen(d);
	while (dml->spaces-- > 0)
	{
		write(1, " ", 1);
		flags->count++;
	}
	return ;
}

void	ft_parse_next_d(long d, t_flags *flags, t_decimal *dml)
{
	ft_flags_space_and_plus_d(d, flags, dml);
	if (flags->zero)
	{
		if (d < 0)
		{
			d = -d;
			write(1, "-", 1);
			flags->count++;
			dml->spaces--;
		}
		while (dml->spaces-- > 0)
		{
			write(1, "0", 1);
			flags->count++;
		}
	}
	else
		ft_parse_next_2_d(&d, flags, dml);
	while (dml->precision-- > 0)
	{
		write(1, "0", 1);
		flags->count++;
	}
	ft_putnbr((long)d);
	flags->count += ft_intlen(d);
}

void	ft_parse_next_2_d(long *d, t_flags *flags, t_decimal *dml)
{
	if (*d < 0)
	{
		dml->spaces--;
		while (dml->spaces-- > 0)
		{
			write(1, " ", 1);
			flags->count++;
		}
		*d = -*d;
		write(1, "-", 1);
		flags->count++;
	}
	else
	{
		while (dml->spaces-- > 0)
		{
			write(1, " ", 1);
			flags->count++;
		}
	}
	return ;
}

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