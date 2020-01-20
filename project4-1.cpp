#include <stdio.h>
#include <stdlib.h>

int main()
{
	FILE *fp;
	char str[]="Yildiz Technical University";
	
	fp=fopen("Example.txt","w");
	if(fp==NULL)
	{
		printf("The file is not opened!!");
		exit(1);
	}
	puts(str);
	fputs(str,fp);
	
	fclose(fp);
	
	return 0;
}

