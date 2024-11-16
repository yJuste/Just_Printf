/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_percent.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:                                            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created:   by Just'                               #+#    #+#             */
/*   Updated:   by Just'                              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

// --------------------------PROTOTYPE--------------------------
void	ft_print_percent(t_flags *flags, const char **format);
void	ft_parse_percent(t_flags *flags, int spaces);
// -------------------------------------------------------------

void	ft_print_percent(t_flags *flags, const char **format)
{
	int		width;
	int		spaces;

	width = ft_atoi(flags->s_width);
	if (width <= 1)
		width = 1;
	spaces = width - 1;
	ft_parse_percent(flags, spaces);
	flags->count += width;
	(*format)++;
}

void	ft_parse_percent(t_flags *flags, int spaces)
{
	if (flags->minus)
	{
		write(1, "%", 1);
		while (spaces-- > 0)
			write(1, " ", 1);
	}
	else
	{
		while (spaces-- > 0)
			write(1, " ", 1);
		write(1, "%", 1);
	}
	return ;
}
