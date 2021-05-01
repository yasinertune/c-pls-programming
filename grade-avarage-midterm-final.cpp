//Yasin Ertune - Ogrencinin vize ve final notuna göre harflendirme yapan program.
#include <iostream>
#include <string>
using namespace std;

float average (int midterm,int final)
{
	float avg=(midterm*0.40)+(final*0.60);
	return avg;
}

string letter_grade(float total)
{
	string letter;
	if(total>=90 && total<100)
		letter="AA";
	else if(total>=80 && total<90)
		letter="BA";
	else if(total>=70 && total<80)
		letter="BB";
	else if(total>=60 && total<70)
		letter="CB";
	else if(total>=50 && total<60)
		letter="CC";
	else if(total>=40 && total<50)
		letter="DC";
	else if(total>=30 && total<40)
		letter="DD";
	else
		letter="FF";
	
	return letter;
}
                                                                 
int main()
{
	float midterm,final,total;
	cout << "Enter midterm note: ";
	cin >>midterm;
	
	cout << "Enter final note: ";
	cin >>final;
	
	total=average(midterm,final);
	cout << "Grade Point Avarage: "<<total<<endl;
	cout << "Letter Grade: "<<letter_grade(total);
	return 0;
}
