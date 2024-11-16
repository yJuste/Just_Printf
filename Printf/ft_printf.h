/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:                                            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created:   by Just'                               #+#    #+#             */
/*   Updated:   by Just'                              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef FT_PRINTF_H
# define FT_PRINTF_H

// Standard Libraries

# include <stdlib.h>
# include <stdarg.h>
# include <unistd.h>
# include <stdio.h>

// Structure

typedef struct s_flags
{
	int		space;
	int		plus;
	int		minus;
	int		hashtag;
	int		zero;
	int		precision;
	char	s_space[10000];
	char	s_plus[10000];
	char	s_minus[10000];
	char	s_hashtag[10000];
	char	s_zero[10000];
	char	s_precision[10000];
	int		count;
}	t_flags;

// ft_printf.c

int		ft_printf(const char *format, ...);
void	ft_print_and_count(t_flags *flags, const char **format);
void	ft_flags_init(t_flags *flags);

// ft_printf_2.c

void	ft_flags(t_flags *flags, const char **format);
void	ft_flags_next(t_flags *flags, const char **format, int i, int j);
void	ft_flags_next_2(t_flags *flags, const char **format, int i, int j);
void	ft_flags_next_3(t_flags *flags, const char **format, int i, int j);

// ft_printf_%.c

void	ft_print_percent(t_flags *flags, const char **format);

// ft_printf_c.c

void	ft_print_c(int c, t_flags *flags, const char **format);

// ft_lib_printf.c

#endif
