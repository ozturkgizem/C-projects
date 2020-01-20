#include <stdio.h>
#include <stdlib.h>

int main()
{
	int a[256], i, k, j;
	char ch;
	//for(i=0; i<256; i++) printf("%d %c \n", i, i);
	for(i=0; i<256; i++) a[i]=0;
	
	char str[]="Yildiz Technical University";
	FILE *fp1, *fp2;
	
	fp1=fopen("search.txt", "w+");
	fp2=fopen("result.txt", "w+");
	if(fp1==NULL || fp2==NULL)
	{
		printf("File is not opened");
		exit(1);
	}
	fseek(fp1,0,SEEK_SET);
	fputs(str,fp1);
	
	fseek(fp1,0,SEEK_END);
	k=ftell(fp1);
	

		fseek(fp1,0,SEEK_SET);
		for(i=0; i<k; i++)
		{
			ch=fgetc(fp1);
			if(feof(fp1)) break;
			a[ch]++;
		}	
	
	for(j=65; j<=90; j++)
		fprintf(fp2,"%c: %d \n", j, a[j]);
	for(j=97; j<=122; j++)
		fprintf(fp2,"%c: %d \n", j, a[j]); 
	  
	fclose(fp1);
	fclose(fp2);
	
	return 0;
}

