#include <stdio.h>
#include <stdlib.h>

int main()
{
	FILE *fp;
	char ch;
	char str[]="Yildiz Technical UniversityZ";
	
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
		if(ch=='z')
		{
			ch='a';
			fseek(fp,-1,SEEK_CUR);
			fputc(ch,fp);
		}
		else if(ch=='Z')
		{
			ch='A';
			fseek(fp,-1,SEEK_CUR);
			fputc(ch,fp);
		}
		else if(ch==' ') continue;
		else
		{
			ch+=1;
			fseek(fp,-1,SEEK_CUR);
			fputc(ch,fp);
			
		}
	}	
	fclose(fp);
	
	return 0;
}

