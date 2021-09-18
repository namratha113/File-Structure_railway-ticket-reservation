#include <iostream>
#include<stdio.h>
#include<stdlib.h>		//standard library
#include<conio.h>		//getch function
#include<dos.h>			//delay function
#include<windows.h>		//Sleep,gotoxy coordinate functions
#include<iomanip>		//output manipulatons
#include<fstream>		//file handling
#include<string.h>		//string abstract datatype
#include<math.h>		//mathematical operations
#include<time.h>
#include<cwchar>
using namespace std;
typedef struct{
	char name[50];
	int train_num;
	int num_of_seats;


}pd;
	char loc[20];
void gotoxy (int x, int y);	//handle output on screen
void frame ();			//frame for every dialog box
void frame_fix();
char *date_time ();
void scroll_note();
void flow(char *ch);
COORD coord = {0, 0};
void menupage();
void login();
void viewdetails(void);							//view details of all the trains
void cancel(void);
void printticket(char name[],int,int,float);	//print ticket
void specifictrain(int);						//print data related to specific train
float charge(int,int);
void insert();							//charge automatically w.r.t number of seats and train
class date;
class date		//class current date and time of system
{
	public:
		int aday,amonth,ayear,ahour,amin,asec;
	void date_times()
	{
		SYSTEMTIME t;		//pre defined in time.h header
 		GetLocalTime(&t);
		aday=t.wDay,amonth=t.wMonth,ayear=t.wYear,ahour=t.wHour,amin=t.wMinute,asec=t.wSecond;

	}
};
class reservation{
	public:
		string resid,res_id;
		string name;
		string num_of_seats;
		string train_num;
		int count;
		float charges;
		void main1();
		int search1(string);
		int delete_from_file1(string);
		string buffer1;
		void insert();
		void update();
};


class mainp {
	public:
	void login();
	void menupage();
};

