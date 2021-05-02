//Yasin Ertune - lokanta uygulamasi
#include <iostream> 
#include <iomanip>
#include <time.h>
#include <windows.h>
#include <fstream>
#include <ctime>
using namespace std; 

float corba=0,pilav=0,nohut=0,patates_kizartmasi=0,hamburger=0,salata=0,patso=0,su=0,kola=0,total=0,table=0;

void menu();
void foods(int value);
float vat_calculate(float unit_price);
void orders();
void write_file();

int main() 
{
	srand(time(NULL));
	table=rand()%20;
	int counter=1,value;
	menu();
	cout<<total;
	cout<<table<<". Masa - Lokantamiza Hosgeldiniz.\n\nSiparisleriniz hemen aliniyor.";
	cout<<"Siparisi bitirmek icin 0'a basiniz.     "<<endl;
	while(true)
	{
		if(value==0)
			break;
		else
		{
			cout<<counter<<". siparis:";
			cin>>value;
			foods(value);
			counter++;
		}
	}
	orders();
	cout<<"\n\nFisiniz Kesildi.Lutfen Masaustune Bakiniz."<<endl;
	write_file();	
}

void foods(int value)
{
	switch(value)
	{
		case 1:
			corba++;
		break;
		
		case 2:
			pilav++;
		break;
		
		case 3:
			nohut++;
		break;
		
		case 4:
			patates_kizartmasi++;
		break;
		
		case 5:
			hamburger++;
		break;
		
		case 6:
			salata++;
		break;
		
		case 7:
			patso++;
		break;
		
		case 8:
			su++;
		break;
		
		case 9:
			kola++;
		break;
	}
	
}

void menu()
{
	cout<<"-------------------------------------------"<<endl;
	cout<<"|                 MENU                    |"<<endl;
	cout<<"-------------------------------------------"<<endl;
	cout<<"| 1. Corba                          5 TL  |"<<endl;
	cout<<"| 2. Pilav                          8 TL  |"<<endl;
	cout<<"| 3. Nohut                          7 TL  |"<<endl;
	cout<<"| 4. Patates Kizartmasi             9 TL  |"<<endl;
	cout<<"| 5. Hamburger                      9 TL  |"<<endl;
	cout<<"| 6. Salata                         4 TL  |"<<endl;
	cout<<"| 7. Patso                          7 TL  |"<<endl;
	cout<<"| 8. Su                             2 TL  |"<<endl;
	cout<<"| 9. Kola                           5 TL  |"<<endl;
	cout<<"-------------------------------------------"<<endl;
}

float vat_calculate(float unit_price)	//value-added-tax  kdv
{
	float vat_price;
	vat_price=unit_price-((unit_price/100)*8);
	return vat_price;
}

void orders()
{
	system("cls");
	cout<<setprecision(2);
	cout<<"Siparisler"<<setw(4)<<""<<"Adet"<<setw(5)<<""<<"KDV'siz Fiyat"<<setw(5)<<""<<"KDV'li Fiyat"<<setw(5)<<""<<"Toplam Fiyat"<<endl;
	cout<<"------------------------------------------------------------------------"<<endl;
	if(corba!=0)
		cout<<setw(10)<<left<<" Corba"<<setw(5)<<""<<corba<<setw(10)<<""<<vat_calculate(5)<<setw(17)<<""<<"5"<<setw(14)<<""<<5*corba<<" TL"<<endl;
	if(pilav!=0)
		cout<<setw(10)<<left<<" Pilav"<<setw(5)<<""<<pilav<<setw(10)<<""<<vat_calculate(8)<<setw(17)<<""<<"8"<<setw(14)<<""<<8*pilav<<" TL"<<endl;
	if(nohut!=0)
		cout<<setw(10)<<left<<" Nohut"<<setw(5)<<""<<nohut<<setw(10)<<""<<vat_calculate(7)<<setw(17)<<""<<"7"<<setw(14)<<""<<7*nohut<<" TL"<<endl;
	if(patates_kizartmasi!=0)
		cout<<setw(10)<<left<<" P.Kizartm"<<setw(5)<<""<<patates_kizartmasi<<setw(10)<<""<<vat_calculate(9)<<setw(17)<<""<<"9"<<setw(14)<<""<<9*patates_kizartmasi<<" TL"<<endl;
	if(hamburger!=0)
		cout<<setw(10)<<left<<" Hamburger"<<setw(5)<<""<<hamburger<<setw(10)<<""<<vat_calculate(9)<<setw(17)<<""<<"9"<<setw(14)<<""<<9*hamburger<<" TL"<<endl;
	if(salata!=0)
		cout<<setw(10)<<left<<" Salata"<<setw(5)<<""<<salata<<setw(10)<<""<<vat_calculate(4)<<setw(17)<<""<<"4"<<setw(14)<<""<<4*salata<<" TL"<<endl;
	if(patso!=0)
		cout<<setw(10)<<left<<" Patso"<<setw(5)<<""<<patso<<setw(10)<<""<<vat_calculate(7)<<setw(17)<<""<<"7"<<setw(14)<<""<<7*patso<<" TL"<<endl;
	if(su!=0)
		cout<<setw(10)<<left<<" Su"<<setw(5)<<""<<su<<setw(10)<<""<<vat_calculate(2)<<setw(17)<<""<<"2"<<setw(14)<<""<<2*su<<" TL"<<endl;
	if(kola!=0)
		cout<<setw(10)<<left<<" Kola"<<setw(5)<<""<<kola<<setw(10)<<""<<vat_calculate(5)<<setw(17)<<""<<"5"<<setw(14)<<""<<5*kola<<" TL"<<endl;
	cout<<"------------------------------------------------------------------------"<<endl;
	cout<<setprecision(4);
	total=(5*corba)+(8*pilav)+(7*nohut)+(9*patates_kizartmasi)+(9*hamburger)+(4*salata)+(7*patso)+(2*su)+(5*kola);
	cout<<table<<". Masa Odenecek Tutariniz: "<<total<<" TL"<<endl;
}

