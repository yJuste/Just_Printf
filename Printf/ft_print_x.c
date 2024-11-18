/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_x.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:                                            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created:   by Just'                               #+#    #+#             */
/*   Updated:   by Just'                              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

// -------------------------------PROTOTYPE-------------------------------
void	ft_print_x(unsigned int u, t_flags *flags, const char **format);
void	ft_calculate_x( unsigned int u, t_flags *flags, t_decimal *dml);
void	ft_flags_precision_and_null_x(unsigned int u,
		t_flags *flags, t_decimal *dml);
void	ft_is_negative_x(unsigned int *u, t_flags *flags, t_decimal *dml);
// -----------------------------------------------------------------------

void	ft_print_x(unsigned int x, t_flags *flags, const char **format)
{
	t_decimal	dml;

	dml.len = 0;
	dml.width = 0;
	dml.spaces = 0;
	dml.precision = 0;
	ft_calculate_x((unsigned int)u, flags, &dml);
	ft_parse_x((unsigned int)u, flags, &dml);
	(*format)++;
}

void	ft_calculate_x(unsigned int u, t_flags *flags, t_decimal *dml)
{
	dml->len = ft_uintlen(u);
	if (u < 0)
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

// ---------- Functions utils for print_u_next ----------

void	ft_flags_precision_and_null_x(unsigned int u,
		t_flags *flags, t_decimal *dml)
{
	if (!u && flags->precision && !ft_atoi(flags->s_precision))
	{
		if (dml->width)
		{
			write(1, " ", 1);
			flags->count++;
		}
		flags->count--;
	}
	else
		ft_putnbr_uint(u);
	return ;
}

void	ft_is_negative_x(unsigned int *u, t_flags *flags, t_decimal *dml)
{
	if (*u < 0)
	{
		*u = -*u;
		write(1, "-", 1);
		flags->count++;
		dml->spaces--;
	}
	return ;
}

