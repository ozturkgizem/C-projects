#include<stdio.h>
#include<string.h>
#include<ctype.h>
int main(){
	char mytext[100];
	printf("metni giriniz.");
	/*scanf("%s",mytext);
	printf("%s",mytext);*/
	gets(mytext);
	printf("stringin uzunlugu: %d\n",strlen(mytext));
	printf("stringin tamaminin kucuk hali: %s\n",strlwr(mytext));
	
	int k=1;
	mytext[0] = toupper(mytext[0]);
	while(mytext[k]!='\0'){
		//if(mytext[i]==' ')
		if (isspace(mytext[k])){
			mytext[k+1] = toupper(mytext[k+1]);
		}
		k++;
	}
	printf("bas harfler buyuk: %s\n",mytext);
	
	char iki[100];
	printf("birinci stringe eklenecek stringi giriniz.");
	gets(iki);
	//strcatte ikinciyi yazarken bosluk birakilmazsa birlesik yazar.
	strcat(mytext, iki);
	printf("metin: %s",mytext);

	return 0;
}

