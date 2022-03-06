#ifndef MINITALK_BONUS_H
#   define MINITALK_BONUS_H

#   include <signal.h>
#   include <unistd.h>
#   include "../ft_printf/ft_printf.h"

int	ft_power(int nb, int power);
size_t ft_strlen(char *s);
int	ft_is_space(char c);
int	ft_is_numeric(const char *str);
int ft_atoi(const char *str);

#endif