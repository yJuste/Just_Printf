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

// --------------------------PROTOTYPE-------------------------
void	ft_print_d(int d, t_flags *flags, const char **format);
void	ft_calculate_d(long d, t_flags *flags, t_decimal *dml);
// ------------------------------------------------------------

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
