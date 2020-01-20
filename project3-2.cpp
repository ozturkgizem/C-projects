#include<stdio.h>
int strlength(char string[]){
	int i=0;
	while (string[i]!='\0'){
		i++;
	}
	return i;
}
//char döndürüyor demiyoruz çünkü stringler pointer mantigiyla çalisiyor.
void myUppercase(char string[]){
	int i=0;
	while (string[i]!='\0'){
		if(string[i]>='a' && string[i]<='z'){
			string[i]-=32;
		}
		i++;
	}
}

void myLowercase(char string[]){
	int i=0;
	while (string[i]!='\0'){
		if(string[i]>='A' && string[i]<='Z'){
			string[i]+=32;
		}
		i++;
	}
}

void ilkharf(char string[]){
	myLowercase(string);
	if(string[0]>='a' && string[0]<='z'){
		string[0]-=32;
	}
	int i=0;
	while(string[i]!='\0'){
		if(string[i]==' '){
			if(string[i+1]>='a' && string[i+1]<='z'){
				string[i+1]-=32;
			}
		}
		i++;
	}
}

void yenidizi(char s1[], char s2[]){
    int i,j;
    i=strlength(s1);
    s1[i]=' ';
    int k=i+1;
    for(j=0; s2[j]!='\0'; k++, j++)
    {
        s1[k] = s2[j];
    }
    s1[k] = '\0';
}
int main(){
	char metin[100]="SEnden ONce senden sonra";
	char metin2[34]="biktim";
	printf("dizinin uzunlugu: %d\n",strlength(metin));
	
	myUppercase(metin);
	printf("harflerin tamami buyuk hali: %s\n",metin);
	
	ilkharf(metin);
	printf("ilk harfler buyuk: %s\n",metin);
	
	yenidizi(metin, metin2);
	printf("birlesim: %s",metin);
	
	
	return 0;
}

