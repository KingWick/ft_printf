#include <stdarg.h>
#include <unistd.h>
#include <stdio.h>

void	ft_putchar(char c)
{
	write(1,&c,1);
}

void	ft_putnbr_u(int nb)
{
	unsigned int	nbr;

	nbr = (unsigned int)nb;
	if (nbr < 0)
	{
		ft_putchar('-', 0);
		nbr = nbr * -1;
	}
	if (nbr > 9)
	{
		ft_putnbr_u(nbr / 10);
		ft_putchar(nbr % 10 + 48, 0);
	}
	if (nbr >= 0 && nbr <= 9)
	{
		ft_putchar(nbr + 48, 0);
	}
}

int main()
{
	ft_putnbr_u(21);
}