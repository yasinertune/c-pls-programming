//Yasin Ertune - Asal sayý bulan program 
/*
	Sayýnýn asal olmasý için sadece 1'e ve kendisinden baþka pozitif tam böleni olmamasý gerekiyor. Programda asal sayý kontrolü yapýyoruz.
	Deðiþkenlerimiz: sayý,sayaç,kalan	
*/

#include <iostream> 
using namespace std;
int main(){
	
   int number,counter,remainder;
   cout<<"Please enter a number:";	
   cin>>number;	
	
   for(int i=2;i<number;i++)	
   {
   		remainder = number % i;			
   		if(remainder==0)
			counter++; 	
   }
   
   if(counter==0 && number>1)
		cout<<number<<" is prime numbers.";
   else
		cout<<number<<" is not prime numbers.";
	return 0;
}

