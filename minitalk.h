#ifndef MINITALK_H
#   define MINITALK_H

#   include <signal.h>
#   include <unistd.h>
#   include "ft_printf/ft_printf.h"

int	ft_power(int nb, int power);
int	ft_is_space(char c);
int	ft_is_numeric(const char *str);
int ft_atoi(const char *str);

#endif