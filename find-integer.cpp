//Yasin Ertune - Kullanicinin tam sayi girmesini isteyen program
#include <iostream> 
using namespace std; 
   
  int main() 
  { 
  	char number[10]; 
  	cout << "Please enter a number:"; 
  	cin >> number; 
  	
  	for(int i=0;i<sizeof(number);i++)	
  	{
  		if(number[i]==',' || number[i]=='.')
  		{
			cout<<"Please enter a integer."<<endl<<endl;
			return main();
		}		
	}
	cout<<"Congratulations.You entered an integer."<<endl;
	return 0;
  } 
