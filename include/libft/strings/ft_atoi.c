/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cemenjiv <cemenjiv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/16 13:26:51 by anarodri          #+#    #+#             */
/*   Updated: 2023/03/15 12:18:30 by cemenjiv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Converts ASCII string to integer.
The atoi function skips all white-space characters,
converts the subsequent characters as part of the number,
and then stops when it encounters the first character that isn't a number.
If no valid conversion could be performed, it returns zero.
*/

#include "../libft.h"

int	ft_atoi(const char *str)
{
	long	nbr;
	int		i;
	int		sign;

	i = 0;
	sign = 1;
	nbr = 0;
	while ((str[i] >= '\t' && str[i] <= '\r') || str[i] == ' ')
		i++;
	if (str[i] == '-')
		sign *= -1;
	if (str[i] == '+' || str[i] == '-')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		nbr = (nbr * 10) + str[i] - '0';
		i++;
		if (nbr * sign > INT_MAX)
			return (0);
		if (nbr * sign < INT_MIN)
			return (0);
	}
	if (str[i] != '\0')
		return (-1);
	return (nbr * sign);
}
