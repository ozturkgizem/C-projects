#include<stdio.h>
#include<math.h>
#define PI 3.141592
struct complex{
	double real;
	double imaginary;
};

struct complex eslenik(struct complex A){
	A.imaginary*=(-1);
	return A;
}

double mutlak(struct complex A){
	int sonuc=sqrt((A.imaginary)*(A.imaginary)+(A.real)*(A.real));
	return sonuc;
}

struct complex toplam(struct complex A,struct complex B){
	struct complex C;
	C.imaginary=A.imaginary+B.imaginary;
	C.real=A.real+B.real;
	return C;
}

struct complex fark(struct complex A,struct complex B){
	struct complex C;
	C.imaginary=B.imaginary-A.imaginary;
	C.real=B.real-A.real;
	return C;
}

struct complex carp(struct complex A, struct complex B){
	struct complex C;
	C.imaginary= A.real*B.imaginary + A.imaginary*B.real;
	C.real=A.real*B.real + A.imaginary*B.imaginary;
	return C;
}

struct complex bolme(struct complex A, struct complex B){
	struct complex ust = carp(A,eslenik(B));
	struct complex alt = carp(B,eslenik(B));
	struct complex S;
	S.real=ust.real/alt.real;
	S.imaginary=ust.imaginary/alt.real;
	return S;
}

struct complex kuvvetalma(struct complex A,int n){
	struct complex C;
	double teta, r;
	if (A.real==0) 
	teta=PI/2;
	else 
	teta=atan(A.imaginary/A.real);

	r=mutlak(A);
	C.real=pow(r,n)*acos(n*teta);
	C.imaginary=pow(r,n)*asin(n*teta);
	return C;
}


void kokler(struct complex A, int n, struct complex B[])
{
	double teta, r;
	if (A.real==0) 
	teta=PI/2;
	else 
	teta=atan(A.imaginary/A.real);
	
	r=mutlak(A);
	int k;
	for (k=0;k<n;k++)
	{
		B[k].real=pow(r,1/n)*cos((2*PI*k+teta)/n);
		B[k].imaginary=pow(r,1/n)*sin((2*PI*k+teta)/n);
	}
	return;
	
}
int main(){
    
	struct complex A;
	A.real=2; 
	A.imaginary=-1;
	printf("A: %f %fi\n", A.real,A.imaginary); 

	struct complex B;
	B.real=2; 
	B.imaginary=-1;
	printf("B: %f %fi\n", B.real,B.imaginary);
	
	struct complex E;
	E=eslenik(A);
	printf("Eslenik: %f %fi\n",E.real,E.imaginary);
	
	double M;
	M=mutlak(A);
	printf("Mutlak: %f\n",M);
	
	struct complex T;
	T=toplam(A,B);
	printf("Toplam: %f %fi\n",T.real,T.imaginary);
	
	struct complex F;
	F=fark(A,B);
	printf("Fark: %f %fi\n",F.real,F.imaginary);
	
	struct complex L;
	L=carp(A,B);
	printf("Carpma: %f %fi\n",L.real,L.imaginary);
	
	struct complex K;
	K=bolme(A,B);
	printf("Bolme: %f %fi\n",K.real,K.imaginary);
	
	int y;
	struct complex V;
	V=kuvvetalma(A,y);
	printf("Kuvveti: %d %di\n",V.real,V.imaginary);
	
	int n=10;
	struct complex C[n];
    kokler(A,n,C);
    int i;
    printf("Kokler:\n");
	for (i=0;i<n;i++)
	{
		printf("    kok%d: %f %fi\n",i+1,C[i].real,C[i].imaginary);
	}
	
	return 0;
}


