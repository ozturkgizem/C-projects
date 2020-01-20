#include<stdio.h>
#define PI 3.14159
struct point {
	double x;
	double y;
};

struct circle{
	struct point m;
	int r;
};

double mesafe(struct point A, struct point B){
	int xEkseni = B.x - A.x;
	int yEkseni = B.y - A.y;
	return (xEkseni^2 + yEkseni^2)^(1/2);
}

void kontrol(struct point A, struct circle B){
	double d=mesafe(A,B.m);
	if (d<B.r) 
	  printf("nokta (%.1f, %.1f) dairenin icinde.\n", A.x, A.y);
	else if (d>B.r) 
	 printf("nokta (%.1f, %.1f) dairenin disinda.\n", A.x, A.y);
	else 
	 printf("nokta (%.1f, %.1f) dairenin ustunde.\n", A.x, A.y);
	return;
}

double cevre(struct circle A){
	return 2*PI*A.r;
}

double alan(struct circle A){
	return PI*(A.r)*(A.r);
}

double alanFarki(struct circle A, struct circle B){
	double alan1,alan2;
	alan1 = alan(A);
	alan2 = alan(B);
	return alan2-alan1;
}

int main()
{
	struct point nokta1;
	nokta1.x=6;
	nokta1.y=1;
	struct point nokta2;
	nokta2.x=3;
	nokta2.y=5;
	
	struct circle daire1;
	daire1.r=2;
	daire1.m.x=1;
	daire1.m.y=3;
	struct circle daire2;
	daire2.r=4;
	daire2.m.x=1;
	daire2.m.y=3;
	
	printf("mesafe: %f\n",mesafe(nokta1,nokta2));
	printf("cevreler: %f %f\n",cevre(daire1),cevre(daire2));
	printf("alanlar: %f %f\n",alan(daire1),alan(daire2));
	printf("alan farki: %f\n",alanFarki(daire1,daire2));
	
	kontrol(nokta2,daire2);
	
	return 0;
}

