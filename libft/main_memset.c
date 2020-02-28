#include <stdio.h>
#include <string.h>

void	*ft_memset(void *str, int c, size_t len);
void	ft_bzero(void *s, size_t n);
void    *ft_memcpy(void *str1, const void *str2, size_t n);
void	*ft_memccpy(void *dst, const void *src, int c, size_t n);

int		main(void)
{
	char mem[14] = "hello i'm m3m";
	char mem2[14] = "hello i'm m3m";
	char mem3[10] = "x3n4 daow";
	char mem4[7] = "34ndwwq";

//	printf("%s\n", memset(mem2, 'a',8));
	ft_memset(mem, 'a', 8);
	printf("%s\n", mem);
	ft_bzero(mem, 5);
	printf("%s\n", mem);
	bzero(mem2, 5);
	printf("%s\n",mem2 + 6);
//	printf("%s\n", mem2);
	printf ("%s\n", mem3);
	printf("%s\n", mem4);
	ft_memcpy(mem3, mem4, 5);
	printf("%s\n", mem3);
	printf("%s\n", mem4);
	ft_memccpy(mem, mem4, 'l', 6);
	printf("%s\n %s\n", mem, mem4);
	return(0);
}
