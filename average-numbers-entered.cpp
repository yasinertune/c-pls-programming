//Yasin Ertune - Girilen sayilarin ortalamasini bulan ve ortalamanin ustunde olanlari bulan program
#include <iostream>
using namespace std;
int main()
{
	int value,counter,sum,avg=0,result=0,numbers[99];
	cout<<"How many numbers will you enter:";
	cin>>value;
	
	for(counter=1;counter<=value;counter++)
	{
		cout<<counter<<": ";
		cin>>numbers[counter];
		sum+=numbers[counter];
	}
	
	avg=sum/value;
	for(counter=1;counter<=value;counter++)
		if(numbers[counter]>avg)
			result++;	
		
	cout<<"Average result: "<<avg<<endl;
	cout<<"Number of values > Average is:"<<result;

}

