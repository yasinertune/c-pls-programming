//Yasin Ertune - Ogrencilere random not atayip haflendirme yapan program
#include <iostream> 
#include <string.h>
#include <windows.h>
#include <time.h>
using namespace std;
  
int main() 
{ 
  srand(time(NULL));
  string names[]=
  { 
	"Alperen","Berkay","Berke",
	"Abdullah","Damlasu","Basak",
	"Hakan","Ismail","Muhammed","Samet",
	"Ahmet","Damla","Enes","Irem","Kemal",
	"Gulden","Ibrahim","Mehmet","Omer",
	"Sevval","Burak","Emre","Hasan","Zehra","Yasin"
  };
	
  int random;
  string note;
  double avg,total;
  
  for(int i=0;i<25;i++)
  {
  	random=rand()%100+1;
  	if(random>=80)
  		note=" AA Passed";
  	else if(random>=60 &&random<80)
  		note=" BB Passed";	
	else if(random>=50 &&random<60)
  		note=" CC Passed";
  	else
  		note=" DD Failed";
  		
  	total+=random;
  	cout<<names[i]<<" Note: "<<random<<note<<endl;
  }
  avg=total/25;
  cout<<endl<<"Class avarage:"<<avg;
  return 0 ;
} 
