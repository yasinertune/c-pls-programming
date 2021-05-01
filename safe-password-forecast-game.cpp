//Yasin Ertune - 2 oyunculu kasa sifresi bulma oyunu
/*
	Nasil Oynanir: Ilk once oyuncular isimlerini girer. Daha sonra kasa sifresini bilgisayar kendisi random olarak belirler. Bu sahneden sonra
    oyuncular sirasiyla sifre belirlemeye baslar. Sifreye yaklasan oyuncuya 2 puan bilen oyuncuya 5 puan verilir.En son sahnede kazanan oyuncunun 
    ismi yazilir. Skor tablosunu txt dosyas�na yazd�rmak icinde gerekli secenek secilir.
*/
#include <iostream> 
#include <string>  
#include <windows.h>
#include <time.h>
#include <fstream>
using namespace std;  

int p1,p2,player1_total=0,player2_total,remainder=0,counter=0,p1_remainder,p2_remainder;	//oyun sahnesi degiskenleri
string player1,player2;	//oyuncu isimlerini tutan de�i�kenler
int add_password,safe_password[5];	//sifre degiskenleri
char selection[1];

int add_safe_password(int safe_password);
int screen();
int menu();
int start_game();
int howplay();
int game_scene();
int end_game();
void forecast(int value);



int main(){
	setlocale(LC_ALL,"Turkish");
	SetConsoleTitle("Tahmin Et Kazan");	
	
	srand(time(NULL));
	for(int i=0;i<4;i++)	//sifreyi fonksiyondan aliyoruz.0. indexe atmiyoruz. Cunku sifreyi hep 0 olarak ayarliyor. O yuzden 1. indexe atiyoruz.
		safe_password[i+1]=add_safe_password(add_password);
	screen();	
}

add_safe_password(int safe_password)	//sifre olu�turma fonksiyonu
{
		safe_password=rand()%10;
		return safe_password;
}

screen()
{
		system("cls");	//Ekrandakileri temizliyor.
		cout<<" TAHM�N ET KAZAN OYUNUNA HO�GELD�N�Z \n\n Birazdan ana men�ye y�nlendirileceksiniz.."<<endl;
		Sleep(3000);	//program� 3 saniye duraklat�yor
		menu();
}

menu()
{
		//Kullanicinin ana menuden secimini aliyoruz.
		SetConsoleTitle("Tahmin Et Kazan - Ana Menu");	//Ana Menu baslik kismi.
		system("cls");
		cout<<"---ANA MEN�---\n\n 1) Oyuna Basla \n\n 2) Nas�l Oynan�r? \n\n\n ";
		cout<<" L�tfen bir se�im yap�n�z.\n  ";
		cin>>selection;
			switch(selection[0])		//Al�nan veriyi switch ile kontrol ediyoruz.
			{
				case '1':
					system("cls");
					start_game();	//ekran� temizle ve oyuna basla fonksiyonuna git.
					break;
				
				case '2':
					system("cls");
					howplay();		//ekran� temizle ve nas�l oynanir fonskiyonuna git.
					break;
					
				default:
					Sleep(100);
					system("cls");		//Yanl�s secim yapt�g� icin tekrar ana menuye yonlendir.
					menu();
					break;
			}
}

start_game()
{
	system("cls");
		SetConsoleTitle("Tahmin Et Kazan - Oyuna Basla ");
		cout<<" Birinci oyunucunun ismini giriniz."<<endl;	
		cin>>player1;
		
		Sleep(500);		
		
		cout<<"\n\n �kinci oyunucunun ismini giriniz."<<endl;
		cin>>player2;
		
		Sleep(500);
		
		cout<<"\n\n L�tfen bekleyiniz oyun sahnesi haz�rlan�yor... \n\n\n";
		Sleep(1000);
		
		game_scene();
}

