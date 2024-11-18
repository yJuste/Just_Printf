/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_lib_2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:                                            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created:   by Just'                               #+#    #+#             */
/*   Updated:   by Just'                              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

// --------------------PROTOTYPE----------------------
int		ft_atoi(char *str);
void	ft_putnbr(long nbr);
void	ft_putnbr_uint(unsigned int nbr);
void	ft_putnbr_hexa(unsigned int nbr, char format);
void	ft_swap_extra(char *a, char *b);
// ---------------------------------------------------

int	ft_atoi(char *str)
{
	int		sign;
	int		res;

	sign = 1;
	res = 0;
	while (*str == ' ' && (*str >= 9 && *str <= 13))
		str++;
	if (*str == '-')
		sign = -sign;
	if (*str == '+' || *str == '-')
		str++;
	while (*str >= '0' && *str <= '9')
	{
		res = res * 10 + *str - '0';
		str++;
	}
	return (sign * res);
}

void	ft_putnbr(long nbr)
{
	char		c;

	if (nbr < 0)
	{
		write(1, "-", 1);
		nbr = -nbr;
	}
	if (nbr >= 10)
	{
		ft_putnbr(nbr / 10);
		ft_putnbr(nbr % 10);
	}
	else
	{
		c = nbr + '0';
		write(1, &c, 1);
	}
}

void	ft_putnbr_uint(unsigned int nbr)
{
	char		c;

	if (nbr >= 10)
	{
		ft_putnbr_uint(nbr / 10);
		ft_putnbr_uint(nbr % 10);
	}
	else
	{
		c = nbr + '0';
		write(1, &c, 1);
	}
}

void	ft_putnbr_hexa(unsigned int nbr, char format)
{
	const char		*digits;

	if (format == 'x')
		digits = "0123456789abcdef";
	else if (format == 'X')
		digits = "0123456789ABCDEF";
	if (nbr >= 16)
	{
		ft_putnbr_hexa(nbr / 16, format);
		ft_putnbr_hexa(nbr % 16, format);
	}
	else
		write(1, &digits[nbr], 1);
}

void	ft_swap_extra(char *a, char *b)
{
	char		temp;

	temp = *a;
	*a = *b;
	*b = temp;
}
