/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nscarab <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 14:25:43 by nscarab           #+#    #+#             */
/*   Updated: 2021/03/25 18:52:10 by nscarab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stdio.h"
#include "unistd.h"
#include "stdlib.h"
#include "string.h"
#include "time.h"
#include "fcntl.h"
#include "errno.h"

size_t	ft_strlen(const char *str);
int		ft_strcmp(const char *str1, const char *str2);
char	*ft_strcpy(char *dst, const char *src);
ssize_t	ft_write(int fildes, const void *buf, size_t nbyte);
ssize_t	ft_read(int fildes, void *buf, size_t nbyte);
char	*ft_strdup(const char *s1);

void	single_strdup_test(char *str)
{
	clock_t start;
	clock_t end;
	char	*tmp;

	start = clock();
	tmp = ft_strdup(str);
	end = clock();
	printf("\033[0;32mLIBASM\n\033[0m");
	printf("command - ft_strdup(\"%s\");\nresult - %s\n", str, tmp);
	printf("time - %lu mks\n", end - start);
	if (tmp)
		free (tmp);
	start = clock();
	tmp = strdup(str);
	end = clock();
	printf("\033[0;34mORIGINAL\n\033[0m");
	printf("command - strdup(\"%s\");\nresult - %s\n", str, tmp);
	printf("time - %lu mks\n", end - start);
	if (tmp)
		free (tmp);
	printf("\033[0;31m===================================================\n\033[0m");
	printf("\033[0;31m===================================================\n\033[0m");
}

void	single_read_test(int fildes, char *buf, size_t nbyte)
{
	clock_t start;
	clock_t end;
	ssize_t	len;

	errno = 0;
	printf("\033[0;32mLIBASM\n\033[0m");
	printf("\ncommand - ft_read(%d, %p, %lu);\n", fildes, buf, nbyte);
	start = clock();
	len = ft_read(fildes, buf, nbyte);
	end = clock();
	buf[len] = '\0';
	printf ("result - %ld, text - %s\n", len, buf);
	printf("Error: %s\nErrno: %d\n", strerror(errno), errno);
	printf("time - %lu mks\n", end - start);
	lseek(fildes, 0, SEEK_SET);
	errno = 0;
	printf("\033[0;34mORIGINAL\n\033[0m");
	printf("\ncommand - ft_read(%d, %p, %lu);\n", fildes, buf, nbyte);
	start = clock();
	len = read(fildes, buf, nbyte);
	end = clock();
	buf[len] = '\0';
	printf ("result - %ld, text - %s\n", len, buf);
	printf("Error: %s\nErrno: %d\n", strerror(errno), errno);
	printf("time - %lu mks\n", end - start);
	lseek(fildes, 0, SEEK_SET);
	buf[0] = '\0';
	printf("\033[0;31m===================================================\n\033[0m");
	printf("\033[0;31m===================================================\n\033[0m");
}

void	single_write_test(int fildes, void *buf, size_t nbyte)
{
	clock_t start;
	clock_t end;
	ssize_t	len;

	errno = 0;
	printf("\033[0;32mLIBASM\n\033[0m");
	start = clock();
	len = ft_write(fildes, buf, nbyte);
	end = clock();
	printf("\ncommand - ft_write(%d, \"%s\", %lu);\nresult - %ld\n", fildes, buf, nbyte, len);
	printf("Error: %s\nErrno: %d\n", strerror(errno), errno);
	printf("time - %lu mks\n", end - start);
	errno = 0;
	printf("\033[0;34mORIGINAL\n\033[0m");
	start = clock();
	len = write(fildes, buf, nbyte);
	end = clock();
	printf("\ncommand - write(%d, \"%s\", %lu);\nresult - %ld\n", fildes, buf, nbyte, len);
	printf("Error: %s\nErrno: %d\n", strerror(errno), errno);
	printf("time - %lu mks\n", end - start);
	printf("\033[0;31m===================================================\n\033[0m");
	printf("\033[0;31m===================================================\n\033[0m");
}

void	single_strlen_test(char *str)
{
	clock_t start;
	clock_t end;
	size_t	len;

	start = clock();
	len = ft_strlen(str);
	end = clock();
	printf("\033[0;32mLIBASM\n\033[0m");
	printf("command - ft_strlen(\"%s\");\nresult - %lu\n", str, len);
	printf("time - %lu mks\n", end - start);
	start = clock();
	len = strlen(str);
	end = clock();
	printf("\033[0;34mORIGINAL\n\033[0m");
	printf("command - strlen(\"%s\");\nresult - %lu\n", str, len);
	printf("time - %lu mks\n", end - start);
	printf("\033[0;31m===================================================\n\033[0m");
	printf("\033[0;31m===================================================\n\033[0m");
}

void	single_strcpy_test(char a, char b, char c, char d)
{
	clock_t start;
	clock_t end;
	char	*src = malloc(19);
	char	*dst = malloc(19);
	
	src[0] = a;
	src[1] = b;
	src[2] = c;
	src[3] = d;
	start = clock();
	dst = ft_strcpy(dst, src);
	end = clock();
	printf("\033[0;32mLIBASM\n\033[0m");
	printf("command - ft_strcpy(dst, \"");
	if (a == '\0')
		printf("\\0");
	else
		printf("%c", a);
	if (b == '\0')
		printf("\\0");
	else
		printf("%c", b);
	if (c == '\0')
		printf("\\0");
	else
		printf("%c", c);
	if (d == '\0')
		printf("\\0");
	else
		printf("%c", d);
	printf("\");\n");
	printf("src - %s; dst - %s\n", src, dst);
	printf("time - %lu mks\n", end - start);
	start = clock();
	dst = strcpy(dst, src);
	end = clock();
	printf("\033[0;34mORIGINAL\n\033[0m");
	printf("command - strcpy(dst, \"");
	if (a == '\0')
		printf("\\0");
	else
		printf("%c", a);
	if (b == '\0')
		printf("\\0");
	else
		printf("%c", b);
	if (c == '\0')
		printf("\\0");
	else
		printf("%c", c);
	if (d == '\0')
		printf("\\0");
	else
		printf("%c", d);
	printf("\");\n");
	printf("src - %s; dst - %s\n", src, dst);
	printf("time - %lu mks\n", end - start);
	printf("\033[0;31m===================================================\n\033[0m");
	printf("\033[0;31m===================================================\n\033[0m");
	free (src);
	free (dst);
}

void	single_strcmp_test(char *str1, char *str2)
{
	clock_t start;
	clock_t end;
	int		diff;

	start = clock();
	diff = ft_strcmp(str1, str2);
	end = clock();
	printf("\033[0;32mLIBASM\n\033[0m");
	printf("command - ft_strcmp(\"%s\", \"%s\");\nresult - %d\n", str1, str2, diff);
	printf("time - %lu mks\n", end - start);
	start = clock();
	diff = strcmp(str1, str2);
	end = clock();
	printf("\033[0;34mORIGINAL\n\033[0m");
	printf("command - strcmp(\"%s\", \"%s\");\nresult - %d\n", str1, str2, diff);
	printf("time - %lu mks\n", end - start);
	printf("\033[0;31m===================================================\n\033[0m");
	printf("\033[0;31m===================================================\n\033[0m");
}

void	check_strcmp(void)
{
	printf("\033[0;36m~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\033[0m");
	printf("\033[0;36m~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\033[0m");
	printf("\033[0;36m                       STRCMP\n\033[0m");
	printf("\033[0;36m~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\033[0m");
	printf("\033[0;36m~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\033[0m");
	single_strcmp_test("", "");
	single_strcmp_test("12345", "12345");
	single_strcmp_test("12345A", "12345");
	single_strcmp_test("12345", "12345A");
	single_strcmp_test("B", "");
	single_strcmp_test("", "B");
}

void	check_strlen(void)
{
	printf("\033[0;36m~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\033[0m");
	printf("\033[0;36m~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\033[0m");
	printf("\033[0;36m                       STRLEN\n\033[0m");
	printf("\033[0;36m~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\033[0m");
	printf("\033[0;36m~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\033[0m");
	single_strlen_test("12345");
	single_strlen_test("");
	single_strlen_test("000000jfkdalsjfka'ggjf;dg'543k6'5k7'465k7op69hgd[hhhhhhn'd");
}

void	check_write(void)
{
	printf("\033[0;36m~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\033[0m");
	printf("\033[0;36m~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\033[0m");
	printf("\033[0;36m                       WRITE\n\033[0m");
	printf("\033[0;36m~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\033[0m");
	printf("\033[0;36m~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\033[0m");
	single_write_test(1, "123456", 6);
	single_write_test(-1, "123456", 6);
	single_write_test(2, "123456", 1);
	single_write_test(2, NULL, 1);
}

void	check_read(void)
{
	printf("\033[0;36m~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\033[0m");
	printf("\033[0;36m~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\033[0m");
	printf("\033[0;36m                       READ\n\033[0m");
	printf("\033[0;36m~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\033[0m");
	printf("\033[0;36m~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\033[0m");
	char buf[100];
	int fd;
	fd = open("1", O_RDONLY);
	single_read_test(fd, buf, 9);
	single_read_test(fd, buf, 0);
	single_read_test(213, buf, 8);
	single_read_test(0, buf, 8);
	if (fd > 0)
		close (fd);
}

void	check_strcpy(void)
{
	printf("\033[0;36m~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\033[0m");
	printf("\033[0;36m~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\033[0m");
	printf("\033[0;36m                       STRCPY\n\033[0m");
	printf("\033[0;36m~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\033[0m");
	printf("\033[0;36m~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\033[0m");
	single_strcpy_test('a', 'b', 'c', '\0');
	single_strcpy_test('a', '\0', 'c', '\0');
	single_strcpy_test('\0', '\0', '\0', '\0');
}

void	check_strdup(void)
{
	printf("\033[0;36m~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\033[0m");
	printf("\033[0;36m~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\033[0m");
	printf("\033[0;36m                       STRDUP\n\033[0m");
	printf("\033[0;36m~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\033[0m");
	printf("\033[0;36m~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\033[0m");
	single_strdup_test("12345");
	single_strdup_test("");
	single_strdup_test("000000jfkdalsjfka'ggjf;dg'543k6'5k7'465k7op69hgd[hhhhhhn'd");
}

int	main(void)
{
	//check_strlen();
	//check_strcmp();
	//check_strcpy();
	//check_read();
	//check_write();
	check_strdup();
}
