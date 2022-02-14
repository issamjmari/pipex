#include "get_next_line.h"

int main()
{
	int fd = open("test.txt", O_RDWR);
    // int fd1 = open("test1", O_RDWR);
    // int fd2 = open("test2", O_RDWR);
    // int fd3 = open("test3", O_RDWR);
    // int fd4 = open("test4", O_RDWR);


	char *ret = get_next_line(fd);

    // ret = get_next_line(fd1);
    // printf("%s\n", ret);
    // ret = get_next_line(fd2);
    // printf("%s\n", ret);
    // free(ret);
    // ret = get_next_line(fd1);
    // printf("%s\n", ret);
    // free(ret);
    // ret = get_next_line(fd3);
    // printf("%s\n", ret);
    // free(ret);
    // ret = get_next_line(fd4);
    // printf("%s\n", ret);
    // free(ret);
    // ret = get_next_line(fd4);
    // printf("%s\n", ret);
    // free(ret);
    // ret = get_next_line(fd2);
    // printf("%s\n", ret);
    // free(ret);
    // ret = get_next_line(fd1);
    // printf("%s\n", ret);
    // free(ret);
    // ret = get_next_line(fd4);
    // printf("%s\n", ret);
    // free(ret);
    // ret = get_next_line(fd4);
    // printf("%s\n", ret);
    // free(ret);
    // while(1);
    int i = 0;
	while (i < 16)
	{
		printf("%s", ret);
		free(ret);
		ret = get_next_line(fd);
        i++;
	}
    system("leaks a.out");
}
