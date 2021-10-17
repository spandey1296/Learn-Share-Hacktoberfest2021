#include<stdio.h>
int main(){
	float cels,fah;
	printf("Enter Temperature in Celsius Scale\n");
	scanf("%f",&cels);
	fah= (cels* 9/5) + 32;
	printf("The %.2fdeg Celsius in fahrenheit scale = %.2fdeg fahrenheit",cels,fah);
	return 0;
}