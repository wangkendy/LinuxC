#include <stdio.h>

int main()
{
	char fname[256], cmd[256], buf[256];
	FILE *f;

	tmpnam(fname);
	sprintf(cmd, "netstat -rn > %s", fname);
	printf("Execute \"%s\"\n", cmd);
	system(cmd);
	f = fopen(fname, "r");
	while(fgets(buf, sizeof buf, f))
		printf("%s", buf);
	fclose(f);
	printf("Remove file \"%s\"\n", fname);
	unlink(fname);
	return 0;
}
