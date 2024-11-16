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
	int		width;
	int		space;
	int		plus;
	int		minus;
	int		hashtag;
	int		zero;
	int		precision;
	char	s_width[15];
	char	s_precision[15];
	int		count;
}	t_flags;

// ft_printf.c

int		ft_printf(const char *format, ...);
void	ft_print_and_count(t_flags *flags, const char **format);

// ft_printf_2.c

void	ft_flags(t_flags *flags, const char **format);
void	ft_flags_next(t_flags *flags, const char **format, int i, int k);
void	ft_flags_next_2(t_flags *flags, const char **format, int i);
void	ft_flags_init(t_flags *flags);

// ft_printf_%.c

void	ft_print_percent(t_flags *flags, const char **format);
void	ft_parse_percent(t_flags *flags, int spaces);

// ft_printf_c.c

void	ft_print_c(int c, t_flags *flags, const char **format);
void	ft_parse_c(int c, t_flags *flags, int spaces);

// ft_lib_printf.c

int	ft_atoi(char *str);

#endif
