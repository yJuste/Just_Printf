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

// --------------------------------PROTOTYPE-------------------------------
void	ft_flags(t_flags *flags, const char **format);
void	ft_flags_next(t_flags *flags, const char **format, int i, int j);
void	ft_flags_next_2(t_flags *flags, const char **format, int i, int j);
void	ft_flags_next_3(t_flags *flags, const char **format, int i, int j);
// ------------------------------------------------------------------------

void	ft_flags(t_flags *flags, const char **format)
{
	if (**format == 'c' || **format == 's' || **format == 'p'
		|| **format == 'd' || **format == 'i' || **format == 'u'
		|| **format == 'x' || **format == 'X' || **format == '%')
		return ;
	else if (**format == ' ')
		ft_flags_next(flags, format, 1, 0);
	else if (**format == '+')
		ft_flags_next(flags, format, 2, 0);
	else if (**format == '-')
		ft_flags_next(flags, format, 3, 0);
	else if (**format == '#')
		ft_flags_next(flags, format, 4, 0);
	else if (**format == '0')
		ft_flags_next(flags, format, 5, 0);
	else if (**format == '.')
		ft_flags_next(flags, format, 6, 0);
	return ;
}

void	ft_flags_next(t_flags *flags, const char **format, int i, int j)
{
	if (i == 1)
	{
		flags->space++;
		(*format)++;
		while (**format >= '0' && **format <= '9')
		{
			flags->s_space[j++] = **format;
			(*format)++;
		}
		flags->s_space[j] = '\0';
		return ;
	}
	else if (i == 2)
	{
		flags->plus++;
		(*format)++;
		while (**format >= '0' && **format <= '9')
		{
			flags->s_plus[j++] = **format;
			(*format)++;
		}
		flags->s_plus[j] = '\0';
		return ;
	}
	ft_flags_next_2(flags, format, i, 0);
}

void	ft_flags_next_2(t_flags *flags, const char **format, int i, int j)
{
	if (i == 3)
	{
		flags->minus++;
		(*format)++;
		while (**format >= '0' && **format <= '9')
		{
			flags->s_minus[j++] = **format;
			(*format)++;
		}
		flags->s_minus[j] = '\0';
		return ;
	}
	else if (i == 4)
	{
		flags->hashtag++;
		(*format)++;
		while (**format >= '0' && **format <= '9')
		{
			flags->s_hashtag[j++] = **format;
			(*format)++;
		}
		flags->s_hashtag[j] = '\0';
		return ;
	}
	ft_flags_next_3(flags, format, i, 0);
}

void	ft_flags_next_3(t_flags *flags, const char **format, int i, int j)
{
	if (i == 5)
	{
		flags->zero++;
		(*format)++;
		while (**format >= '0' && **format <= '9')
		{
			flags->s_zero[j++] = **format;
			(*format)++;
		}
		flags->s_zero[j] = '\0';
		return ;
	}
	else if (i == 6)
	{
		flags->hashtag++;
		(*format)++;
		while (**format >= '0' && **format <= '9')
		{
			flags->s_precision[j++] = **format;
			(*format)++;
		}
		flags->s_precision[j] = '\0';
		return ;
	}
	return ;
}
