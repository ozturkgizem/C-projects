#include <stdio.h>
#include <stdlib.h>

int main()
{
	char str[]="#!Yildiz Technical University#$!!";
	char ch;
	int k,i;
	FILE *fp;
	
	fp=fopen("Example.txt", "w+");
	if(fp==NULL)
	{
		printf("The file is not opened!");
		exit(1);
	}
	fputs(str,fp);
	
	fseek(fp,0,SEEK_END);
	k=ftell(fp);
	
	fseek(fp,0,SEEK_SET);
	for(i=0; i<k; i++)
	{
		fseek(fp,i,SEEK_SET);
		ch=fgetc(fp);
		if(feof(fp)) break;
		if( (ch>='a' && ch<='z') || (ch>='A' && ch<='Z') )
			continue;
		fseek(fp,i,SEEK_SET);
		fputc('*',fp);		
	}
	
	fclose(fp);
	return 0;
}

