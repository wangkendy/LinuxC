#include <sys/mman.h>
#include <stdio.h>

int main() {
	int a;
	int *b = (int*)valloc(sizeof(int));
	*b = 5;
	printf("b=%d\n", *b);
	printf("I am writing b %d", *b = 2);
	if(mprotect((void *)b, sizeof(int), PROT_READ) != 0)
		perror("mprotect");
	printf("b=%d\n", *b);
	*b = 4;
	printf("b=%d\n", *b);
	return 0;
}
