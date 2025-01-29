/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adichou <adichou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 00:25:32 by adichou           #+#    #+#             */
/*   Updated: 2025/01/02 07:11:38 by adichou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdio.h>
# include <stdlib.h>
# include <stdarg.h>
# include <unistd.h>

// Prototypes des fonctions

int		ft_strlen(const char *str);
int		ft_putvoidptr(unsigned long ptr);
int		ft_putnbr(int nb);
int		ft_putnbr_unsigned(unsigned int nb);
int		ft_putstr(char *str);
int		ft_putchar(int c);
void	ft_puthex(unsigned int nbr, char format, int *count);
int		ft_puthex_low(int nbr);
void	reverse_str(char *str);
int		count_arg(const char *format);
void	argtypes_to_str(const char *format, char *argtypes);
// void	print_arg(const char *format, char *argtypes, va_list args, int *count);
void	print_arg(const char *format, va_list *args, int *count);
int		ft_puthex_hub(unsigned int nbr, char format);
int		ft_put_ptr(void *ptr);
int		ft_printf(const char *format, ...);
int		count_arg(const char *format);
int		ft_strlen(const char *str);

#endif
