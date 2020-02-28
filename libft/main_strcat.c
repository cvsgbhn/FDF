#include <stdio.h>

char	*ft_strcat(char *destination, const char *const_source);

int	main(void)
{
	char destination[12] = "we are all ";
	char source[22] = "going to burn in hell";

	ft_strcat(destination, source);
	printf("%s", destination);
	return(0);
}
