/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printfunctions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adichou <adichou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 00:25:00 by adichou           #+#    #+#             */
/*   Updated: 2025/01/06 02:14:30 by adichou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	count_arg(const char *format)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (format[i] != '\0')
	{
		if (format[i] == '%' && format[i + 1] != '\0')
			count ++;
		i ++;
	}
	return (count);
}

void	ft_swap_extra(char *a, char *b)
{
	char		temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

int	ft_putvoidptr(unsigned long ptr)
{
	int				i;
	int				j;
	char			hexa[17];
	char			*base;

	i = 0;
	base = "0123456789abcdef";
	if (ptr == 0)
		hexa[i++] = '0';
	else
	{
		while (ptr > 0)
		{
			hexa[i++] = base[ptr % 16];
			ptr /= 16;
		}
	}
	j = 0;
	while (j < i / 2)
	{
		ft_swap_extra(&hexa[j], &hexa[i - j - 1]);
		j++;
	}
	hexa[i] = '\0';
	return (ft_putstr("0x"), ft_putstr(hexa) + 2);
}

int	ft_putnbr(int nb)
{
	int		count;
	char	res;

	count = 0;
	if (nb == -2147483648)
	{
		write(1, "-2147483648", 11);
		return (11);
	}
	if (nb < 0)
	{
		write(1, "-", 1);
		count += 1;
		nb *= -1;
	}
	if (nb >= 10)
		count += ft_putnbr(nb / 10);
	res = (nb % 10) + '0';
	write(1, &res, 1);
	count += 1;
	return (count);
}

int	ft_putnbr_unsigned(unsigned int nb)
{
	int	res;
	int	count;

	count = 0;
	if (nb >= 10)
		count += ft_putnbr(nb / 10);
	res = (nb % 10) + 48;
	write (1, &res, 1);
	count += 1;
	return (count);
}
