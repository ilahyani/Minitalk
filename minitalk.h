/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilahyani <ilahyani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/06 13:16:22 by ilahyani          #+#    #+#             */
/*   Updated: 2022/03/06 15:29:27 by ilahyani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <signal.h>
# include <unistd.h>
# include "ft_printf/ft_printf.h"

int		ft_power(int nb, int power);
size_t	ft_strlen(char *s);
int		ft_is_space(char c);
int		ft_is_numeric(const char *str);
int		ft_atoi(const char *str);

#endif