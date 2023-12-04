/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cviegas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 10:19:01 by cviegas           #+#    #+#             */
/*   Updated: 2023/06/29 19:54:24 by cviegas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr_aux(int nb)
{
	if (nb == -2147483648)
	{
		write(1, "2147483648", 10);
	}
	else if (nb >= 10)
	{
		ft_putnbr_aux(nb / 10);
		ft_putnbr_aux(nb % 10);
	}	
	else
	{
		ft_putchar(nb + '0');
	}
}

void	ft_putnbr(int nb)
{
	if (nb < 0)
	{
		ft_putchar('-');
		nb = nb * -1;
	}		
	ft_putnbr_aux(nb);
}

/*
int	main(void)
{
	ft_putnbr(-2147483648);
	return (0);
}
*/
