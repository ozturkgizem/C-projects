#include <stdio.h>
#include <stdlib.h>

int main()
{
	FILE *fp;
	char ch, temp;
	int k,i;
	char str[]="Yildiz Technical University";
	
	fp=fopen("Example.txt","w+");
	if(fp==NULL)
	{
		printf("The file is not opened!!");
		exit(1);
	}
	fputs(str,fp);
	
	fseek(fp,0,SEEK_END);
	k=ftell(fp);
	
	for(i=0;i<=k/2;i++)
	{
		fseek(fp,i,SEEK_SET);
		ch=fgetc(fp);
		temp=ch;
		fseek(fp,-1-i,SEEK_END);
		ch=fgetc(fp);
		fseek(fp,i,SEEK_SET);
		fputc(ch,fp);
		fseek(fp,-1-i,SEEK_END);
		fputc(temp,fp);
		
	}
	
	
	fclose(fp);
	
	
	return 0;
}