void write_file()
{
	time_t date = time(NULL);
  	char mDate[50];
  	strftime(mDate, sizeof(mDate), "%d-%m-%Y %H:%M", localtime(&date));
	
	ofstream myfile; 
	myfile.open("Table_Bill.txt");
	myfile<<setprecision(2);
	myfile<<setw(20)<<""<<"LOKANTAMIZA HOSGELDINIZ"<<setw(13)<<""<<mDate<<endl<<endl;
	myfile<<"Siparisler"<<setw(4)<<""<<"Adet"<<setw(5)<<""<<"KDV'siz Fiyat"<<setw(5)<<""<<"KDV'li Fiyat"<<setw(5)<<""<<"Toplam Fiyat"<<endl;
	myfile<<"------------------------------------------------------------------------"<<endl;
	if(corba!=0)
		myfile<<setw(10)<<left<<" Corba"<<setw(5)<<""<<corba<<setw(10)<<""<<vat_calculate(5)<<setw(17)<<""<<"5"<<setw(14)<<""<<5*corba<<" TL"<<endl;
	if(pilav!=0)
		myfile<<setw(10)<<left<<" Pilav"<<setw(5)<<""<<pilav<<setw(10)<<""<<vat_calculate(8)<<setw(17)<<""<<"8"<<setw(14)<<""<<8*pilav<<" TL"<<endl;
	if(nohut!=0)
		myfile<<setw(10)<<left<<" Nohut"<<setw(5)<<""<<nohut<<setw(10)<<""<<vat_calculate(7)<<setw(17)<<""<<"7"<<setw(14)<<""<<7*nohut<<" TL"<<endl;
	if(patates_kizartmasi!=0)
		myfile<<setw(10)<<left<<" P.Kizartm"<<setw(5)<<""<<patates_kizartmasi<<setw(10)<<""<<vat_calculate(9)<<setw(17)<<""<<"9"<<setw(14)<<""<<9*patates_kizartmasi<<" TL"<<endl;
	if(hamburger!=0)
		myfile<<setw(10)<<left<<" Hamburger"<<setw(5)<<""<<hamburger<<setw(10)<<""<<vat_calculate(9)<<setw(17)<<""<<"9"<<setw(14)<<""<<9*hamburger<<" TL"<<endl;
	if(salata!=0)
		myfile<<setw(10)<<left<<" Salata"<<setw(5)<<""<<salata<<setw(10)<<""<<vat_calculate(4)<<setw(17)<<""<<"4"<<setw(14)<<""<<4*salata<<" TL"<<endl;
	if(patso!=0)
		myfile<<setw(10)<<left<<" Patso"<<setw(5)<<""<<patso<<setw(10)<<""<<vat_calculate(7)<<setw(17)<<""<<"7"<<setw(14)<<""<<7*patso<<" TL"<<endl;
	if(su!=0)
		myfile<<setw(10)<<left<<" Su"<<setw(5)<<""<<su<<setw(10)<<""<<vat_calculate(2)<<setw(17)<<""<<"2"<<setw(14)<<""<<2*su<<" TL"<<endl;
	if(kola!=0)
		myfile<<setw(10)<<left<<" Kola"<<setw(5)<<""<<kola<<setw(10)<<""<<vat_calculate(5)<<setw(17)<<""<<"5"<<setw(14)<<""<<5*kola<<" TL"<<endl;
	myfile<<"------------------------------------------------------------------------"<<endl;

	myfile<<setprecision(4);		
	myfile<<table<<". Masa Odenecek Tutariniz: "<<total<<" TL"<<endl;
	myfile.close();
}
