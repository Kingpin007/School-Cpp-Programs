#include <iostream>
#include <fstream>
#include <cstring>
#include <cstdlib>
#include <conio.h>

using namespace std;
class User
{
protected:
    long int ID;
    char password[20];
public:
    User();
    ~User();
    void book();
    void cancel();
    void view();
    void initialize();
    long int getID()
    {
        return ID;
    }
    char* getpass()
    {
        return password;
    }
};
class Admin : public User
{
protected:
    int key;
public:
    Admin();
    ~Admin();
    void finance();
};
class OutputData
{
    OutputData(User u1)
    {
        ofstream fout("Data.txt", ios::binary|ios::app);
        u1.initialize();
        fout.write((char*)&u1,sizeof(u1));
        fout.close();
    }
};
class InputData
{
public:
    User u1;
    int read(long int id, char pass[20])
    {
        ifstream fin("Data.txt", ios::binary);
        while(!fin.eof())
        {
            fin.read((char*)&u1,sizeof(u1));
            if(u1.getID()==id)
            {
                if(strcmp(u1.getpass(),pass)==0)
                    return 1;
            }
        }
        return 0;
    }
};
class Login
{
public:
    Login()
    {
        cout<<"Enter User ID: ";
        cin>>ID;
        cout<<"Enter password: ";
        cin>>password;
        InputData i;
        if(i.read(ID,password))
        {
            cout<<"Login Succesful! You may now proceed! Press any key to continue....";
            getch();
            system("cls");
            cout<<"Please select your choice: \n1.Book new tickets\2.Cancel tickets\3.View Old Tickets\n4.Exit\nPlease Enter your choice: ";
            int c;
            cin>>c;
            User u1;
            switch(c)
            {
            case 1:
                u1.book();
                break;
            case 2:
                u1.cancel();
                break;
            case 3:
                u1.view();
            case 4:
                cout<<"Exiting...";
                system("pause");
                exit(2);
            default:
                cout<<"Wrong input..";
                getch();
                exit(3);

            }
        }
    }
private:
    long int ID;
    char password[20];
};
int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
