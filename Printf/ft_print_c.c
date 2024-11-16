/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_c.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:                                            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created:   by Just'                               #+#    #+#             */
/*   Updated:   by Just'                              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

// --------------------------PROTOTYPE--------------------------
void	ft_print_c(int c, t_flags *flags, const char **format);
void	ft_parse_c(int c, t_flags *flags, int spaces);
// -------------------------------------------------------------

void	ft_print_c(int c, t_flags *flags, const char **format)
{
	int	width;
	int	spaces;

	width = ft_atoi(flags->s_width);
	if (width <= 1)
		width = 1;
	spaces = width - 1;
	ft_parse_c(c, flags, spaces);
	flags->count += width;
	(*format)++;
}

void	ft_parse_c(int c, t_flags *flags, int spaces)
{
	if (flags->minus)
	{
		write(1, &c, 1);
		while (spaces)
		{
			write(1, " ", 1);
			spaces--;
		}
	}
	else
	{
		while (spaces)
		{
			write(1, " ", 1);
			spaces--;
		}
		write(1, &c, 1);
	}
	return ;
}
