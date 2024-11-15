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

// --------------------------PROTOTYPE-----------------------------
void	ft_flags(t_flags *flags, const char *format);
void	ft_flags_next(t_flags *flags, const char *format, int i);
void	ft_flags_next_2(t_flags *flags, const char *format, int i);
void	ft_flags_next_3(t_flags *flags, const char *format, int i);
void	ft_flags_init(t_flags *flags);
// ----------------------------------------------------------------

void	ft_flags(t_flags *flags, const char *format)
{
	ft_flags_init(flags);
	if (*format == ' ')
		ft_flags_next(flags, format, 1);
	if (*format == '+')
		ft_flags_next(flags, format, 2);
	if (*format == '-')
		ft_flags_next(flags, format, 3);
	if (*format == '#')
		ft_flags_next(flags, format, 4);
	if (*format == '0')
		ft_flags_next(flags, format, 5);
	if (*format == '.')
		ft_flags_next(flags, format, 6);
	return ;
}

void	ft_flags_next(t_flags *flags, const char *format, int i)
{
	int		j;

	j = 0;
	if (i == 1)
	{
		flags->space++;
		format++;
		while (*format >= '0' || *format <= '9')
			flags->s_space[j++] = *format++;
		flags->s_space[j] = '\0';
		return ;
	}
	if (i == 2)
	{
		flags->plus++;
		format++;
		while (*format >= '0' || *format <= '9')
			flags->s_plus[j++] = *format++;
		flags->s_plus[j] = '\0';
		return ;
	}
	ft_flags_next_2(flags, format, i);
}

void	ft_flags_next_2(t_flags *flags, const char *format, int i)
{
	int		j;

	j = 0;
	if (i == 3)
	{
		flags->minus++;
		format++;
		while (*format >= '0' || *format <= '9')
			flags->s_minus[j++] = *format++;
		flags->s_minus[j] = '\0';
		return ;
	}
	if (i == 4)
	{
		flags->hashtag++;
		format++;
		while (*format >= '0' || *format <= '9')
			flags->s_hashtag[j++] = *format++;
		flags->s_hashtag[j] = '\0';
		return ;
	}
	ft_flags_next_3(flags, format, i);
}

void	ft_flags_next_3(t_flags *flags, const char *format, int i)
{
	int		j;

	j = 0;
	if (i == 5)
	{
		flags->zero++;
		format++;
		while (*format >= '0' || *format <= '9')
			flags->s_zero[j++] = *format++;
		flags->s_zero[j] = '\0';
		return ;
	}
	if (i == 6)
	{
		flags->hashtag++;
		format++;
		while (*format >= '0' || *format <= '9')
			flags->s_precision[j++] = *format++;
		flags->s_precision[j] = '\0';
		return ;
	}
	return ;
}

void	ft_flags_init(t_flags *flags)
{
	flags->minus = 0;
	flags->zero = 0;
	flags->precision = 0;
	flags->space = 0;
	flags->hashtag = 0;
	flags->plus = 0;
}
