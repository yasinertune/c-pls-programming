//Yasin Ertune - C++ dilinde biçimleyiciler 
#include <iostream> 
#include <iomanip> 
using namespace std; 
int main() {
	string name, surname; 
	cout<<"\nIsminizi girin: "; 
	cin>>name; 
	cout<<"Soyadinizi girin: ";
	cin>>surname;
	if(name=="Yasin" && surname=="Ertune")
	{
		cout<<name.substr(0,1)<<". "<<surname<<endl;
		cout<<surname<<" "<<name.substr(0,1)<<"."<<endl;
		cout<<name.substr(0,1)<<" "<<name.substr(1,1)<<" "<<name.substr(2,1)<<" "<<name.substr(3,1)<<" "<<name.substr(4,1)<<" "<<name.substr(5,1)<<endl<<endl<<endl;                   
	}
	
	float a=12.32441232432;
	int b=80;
	cout<<"Normali:"<<a<<endl;
	cout<<"Setbase(16):"<<setbase(16)<<b<<endl;	//16 lýk tabanda 
	cout<<"Setbase(10):"<<setbase(10)<<b<<endl;	//10 luk tabanda 
	cout<<"Setprecision:"<<setprecision(5)<<a<<endl;	//5 tane sayiyi aliyor 
	cout<<"Fixed:"<<fixed<<a<<endl;	
	cout<<"Scientific:"<<scientific<<a<<endl;	//bilimsel
	cout<<"Dec(10):"<<dec<<b<<endl;	//ondalýk 
	cout<<"Hex(16):"<<hex<<b<<endl;	//onaltýlýk
	cout<<"Oct(8):"<<oct<<b<<endl; //sekizlik 
}
