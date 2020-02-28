#include <stdio.h>

char	*ft_strcpy(char *destination, char *sorce);
char	*ft_strchr(const char *string, int symbol);

int	main(void)
{
	char symbol = 'd';
	char *string = "safggbsdvdddvbg";
	char *symbol2;

	symbol2 = ft_strchr(string, symbol);
	printf("%s", symbol2);
	return (0);
}
