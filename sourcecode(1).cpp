#include<fstream>
#include<iostream>
#include<conio.h>
#include<stdio.h>
#include<windows.h>
#include<string.h>
#include<ctype.h>
using namespace std;
  void gotoxy(int x, int y)
{
   COORD ord;
   ord.X = x;
   ord.Y = y;
   SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), ord);
}
void loading()
{
    int x=0;
       while(x!=3)
       {  gotoxy(45,10);
          cout<<"LOADING. |  |  |  |  |  |  |  |  |  |  |  |   ";
          Sleep(100);
          system("cls");
          gotoxy(45,10);
          cout<<"LOADING.. /  /  /  /  /  /  /  /  /  /  /  / ";
          Sleep(100);
          system("cls");
          gotoxy(45,10);
          cout<<"LOADING... -  -  -  -  -  -  -  -  -  -  - ";
          Sleep(100);
          system("cls");
          gotoxy(45,10);
          cout<<"LOADING.... \\  \\  \\  \\  \\  \\  \\  \\  \\  \\ ";
          Sleep(100);
          system("cls");
          x++;
       }
}
void board_login();
void board_control();
void board_profile_edit();
void board_print_profile();
void retail_login();
void retail_control();
void create_retail_node();
void remove_retail_node();
void edit_retail_detail();
void cust_login();
void cust_control();
void create_customer_node();
void remove_customer_node();
void edit_cust_detail();
int x=0,y=0,z=0;
void main_main()
{
        char ch;
        system("cls");
		cout<<"\n\t\t\t\t\t\t      MAIN MENU \n";
		cout<<"\t\t\t\t\t__________________________________\n\n";
		cout<<"\n\t\t\t\t\t\t1.Board Administrator Login \n";
		cout<<"\n\t\t\t\t\t\t2.Retailer Login\n";
		cout<<"\n\t\t\t\t\t\t3.Customer Login\n";
		cout<<"\n\t\t\t\t\t\t4.Exit\n";
		cout<<"\n\t\tEnter your choice :  ";
		ch=getche();
		switch(ch)
		{
		    case '1':board_login();
		             break;
            case '2':retail_login();
                     break;
            case '3':cust_login();
                     break;
            case '4':exit(0);
            default: cout<<"Wrong Input";
                     main_main();
		}

}
  void start()
{
	Sleep(800);
    gotoxy(45,10);
    cout<<"Electricity Supply Management System\n";
	Sleep(600);
	system("color 71");
	gotoxy(45,12);
    Sleep(1000);
	cout<<"\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB";
	Sleep(2000);
	cout<<"\xDB\xDB\xDB\xDB";
	Sleep(1000);
	cout<<"\xDB\xDB\xDB\xDB\xDB\xDB";
	Sleep(1000);
	cout<<"\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB";
	Sleep(100);
	cout<<"\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB";
	Sleep(1000);
	main_main();
}

