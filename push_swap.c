// Created: 20/04/21 - 16:00
#include <stdlib.h>
#include <stdio.h>

int ft_strlen(char *str)
{
    int i = 0;
    while (str[i])
        i++;
    return i;
}
int	ft_long(int n)
{
	long	nb;
	int		i;

	nb = n;
	i = 0;
	if (nb == 0)
		return (1);
	if (nb < 0)
	{
		i++;
		nb = -nb;
	}
	while (nb > 0)
	{
		nb = nb / 10;
		i++;
	}
	return (i);
}
int ft_atoi(char *str)
 {
    int i = 0;
    int sign = 1;
         int result = 0;

    while (str[i] == ' ' || str[i] == '\t' || (str[i] >= 9 && str[i] <= 13))
        i++;

    if (str[i] == '+' || str[i] == '-') 
    {
        if (str[i] == '-')
            sign = -1;
        i++;
    }
    if(!(str[i] >= '0' && str[i] <= '9'))
    {
        printf("Error\n");
        exit(1);
    }
    while (str[i] >= '0' && str[i] <= '9')
    {
        result = result * 10 + (str[i] - '0');
        i++;
    }
    if(ft_long(result*sign)!= ft_strlen(str))
    {
        printf("Error bad character\n");
        exit(1);
    }
    return result * sign;
}

int *parc(int ac, char *av[]) 
{
    if(ac == 1)
    {
        printf("Error\n");
        exit(1);
    }
    int i = 1;
    int j = 0;
    int *tab1;
    int k = 0;
    tab1 = malloc(sizeof(int) * (ac - 1));
    if (!tab1)
        return NULL;
    while (i < ac) 
    {
        tab1[j] = ft_atoi(av[i]);
        j++;
        i++;
    }
    i = 0;
    while (i < j - 1) 
    {
            k = i + 1;
        while(k < j) 
        {
            if (tab1[i] == tab1[k]) 
            {
                printf("Error of number\n");
                exit(1);
            }
            k++;
        }
        i++;
    }

    return tab1;
}
int main(int ac, char *av[]) 
{

    int *tab;
    int i = 0;
    tab = parc(ac, av);
    while (i < ac - 1) 
    {
        printf("%d\n", tab[i]);
        i++;                                                                                            
    }
    return 0;
}
