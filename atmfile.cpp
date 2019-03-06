#include<iostream>
#include <fstream>
#include <conio.h>
#include <stdlib.h>
using namespace std;
int pin=1234;
int data;
int trs;
class atm
{
	int amount;
		public:
		void setdata()
		{
			cout<<"\nEnter Amount : ";
			
			cin>>amount;
		}
		int getdata()
		{
			return amount;
		}
};



int realrs()
{
	
	ifstream fin;
	fin.open("ATM.dat",ios::binary|ios::app);
	
	fin.seekg(-7,ios::end);
	
	
	if(fin)
	{
		fin>>data;
	}
	
	
	
	fin.close();
	trs=data;
	
}






void balinq()
{
	realrs();
	cout<<"\nAvailable Balance : "<<trs<<endl;
	
}




void withdrawal()
{
	ofstream fout;
	
	abc:
	atm obj;
	obj.setdata();
	if (obj.getdata()%100==0)
	{
	cout<<"Enter your Pin  ";
	cin>>pin;
	if (pin==1234)
	{

	trs=trs-(obj.getdata());
	int cashwid= obj.getdata();
	fout.open("ATM.dat",ios::binary|ios::app);
	fout<<"\nCash Withdrawal : "<<cashwid<<"                          Available balance      "<<trs<<endl;


	fout.close();
	
	cout<<"\nCash Withdrawal : "<<cashwid<<endl;
	cout<<"Available balance : "<<trs<<endl;
	
	}
	else
	cout<<"Enter incorrect PIN"<<endl;
	}
	else
	{
	cout<<"Enter the Multiple of 100 or 500"<<endl;
	goto abc;
	}
	
	fout.close();
}


void Credit()
{
	int trs1;
	cout<<"Enter amount to deposit : ";
	cin>>trs1;
	trs=trs+trs1;
	cout<<trs1<<" rupees add in your account"<<endl;
	ofstream fout;
	fout.open("ATM.dat",ios::binary|ios::app);
	fout<<trs1<<" rupees credited                            Available balance       "<<trs<<endl;
	fout.close();
}


void  transfer()
{
	unsigned long int card1,card2;
	int transf;
	
	ofstream fout;
	fout.open("ATM.dat",ios::binary|ios::app);
		
	cout<<"1.By Card to Card (using card no.)"<<endl;
	cout<<"2.By Card to Account (using account no.)"<<endl;
	cin>>transf;
	if (transf==1)
	{
		cout<<"Enter the card no.     ";
		cin>>card1;
		cout<<"Re-enter the card no.   ";
		cin>>card2;
		if (card1==card2)
		{
			atm obj;
			obj.setdata();
			cout<<"Enter your PIN  ";
			cin>>pin;
			if (pin==1234)
			{
				trs=trs-(obj.getdata());
				cout<<"Transaction Complete"<<endl;
				cout<<"Available Balance   "<<trs<<endl;
				fout<<"\n"<<obj.getdata()<<"  Amount Transfered By Card                  Available Balance      "<<trs<<endl;
			}
		else
		{
			cout<<"Incorrect PIN"<<endl;
		}
		}
	else
	{
		cout<<"You Entered Different Card No."<<endl;
	}
	}
	else if (transf==2)
	{	
		cout<<"Enter The Account No.   ";
		cin>>card1;
		cout<<"Re-enter The Account No.   ";
		cin>>card2;
		if (card1==card2)
		{
			atm obj;
			obj.setdata();
			trs=trs-(obj.getdata());
			cout<<"Enter your PIN  ";
			cin>>pin;
			if (pin==1234)
			{
				cout<<"Transaction complete"<<endl;
				cout<<"Available Balance  "<<trs<<endl;
				fout<<"\n"<<obj.getdata()<<" Amount transfer by account no.            Available Balance      "<<trs<<endl;
			}
			else
			{
				cout<<"Incorrect PIN"<<endl;
			}
		}
		else
		{
			cout<<"You Entered Different Account No."<<endl;
		}
	}
	fout.close();
}

void ministat()
{
	
	char ch;
	ifstream fin;
	fin.open("ATM.dat",ios::binary|ios::app);
	while(fin)
	{
	char ch;
	fin.get(ch);
	cout<<ch;
	}
}




int main()
{
	int choice;
	cout<<"                           WELCOME TO OUR ATM"<<endl;
	
	do
	{
		cout<<"***********************************************************************************\n";
		cout<<"*                                                                                 *\n";
		cout<<"*   1. Deposit                              2. Balance Enquiry                    *\n";
		cout<<"*                                                                                 *\n";
		cout<<"*   3. Withdrawl                            4. Transfer                           *\n";
		cout<<"*                                                                                 *\n";
		cout<<"*   5. Mini Statement                       6. Exit                               *\n";
		cout<<"*                                                                                 *\n";
		cout<<"*                                                                                 *\n";
		cout<<"*              ENTER           YOUR            CHOICE                             *\n";
		cout<<"*                                                                                 *\n";
		cout<<"***********************************************************************************\n";
		cin>>choice;                                                                                 
		realrs();
		
		
		
		switch(choice)
		{
		
			case 1: Credit();
			break;
			case 2: balinq();
			break;
			case 3: withdrawal();
			break;
			case 4: transfer();
			break;
			case 5: ministat();
			case 6:
			break;
			default: cout<<"INVALID CHOICE"<<endl;
			break;
		}
		getch();
		system("CLS");
	
}
	while(choice!=6);
	
	
cout<<"\n             *****THANKS FOR USING ATM****** ";
}
