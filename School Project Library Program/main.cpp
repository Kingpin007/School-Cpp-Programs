#include<fstream>
#include<conio.h>
#include<cstdio>
#include<process.h>
#include<cstring>
#include <iostream>
#include <cstdlib>
using namespace std;
char t[2];
class book
{
	char bno[6];
	char bname[50];
	char aname[20];
  public:
	void create_book()
	{
		cout<<"\nNEW BOOK ENTRY...\n";
		cout<<"\nEnter The book no. : ";
		cin>>bno;
		cout<<"\n\nEnter The Name of The Book: ";
		gets(t);
		gets(bname);
		cout<<"\n\nEnter The Author's Name: ";
		gets(aname);
		cout<<"\n\n\nBook Created..";
	}
	void show_book()
	{
		cout<<"\nBook no. : "<<bno;
		cout<<"\nBook Name : "<<bname;
		cout<<"Author Name : "<<aname;
	}
	void modify_book()
	{
		cout<<"\nBook no. : "<<bno;
		cout<<"\nEnter the New Book Name : ";
		gets(t);
		gets(bname);
		cout<<"\nEnter the new Author Name : ";
		gets(aname);
	}
	char* retbno()
	{
		return bno;
	}
	void report()
	{
	    cout<<bno<<"\t\t"<<bname<<"\t\t"<<aname<<endl;
    }
};
class student
{
	char admno[6];
	char name[20];
	char stbno[6];
	int token;
public:
	void create_student()
	{
		system("cls");
	 	cout<<"\nNew Student Entry\n";
		cout<<"Enter The admission no. : ";
		cin>>admno;
		cout<<"Enter The Name of The Student : ";
		gets(t);
		gets(name);
		token=0;
		stbno[0]='/0';
		cout<<"\nStudent Record Created..";
	}
	void show_student()
	{
		cout<<"\nAdmission no. : "<<admno<<"\nStudent Name: "<<name<<"\nNo. of Book issued: "<<token;
		if(token==1)
			cout<<"\nBook No "<<stbno;
	}
	void modify_student()
	{
		cout<<"\nAdmission no. : "<<admno;
		cout<<"\nEnter new Student Name : ";
		gets(t);
		gets(name);
	}
	char* retadmno()
	{
		return admno;
	}
	char* retstbno()
	{
		return stbno;
	}
	int rettoken()
	{
		return token;
	}
	void addtoken()
	{token=1;}
	void resettoken()
	{token=0;}
	void getstbno(char t[])
	{
		strcpy(stbno,t);
	}
	void report()
	{
	    cout<<"\t\t"<<admno<<"\t\t"<<name<<"\t\t"<<token<<endl;
    }
};
fstream fp,fp1;
book bk;
student st;
void write_book()
{
	char ch;
	fp.open("book.dat",ios::out|ios::app);
	do
	{
		system("cls");
		bk.create_book();
		fp.write((char*)&bk,sizeof(book));
		cout<<"\nDo you want to add more records..(y/n?): ";
		cin>>ch;
	}while(ch=='y'||ch=='Y');
	fp.close();
}
void write_student()
{
	char ch;
	fp.open("student.dat",ios::out|ios::app);
	do
	{
		st.create_student();
		fp.write((char*)&st,sizeof(student));
		cout<<"\nDo you want to add more records..(y/n?): ";
		cin>>ch;
	}while(ch=='y'||ch=='Y');
	fp.close();
}
void display_spb(char n[])
{
	cout<<"\nBook Details\n";
	int flag=0;
	fp.open("book.dat",ios::in);
	while(fp.read((char*)&bk,sizeof(book)))
	{
		if(strcmpi(bk.retbno(),n)==0)
		{
			bk.show_book();
		 	flag=1;
		}
	}
	fp.close();
	if(flag==0)
		cout<<"\nBook does not exist!!";
	getch();
}
void display_sps(char n[])
{
	cout<<"\nStudent Details\n";
	int flag=0;
	fp.open("student.dat",ios::in);
	while(fp.read((char*)&st,sizeof(student)))
	{
		if((strcmpi(st.retadmno(),n)==0))
		{
			st.show_student();
			flag=1;
		}
	}
	fp.close();
	if(flag==0)
    		cout<<"\nStudent does not exist!!";
 	getch();
}
void modify_book()
{
	char n[6];
	int found=0;
	system("cls");
	cout<<"\n\tModify book records ";
	cout<<"\n\tEnter The book no. of The book: ";
	cin>>n;
	fp.open("book.dat",ios::in|ios::out);
	while(fp.read((char*)&bk,sizeof(book)) && found==0)
	{
		if(strcmpi(bk.retbno(),n)==0)
		{
			bk.show_book();
			cout<<"\nEnter The New Details of book: "<<endl;
			bk.modify_book();
			int pos=-1*sizeof(bk);
		    	fp.seekp(pos,ios::cur);
		    	fp.write((char*)&bk,sizeof(book));
		    	cout<<"\n\t Record Updated";
		    	found=1;
		}
	}
    	fp.close();
    	if(found==0)
    		cout<<"\n\n Record Not Found ";
    	getch();
}
void modify_student()
{
	char n[6];
	int found=0;
	system("cls");
	cout<<"\n\tModify student recors ";
	cout<<"\n\tEnter The admission no. of The student";
	cin>>n;
	fp.open("student.dat",ios::in|ios::out);
	while(fp.read((char*)&st,sizeof(student)) && found==0)
	{
		if(strcmpi(st.retadmno(),n)==0)
		{
			st.show_student();
			cout<<"\nEnter The New Details of student"<<endl;
			st.modify_student();
			int pos=-1*sizeof(st);
			fp.seekp(pos,ios::cur);
			fp.write((char*)&st,sizeof(student));
			cout<<"\n\t Record Updated";
			found=1;
		}
	}
	fp.close();
	if(found==0)
		cout<<"\nRecord Not Found ";
	getch();
}
void delete_student()
{
	char n[6];
	int flag=0;
	system("cls");
    	cout<<"\n\tDelete Student";
    	cout<<"\nEnter The admission no. of the Student You Want To Delete : ";
    	cin>>n;
    	fp.open("student.dat",ios::in|ios::out);
    	fstream fp2;
    	fp2.open("Temp.dat",ios::out);
    	fp.seekg(0,ios::beg);
    	while(fp.read((char*)&st,sizeof(student)))
	{
		if(strcmpi(st.retadmno(),n)!=0)
	     		fp2.write((char*)&st,sizeof(student));
		else
	   		flag=1;
	}
	fp2.close();
    	fp.close();
    	remove("student.dat");
    	rename("Temp.dat","student.dat");
    	if(flag==1)
     		cout<<"\n\tRecord Deleted ..";
    	else
     		cout<<"\nRecord not found";
    	getch();
}
void delete_book()
{
	char n[6];
	system("cls");
	cout<<"\n\tDelete Book";
	cout<<"\nEnter The Book no. of the Book You Want To Delete : ";
	cin>>n;
	fp.open("book.dat",ios::in|ios::out);
	fstream fp2;
	fp2.open("Temp.dat",ios::out);
	fp.seekg(0,ios::beg);
	while(fp.read((char*)&bk,sizeof(book)))
	{
		if(strcmpi(bk.retbno(),n)!=0)
		{
			fp2.write((char*)&bk,sizeof(book));
		}
	}
	fp2.close();
    	fp.close();
    	remove("book.dat");
    	rename("Temp.dat","book.dat");
    	cout<<"\n\tRecord Deleted ..";
    	getch();
}
void display_alls()
{
	system("cls");
     	fp.open("student.dat",ios::in);
     	if(!fp)
     	{
       		cout<<"ERROR!!! file could not be opened!!! ";
       		getch();
       		return;
     	}

	cout<<"\n\n\t\tSTUDENT LIST\n\n";
	cout<<"==================================================================\n";
	cout<<"\t\tAdmission No."<<"\t\t"<<"Name"<<"\t\t"<<"Book Issued\n";
	cout<<"==================================================================\n";

	while(fp.read((char*)&st,sizeof(student)))
	{
		st.report();
	}

	fp.close();
	getch();
}
void display_allb()
{
	system("cls");
	fp.open("book.dat",ios::in);
	if(!fp)
	{
		cout<<"ERROR!!! file could not be opened! ";
       		getch();
       		return;
     	}

	cout<<"\n\t\tBook LIST\n\n";
	cout<<"=========================================================================\n";
	cout<<"Book Number"<<"\t\t"<<"Book Name"<<"\t\t"<<"Author\n";
	cout<<"=========================================================================\n";

	while(fp.read((char*)&bk,sizeof(book)))
	{
		bk.report();
	}
     	fp.close();
     	getch();
}
void book_issue()
{
	char sn[6],bn[6];
	int found=0,flag=0;
	system("cls");
	cout<<"\nIssue a book";
	cout<<"\n\tEnter The student's admission no.: ";
	cin>>sn;
	fp.open("student.dat",ios::in|ios::out);
    	fp1.open("book.dat",ios::in|ios::out);
    	while(fp.read((char*)&st,sizeof(student)) && found==0)
       	{
		if(strcmpi(st.retadmno(),sn)==0)
		{
			found=1;
			if(st.rettoken()==0)
			{
		      		cout<<"\n\tEnter the book no.: ";
				cin>>bn;
				while(fp1.read((char*)&bk,sizeof(book))&& flag==0)
				{
			   		if(strcmpi(bk.retbno(),bn)==0)
					{
						bk.show_book();
						flag=1;
						st.addtoken();
						st.getstbno(bk.retbno());
       						int pos=-1*sizeof(st);
						fp.seekp(pos,ios::cur);
						fp.write((char*)&st,sizeof(student));
						cout<<"\n\t Book issued successfully\nPlease Note: Write the current date in backside of your book and submit within 15 days fine Rs. 1 for each day 							after 15 days period";
					}
                }
		  		if(flag==0)
		    		cout<<"Book no does not exist";
            }
            else
                cout<<"Please return the previous book you have issued!!";
		}
	}
    if(found==0)
		cout<<"Student record not exist...";
	getch();
  	fp.close();
  	fp1.close();
}
void book_deposit()
{
    char sn[6],bn[6];
    int found=0,flag=0,day,fine;
    system("cls");
    cout<<"\nBook Return";
    cout<<"\n\tEnter The student’s admission no.: ";
    cin>>sn;
    fp.open("student.dat",ios::in|ios::out);
    fp1.open("book.dat",ios::in|ios::out);
    while(fp.read((char*)&st,sizeof(student)) && found==0)
       {
	    if(strcmpi(st.retadmno(),sn)==0)
	    {
		    found=1;
		    if(st.rettoken()==1)
		    {
			while(fp1.read((char*)&bk,sizeof(book))&& flag==0)
			{
			   if(strcmpi(bk.retbno(),st.retstbno())==0)
			{
				bk.show_book();
				flag=1;
				cout<<"\nBook deposited in no. of days: ";
				cin>>day;
				if(day>15)
				{
				   fine=(day-15)*1;
				   cout<<"\nFine has to deposited Rs.: "<<fine;
				}
					st.resettoken();
					int pos=-1*sizeof(st);
					fp.seekp(pos,ios::cur);
					fp.write((char*)&st,sizeof(student));
					cout<<"\n\t Book returned successfully: ";
			}
		    }
		  if(flag==0)
		    cout<<"Book no does not exist";
		      }
		 else
			cout<<"No book is issued..please check!!";
		}
	   }
      if(found==0)
	cout<<"Student record not exist...";
	getch();
  fp.close();
  fp1.close();
}
void intro()
{
	system("cls");
	cout<<"Welcome to the school library management program\n";
	cout<<"\n\nMade By : Anirudh Kanabar of XII Sc. C Roll No. : 8";
	cout<<"\n\nSchool: Birla High School\n\n";
	system("pause");
}
void student_menu()
{
	system("cls");
	int ch2;
	cout<<"\nStudent Menu\n1.Create New Student\n2.Display All student Records\n3.Display a specific Student Record\n4.Edit Student Record\n5.Delete a student record\n6.Back to Main Menu\nPlease Enter Your Choice (1-7): ";
	cin>>ch2;
	switch(ch2)
	{
    case 1:
        system("cls");
        write_student();
        break;
    case 2:
        display_alls();
        break;
    case 3:
        char num[6];
        system("cls");
        cout<<"\n\tPlease Enter The Admission No. ";
        cin>>num;
        display_sps(num);
        break;
    case 4:
        modify_student();
        break;
    case 5:
        delete_student();
        break;
    case 6:
        return;
    default:
        cout<<"Error!! Please enter corrrect option.";
   	}
   	student_menu();
}
void book_menu()
{
    system("cls");
    int ch2;
	cout<<"\nBook Menu\n1.Issue A Book\n2.Return a Book\n3.Create New Book\n4.Display All Books\n5.Display Specific Book\n6.Edit Book\n7.Delete Book\n8.Back to Main Menu\ntPlease Enter Your Choice (1-8): ";
	cin>>ch2;
	switch(ch2)
	{
    case 1:
        system("cls");
        book_issue();
        break;
    case 2:
        system("cls");
        book_deposit();
        break;
    case 3:
        system("cls");
        write_book();
        break;
    case 4:
        display_allb();
        break;
    case 5:
        char num[6];
        system("cls");
        cout<<"\n\tPlease Enter The book No.: ";
        cin>>num;
        display_spb(num);
        break;
    case 6:
        modify_book();
        break;
    case 7:
        delete_book();
        break;
    case 8:
        return;
    default:
        cout<<"Error!! Please enter corrrect option.";
	}
}
int main()
{
	char ch;
	intro();
	do
	{
		system("cls");
		cout<<"\nMain Menu\n01. Book Menu\n02. Student Menu\n03. Exit\nPlease Select Your Option (1-3): ";
	  	cin>>ch;
	  	switch(ch)
	  	{
        case '1':
            system("cls");
            book_menu();
            break;
        case '2':
            student_menu();
            break;
        case '3':
            exit(3);
        default :
            cout<<"Error!! Wrong Input!";
		}
    }while(ch!='4');
}