void gotoxy (int x, int y)	//defining/initializing to predefined objects
{
    coord.X = x;
    coord.Y = y; // X and Y coordinates
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void frame()
{
	int i,j=117;
	for(i = 0;i<118,j>=0;i++,j--)
	{
		gotoxy(i,3);
		Sleep(0.9);
		cout<<"_";
		gotoxy(j,22);
		Sleep(0.9);
		cout<<"_";
	}
	gotoxy(90,2);
	char s[20];
	strcpy(s,date_time());
	cout<<s;		//every frame has date on the right top

}
void frame1()	//instead of flow line fixing the frame
{
	int i;
	for(i = 0;i<118;i++)
	{
		gotoxy(i,3);
		cout<<"_";
		Sleep(0.5);
	}
	gotoxy(90,2);
	char s[20];
	strcpy(s,date_time());
	cout<<s;
}
char *date_time()
{
	time_t t;
	time(&t);
	char *loc=ctime(&t);
	return loc;	//returns local time and date
}
void scroll_note()	//welcome note
{
	system("color F4");
	int j,i,x,y;
	CONSOLE_FONT_INFOEX cfi;
	cfi.cbSize=sizeof(cfi);
	cfi.nFont=0;
	cfi.dwFontSize.X=8;
	cfi.dwFontSize.Y=18;
	cfi.FontFamily=FF_DONTCARE;
	cfi.FontWeight=700;
	wcscpy(cfi.FaceName,L"Courier");
	SetCurrentConsoleFontEx(GetStdHandle(STD_OUTPUT_HANDLE),FALSE,&cfi);
	gotoxy(30,8);cout << char(201);      for(int i=0; i<49; i++){cout << char(205);}      cout << char(187);
	gotoxy(30,9); cout << char(186) << "                  				" << char(186);
	gotoxy(30,10);cout << char(186) << "                     				" << char(186);
	gotoxy(30,11);cout << char(186) << "  		           					";gotoxy(80,11); cout<< char(186);
	gotoxy(30,12);cout << char(186) << "                  					" ;gotoxy(80,12); cout<< char(186);
	gotoxy(30,13);cout << char(186) << "                     				" << char(186);
	gotoxy(30,14);cout << char(186) << "                     				" << char(186);
	gotoxy(30,15);cout << char(186) << "                   				" << char(186);
	gotoxy(30,16);cout << char(200);      for(int i=0; i<49; i++){cout << char(205);}      cout << char(188) << endl;

	gotoxy(39,12);cout<<"TRAIN TICKET RESERVATION";
	for(int j=0,k=115;j<=115,k>=0;j++,k--)
	{

		gotoxy(j,4);cout<<"*";
		Sleep(1);
		gotoxy(k,20);cout<<"*";

		Sleep(1);
	}
	gotoxy(86,23);cout<<"YIT";
	gotoxy(86,24);cout<<"BATCH-8\n";
	gotoxy(86,26);system("PAUSE");

}
void mainp::login(){
	system("color 5F");
	char addname[30],pass[30];
	char adname1[]="admin";
	char password1[]="admin";
	char adname2[]="user";
	char password2[]="pass";
	while(1)
	{
		system("cls");
		frame();
		gotoxy(48,2);
		cout<<"LOGIN PAGE ";
		gotoxy(29,10);
		cout<<"Enter name of the admin : ";

		cin>>addname;
			if(strcmp(adname1,addname)==0||strcmp(adname2,addname)==0)
			{
				gotoxy(29,13);
				cout<<"Enter password : ";
				cin>>pass;
				if(strcmp(password1,pass)==0,strcmp(password2,pass)==0)
				{

					menupage();

				}
				{
		printf("\nSorry you have entered the wrong username and password !!!");
		getch();
        system("cls");

		}
			}
	}
}
void mainp::menupage(){
	int op1;
	fstream file;
	while(1)
	{
		system("cls");
		system("COLOR 8F");
		frame();
		gotoxy(48,8);
		cout<<"1.RESERVATION\n ";
		gotoxy(48,10);
		cout<<"2.VIEW DETAILS\n";
		gotoxy(48,12);
        cout<<"3.EXIT\n";
		gotoxy(48,18);
		cout<<"Select your option : ";
		op1=getch();
		if(op1=='1')
		{
			reservation ap;
			ap.main1();
		}
		else if(op1=='2'){
			viewdetails();
			printf("\n\nPress any key to go to Main Menu..");
			getch();
		}
		else if(op1=='2'){
			viewdetails();
			printf("\n\nPress any key to go to Main Menu..");
			getch();
		}
		else if(op1=='3'){
			exit(0);
		}
		else
		{
			gotoxy(48,24);cout<<"INVALID INPUT...TRY AGAIN!!!";
			Sleep(1000);
			system("cls");
		}
	}
}

void reservation::main1(){
    char confirm;
	int i=0;
	float charges;
	 pd passdetails;
	int op1;
	reservation a;
	while(1)
	{
	system("cls");
	system("COLOR 8F");
    frame();
    gotoxy(48,8);
    cout<<"1.ADD NEW PASSENGER ";
		gotoxy(48,10);
		cout<<"2.BACK";
		gotoxy(48,20);
		cout<<"Select your option : ";
		op1=getch();
       if(op1=='1'){


			system("cls");
			system("COLOR 8F");
			frame();
			gotoxy(40,8);

	printf("\nEnter Your Name:> ");
	fflush(stdin);
	gets(passdetails.name);
	printf("\nEnter Number of seats:> ");
	scanf("%d",&passdetails.num_of_seats);
	printf("\n\n>>Press Enter To View Available Trains<< ");
	getch();
	system("cls");
	viewdetails();
	printf("\n\nEnter train number:> ");
	start1:
	scanf("%d",&passdetails.train_num);
	if(passdetails.train_num>=1001 && passdetails.train_num<=1010)
	{
		charges=charge(passdetails.train_num,passdetails.num_of_seats);
		printticket(passdetails.name,passdetails.num_of_seats,passdetails.train_num,charges);
	}
	else
	{
		printf("\nInvalid train Number! Enter again--> ");
		goto start1;
	}

	printf("\n\nConfirm Ticket (y/n):>");
	start:
	scanf(" %c",&confirm);
	if(confirm == 'y')
	{
	    ofstream ofs;
            ofs.open("reserved.txt");
			ofs << passdetails.name;
			ofs << "|";
			ofs << passdetails.num_of_seats;
			ofs << "|";
			ofs <<passdetails.train_num;
			ofs << "|";
			ofs << charges;
			ofs.open("reserved.txt");
			ofs<<endl;
       ofs<<&passdetails.name;
       ofs<<&passdetails.num_of_seats;
       ofs<<&passdetails.train_num;
       ofs<<&charges;

		printf("==================");
		printf("\n Reservation Done\n");
		printf("==================");
		printf("\nPress any key to go back to Main menu");
		getch();

		 ofs.close();
	}
	else
	{
		if(confirm=='n'){
			printf("\nReservation Not Done!\nPress any key to go back to  Main menu!");
		}
		else
		{
			printf("\nInvalid choice entered! Enter again-----> ");
			goto start;
		}
    }
       }
else if(op1=='2'){
			mainp p;
			p.menupage();
		}
		else
		{
			gotoxy(48,24);cout<<"INVALID INPUT...TRY AGAIN!!!";
			Sleep(1000);
			system("cls");
		}

}}
float charge(int train_num,int num_of_seats)
{
		if (train_num==1001)
	{
		return(5000.0*num_of_seats);
	}
	if (train_num==1002)
	{
		return(5000.0*num_of_seats);
	}
	if (train_num==1003)
	{
		return(4500.0*num_of_seats);
	}
	if (train_num==1004)
	{
		return(4500.0*num_of_seats);
	}
	if (train_num==1005)
	{
		return(4000.0*num_of_seats);
	}
	if (train_num==1006)
	{
		return(4000.0*num_of_seats);
	}
	if (train_num==1007)
	{
		return(3500.0*num_of_seats);
	}
	if (train_num==1008)
	{
		return(3500.0*num_of_seats);
	}
	if (train_num==1009)
	{
		return(6000.0*num_of_seats);
	}
	if (train_num==1010)
	{
		return(6000.0*num_of_seats);
	}
}
void viewdetails(void)
{
	system("cls");
	printf("-----------------------------------------------------------------------------");
	printf("\nTr.No\tName\t\t\tDestinations\t\tCharges\t\tTime\n");
	printf("-----------------------------------------------------------------------------");
	printf("\n1001\tRed Lines Express\tBoston to Manhattan\tRs.5000\t\t9am");
	printf("\n1002\tRed Lines Express\tManhattan To Boston\tRs.5000\t\t12pm");
	printf("\n1003\tLA City Express\t\tBoston To L.A\t\tRs.4500\t\t8am");
	printf("\n1004\tLA City Express\t\tL.A To Boston\t\tRs.4500\t\t11am");
	printf("\n1005\tIron City Express\tBoston To Chicago\tRs.4000\t\t7am");
	printf("\n1006\tIron City Express\tChicago To Boston\tRs.4000\t\t9.30am");
    printf("\n1007\tKeystone Express\tBoston To Washington\tRs.3500\t\t1pm");
    printf("\n1008\tKeystone Express\tWashington To Boston\tRs.3500\t\t4pm");
    printf("\n1009\tMeteor Express\t\tBoston To Miami\t\tRs.6000\t\t3.35pm");
    printf("\n1009\tMeteor Express\t\tMiami To Boston\t\tRs.6000\t\t4.15pm");
}

void printticket(char name[],int num_of_seats,int train_num,float charges)
{
	system("cls");
	printf("-------------------\n");
	printf("\tTICKET\n");
	printf("-------------------\n\n");
	printf("Name:\t\t\t%s",name);
	printf("\nNumber Of Seats:\t%d",num_of_seats);
	printf("\nTrain Number:\t\t%d",train_num);
	specifictrain(train_num);
	printf("\nCharges:\t\t%.2f",charges);
}
void specifictrain(int train_num)
{

	if (train_num==1001)
	{
		printf("\nTrain:\t\t\tRed Lines Express");
		printf("\nDestination:\t\tBoston to Manhattan");
		printf("\nDeparture:\t\t9am ");
	}
	if (train_num==1002)
	{
		printf("\nTrain:\t\t\tRed Lines Express");
		printf("\nDestination:\t\tManhattan to Boston");
		printf("\nDeparture:\t\t12pm");
	}
	if (train_num==1003)
	{
		printf("\nTrain:\t\t\tLA City Express");
		printf("\nDestination:\t\tBoston to L.A");
		printf("\nDeparture:\t\t8am");
	}
	if (train_num==1004)
	{
		printf("\nTrain:\t\t\tLA City Express");
		printf("\nDestination:\t\tL.A to Boston");
		printf("\nDeparture:\t\t11am ");
	}
	if (train_num==1005)
	{
		printf("\nTrain:\t\t\tIron City Express");
		printf("\nDestination:\t\tBoston to Chicago");
		printf("\nDeparture:\t\t7am");
	}
	if (train_num==1006)
	{
		printf("\ntrain:\t\t\tIron City Express");
		printf("\nDestination:\t\tChicago to Boston");
		printf("\nDeparture:\t\t9.30am ");
	}
	if (train_num==1007)
	{
		printf("\ntrain:\t\t\tKeystone Express");
		printf("\nDestination:\t\tBoston to Washington");
		printf("\nDeparture:\t\t1pm ");
	}
	if (train_num==1008)
	{
		printf("\ntrain:\t\t\tKeystone Express");
		printf("\n Destination:\t\tWashington to Boston");
		printf("\nDeparture:\t\t4pm ");
	}
	if (train_num==1009)
	{
		printf("\ntrain:\t\t\tMeteor Express");
		printf("\nDestination:\t\tBoston to Miami");
		printf("\nDeparture:\t\t3.35pm ");
	}
	if (train_num==1010)
	{
		printf("\ntrain:\t\t\tMeteor Express");
		printf("\nDestination:\t\tMiami to Boston");
		printf("\nDeparture:\t\t1.15 ");
	}
}
int main() {//int argc, char** argv
	mainp q;
	scroll_note();
	Sleep(10);
    q.login();

	return 0;
}