howplay(){
	SetConsoleTitle("Tahmin Et Kazan - Nas�l Oynan�r?");
		system("cls");
		cout<<"\n NASIL OYNANIR?.\n\n";
		Sleep(2000);
		cout<<" 1) Tahmin et kazan iki ki�iyle oynanan bir oyundur.\n\n";
		Sleep(2000);
		cout<<" 2) �elik kasan�n d�rt haneli bir �ifresi vard�r.Kasan�n �ifrelerini tek tek ��zmelisiniz. \n\n";
		Sleep(2000);
		cout<<" 3) Oyun, birinci oyuncunun ilk �ifreyi tahmin etmesiyle ba�lar. Birinci oyuncudan sonra ikinci oyuncuda tahminini girer. \n\n";
		Sleep(2500);
		cout<<" 4) Daha sonra kontrol i�lemi ger�ekle�ir. Birinci �ifreyi do�ru giren oyuncuya 5 puan, \n\n    yakla�an oyuncuya 2 puan verilir. D�rt �ifreyi bulana kadar puanlama b�yle devam eder. \n\n";
		Sleep(4000);
		cout<<" 5) Toplam d�rt �ifre vard�r. �ifrelerin hepsini ��zd�kten sonra puan� en y�ksek olan oyuncu oyunu kazan�r. \n\n";
		Sleep(3000);
		cout<<" 6) Ana Men�ye gitmek i�in ""Enter"" tu�una bas�n�z. \n\n\n\n\n ";
		system("pause");
		menu();
}

game_scene()
{
	system("cls");
		SetConsoleTitle("Tahmin Et Kazan - Oyuna Basla ");
		cout<<"\n Kasan�n �ifresi ayarlan�yor l�tfen bekleyiniz..."<<endl;
		Sleep(2000);
		cout<<"Kasan�n �ifresi ayarland�...\n Kasa Sifresi = ****  \n\n Oyuna ba�layabilirsiniz."<<endl;	
		Sleep(1000);
		while(counter!=4)		//Oyunun basladigi kod blogu while ile sayac 4 oldugunda sona erecek
		{
			switch(counter)	//sayac degerimiz 0 dan basliyor ve 1 2 3 diye gidiyor. 4 oldu�unda oyun bitiyor.
			{
				case 0:
					{
						forecast(0);
						counter++;
					}
					break;
				
				case 1:
					{		
						system("cls");
						cout<< "\n Kasan�n �ifresi = "<<safe_password[1]<<"***";	
						forecast(1);
						counter++;
					}
					break;
				
				case 2:
					{
						system("cls");
						cout<< "\n Kasan�n �ifresi = "<<safe_password[1]<<safe_password[2]<<"**";	
						forecast(2);
						counter++;
					}
					break;	
					
				case 3:
					{	
						system("cls");
						//Case 0 da olan i�lemlerin ayn�s�n� yap�yor. Tek fark kasan�n birinci,ikinci ve ���nc� �ifresini buldu�u i�in kasan�n birinci,ikinci ve ���nc� �ifresini ekrana yazd�rd�k.
						cout<< "\n Kasan�n �ifresi = "<<safe_password[1]<<safe_password[2]<<safe_password[3]<<"*";
						forecast(3);	
						counter++;
						end_game();
					}
					break;	
				default:
					{
						system("cls");
						Sleep(1000);
						exit(0);
					}
				break;								
			}
		}	
}

void forecast(int value)
{
	value++;
	while(true)
	{
			cout<<endl<<value<<". �ifre i�in tahmininizi giriniz... "<<endl;
						cout<<" P1:";
						cin>>p1;
						
						cout<<" P2:";
						cin>>p2;
						
						//Sifreye yaklasan oyuncuya 2 puan vermek icin tahmininin farkini aliyoruz.
							if(safe_password[value]>p1)
								p1_remainder=safe_password[value]-p1;
							if(safe_password[value]<p1)
								p1_remainder=p1-safe_password[value];
							if(safe_password[value]>p2)
								p2_remainder=safe_password[value]-p2;
							if(safe_password[value]<p2)
								p2_remainder=p2-safe_password[value];
							
							//bu blokta bilen oyuncuya +5 puan, sifreye en fazla 2 fark uzaklikta olan oyuncuya +2 puan veriliyor.
							if(p1==safe_password[value])
							{
								player1_total+=5;
								cout<<" Tebrikler bildiniz. "<<value<<". �ifre = "<<p1<<"\n P1 puan="<<player1_total<<endl;
								Sleep(1500);
								break;
							}
							else if(p1_remainder==1 || p1_remainder==2)
							{
								player1_total+=2;
								cout<<" Yakla�t�n�z. +2 puan� hak ettin.\n P1 puan="<<player1_total<<endl;				
							}
						    else
							{
								player1_total+=0;
								cout<<" Uzak tahmin ettin.Malesef puan alamad�n.\n P1 puan="<<player1_total<<endl;
							}
								
							if(p2==safe_password[value])
							{
								player2_total+=5;
								cout<<" Tebrikler bildiniz."<<value<<".�ifre = "<<p2<<"\n P2 puan="<<player2_total<<endl;
								Sleep(1500);
								break;
								
							}
							else if(p2_remainder==1 || p2_remainder==2)
							{					
								player2_total+=2;
								cout<<" Yakla�t�n�z. +2 puan� hak ettin.\n P2 puan="<<player2_total<<endl;
							}
							else 
							{
								player2_total+=0;
								cout<<" Uzak tahmin ettin.Malesef puan alamad�n.\n P2 puan="<<player2_total<<endl;
							}		
					}
	}

