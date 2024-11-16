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
// -------------------------------------------------------------

void	ft_print_c(int c, t_flags *flags, const char **format)
{
	(void)format;
	if (flags->minus)
		return ;
	write(1, &c, 1);
	flags->count++;
}
