/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfaria-d <pfaria-d@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 09:43:40 by pfaria-d          #+#    #+#             */
/*   Updated: 2022/11/15 16:42:04 by pfaria-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <stdarg.h>

int		ft_printf(const	char *str, ...);

void	ft_putchar_fd(char c, int fd);

void	ft_putdnbr_fd(size_t nbr, int fd, char *base);

void	ft_putendl_fd(char *s, int fd);

void	ft_putnbr_fd(int n, int fd);

void	ft_putstr_fd(char *s, int fd);

void	ft_putunbr_fd(unsigned int nb, int fd);

size_t	ft_strlen(const char *str);

void	ft_putddnbr_fd(int nbr, int fd, char *base);

int		ft_pow(unsigned long x);

int		ft_power_base(size_t x);

#endif