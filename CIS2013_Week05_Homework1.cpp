#include <bits/stdc++.h>

using namespace std;

int dayNumber (int day, int month, int year){
	static int t[] = {0, 3, 2, 5, 0, 3, 5, 1, 4, 6, 2, 4};
	
	year -= month < 3;
	return (year + year/4 - year/100 + year/400+ t[month-1] + day)%7;
}

string getMonthName(int monthNumber){
	string months[] = {"January", "February", "March", "April", "May", "June", "July", "August", 
		"September", "October", "November", "December"};
	return (months[monthNumber]);
}

int numberOfDays (int monthNumber, int year){
	//January
	if (monthNumber == 0)
		return (31);
	//February
	if (monthNumber == 1){
		if (year % 400 == 0 || (year % 4 == 0 && year % 100 != 0))
			return (29);
		else
			return (28);
	}
	//March
	if (monthNumber == 2)
		return (31);
	//April
	if (monthNumber == 3)
		return (30);
	//May
	if (monthNumber == 4)
		return (31);
	//June
	if (monthNumber == 5)
		return (30);
	//July
	if (monthNumber == 6)
		return (31);
	//August
	if (monthNumber == 7)
		return (31);
	//September
	if (monthNumber == 8)
		return (30);
	//October
	if (monthNumber == 9)
		return (31);
	//November
	if (monthNumber == 10)
		return (30);
	//December
	if (monthNumber == 11)
		return (31);
		
}

void printCalendar (int year, int whatMonth){
	printf ("	Calendar - %d\n\n", year);
	int days;
	int current = dayNumber (1, 1, year);
	
	
	//for (int i=0; i<12; i++){
		
		days = numberOfDays (whatMonth, year);
		printf ("\n --------------%s-------------\n",
		getMonthName (whatMonth).c_str());
		
		printf ("  Sun  Mon  Tue  Wed  Thu  Fri  Sat\n");
		
		int k;
		
		for (k = 0; k < current; k++)
			printf("		");
		
		for (int j = 1; j <= days; j++){
			printf ("%5d", j);
			
			if (++k > 6){
				k = 0;
				printf("\n");
			}
		}
		if (k)
			printf("\n");
		
		current = k;
	//}
	return;
}

int main(){
	int year = 2018;
	int whatMonth = 0;
	cout << "Please enter a year between 1 and 3000: ";
	cin >> year;
	cout << "Please choose a month from 1 through 12: ";
	//cout << "Please enter the month number choose from the list below:"<<endl;
	/*cout << "0 = January" << endl;
	cout << "1 = February" << endl;
	cout << "2 = March" << endl;
	cout << "3 = April" << endl;
	cout << "4 = May" << endl;
	cout << "5 = June" << endl;
	cout << "6 = July" << endl;
	cout << "7 = August" << endl;
	cout << "8 = September" << endl;
	cout << "9 = October" << endl;
	cout << "10 = November" << endl;
	cout << "11 = December" << endl;*/
	cin >> whatMonth;
	whatMonth = whatMonth -1;
	cout << endl;
	cout << endl;
	printCalendar(year, whatMonth);
	
	return (0);
}