struct board_info
{
    struct retail_info_node *ret_start=NULL,*ret_current,*ret_current1;
    char boar_name[100],boar_phno[20];
    struct boar_addr
    {
    char boar_state[20],boar_city[20],boar_area[20],boar_landmark[20],boar_pincode[20];
    }badr;
    struct boar_login_info
    {
    char busrname[20];
    char bpass[20];
    char bcnfpass[20];
    }bli;
    int a;
}b;
struct retail_info_node
{
    struct cust_info_node *cust_start=NULL,*cust_current,*cust_current1;
    int ret_id;
    char ret_name[100];
    char ret_phno[20];
    char ret_email[20];
    struct ret_login_info
   {
    char rusrname[20];
    char rpass[20];
    char rcnfpass[20];
   }rli;
    struct ret_demand
   {
    float tvoltage,tload;
    int tno_of_meters;
   }rd;
    struct ret_addr
   {
    char ret_state[20],ret_city[20],ret_area[20],ret_landmark[20],ret_pincode[20],ret_hno[20];
   }radr;
    struct ret_supply_dates
   {
    char rsdd,rsmm,rsyyyy;
    char redd,remm,reyyyy;
   }rsd;
   int tot=0;
   struct retail_info_node *rifn;
}r;
struct cust_info_node
{ int cust_id;
  char cust_name[100];
  char cust_phno[20];
  char cust_email[20];
  struct cust_login_info
  {
    char cusrname[20];
    char cpass[20];
    char ccnfpass[20];
  }cli;
  struct cust_demand
  {
    float voltage,load;
    int no_of_meters;

  }cd;
  struct cust_addr
  {
    char cust_state[20],cust_city[20],cust_area[20],cust_landmark[20],cust_pincode[20],cust_hno[20];
  }cadr;
  struct cust_supply_dates
  {
    char sdd,smm,syyyy;
    char edd,emm,eyyyy;
  }csd;
  struct cust_info_node *cifn;
  int tot=0;
}c;
void board_login()
{      system("cls");
       loading();
       int y=0;
       char get1[100],get2[100],get3[100];
       if(x==0)
       {
          strcpy(b.bli.busrname,"admin");
          strcpy(b.bli.bpass,"admin");
          strcpy(b.bli.bcnfpass,"admin");
          x++;
       }
       do{
       cout<<"\n\t\t\t\t\t\t  BOARD ADMINISTRATOR LOGIN \n";
       cout<<"\t\t\t\t\t______________________________________\n\n";
       cout<<"\n\t\t\t\t\t\t(DEFAULT USERNAME AND PASSWORD ARE 'admin' 'admin')\n";
       cout<<"\n\t\t\t\t\t\tEnter username : ";
       cin>>get1;
       cout<<"\n\t\t\t\t\t\t";
       cout<<"Enter password : ";
       cin>>get2;
       if(strcmp(b.bli.busrname,get1)==0)
       {   if(strcmp(b.bli.bpass,get2)==0)
           {
           cout<<"\n\t\t\t\t\t\tLogged in successfully\n ";
           Sleep(2000);
           system("cls");
           y++;
           board_control();
           }
           else
           {
            cout<<"\n\t\t\t\t\t\tYou entered the wrong password. Try again.\n";
            Sleep(2000);
            system("cls");
           }
       }
       else
       {
           cout<<"\n\t\t\t\t\t\tYou entered the wrong username. Try again.\n";
           Sleep(2000);
           system("cls");
       }
       }while(y==0);
}
void board_control()
{   loading();
    char get1[100],get2[100],get3[100],ch;
    strcpy(get1,b.bli.busrname);
    cout<<"\n\t\t\t\t\t\t  WELCOME "<<get1<<" \n";
    cout<<"\t\t\t\t\t______________________________________\n\n";
    cout<<"\n\t\t\t\t\t\t1. Edit profile details\n";
    cout<<"\n\t\t\t\t\t\t2. Print your profile details\n";
    cout<<"\n\t\t\t\t\t\t3. View retailer information\n";
    cout<<"\n\t\t\t\t\t\t4. View customer information\n";
    cout<<"\n\t\t\t\t\t\t5. Go back to main menu\n";
    cout<<"\n\t\t\t\t\t\tEnter your choice ::  ";
    ch=getche();
    switch(ch)
    {
    case '1': board_profile_edit();
              break;
    case '2': board_print_profile();
              break;
    case '3': retail_control();
              break;
    case '4': cust_control();
              break;
    case '5': main_main();
              break;
    default: cout<<"Invalid option entered!";
             board_control();
    }
}
void board_profile_edit()
{
    loading();
    char ch,y;
    cout<<"\n\t\t\t\t\t\t       Board profile Edit         \n";
    cout<<"\t\t\t\t\t_____________________________________\n\n";
    cout<<"\n\t\t\t\t\t\t1.Change Username                 \n";
    cout<<"\n\t\t\t\t\t\t2.Change Password                 \n";
    cout<<"\n\t\t\t\t\t\t3.Edit Address details            \n";
    cout<<"\n\t\t\t\t\t\t4.Back to previous menu           \n";
    cout<<"\n\t\t\t\t\t\t5.Exit                            \n";
    cout<<"\n\t\tEnter your choice :  ";
    ch=getche();
    switch(ch)
    {
        case '1': system("cls");
                  Sleep(300);
                  cout<<"\n\n\t\t\t\t\t\tCurrent username is :  "<<b.bli.busrname<<endl;
                  cout<<"\t\t\t\t\t\tEnter new username  :  ";
                  cin>>b.bli.busrname;
                  cout<<"\n\t\t\t\t\t\t New username saved"<<endl;
                  Sleep(2000);
                  board_profile_edit();
                  break;
        case '2': system("cls");
                  Sleep(300);
                  cout<<"\n\n\t\t\t\t\t\tCurrent password is  : "<<b.bli.bpass<<endl;
                  cout<<"\n\t\t\t\t\t\tEnter new password   : ";
                  cin>>b.bli.bpass;
                  cout<<"\t\t\t\t\t\tRenter new password  : ";
                  cin>>b.bli.bcnfpass;
                  cout<<"\t\t\t\t\t\tPassword changed!";
                  Sleep(2000);
                  board_profile_edit();
                  break;
        case '3': system("cls");
                  if(x==0)
                  {
                      cout<<"\n\t\t\t\t\t\t No address has been added.\n";
                      cout<<"\n\t\t\t\t\t\t Enter State        : ";
                      cin>>b.badr.boar_state;
                      cout<<"\n\t\t\t\t\t\t Enter the City     : ";
                      cin>>b.badr.boar_city;
                      cout<<"\n\t\t\t\t\t\t Enter the area     : ";
                      cin>>b.badr.boar_area;
                      cout<<"\n\t\t\t\t\t\t Enter the pincode  : ";
                      cin>>b.badr.boar_pincode;
                      cout<<"\n\t\t\t\t\t\t Enter the landmark : ";
                      cin>>b.badr.boar_landmark;
                      x++;
                      cout<<"\n\t\t\t\t\t\t Address has been added \n";
                      board_profile_edit();
                  }
                  else
                 {
                   cout<<"\n\t\t\t\t\t\t Address has been added \n";
                   cout<<"\n\t\t\t\t\t\t State    : ";
                   puts(b.badr.boar_state);
                   cout<<"\n\t\t\t\t\t\t City     : ";
                   puts(b.badr.boar_city);
                   cout<<"\n\t\t\t\t\t\t Area     : ";
                   puts(b.badr.boar_area);
                   cout<<"\n\t\t\t\t\t\t Pincode  : ";
                   puts(b.badr.boar_pincode);
                   cout<<"\n\t\t\t\t\t\t Landmark : ";
                   puts(b.badr.boar_landmark);
                   cout<<"\n\t\t\t\t\t\t Do you wish to edit this address?  (0/1) ";
                   y=getche();
                   if(y=='1')
                   {
                      cout<<"\n\t\t\t\t\t\t Enter State        : ";
                      gets(b.badr.boar_state);
                      cout<<"\n\t\t\t\t\t\t Enter the City     : ";
                      gets(b.badr.boar_city);
                      cout<<"\n\t\t\t\t\t\t Enter the area     : ";
                      gets(b.badr.boar_area);
                      cout<<"\n\t\t\t\t\t\t Enter the pincode  : ";
                      gets(b.badr.boar_pincode);
                      cout<<"\n\t\t\t\t\t\t Enter the landmark : ";
                      gets(b.badr.boar_landmark);
                      x++;
                      cout<<"\n\t\t\t\t\t\t Address has been added \n";
                      board_profile_edit();
                   }
                   else
                   {
                       cout<<"\n\t\t\t\t\t\t Redirecting to previous menu \n";
                       Sleep(2000);
                       board_profile_edit();
                   }
                 }
                 break;
        case '4': board_control();
                 break;
        case '5': cout<<"\n\t\t\t\t\t\t Logging out and exiting ";
                  exit(0);
        default: cout<<"\n\t\t\t\t\t\t Please enter a valid choice.";
                 board_profile_edit();
    }
}
void board_print_profile()
{
    loading();
    if(x==0)
    {   system("cls");
        cout<<"\n\n\n\n\n\n\t\t\t\t\t\tAddress details have to be added to print";
        Sleep(3000);
        board_control();
    }
    else
    {
    cout<<"\n\t\t\t\t\t\t"<<b.bli.busrname<<" your profile details are  \n" ;
    cout<<"\n\t\t\t\t\t\t____________________________\n";
    cout<<"\n\t\t\t\t\t\tUsername is :  "<<b.bli.busrname<<endl;
    cout<<"\n\n\t\t\t\t\t\tAddress details";
    cout<<"\n\t\t\t\t\t\t____________________________\n";
    cout<<"\n\t\t\t\t\t\t State    : ";
    puts(b.badr.boar_state);
    cout<<"\n\t\t\t\t\t\t City     : ";
    puts(b.badr.boar_city);
    cout<<"\n\t\t\t\t\t\t Area     : ";
    puts(b.badr.boar_area);
    cout<<"\n\t\t\t\t\t\t Pincode  : ";
    puts(b.badr.boar_pincode);
    cout<<"\n\t\t\t\t\t\t Landmark : ";
    puts(b.badr.boar_landmark);
    }
    char ch=getch();
    board_profile_edit();
}
void retail_login()
{
   system("cls");
   loading();
   int x=0,y=0;
   char get1[100],get2[100],get3[100],ch;
       cout<<"\n\t\t\t\t\t\t  RETAILER LOGIN \n";
       cout<<"\t\t\t\t\t______________________________\n\n";
       cout<<"\n\t\t\t\t\t\tAre you a returning retailer?  (Y/N)  : ";
       ch=getche();
       if(ch=='Y')
      {
       if(b.ret_start==NULL)
       {
           cout<<"\n\n\n\t\t\tThere is no retailer added to the list till now. Redirecting to main menu\n";
           Sleep(2000);
           system("cls");
           main_main();

       }
       else
       {
       cout<<"\n\t\t\t\t\t\tEnter username : ";
       cin>>get1;
       cout<<"\n\t\t\t\t\t\t";
       cout<<"Enter password : ";
       cin>>get2;
       b.ret_current1=b.ret_start;
       do
       {
       if(strcmp(b.ret_current1->rli.rusrname,get1)==0)
       {
           do
           {
           if(strcmp(b.ret_current1->rli.rpass,get2)==0)
           {
           cout<<"\n\t\t\t\t\t\tLogged in successfully\n ";
           Sleep(2000);
           system("cls");
           y++;
           edit_retail_detail();
           }
           else
           {
            cout<<"\n\t\t\t\t\t\tYou entered the wrong password. Try again.\n";
            Sleep(2000);
            system("cls");
           }
           }while(y==0);
       }
       else
       {   b.ret_current1=b.ret_current1->rifn;
           x++;
       }

       }while(b.ret_current1->rifn!=NULL);
      }
      }
      else
      {
       system("cls");
       cout<<"\n\t\t\t\t\t\tNEW USERS PLEASE CONTACT BOARD ADMIN TO GET REGISTERATION";
       Sleep(2000);
       main_main();
      }
}
void retail_control()
{
   loading();
   system("cls");
   char ch,y;
    cout<<"\n\t\t\t\t\t\t     Retailer Information         \n";
    cout<<"\t\t\t\t\t____________________________________\n\n";
    cout<<"\n\t\t\t\t\t\t1.Add retailer                    \n";
    cout<<"\n\t\t\t\t\t\t2.Delete retailer                 \n";
    cout<<"\n\t\t\t\t\t\t3.Back to previous menu           \n";
    cout<<"\n\t\tEnter your choice :  ";
    ch=getche();
    switch(ch)
    {
        case '1': create_retail_node();
                  break;
        case '2': remove_retail_node();
                  break;
        case '3': cout<<"\n\t\t\t\t\t\tLogging off\n\n";
                  Sleep(3000);
                  board_control();
                  break;
        default: cout<<"\n\t\t\t\t\t\tInvalid Choice entered\n\n";
                 Sleep(2000);
                 retail_control();
    }

}
void create_retail_node()
{
    system("cls");
    loading();
    r.tot++;
    struct retail_info_node *new_node=new struct retail_info_node;
    cout<<"\n\t\t\t\t\t\t     Add new retailer           \n";
    cout<<"\t\t\t\t\t__________________________________\n\n";
    cout<<"\n\t\t\t\t\t\t1.Retailer id is      :   "<<r.tot<<endl;
    new_node->ret_id=r.tot;
    cout<<"\n\t\t\t\t\t\t2.Enter Username      :   ";
    cin>>new_node->rli.rusrname;
    cout<<"\n\t\t\t\t\t\t3.Enter password      :   ";
    cin>>new_node->rli.rpass;
    cout<<"\n\t\t\t\t\t\t4.Confirm password    :   ";
    cin>>new_node->rli.rcnfpass;
    cout<<"\n\t\t\t\t\t\t5.Enter phone number  :   ";
    cin>>new_node->ret_phno;
    cout<<"\n\t\t\t\t\t\t6.Enter Email         :   ";
    cin>>new_node->ret_email;
    cout<<"\n\t\t\t\t\t\tEnter address details :   ";
    Sleep(200);
    cout<<"\n\t\t\t\t\t\t\t\t1.Enter state    :   ";
    cin>>new_node->radr.ret_state;
    cout<<"\n\t\t\t\t\t\t\t\t2.Enter city     :   ";
    cin>>new_node->radr.ret_city;
    cout<<"\n\t\t\t\t\t\t\t\t3.Enter area     :   ";
    cin>>new_node->radr.ret_area;
    cout<<"\n\t\t\t\t\t\t\t\t4.Enter landmark :   ";
    cin>>new_node->radr.ret_landmark;
    cout<<"\n\t\t\t\t\t\t\t\t1.Enter home no. :   ";
    cin>>new_node->radr.ret_hno;
    cout<<"\n\t\t\t\t\t\t\t\t6.Enter Demand details :   ";
    cout<<"\n\t\t\t\t\t\t\t\t\tEnter voltage allowance :   ";
    cin>>new_node->rd.tvoltage;
    cout<<"\n\t\t\t\t\t\t\t\t\tEnter total load :   ";
    cin>>new_node->rd.tload;
    cout<<"\n\t\t\t\t\t\t\t\t\tEnter number of meters :   ";
    cin>>new_node->rd.tno_of_meters;
    cout<<"\n\t\t\t\t\t\t7.Enter start and end dates :   ";
    cout<<"\n\t\t\t\t\t\t START : ";
    new_node->rsd.rsdd=getche();cout<<"/";new_node->rsd.rsmm=getche();cout<<"/1";new_node->rsd.rsyyyy=getche();
    cout<<"\n\t\t\t\t\t\t END   : ";
    new_node->rsd.redd=getche();cout<<"/";new_node->rsd.remm=getche();cout<<"/1";new_node->rsd.reyyyy=getche();
    if(b.ret_start==NULL)
    {
        new_node->rifn=NULL;
        b.ret_start=new_node;
        b.ret_current=new_node;
    }
    else
    {
        new_node->rifn=NULL;
        b.ret_current->rifn=new_node;
        b.ret_current=new_node;
    }
    cout<<"\n\t\t\t\t\t\t Do you want to insert another retailer?  (0/1) : ";
    int i;
    cin>>i;
    if(i==0)
    {
    	retail_control();
	}
	else
	{
       create_retail_node();
	}
}
void remove_retail_node()
{
     int a=0;
     char get1[100];
     cout<<"\n\t\t\t\t\t\tEnter username of the retailer to delete : ";
     cin>>get1;
     b.ret_current1=b.ret_start;
     do
     {
       if(strcmp(b.ret_current1->rli.rusrname,get1)==0)
       {
         struct retail_info_node *x,*y;
         x=b.ret_start;
         for(int i=0;i<a-1;i++)
         {
            x=x->rifn;
            cout<<x->rli.rusrname<<" ";
         }
         y=b.ret_current1->rifn;
         x->rifn=y;
         free(b.ret_current1);
         cout<<"\n\t\t\t\t\t\tThe retailer with username : "<<get1<<" was deleted\n";
         r.tot--;
         Sleep(4000);
         retail_control();
       }
       else
       {
         b.ret_current1=b.ret_current1->rifn;
         a++;
       }
       if(a>r.tot)
       {
           cout<<"\n\t\t\t\t\t\tThe retailer with username : "<<get1<<" does not exist. Please enter a valid name"<<endl;
           Sleep(4000);
           remove_retail_node();
       }

     }while(b.ret_current1->rifn!=NULL);
}
void edit_retail_detail()
{
    char ch;
    system("cls");
    loading();
    cout<<"\n\t\t\t\t\t\t   Welcome "<<b.ret_current1->rli.rusrname<<endl;
    cout<<"\n\t\t\t\t______________________________________\n";
    cout<<"\n\t\t\t\t\t\t1.Change Username                 \n";
    cout<<"\n\t\t\t\t\t\t2.Change Password                 \n";
    cout<<"\n\t\t\t\t\t\t3.Edit Address details            \n";
    cout<<"\n\t\t\t\t\t\t4.Back to previous menu           \n";
    cout<<"\n\t\t\t\t\t\t5.Exit                            \n";
     cout<<"\n\t\tEnter your choice :  ";
    ch=getche();
    switch(ch)
    {
        case '1': system("cls");
                  Sleep(300);
                  cout<<"\n\n\t\t\t\t\t\tCurrent username is :  "<<b.ret_current1->rli.rusrname<<endl;
                  cout<<"\t\t\t\t\t\tEnter new username  :  ";
                  cin>>b.ret_current1->rli.rusrname;
                  cout<<"\n\t\t\t\t\t\t New username saved"<<endl;
                  Sleep(2000);
                  edit_retail_detail();
                  break;
        case '2': system("cls");
                  Sleep(300);
                  cout<<"\n\n\t\t\t\t\t\tCurrent password is  : "<<b.ret_current1->rli.rpass<<endl;
                  cout<<"\n\t\t\t\t\t\tEnter new password   : ";
                  cin>>b.ret_current1->rli.rpass;
                  cout<<"\t\t\t\t\t\tRenter new password  : ";
                  cin>>b.ret_current1->rli.rcnfpass;
                  cout<<"\t\t\t\t\t\tPassword changed!";
                  Sleep(2000);
                  edit_retail_detail();
                  break;
        case '3': system("cls");
                   cout<<"\n\t\t\t\t\t\t Address has been added \n";
                   cout<<"\n\t\t\t\t\t\t State    : ";
                   puts(b.ret_current1->radr.ret_state);
                   cout<<"\n\t\t\t\t\t\t City     : ";
                   puts(b.ret_current1->radr.ret_city);
                   cout<<"\n\t\t\t\t\t\t Area     : ";
                   puts(b.ret_current1->radr.ret_area);
                   cout<<"\n\t\t\t\t\t\t Pincode  : ";
                   puts(b.ret_current1->radr.ret_pincode);
                   cout<<"\n\t\t\t\t\t\t Landmark : ";
                   puts(b.ret_current1->radr.ret_landmark);
                   cout<<"\n\t\t\t\t\t\t House Number : ";
                   puts(b.ret_current1->radr.ret_hno);
                   cout<<"\n\t\t\t\t\t\t Do you wish to edit this address?  (0/1) ";
                   y=getche();
                   if(y=='1')
                   {
                      cout<<"\n\t\t\t\t\t\t State    : ";
                      gets(b.ret_current1->radr.ret_state);
                      cout<<"\n\t\t\t\t\t\t City     : ";
                      gets(b.ret_current1->radr.ret_city);
                      cout<<"\n\t\t\t\t\t\t Area     : ";
                      gets(b.ret_current1->radr.ret_area);
                      cout<<"\n\t\t\t\t\t\t Pincode  : ";
                      gets(b.ret_current1->radr.ret_pincode);
                      cout<<"\n\t\t\t\t\t\t Landmark : ";
                      gets(b.ret_current1->radr.ret_landmark);
                      cout<<"\n\t\t\t\t\t\t House Number : ";
                      gets(b.ret_current1->radr.ret_hno);
                      cout<<"\n\t\t\t\t\t\t Address has been added \n";
                      edit_retail_detail();
                   }
                   else
                   {
                       cout<<"\n\t\t\t\t\t\t Redirecting to previous menu \n";
                       Sleep(2000);
                       edit_retail_detail();
                   }
                 break;
        case '4': retail_login();
                  break;
        case '5': cout<<"\n\t\t\t\t\t\t Logging out and exiting ";
                  Sleep(3000);
                  exit(0);
        default: cout<<"\n\t\t\t\t\t\t Please enter a valid choice.";
                 edit_retail_detail();
    }
}
void cust_login()
{
   system("cls");
   loading();
   int x=0,y=0;
   char get1[100],get2[100],get3[100],get4[100],ch;
       cout<<"\n\t\t\t\t\t\t     CUSTOMER LOGIN         \n";
       cout<<"\t\t\t\t\t______________________________\n\n";
       cout<<"\n\t\t\t\t\t\tAre you a returning customer?  (Y/N)  : ";
       ch=getche();
       if(ch=='Y')
      {
       cout<<"\n\t\t\t\t\t\tEnter the name of your retailer : ";
       cin>>get4;
       if(b.ret_start==NULL)
       {
           cout<<"\n\n\n\t\t\tThere is no retailer added to the list till now. Redirecting to main menu\n";
           Sleep(2000);
           system("cls");
           main_main();

       }
       else
       {
       b.ret_current1=b.ret_start;
       do
       {
       if(strcmp(b.ret_current1->rli.rusrname,get4)==0)
       {
           if(x>r.tot)
           {
               cout<<"\n\t\t\t\t\t\tRetailer not found ";
               cust_login();
           }
           cout<<"\n\t\t\t\t\t\tFound retailer : "<<get4;
           cout<<"\n\t\t\t\t\t\tEnter username : ";
           cin>>get1;
           cout<<"\n\t\t\t\t\t\t";
           cout<<"Enter password : ";
           cin>>get2;
           b.ret_current1->cust_current1=b.ret_current1->cust_start;
          do
          {
          if(strcmp(b.ret_current1->cust_current1->cli.cusrname,get1)==0)
          {
           do
           {
           if(strcmp(b.ret_current1->cust_current1->cli.cpass,get2)==0)
           {
           cout<<"\n\t\t\t\t\t\tLogged in successfully\n ";
           Sleep(2000);
           system("cls");
           y++;
           edit_cust_detail();
           }
           else
           {
            cout<<"\n\t\t\t\t\t\tYou entered the wrong password. Try again.\n";
            Sleep(2000);
            system("cls");
           }
           }while(y==0);
          }
        else
        {   b.ret_current1->cust_current1=b.ret_current1->cust_current1->cifn;
           x++;
        }

      }while(b.ret_current1->rifn!=NULL);

      }
      else
       {   b.ret_current1=b.ret_current1->rifn;
           x++;
       }

       }while(b.ret_current1->rifn!=NULL);
      }
      }
      else
      {
       system("cls");
       cout<<"\n\t\t\t\t\t\tNEW USERS PLEASE CONTACT BOARD ADMIN TO GET REGISTERATION";
       Sleep(2000);
       main_main();
      }
}
void cust_control()
{
    loading();
    system("cls");
    char ch,y;
    cout<<"\n\t\t\t\t\t\t     Customer Information         \n";
    cout<<"\t\t\t\t\t____________________________________\n\n";
    cout<<"\n\t\t\t\t\t\t1.Add customer                    \n";
    cout<<"\n\t\t\t\t\t\t2.Delete customer                 \n";
    cout<<"\n\t\t\t\t\t\t3.Back to previous menu           \n";
    cout<<"\n\t\tEnter your choice :  ";
    ch=getche();
    switch(ch)
    {
        case '1': create_customer_node();
                  break;
        case '2': remove_customer_node();
                  break;
        case '3': cout<<"\n\t\t\t\t\t\tLogging off\n\n";
                  Sleep(3000);
                  board_control();
                  break;
        default: cout<<"\n\t\t\t\t\t\tInvalid Choice entered\n\n";
                 Sleep(2000);
                 cust_control();
    }

}
void create_customer_node()
{
       char get4[100];
       cout<<"\n\t\t\t\t\t\tEnter the name of retailer : ";
       cin>>get4;
       if(b.ret_start==NULL)
       {
           cout<<"\n\n\n\t\t\tThere is no retailer added to the list till now. Redirecting to main menu\n";
           Sleep(2000);
           system("cls");
           main_main();

       }
       else
    {
       b.ret_current1=b.ret_start;
       do
      {
       if(strcmp(b.ret_current1->rli.rusrname,get4)==0)
       {
           cout<<"\n\t\t\t\t\t\tFound retailer : "<<get4;
           c.tot++;
           if(b.ret_current1->cust_start==NULL)
           {
               int i=0,j=0,k=0;
               struct cust_info_node *nn;
               nn=new struct cust_info_node;
               cout<<"\n\t\t\t\t\t\t     Add new customer           \n";
               cout<<"\t\t\t\t\t__________________________________\n\n";
               cout<<"\n\t\t\t\t\t\t1.Customer id is      :   "<<c.tot<<endl;
               nn->cust_id=c.tot;
               cout<<"\n\t\t\t\t\t\t2.Enter Username      :   ";
               cin>>nn->cli.cusrname;
               cout<<"\n\t\t\t\t\t\t3.Enter password      :   ";
               cin>>nn->cli.cpass;
               cout<<"\n\t\t\t\t\t\t4.Confirm password    :   ";
               cin>>nn->cli.ccnfpass;
               cout<<"\n\t\t\t\t\t\t5.Enter phone number  :   ";
               cin>>nn->cust_phno;
               cout<<"\n\t\t\t\t\t\t6.Enter Email         :   ";
               cin>>nn->cust_email;
               cout<<"\n\t\t\t\t\t\tEnter address details :   ";
               Sleep(200);
               cout<<"\n\t\t\t\t\t\t\t\t1.Enter state    :   ";
               cin>>nn->cadr.cust_state;
               cout<<"\n\t\t\t\t\t\t\t\t2.Enter city     :   ";
               cin>>nn->cadr.cust_city;
               cout<<"\n\t\t\t\t\t\t\t\t3.Enter area     :   ";
               cin>>nn->cadr.cust_area;
               cout<<"\n\t\t\t\t\t\t\t\t4.Enter landmark :   ";
               cin>>nn->cadr.cust_landmark;
               cout<<"\n\t\t\t\t\t\t\t\t5.Enter home no. :   ";
               cin>>nn->cadr.cust_hno;
               cout<<"\n\t\t\t\t\t\t\t\t6.Enter Demand details :   ";
              while(i==0 && j==0 && k==0)
            {  cout<<"\n\t\t\t\t\t\t\t\t\tEnter voltage allowance :   ";
               cin>>nn->cd.voltage;
               if(nn->cd.voltage<b.ret_current1->rd.tvoltage)
               {
                   i++;
               }
               cout<<"\n\t\t\t\t\t\t\t\t\tEnter total load :   ";
               cin>>nn->cd.load;
               if(nn->cd.load<b.ret_current1->rd.tload)
               {
                   j++;
               }
               cout<<"\n\t\t\t\t\t\t\t\t\tEnter number of meters :   ";
               cin>>nn->cd.no_of_meters;
               if(nn->cd.load<b.ret_current1->rd.tno_of_meters)
               {
                   k++;
               }
               if(i==0 && j!=0 && k!=0)
               {
                   cout<<"\n\t\t\t\t\t\t\t\t\tPlease enter voltage in the limit of the retailer   ";
               }
               else if(i!=0 && j==0 && k!=0)
               {
                   cout<<"\n\t\t\t\t\t\t\t\t\tPlease enter load in the limit of the retailer   ";
               }
               else if(i!=0 && j!=0 && k==0)
               {
                   cout<<"\n\t\t\t\t\t\t\t\t\tPlease enter no of meters in the limit of the retailer   ";
               }
            }
               cout<<"\n\t\t\t\t\t\t7.Enter start and end dates :   ";
               cout<<"\n\t\t\t\t\t\t START : ";
               nn->csd.sdd=getche();cout<<"/";nn->csd.smm=getche();cout<<"/1";nn->csd.syyyy=getche();
               cout<<"\n\t\t\t\t\t\t END   : ";
               nn->csd.edd=getche();cout<<"/";nn->csd.emm=getche();cout<<"/1";nn->csd.eyyyy=getche();
               nn->cifn=NULL;
               b.ret_current1->cust_start=nn;
               b.ret_current1->cust_current=nn;
            }
            else
            {
               struct cust_info_node *nn;
               int i=0,j=0,k=0;
               nn=new struct cust_info_node;
               cout<<"\n\t\t\t\t\t\t     Add new customer           \n";
               cout<<"\t\t\t\t\t__________________________________\n\n";
               cout<<"\n\t\t\t\t\t\t1.Customer id is      :   "<<c.tot<<endl;
               nn->cust_id=c.tot;
               cout<<"\n\t\t\t\t\t\t2.Enter Username      :   ";
               cin>>nn->cli.cusrname;
               cout<<"\n\t\t\t\t\t\t3.Enter password      :   ";
               cin>>nn->cli.cpass;
               cout<<"\n\t\t\t\t\t\t4.Confirm password    :   ";
               cin>>nn->cli.ccnfpass;
               cout<<"\n\t\t\t\t\t\t5.Enter phone number  :   ";
               cin>>nn->cust_phno;
               cout<<"\n\t\t\t\t\t\t6.Enter Email         :   ";
               cin>>nn->cust_email;
               cout<<"\n\t\t\t\t\t\tEnter address details :   ";
               Sleep(200);
               cout<<"\n\t\t\t\t\t\t\t\t1.Enter state    :   ";
               cin>>nn->cadr.cust_state;
               cout<<"\n\t\t\t\t\t\t\t\t2.Enter city     :   ";
               cin>>nn->cadr.cust_city;
               cout<<"\n\t\t\t\t\t\t\t\t3.Enter area     :   ";
               cin>>nn->cadr.cust_area;
               cout<<"\n\t\t\t\t\t\t\t\t4.Enter landmark :   ";
               cin>>nn->cadr.cust_landmark;
               cout<<"\n\t\t\t\t\t\t\t\t1.Enter home no. :   ";
               cin>>nn->cadr.cust_hno;
               cout<<"\n\t\t\t\t\t\t\t\t6.Enter Demand details :      ";
               while(i==0 && j==0 && k==0)
            {  cout<<"\n\t\t\t\t\t\t\t\t\tEnter voltage allowance :   ";
               cin>>nn->cd.voltage;
               if(nn->cd.voltage<b.ret_current1->rd.tvoltage)
               {
                   i++;
               }
               cout<<"\n\t\t\t\t\t\t\t\t\tEnter total load :   ";
               cin>>nn->cd.load;
               if(nn->cd.load<b.ret_current1->rd.tload)
               {
                   j++;
               }
               cout<<"\n\t\t\t\t\t\t\t\t\tEnter number of meters :   ";
               cin>>nn->cd.no_of_meters;
               if(nn->cd.load<b.ret_current1->rd.tno_of_meters)
               {
                   k++;
               }
               if(i==0 && j!=0 && k!=0)
               {
                   cout<<"\n\t\t\t\t\t\t\t\t\tPlease enter voltage in the limit of the retailer   ";
               }
               else if(i!=0 && j==0 && k!=0)
               {
                   cout<<"\n\t\t\t\t\t\t\t\t\tPlease enter load in the limit of the retailer   ";
               }
               else if(i!=0 && j!=0 && k==0)
               {
                   cout<<"\n\t\t\t\t\t\t\t\t\tPlease enter no of meters in the limit of the retailer   ";
               }
            }
               cout<<"\n\t\t\t\t\t\t7.Enter start and end dates :   ";
               cout<<"\n\t\t\t\t\t\t START : ";
               nn->csd.sdd=getche();cout<<"/";nn->csd.smm=getche();cout<<"/1";nn->csd.syyyy=getche();
               cout<<"\n\t\t\t\t\t\t END   : ";
               nn->csd.edd=getche();cout<<"/";nn->csd.emm=getche();cout<<"/1";nn->csd.eyyyy=getche();
               nn->cifn=NULL;
               b.ret_current1->cust_current->cifn=nn;
               b.ret_current1->cust_current=nn;
            }
            cout<<"\n\t\t\t\t\t\t Do you want to insert another retailer?  (0/1) : ";
            int i;
            cin>>i;
            if(i==0)
            {
             cust_control();
            }
            else
            {
             create_customer_node();
            }
        }
        else
        {
           b.ret_current1=b.ret_current1->rifn;
           x++;
        }
      }while(b.ret_current1->rifn!=NULL);
    }
}
void remove_customer_node()
{
     loading();
     int a=0,b1=0;
     char get1[100],get2[100];
     cout<<"\n\t\t\t\t\t\tEnter username of retailer : ";
     cin>>get1;
     if(b.ret_start==NULL)
     {
        cout<<"\n\t\t\t\t\t\tNo retailers have been added to. Please add some retailers first ";
        cout<<"\n\t\t\t\t\t\t\t\tRedirecting to previous menu";
        Sleep(3000);
        system("cls");
        cust_control();
     }
     b.ret_current1=b.ret_start;
    do
    {
       if(strcmp(b.ret_current1->rli.rusrname,get1)==0)
       {
         if(b.ret_current1->cust_start==NULL)
         {
             cout<<"\n\t\t\t\t\t\tThe retailer does not have any customers ";
             cout<<"\n\t\t\t\t\t\t\tRedirecting";
             Sleep(2000);
             remove_customer_node();
         }
        else
        {
          cout<<"\n\t\t\t\t\t\tEnter the name of the customer you want to delete  :  ";
          cin>>get2;
          b.ret_current1->cust_current1=b.ret_current1->cust_start;
         do
         {
          if(strcmp(b.ret_current1->cust_current1->cli.cusrname,get2)==0)
          {
             struct cust_info_node *x,*y;
             x=b.ret_current1->cust_start;
             for(int i=0;i<a-1;i++)
             {
              x=x->cifn;
             }
             y=b.ret_current1->cust_current1->cifn;
             x->cifn=y;
             free(b.ret_current1);
             cout<<"\n\t\t\t\t\t\tThe customer with username : "<<get2<<" was deleted\n";
             r.tot--;
             Sleep(4000);
             cust_control();
         }
         else
         {
             b.ret_current1->cust_current1=b.ret_current1->cust_current1->cifn;
             b1++;
         }
         if(b1>c.tot)
         {
           cout<<"\n\t\t\t\t\t\tThe customer with username : "<<get2<<" does not exist. Please enter a valid name"<<endl;
           Sleep(4000);
           remove_customer_node();
         }
        }while(b.ret_current1->cust_current1->cifn!=NULL);
       }
     }
     else
     {
      b.ret_current1=b.ret_current1->rifn;
      a++;
     }
     if(a>r.tot)
     {
      cout<<"\n\t\t\t\t\t\tThe retailer with username : "<<get1<<" does not exist. Please enter a valid name"<<endl;
      Sleep(4000);
      remove_customer_node();
     }

   }while(b.ret_current1->rifn!=NULL);
}
void edit_cust_detail()
{
    char ch;
    system("cls");
    loading();
    cout<<"\n\t\t\t\t\t\t   Welcome "<<b.ret_current1->cust_current1->cli.cusrname<<endl;
    cout<<"\n\t\t\t\t______________________________________\n";
    cout<<"\n\t\t\t\t\t\t1.Change Username                 \n";
    cout<<"\n\t\t\t\t\t\t2.Change Password                 \n";
    cout<<"\n\t\t\t\t\t\t3.Edit Address details            \n";
    cout<<"\n\t\t\t\t\t\t4.Print customer details          \n";
    cout<<"\n\t\t\t\t\t\t5.Back to previous menu           \n";
    cout<<"\n\t\t\t\t\t\t6.Exit                            \n";
    cout<<"\n\t\tEnter your choice :  ";
    ch=getche();
    switch(ch)
    {
        case '1': system("cls");
                  Sleep(300);
                  cout<<"\n\n\t\t\t\t\t\tCurrent username is :  "<<b.ret_current1->cust_current1->cli.cusrname<<endl;
                  cout<<"\t\t\t\t\t\tEnter new username  :  ";
                  cin>>b.ret_current1->cust_current1->cli.cusrname;
                  cout<<"\n\t\t\t\t\t\t New username saved"<<endl;
                  Sleep(2000);
                  edit_cust_detail();
                  break;
        case '2': system("cls");
                  Sleep(300);
                  cout<<"\n\n\t\t\t\t\t\tCurrent password is  : "<<b.ret_current1->cust_current1->cli.cpass<<endl;
                  cout<<"\n\t\t\t\t\t\tEnter new password   : ";
                  cin>>b.ret_current1->cust_current1->cli.cpass;
                  cout<<"\t\t\t\t\t\tRenter new password  : ";
                  cin>>b.ret_current1->cust_current1->cli.ccnfpass;
                  cout<<"\t\t\t\t\t\tPassword changed!";
                  Sleep(2000);
                  edit_cust_detail();
                  break;
        case '3': system("cls");
                   cout<<"\n\t\t\t\t\t\t Address has been added \n";
                   cout<<"\n\t\t\t\t\t\t State    : ";
                   puts(b.ret_current1->cust_current1->cadr.cust_state);
                   cout<<"\n\t\t\t\t\t\t City     : ";
                   puts(b.ret_current1->cust_current1->cadr.cust_city);
                   cout<<"\n\t\t\t\t\t\t Area     : ";
                   puts(b.ret_current1->cust_current1->cadr.cust_area);
                   cout<<"\n\t\t\t\t\t\t Pincode  : ";
                   puts(b.ret_current1->cust_current1->cadr.cust_pincode);
                   cout<<"\n\t\t\t\t\t\t Landmark : ";
                   puts(b.ret_current1->cust_current1->cadr.cust_landmark);
                   cout<<"\n\t\t\t\t\t\t House Number : ";
                   puts(b.ret_current1->cust_current1->cadr.cust_hno);
                   cout<<"\n\t\t\t\t\t\t Do you wish to edit this address?  (0/1) ";
                   y=getche();
                   if(y=='1')
                   {
                      cout<<"\n\t\t\t\t\t\t State    : ";
                      gets(b.ret_current1->cust_current1->cadr.cust_state);
                      cout<<"\n\t\t\t\t\t\t City     : ";
                      gets(b.ret_current1->cust_current1->cadr.cust_city);
                      cout<<"\n\t\t\t\t\t\t Area     : ";
                      gets(b.ret_current1->cust_current1->cadr.cust_area);
                      cout<<"\n\t\t\t\t\t\t Pincode  : ";
                      gets(b.ret_current1->cust_current1->cadr.cust_pincode);
                      cout<<"\n\t\t\t\t\t\t Landmark : ";
                      gets(b.ret_current1->cust_current1->cadr.cust_landmark);
                      cout<<"\n\t\t\t\t\t\t House Number : ";
                      gets(b.ret_current1->cust_current1->cadr.cust_hno);
                      cout<<"\n\t\t\t\t\t\t Address has been added \n";
                      edit_cust_detail();
                   }
                   else
                   {
                       cout<<"\n\t\t\t\t\t\t Redirecting to previous menu \n";
                       Sleep(2000);
                       edit_retail_detail();
                   }
                 break;
        case '4': cout<<"\n\t\t\t\t\t\t"<<b.ret_current1->cust_current1->cli.cusrname<<" your profile details are  \n" ;
                  cout<<"\n\t\t\t\t\t\t____________________________\n";
                  cout<<"\n\t\t\t\t\t\tUsername is :  "<<b.ret_current1->cust_current1->cli.cusrname<<endl;
                  cout<<"\n\n\t\t\t\t\t\tAddress details";
                  cout<<"\n\t\t\t\t\t\t____________________________\n";
                  cout<<"\n\t\t\t\t\t\t State    : ";
                  puts(b.ret_current1->cust_current1->cadr.cust_state);
                  cout<<"\n\t\t\t\t\t\t City     : ";
                  puts(b.ret_current1->cust_current1->cadr.cust_city);
                  cout<<"\n\t\t\t\t\t\t Area     : ";
                  puts(b.ret_current1->cust_current1->cadr.cust_area);
                  cout<<"\n\t\t\t\t\t\t Pincode  : ";
                  puts(b.ret_current1->cust_current1->cadr.cust_pincode);
                  cout<<"\n\t\t\t\t\t\t Landmark : ";
                  puts(b.ret_current1->cust_current1->cadr.cust_landmark);
                  getch();
                  edit_cust_detail();
                  break;
        case '5': cust_login();
                  break;
        case '6': cout<<"\n\t\t\t\t\t\t Logging out and exiting ";
                  Sleep(3000);
                  exit(0);
        default: cout<<"\n\t\t\t\t\t\t Please enter a valid choice.";
                 edit_retail_detail();
    }
}
main()
{  start();
}

