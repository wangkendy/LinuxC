#include <sys/signal.h>
#include <setjmp.h>
#include <stdio.h>

static jmp_buf env;

void sigfpe(int sig)
{
	signal(SIGFPE, sigfpe);
	longjmp(env, 1);
}

int main(void)
{
	int a, b;
	if ( _POSIX_C_SOURCE >= 1 || _POSIX_SOURCE)
		printf("sigaction could be used on the system.\n");
	if(setjmp(env))
		printf("Divide by 0\n");
	signal(SIGFPE, sigfpe);
	printf("after signal()\n");
	for(;;) {
		printf("Input a & b: ");
		scanf("%d%d", &a, &b);
		printf("%d/%d=%d\n", a, b, a / b);
		printf("%d%%%d=%d\n", a, b, a % b);
	}
	return 0;
}
