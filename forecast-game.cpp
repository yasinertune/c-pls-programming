//Yasin Ertune - 1 ile 100 arasýnda sayý tahmin etme uygulamasý 
//Deðiskenler: Kalan_hak,tahmin,kalan,ceza_puani
#include<iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;

int main()
{
	srand(time(NULL));
	int random=1+rand()%100;
	cout<<random<<endl; //delete 
	int lifecycle=5,forecast,remainder,penalty_points=0;
	
	while(lifecycle>0)
	{
		cout<<"Enter your forecast: ";
		cin>>forecast;
		
		if(random>forecast)
		{
				remainder=random-forecast;
				if(remainder<15)
				{
					cout<<"You came close. Raise forecast."<<endl;
					penalty_points+=10;
				}
					
				else 
				{
					cout<<"Far away. Raise forecast."<<endl;
					penalty_points+=10;
				}
		}
			
		else if(random==forecast)	
		{
				cout<<"Congratulations. You found the forecast."<<endl<<"Your penalty score: "<<penalty_points<<endl;
				break;	
		}
		else
		{
				remainder=forecast-random;
				if(remainder<15)
				{
					cout<<"You came close. Shrink forecast."<<endl;
					penalty_points+=10;
				}
					
				else 
				{
					cout<<"Far away. Shrink forecast."<<endl;
					penalty_points+=10;
				}
		}
		lifecycle--;
		if(lifecycle==0)
		{
			cout<<"Right is over. Try again."<<endl;
			cout<<"Your penalty score: "<<penalty_points;
			break;
		}			
	}
	return 0;
}

