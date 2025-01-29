/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printfunctions2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adichou <adichou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/01 19:48:27 by adichou           #+#    #+#             */
/*   Updated: 2025/01/06 02:14:29 by adichou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putstr(char *str)
{
	int	i;

	i = 0;
	if (str == NULL)
		return (ft_putstr("(null)"));
	while (str[i] != '\0')
	{
		write(1, &str[i], 1);
		i++;
	}
	return (ft_strlen(str));
}

int	ft_putchar(int c)
{
	write(1, &c, 1);
	return (1);
}

void	ft_puthex(unsigned int nbr, char format, int *count)
{
	const char		*digits = "0123456789abcdef";

	if (format == 'X')
		digits = "0123456789ABCDEF";
	if (nbr >= 16)
		ft_puthex(nbr / 16, format, count);
	write(1, &digits[nbr % 16], 1);
	(*count)++;
}

int	ft_puthex_hub(unsigned int nbr, char format)
{
	int		count;

	count = 0;
	ft_puthex(nbr, format, &count);
	return (count);
}

int	ft_put_ptr(void *ptr)
{
	int		count;

	if (!ptr)
		return (write(1, "(nil)", 5), 5);
	count = ft_putvoidptr((unsigned long)ptr);
	return (count);
}
