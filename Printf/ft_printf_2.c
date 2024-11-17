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
void	ft_flags(t_flags *flags, const char **format);
void	ft_flags_next(t_flags *flags, const char **format, int i, int k);
void	ft_flags_next_2(t_flags *flags, const char **format, int i);
void	ft_flags_init(t_flags *flags);
// ----------------------------------------------------------------------

void	ft_flags(t_flags *flags, const char **format)
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
	return ;
}

void	ft_flags_next(t_flags *flags, const char **format, int i, int k)
{
	if (i == 6)
	{
		flags->width++;
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
		flags->precision++;
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
		flags->space = 1;
	else if (i == 3)
		flags->plus = 1;
	else if (i == 4)
		flags->minus = 1;
	else if (i == 5)
		flags->hashtag = 1;
	(*format)++;
}

void	ft_flags_init(t_flags *flags)
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
	while (i < 20)
	{
		flags->s_width[i] = '\0';
		flags->s_precision[i] = '\0';
		i++;
	}
	return ;
}
