#include <stdio.h>
#include <stdlib.h>

int main()
{
	//char str[]="Yildiz Technical University";
	char ch;
	FILE *fp;
	
	fp=fopen("Example.txt", "r+");
	if(fp==NULL)
	{
		printf("The file is not opened!");
		exit(1);
	}
	//fputs(str,fp);

	fseek(fp,0,SEEK_SET);
	//while(!feof(fp))
	while(1)
	{
		fseek(fp,0,SEEK_CUR);
		ch=fgetc(fp);
		if(feof(fp)) break;
		if(ch=='a')
		{
			ch='z';
			fseek(fp,-1,SEEK_CUR);
		    fputc(ch,fp);
		}
		else if(ch=='A')
		{
			ch='Z';
			fseek(fp,-1,SEEK_CUR);
		    fputc(ch,fp);
		}
		else if(ch==' ') continue;
		else
		{
			ch-=1;
			fseek(fp,-1,SEEK_CUR);
			fputc(ch,fp);
		}	
	}
	
    fclose(fp);
		
	return 0;
}

