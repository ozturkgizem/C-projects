#include <stdio.h>
#include <stdlib.h>

int main()
{
	FILE *fp;
	char ch;
	char str[]="Yildiz Technical University";
	
	fp=fopen("Example.txt","w+");
	if(fp==NULL)
	{
		printf("The file is not opened!!");
		exit(1);
	}
	fputs(str,fp);
	
	fseek(fp,0,SEEK_SET);
	while(1)
	{
		fseek(fp,0,SEEK_CUR);
		ch=fgetc(fp);
		if(feof(fp)) break;
		if(ch>=65 && ch<=90)
		{
			ch+=32;
			fseek(fp,-1,SEEK_CUR);
			fputc(ch,fp);
		}
		else if(ch>=97 && ch<=122)
		{
			ch-=32;
			fseek(fp,-1,SEEK_CUR);
			fputc(ch,fp);
		}
	}
	
	fclose(fp);
	
	return 0;
}

