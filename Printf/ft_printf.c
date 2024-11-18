/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:                                            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created:   by Just'                               #+#    #+#             */
/*   Updated:   by Just'                              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

#define ARGS "|%*s|", -9, "coucou"

/*
 - [OUTPUT] ft_printf("{%*d}", -5, 42)
 - [OUTPUT] ft_printf("neg1 %*s\n", -9, "coucou")
 - [OUTPUT] ft_printf("neg2 %*.*s\n", -9, 4, "coucou")
 - [OUTPUT] ft_printf("neg3 %*s\n", -9, NULL)
 - [OUTPUT] ft_printf("neg5 %*s\n", -100, "coucou")
 - [OUTPUT] ft_printf("neg6 %*s\n", -156, "coucou")
 - [OUTPUT] ft_printf("neg7 %*.*s\n", -1586, 15, "coucou")
 - [OUTPUT] ft_printf("neg8 %*.*s\n", -1586, 15, "coucou")
 - [OUTPUT] ft_printf("neg10 %*.*s\n", -15586, 15, "coucou")
 - [OUTPUT] ft_printf("neg11 %*.*s\n", -15586, 15, "coucou")
 - [OUTPUT] ft_printf("neg1 %*d\n", -9, 150)
 - [OUTPUT] ft_printf("neg2 %*.*d\n", -9, 4, 1555)
 - [OUTPUT] ft_printf("neg3 %*d\n", -9, -255)
 - [OUTPUT] ft_printf("neg5 %*d\n", -100, -589)
 - [OUTPUT] ft_printf("neg6 %*d\n", -156, 15555)
 - [OUTPUT] ft_printf("neg7 %*.*d\n", -1586, 15, 0)
 - [OUTPUT] ft_printf("neg8 %*.*d\n", -1586, 15, 300)
 - [OUTPUT] ft_printf("neg10 %*.*d\n", -15586, 15, 150)
 - [OUTPUT] ft_printf("neg11 %*.*d\n", -15586, 15, 0)
 - [OUTPUT] ft_printf("***************%*s%*d**************%*u*************", 10, "coucou", 10, 10, -50, 20)
 - [OUTPUT] ft_printf("%-171.108s%0022.*u%-93.114u%*c" ,"r>KM,cWZ,k7U",-75,1057557429u,580880397u,-25,-80)
 - [OUTPUT] ft_printf("%-149.*%%-114.120i%0*.24%%--*.28d" ,-63,1318471055,-125,-68,-1205906582)
 - [OUTPUT] ft_printf("%-102p%-91p%00*.32%" ,(void*)17383623580121946936lu,(void*)6825043625903153404lu,-125)
 - [OUTPUT] ft_printf("%-*c" ,-80,123)
 - [OUTPUT] ft_printf("%-69.27%%--*p" ,-94,(void*)7045295314441527752lu)
 - [OUTPUT] ft_printf("%-82.43i%-*.82%%-*.20X" ,-1945174241,-26,94,1446072230u)
 - [OUTPUT] ft_printf("%--140.183u%-*.35u" ,3194611513u,-160,4264407200u)
 - [OUTPUT] ft_printf("%*p%-127.193x%0120.150d" ,-64,(void*)1126585860702498506lu,4001913452u,444237491)
 - [OUTPUT] ft_printf("%-*c%-141p%-28.9u" ,-65,-4,(void*)7073624398654675005lu,113714125u)
 - [OUTPUT] ft_printf("%--*X%-88.73i" ,-14,2096742096u,754878051)
 - [OUTPUT] ft_printf("%-66p%-90c%--*.69x%0045.*u" ,(void*)9420165689360028937lu,-29,-122,174318236u,-127,2553740548u)
 - [OUTPUT] ft_printf("%00142.67d%-87.120s%-21.160%%-*.98d%-105.71d" ,1277409698,"/]>n?I^K$-",-187,-569482950,1801496736)
 */

// --------------------------PROTOTYPE--------------------------
int		ft_printf(const char *format, ...);
void	ft_printf_recall(va_list *args, t_flags *flags, const char **format);
void	ft_printf_arguments(va_list *args, t_flags *flags, const char **format);
void	ft_print_and_count(t_flags *flags, const char **format);
// -------------------------------------------------------------

int	ft_printf(const char *format, ...)
{
	t_flags		flags;
	t_decimal	dml;
	va_list		args;

	flags.count = 0;
	va_start(args, format);
	while (*format)
	{
		ft_flags_init(&flags, &dml);
		if (*format == '%')
		{
			format++;
			ft_printf_recall(&args, &flags, &format);
			ft_printf_arguments(&args, &flags, &format);
		}
		else
			ft_print_and_count(&flags, &format);
	}
	va_end(args);
	return (flags.count);
}

void	ft_printf_recall(va_list *args, t_flags *flags, const char **format)
{
	int		i;

	i = 0;
	while (i < 10)
	{
		ft_flags(args, flags, format);
		i++;
	}
	return ;
}

void	ft_printf_arguments(va_list *args, t_flags *flags, const char **format)
{
	if (**format == '%')
		ft_print_percent(flags, format);
	else if (**format == 'c')
		ft_print_c(va_arg(*args, int), flags, format);
	else if (**format == 's')
		ft_print_s(va_arg(*args, char *), flags, format);
	else if (**format == 'p')
		ft_print_p(va_arg(*args, void *), flags, format);
	else if (**format == 'd' || **format == 'i')
		ft_print_d(va_arg(*args, int), flags, format);
	else if (**format == 'u' || **format == 'x' || **format == 'X')
		ft_print_u(va_arg(*args, unsigned int), flags, format);
	return ;
}

void	ft_print_and_count(t_flags *flags, const char **format)
{
	write(1, *format, 1);
	flags->count++;
	(*format)++;
	return ;
}

int	main(void)
{
	printf("		|true printf, count : %d|", printf(ARGS));
	printf("\n\\n\n");
	printf("		|myft_printf, count : %d|", ft_printf(ARGS));
	printf("\n\\n\n");
	return (0);
}
