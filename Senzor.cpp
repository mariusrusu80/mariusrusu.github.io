#include <iostream>
#include <conio.h>
using namespace std;
	
int main()
{	int temperatura=10,i;
	char buton;
	do
	{
		buton=getch();
		if(buton=='a') temperatura--;
		else if (buton=='d') temperatura++;
		for(i=1;i<=temperatura;i++) 
		cout<<"*";
		cout<<endl;
		
	
	}while(buton!='p');
	return 0;
	
}

