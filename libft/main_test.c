#include <stdio.h>

int	ft_isdigit(int character);
int	ft_isalpha(int character);
int	ft_isalnum(int character);
int	ft_isascii(int character);
int	ft_isprint(int character);
int	ft_toupper(int character);
char	*ft_strchr(char *str, int c);

int	main(void)
{
	printf("%s\n", "ISDIGIT TESTS");
	printf("%d %s\n", ft_isdigit('1'), "expected 1");
	printf("%d %s\n", ft_isdigit('\0'), "expected 0");
	printf("%d %s\n", ft_isdigit(' '), "expected 0");
	printf("%d %s\n", ft_isdigit('s'), "expected 0 ");
	printf("%s", "\n\n\n\n");


	printf("%s\n", "ISALPHA TESTS");
	printf("%d %s\n", ft_isalpha('1'), "expected 0");
	printf("%d %s\n", ft_isalpha('a'), "expected 1");
	printf("%d %s\n", ft_isalpha('g'), "expected 1");
	printf("%d %s\n", ft_isalpha('z'), "expected 1");
	printf("%d %s\n", ft_isalpha('A'), "expected 1");
	printf("%d %s\n", ft_isalpha('R'), "expected 1");
	printf("%d %s\n", ft_isalpha('Z'), "expected 1");
	printf("%d %s\n", ft_isalpha('-'), "expected 0");
	printf("%d %s\n", ft_isalpha(' '), "expected 0");
	printf("%s", "\n\n\n\n");

	printf("%s\n", "ISALNUM TESTS");
	printf("%d %s\n", ft_isalnum('1'), "expected 1");
	printf("%d %s\n", ft_isalnum('a'), "expected 1");
	printf("%d %s\n", ft_isalnum('V'), "expected 1");
	printf("%d %s\n", ft_isalnum('-'), "expected 0");
	printf("%d %s\n", ft_isalnum('\t'), "expected 0");
	printf("%s", "\n\n\n\n");

	printf("%s\n", "ISASCII TESTS");
	printf("%d %s\n", ft_isascii('1'), "expected 1");
	printf("%d %s\n", ft_isascii(5), "expected 0");
	printf("%d %s\n", ft_isascii('g'), "expected 1");
	printf("%d %s\n", ft_isascii('\n'), "expected 1");
	printf("%s", "\n\n\n\n");

	printf("%s\n", "ISPRINT TESTS");
	printf("%d %s\n", ft_isprint('1'), "expected 1");
	printf("%d %s\n", ft_isprint('\0'), "expected 0");
	printf("%d %s\n", ft_isprint(7), "expected 0");
	printf("%s", "\n\n\n\n");

	printf("%s\n", "TOUPPER");
	printf("%d %s\n", ft_toupper('1'), "expected 49");
	printf("%d %s\n", ft_toupper('a'), "expected 65");
	printf("%d %s\n", ft_toupper('z'), "expected 90");
	printf("%d %s\n", ft_toupper('s'), "expected 83");
	printf("%d %s\n", ft_toupper('-'), "expected 45");
	printf("%s", "\n\n\n\n");

	printf("%s\n", "STRCHR TESTS");
	printf("%s %s\n", *ft_strchr("qwewrtyjjgmhn", 'w');
	printf("$s", "\n\n\n");
	return (0);
}
