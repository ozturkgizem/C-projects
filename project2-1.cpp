#include<stdio.h>

struct zaman{
	double saat;
	double dakika;
	double saniye;
};

typedef struct zaman mytime;

mytime farkbul(mytime A,mytime B){
	mytime C;
	if(B.saniye<A.saniye){
		B.saniye+=60;
		B.dakika-=1;
	}
	C.saniye = B.saniye - A.saniye;
	if(B.dakika<A.dakika){
		B.dakika+=60;
		B.saat-=1;
	}
	C.dakika = B.dakika - A.dakika;
	if (B.saat < A.saat) { 
	    return farkbul(B,A); 
	}
	C.saat = B.saat - A.saat;

	return C;
}

struct tarih {
	int yil;
	int ay;
	int gun;
};

struct Kitap {
	int ISBN;
	char ad[25], yazar[30], konu[100];
	struct tarih alimTarihi, teslimTarihi;	
};
 

int main(){
	mytime A;
	mytime B;
	A.saat=3; A.dakika=2; A.saniye=5;
	B.saat=5; B.dakika=9; B.saniye=4;
	printf("%f %f %f\n",A.saat,A.dakika,A.saniye);
	printf("%f %f %f\n",B.saat,B.dakika,B.saniye);
	
	mytime X=farkbul(A,B);
	printf("%f %f %f\n",X.saat,X.dakika,X.saniye);
	return 0;
	
      struct kitap kitaplar[10]= {1, "Kürk Mantolu Madonna", "Sabahattin Ali", "Roman", {2018, 2, 12}, {2018, 4, 15},
			        2, "Hayvan Ciftligi", " George Orwell", "Roman", {2019, 1, 10}, {2019, 4, 20},
				 3, "?çimizdeki ?eytan", "Sabahattin Ali", "Roman", {2018, 6, 31}, {2018, 10, 15},
				 4, "Simyaci", "Paulo Coelho", "Roman", {2018, 3, 12}, {2018, 4, 15},
				 5, "Yabanci", "Albert Camus", "Roman", {2018, 7, 21}, {2018, 8, 4},
				 6, "Kuyucakl? Yusuf", "Sabahattin Ali", "Roman", {2018, 1, 2}, {2018, 4, 1},
				 7, "Huzursuzluk", "Zülfü Livaneli", "Roman", {2018, 4, 22}, {2018, 5, 30},
				 8, "Satranç", "Stefan Zweig", "Roman", {2018, 9, 6}, {2018, 11, 7},
				 9, "Seker Portakali", "Jose Mauro de Vasconcelos", "Roman", {2018, 2, 21}, {2018, 3, 12},
				 10, "Fareler ve Insanlar", "John Steinbeck", "Roman", {2018, 3, 10}, {2018, 5, 8}
	};
	
	for (int i =0; i<10; i++)
	{
		printf("\n%d. kitabin:  Adi -> %s\n",i+1, diziler[i].ad);
	}
	
	/*d)Dinamik bellek kullanilarak(malloc) istenilen sayida kitap girisi yapilmasina ve 
	listedeki kitaplarin ekrana yazilmasini saglayan C programini yaziniz.*/	
	struct kitap *diziler2;
	int sayi;
	printf("istediginiz sayiyi giriniz: ");
	scanf("%d",&sayi);
	diziler2=(struct kitap*)malloc(sayi*sizeof(struct kitap));

	return 0;	
}

