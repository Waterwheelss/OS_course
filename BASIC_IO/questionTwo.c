#include<stdio.h>

main()
{


	int fd1;
	int fd2;
	char filename[100]="foo";

	fd1 = 0;
	fd2 = 0;

	printf("If you don't close the first file first, and open the second file.\n");
	fd1 = open(filename, 0);
	fd2 = open(filename, 0);
	printf("The first file descriptor is %d.\n", fd1);
	printf("The second file descriptor is %d.\n\n", fd2);
	
	close(fd1);
	close(fd2);

	printf("If you close the first file first, and open the second file.\n");
	fd1 = open(filename, 0);
	close(fd1);
	fd2 = open(filename, 0);
	printf("The first file descriptor is %d.\n", fd1);
	printf("The second file descriptor is %d.\n", fd2);

	
}
