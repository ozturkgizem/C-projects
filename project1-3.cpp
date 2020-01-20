#include<stdio.h>
struct date{
	int day;
	int month;
	int year;
};
struct date fark(struct date A,struct date B){
	
	struct date P;
	if(A.day>B.day){
		B.day+=30;
		B.month-=1;
	}
	P.day=B.day-A.day;
	
	if(A.month>B.month){
		B.month+=12;
		B.year-=1;
	}
	
	P.month=B.month-A.month;
	P.year=B.year-A.year;
	return P;
}
/*Yil bilgisi ve 0-365 arasinda sayi alinir. 
Artik yil degerlendirilerek yil basina günler eklenir ve tarih döndürülür.*/
struct date yilfonk(int sayi,int B){
	struct date tarih;
	int months[12]={31,28,31,30,31,30,31,31,30,31,30,31};
	int months_L[12]={31,29,31,30,31,30,31,31,30,31,30,31};
	//leap year varsa mod4 sifirdir.

	tarih.month=1;
	int i;
	for(i=0;i<12;i++){
		if(B%4==0){	
		    if(sayi-months_L[i]>0){
		    	tarih.month+=1;
		    	sayi-=months_L[i];
			}	
		}
		else{
		    if(sayi-months[i]>0){
		    	tarih.month+=1;
		    	sayi-=months[i];
			}	
		}  	
	}
	tarih.day=sayi;	
	tarih.year=B;
	return tarih;
}
int main(){
	struct date zaman1;
	struct date zaman2;
	zaman1.day=12;
	zaman1.month=6;
	zaman1.year=2011;
	zaman2.day=23;
	zaman2.month=5;
	zaman2.year=2018;
	
	struct date zamanfarki;
	zamanfarki=fark(zaman1,zaman2);
	printf("%d %d %d\n",zamanfarki.day,zamanfarki.month,zamanfarki.year);
	
	int A,B;
	printf("sirasiyla 1-365 arasi bir sayi giriniz ve yil bilgisi giriniz.\n");
	scanf("%d%d",&A,&B);
	
	struct date sonuc;
	sonuc=yilfonk(A,B);
	printf("%d %d %d",sonuc.day,sonuc.month,sonuc.year);
	return 0;
}

