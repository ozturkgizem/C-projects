#include<stdio.h>
struct time{
	int hour;
	int minute;
	int second;
	int milisecond;
};
struct time cevirici(int x){
	
struct time zaman;
	zaman.milisecond=x;
	zaman.second=0;
	zaman.minute=0;
	zaman.hour=0;
	
	//1 saniye 100 milisaniye.
	while(zaman.milisecond>=100){
		zaman.milisecond-=100;
        zaman.second+=1;
        //1 dakika 60 saniye. 
	    while(zaman.second>=60){
		    zaman.second-=60;
		    zaman.minute+=1;
			
	        while(zaman.minute>=60){
		        zaman.minute-=60;
		        zaman.hour+=1;
	        }
	    }
	}return zaman;
};

struct time zamanfarki(struct time A, struct time B){
	struct time P;
	
	if(A.milisecond>B.milisecond){
		A.milisecond+=100;
	}
	P.milisecond=B.milisecond-A.milisecond;
	
	if(A.second>B.second){
		A.second+=60;
	}
	P.second=B.second-A.second;
	
	if(A.minute>B.minute){
		A.minute+=60;
	}
	P.minute=B.minute-A.minute;
	P.hour=B.hour-A.hour;
	return P;
}
int main(){
	
struct time zeminzaman;
	struct time duzenlisaat;
	struct time fark;
	zeminzaman.hour=12;
	zeminzaman.minute=34;
	zeminzaman.second=44;
	zeminzaman.milisecond=66;
	printf("%d %d %d %d\n",zeminzaman.hour,zeminzaman.minute,zeminzaman.second,zeminzaman.milisecond);	
	printf("1-8640000 arasinda bir milisaniye degeri giriniz.\n");
     int A;
     scanf("%d",&A);
    
	duzenlisaat= cevirici(A);
     printf("%d %d %d %d\n",duzenlisaat.hour,duzenlisaat.minute,duzenlisaat.second,duzenlisaat.milisecond);
	
	fark = zamanfarki(duzenlisaat,zeminzaman);
	printf("%d %d %d %d\n",fark.hour,fark.minute,fark.second,fark.milisecond);

	return 0;
}

