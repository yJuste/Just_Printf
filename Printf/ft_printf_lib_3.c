/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_lib_3.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:                                            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created:   by Just'                               #+#    #+#             */
/*   Updated:   by Just'                              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

// -------------------PROTOTYPE-------------------
void	ft_itoa_stack(int src, char *dest);
void	ft_strdup_stack(char *src, char *dest);
// -----------------------------------------------

void	ft_itoa_stack(int src, char *dest)
{
	int	len;

	len = ft_intlen((long)src);
	dest[len] = '\0';
	if (src == -2147483648)
	{
		ft_strdup_stack("-2147483648", dest);
		return ;
	}
	if (src == 0)
	{
		dest[0] = '0';
		dest[1] = '\0';
		return ;
	}
	if (src < 0)
	{
		dest[0] = '-';
		src = -src;
	}
	while (src)
	{
		dest[--len] = src % 10 + '0';
		src /= 10;
	}
}

void	ft_strdup_stack(char *src, char *dest)
{
	int	i;

	i = 0;
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
}