end_game(){
	system("cls");
		SetConsoleTitle("Tahmin Et Kazan - Kazanan Tablosu ");
		ofstream myfile; 
		
		cout<< " Kasan�n �ifresi = "<<safe_password[1]<<safe_password[2]<<safe_password[3]<<safe_password[4]<<endl<<endl;
		//puanlar� karsilastiriyoruz. 
		if(player1_total>player2_total)
		{
			cout<<"\n -------PUAN TABLOSU-------"<<endl<<" 1. "<<player1<<" puan� = "<<player1_total<<endl;
			cout<<" 2. "<<player2<< " puan� = "<<player2_total;
			cout<<" \n\n Tebrikler "<<player1<<" kazand�...";
		}
		else if(player1_total==player2_total)
		{
			cout<<"\n -------PUAN TABLOSU-------"<<endl<<" 1. "<<player1<<" puan� = "<<player1_total<<endl;
			cout<<" 2. "<<player2<< " puan� = "<<player2_total;
			cout<<" \n\n Kazanan yok berabere bitti...";
		}
		else
		{
			cout<<"\n\n -------PUAN TABLOSU-------"<<endl<<" 1. "<<player2<<" puan� = "<<player2_total<<endl;
			cout<<" 2. "<<player1<< " puan� = "<<player1_total<<endl;
			cout<<"\n Tebrikler "<<player2<<" kazand�...";
		}
			
		
		cout<<"\n\n\n 1- Oyunu Kapat..."<<endl;
		cout<<" 2- Skor Tablosunu not defterine yazd�r...\n\n L�tfen se�im yap�n�z = ";
		cin>>counter;
		switch(counter)
		{
			case 1:
				cout<<"\n\n Oyun Kapat�l�yor.";	//oyun kapaniyor...
				Sleep(1500);
				exit(0);
				break;
			case 2:
				cout<<"\n\n Skor Tablosu masa�st�n�ze yazd�r�ld�. Oyun birazdan kapanacak.";
				myfile.open("Score_table.txt");
				
				if(player1_total>player2_total)	//kazanan� belirleyip txt defterine yazd�r�yoruz.
				{
					myfile<<"\n -------PUAN TABLOSU-------\n 1. "<<player1<<" puan� = "<<player1_total;
					myfile<<"\n 2. "<<player2<< " puan� = "<<player2_total;
					myfile<<" \n\n Tebrikler "<<player1<<" kazand�...";
				}
				else if(player1_total==player2_total)
				{
					myfile<<"\n -------PUAN TABLOSU-------\n 1. "<<player1<<" puan� = "<<player1_total;
					myfile<<"\n 2. "<<player2<< " puan� = "<<player2_total;
					myfile<<" \n\n Kazanan yok berabere bitti...";
				}
				else
				{
					myfile<<"\n\n -------PUAN TABLOSU-------\n 1. "<<player2<<" puan� = "<<player2_total;
					myfile<<"\n 2. "<<player1<< " puan� = "<<player1_total;
					myfile<<" \n\n Tebrikler "<<player2<<" kazand�...";
				}
				myfile.close();
				Sleep(5000);
				exit(0);
				break;
				
			default:
				cout<<"\n Yanl�� se�im yapt�n�z.Oyun kapat�l�yor.";	
				exit(0);
				break;			
		}	
}

