#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <conio.h>
#include <cwchar>
#include <windows.h>

using namespace std;

class directory
{
	int password;
	char website[50], email_id [50];
	
	public:
		string getpword()
{
	char ch;
	string pass="";
	cout << "Please Enter the Password: ";
	oo:
	ch=getch();
	if(ch==8)
	{
		goto oo;
	}	
	while(ch!=13)
	{
		if(ch==8)
		{
			if(pass.size()==0)
			{	
				goto ps;
			}
			pass.erase(pass.size()-1);
			cout << "\b \b";
			ps:
			goto pp;
		}
		pass.push_back(ch);
		cout << "*";
		pp:
		ch=getch();
	}
	return pass;
}
int check(string a)
{
	int flag=0;
	string b;
	fstream f1("Accounts.dir",ios::in);
	while(f1)
	{
		f1 >> b;
		if(b==a)
		{
			flag = 1; break;
		}
	}
	f1.close();
	if(flag==1)
	{
		cout << "\nSorry! Username already exists. \nPlease try another: ";
		return 1;
	}
	return 0;
}
	
int SignIn()
{
	string uname, password, struname, strpassword, line;
	ghi:
	fstream file1("Accounts.dir");
	int flag=0, nextLoc=0;
	system("cls");
	cout << "\n\n\t\t-----------WELCOME TO REMWORD : your personal password reminder -------------\n\n";
	cout << "Please Enter Your Username: ";
	cin >> struname;
	if (struname=="Admin")
	{
		return 2;
	}
	if (struname=="admin")
	{
		return 3;
	}
	while (! file1.eof() )
		{
			getline (file1,line);
			nextLoc=line.find(" ");
			uname=line.substr(0,nextLoc);
			line = line.substr(nextLoc+1,line.length());
			password=line;
			if(uname==struname)
			{
				flag=1;
				break;
			}
		}
		
	file1.close();
	if(flag==1)
	{

		def:
		strpassword=getpword();
		if(strpassword==password)
		{
			cout << "Sign-In Succesful.";
		}
		else
		{
			cout << "\nWrong Password! ";
			goto def;
		}
	}
	
	else
	{
		cout << "\n\nYour Username was not Found in our Database.\nPlease Sign-Up or Enter correct Username";
		cout << "\nPress   <1> To Sign-Up    OR\n        <2> To Sign-In Again\n";
		int choice1;
		cin >> choice1;
		if(choice1==1)
		{
			return 1;
		}
		else
		{
			goto ghi;
		}
	}
	return 0;
}

void SignUp()
{	string uname, struname, line, Password;
	int flag;
	system("cls");
	cout << "\n\n\t\t-----------WELCOME TO REMWORD -------------\n\n";
	fstream file1("Accounts.dir",ios::in|ios::out|ios::app);
	cout << "Please Enter an Username: ";
	cv:
	cin >> struname;
	flag = check(struname);
	if(flag==1)
	{
		goto cv;
	}
	cout << "Please Enter a Password: ";
	cin >> Password;
 	file1 << "\n" << struname << " " << Password;
	cout << "\nAccount Created Successfully\n\n";
	system("pause");
	return;
}

void GetDetails()
{
	string websitename, email_id, pass_word;
	char choice = 'y';
	fstream myfile("Directory.dir",ios::app);
	while(choice=='Y'||choice=='y')
	{
	system("cls");
	cout << "\n\n\t\t-----------ADD DETAILS-------------\n\n";
	cout << "Enter name of website : ";
	cin >> websitename;
	myfile << websitename << " ";
	cout << "\nEnter email id used : ";
	cin >> email_id;
	myfile << email_id << " ";
	cout << "\nEnter password used : ";
	cin >> pass_word;
	
	myfile << pass_word << "\n";
	cout << "\nDo you want to enter more? (y/n)";
	cin >> choice; cout << "\n";
	}

	myfile.close();
}

void SearchAndDisplay()
{
	string line;
	string websitename,email_id,pass_word, strwebsite, stremail_id;
	char choice;
	int flag=0;
	int nextLoc=0;
	system("color F0");
	system("cls");
	do{
		cout << "\n\n\t\t-----------SEARCH/VIEW DETAILS -------------\n\n";
			flag=0;
			ifstream myfile ("Directory.dir");
			if (myfile.is_open())
			{
				cout<<endl<<"Enter website name you need : ";
				cin>>strwebsite;
				cout<<"Enter email id used : ";
				cin>>stremail_id;
				while (! myfile.eof() )
				{
					getline (myfile,line);
					nextLoc=line.find(" ");
					websitename=line.substr(0,nextLoc);
					line = line.substr(nextLoc+1,line.length());
					nextLoc=line.find(" ");
					email_id=line.substr(0,nextLoc);
					line = line.substr(nextLoc+1,line.length());
					pass_word = line;
					if(websitename==strwebsite && email_id==stremail_id)
					{
						cout<<"\nFound!!"<<endl;
						cout<<endl<<"Website name : "<<websitename<<"\n"<<"Mail id used: "<<email_id<<"\n"<<"Password used : "<<pass_word<<endl ;
						flag=1;
						break;
					}
				}
			}
			else
			{
				cout << "Unable to open file"<<endl;
				exit(0);
			}
			if(flag==0)
			{
				cout<<"Not Found...Sorry."<<endl;
			}
			cout << "\nDo you want to enter more?(y/n) ";
			cin >> choice;
			system("cls");
	}while(choice=='y');
	return;
}

void Delete()
{
    system("cls");
    string line, websitename, email_id, stremail_id, strwebsite, pass_word;
    int nextLoc=0,flag=0;
    cout << "\n\n\t\t-----------DELETE-------------\n\n";
    cout << "Please enter the website whose details you want to delete: ";
    cin>>strwebsite;
    cout << "\nPlease enter the email id used for this website you want to delete: ";
    cin>>stremail_id;
    ifstream myfile;
    ofstream temp;
    myfile.open("Directory.dir");
    temp.open("temp.dir");
    while (!myfile.eof())
    {
  	getline (myfile,line);
	nextLoc=line.find(" ");
	websitename=line.substr(0,nextLoc);
	line = line.substr(nextLoc+1,line.length());
	nextLoc=line.find(" ");
	email_id=line.substr(0,nextLoc);
	line = line.substr(nextLoc+1,line.length());
	pass_word = line;
	if(!(websitename==strwebsite && email_id==stremail_id))
      	temp << websitename <<" "<< email_id <<" "<< pass_word<< endl;
    else 
    	flag++;
      
  }
  if(flag==0)
  {
  	 cout<<"\nRecord not found!!\n\n";
	 goto afg;	
  }
  cout << "The record with the name " << strwebsite <<" "<<stremail_id<< " has been deleted " << endl;
  myfile.close();
  temp.close();
  remove("Directory.dir");
  rename("temp.dir", "Directory.dir");
  afg:
  return;
}
void mod()
{
	system("cls");
	system("color F0");
	string line, websitename, email_id, stremail_id, strwebsite, pass_word;
    int nextLoc=0,flag=0;
    cout << "\n\n\t\t-----------MODIFY-------------\n\n";
    afgh:
    cout << "Please enter the website whose details you want to modify: ";
    cin>>strwebsite;
    cout << "\nPlease enter the mail id of the website details you want to modify: ";
    cin>>stremail_id;
    ifstream myfile;
    ofstream temp;
    myfile.open("Directory.dir");
    temp.open("temp1.dir");
    while (!myfile.eof())
    {
  	getline (myfile,line);
	nextLoc=line.find(" ");
	websitename=line.substr(0,nextLoc);
	line = line.substr(nextLoc+1,line.length());
	nextLoc=line.find(" ");
	email_id=line.substr(0,nextLoc);
	line = line.substr(nextLoc+1,line.length());
	pass_word = line;
	if(!(websitename==strwebsite && email_id==stremail_id))
      	temp << websitename <<" "<< email_id <<" "<< pass_word<< endl;
    else 
    	flag++;
      
  }
  if(flag==0)
  {
  	 cout<<"\nRecord not found!! Try Again.\n\n";
	 goto afgh;	
  }
  myfile.close();
  temp.close();
  remove("Directory.dir");
  rename("temp1.dir", "Directory.dir");
  
	
	
	string websitename2, email_id2, pass_word2;
	fstream myfile2("Directory.dir",ios::app);
	cout << "\n\nEnter wesbite  : ";
	cin >> websitename2;
	myfile2 << websitename2 << " ";
	cout << "\nEnter mail id used : ";
	cin >> email_id2;
	myfile2 << email_id2 << " ";
	cout << "\nEnter password : ";
	cin >> pass_word2;
	
	myfile2 << pass_word2;
	myfile2.close();
	
	return;
}
};
int main()
{
	directory d;
	system("color F0");
	CONSOLE_FONT_INFOEX cfi;
    cfi.cbSize = sizeof(cfi);
    cfi.nFont = 0;
    cfi.dwFontSize.X = 0;
    cfi.dwFontSize.Y = 19;
    cfi.FontFamily = FF_DONTCARE;
    cfi.FontWeight = FW_NORMAL;
    std::wcscpy(cfi.FaceName, L"Consolas");
    SetCurrentConsoleFontEx(GetStdHandle(STD_OUTPUT_HANDLE), FALSE, &cfi);
	int choice, choice3, returnedValue;
	char choice2='y', choice4='y'; 
	string pword;
	dkj:
	system("cls");
	cout << "\n\n\t\t-----------WELCOME TO REMWORD-------------\n\n";
	cout << "Please Sign-In or Sign-Up to Continue\n\n\t1.  Sign-In to an Existing Account\n\t2.  Create a new Account\n\t3.  Exit\n";
	cout << "\nPlease Enter your choice: "; 
	cin >> choice3;
	if(choice3==1)
	{
		returnedValue=d.SignIn();
		if(returnedValue==1)
		{
			d.SignUp();
		}
		else if(returnedValue==2)
		{
			yz:
			pword=d.getpword();
			if(pword=="Root")
			{
				system("cls");
				cout << "Admin Signed In\n";
				system("pause");
				goto mno;
			}
			else
			{
				cout << "\nPassword Incorrect! Please Enter Again: ";
				goto yz;
			}
		}
		else if(returnedValue==3)
		{
			vwx:
			pword=d.getpword();
			if(pword=="root")
			{
				system("cls");
				cout << "Admin Signed In\n";
				system("pause");
				goto mno;
			}
			else
			{
				cout << "\nPassword Incorrect. Please Enter Again: ";
				goto vwx;
			}
		}
	}
	
	else if(choice3==2)
	{

		jkl:
		d.SignUp();
	}
	
	else
	{
	exit(0);
	}
	
	while(choice2=='Y'||choice2=='y')
	{
	system("color F0");
	system("cls");
	cout << "\n\n\t\t-----------RemWord-------------\n\n";
	cout <<"Do you want to \n\n\t1.View Existing Directories \n\t2.Log Out\n\t3.Log Out and Exit\n";
	cout<<"\nPlease enter your choice: ";
	abc:
	cin >> choice;

	switch (choice)
	{
		case 1: d.SearchAndDisplay(); break;
		case 2: cout<<"\nLogged out successfully!\n";
				system("pause");
				goto dkj;
		case 3:	exit(0); break;
		default: cout << "\nWrong Input! Try Again... "; goto abc;
	}
	
	}
	goto stu;
	mno:
	system("color F0");
	system("cls");
	cout << "\n\n\t\t-----------remword-------------\n\n";
	cout << "Do you want to \n\n\t1.Enter New Directories\n\t2.View Existing Directories\n\t3.Delete Existing Directories\n\t4.Modify Existing Directories\n\t5.Log Out\n\t6.Log Out and Exit\n";
	cout<<"\nPlease enter your choice: ";
	pqr:
	cin >> choice;
	lok:
	switch (choice)
	{
		case 1: d.GetDetails(); break;
		case 2: d.SearchAndDisplay(); break;
		case 3: d.Delete();break;
		case 4: d.mod();break;
		case 5: cout<<"\nLogged out successfully!\n";
				system("pause");
				goto dkj;
		case 6:	exit(0);
		default: cout << "\nWrong Input! Try Again... "; goto pqr;
	}
	cout << "Do you want to continue? (y/n) : ";
	choice4=getch();
	if(choice4=='Y'||choice4=='y')
	{
		goto lok;
	}
	else
	goto mno;
	
	stu:
	exit(0);
}
