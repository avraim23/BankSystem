#include "Admin.h"
using namespace std ;
const int pass = 1523 ;
void write_account( void )
{
    Admin ac;
    ofstream outFile;
    outFile.open("account.dat",ios::binary|ios::app);
    ac.createAccount() ;
    outFile.write(reinterpret_cast<char *> (&ac), sizeof(Admin));
    outFile.close();
    cout << "\n Account Created " ;
}
void display_all()
{
    Admin ac;
    ifstream inFile;
    inFile.open("account.dat",ios::binary);
    if(!inFile)
    {
        cout<<"File could not be open !! Press any Key...";
        return;
    }
    cout<<"\n\n\t\tACCOUNT HOLDER LIST" << endl ;
    cout<<"===================================================="<< endl;
    cout<<"A/c No.            NAME          Balance" << endl ;
    cout<<"====================================================" << endl;
    while(inFile.read(reinterpret_cast<char *> (&ac), sizeof(Admin)))
    {
        ac.displayData();
    }
    inFile.close();
}
void delete_account(int n)
{
    Admin ac;
    ifstream inFile;
    ofstream outFile;
    inFile.open("account.dat",ios::binary);
    if(!inFile)
    {
        cout<<"File Could Not Be Opened !! Press Any Key...";
        return;
    }
    outFile.open("Temp.dat",ios::binary);
    inFile.seekg(0,ios::beg);
    while(inFile.read(reinterpret_cast<char *> (&ac), sizeof(Admin)))
    {
        if(ac.retacno()!=n)
        {
            outFile.write(reinterpret_cast<char *> (&ac), sizeof(Admin));
        }
    }
    inFile.close();
    outFile.close();
    remove("account.dat");
    rename("Temp.dat","account.dat");
    cout<<"\n\n\tAccount Deleted ..";
}
void deposit_withdraw(int n, int option)
{
    int amt;
    bool found=false;
    User ac;
    fstream File;
    File.open("account.dat", ios::binary|ios::in|ios::out);
    if(!File)
    {
        cout<<"File Could Not Be Opened !! Press Any Key...";
        return;
    }
    while(!File.eof() && found==false)
    {
        File.read(reinterpret_cast<char *> (&ac), sizeof(User));
        if(ac.retacno()==n)
        {
            cout << endl ;
            ac.displayData();
            if(option==1)
            {
                cout<<"\nTO DEPOSITE AMOUNT -- ";
                cout<<"Enter The Amount To Be Deposited : ";
                cin>>amt;
                ac.dep(amt);
            }
            if(option==2)
            {
                cout<<"\nTO WITHDRAW AMOUNT -- ";
                cout<<"Enter The Amount To Be Withdraw : ";
                cin>>amt;
                int bal=ac.retdeposit()-amt ;
                    ac.draw(amt);
            }
            int pos=(-1)*static_cast<int>(sizeof(ac));
            File.seekp(pos,ios::cur);
            File.write(reinterpret_cast<char *> (&ac), sizeof(User));
            cout<<"\n\n\t !!!DONE!!!";
            found=true;
           }
         }
    File.close();
    if(found==false)
        cout<<"\n\n Record Not Found ";
}
void viewData (int n )
{
    bool found=false;
    User ac;
    fstream File;
    File.open("account.dat", ios::binary|ios::in|ios::out);
    if(!File)
    {
        cout<<"File Could Not Be Opened !! Press Any Key...";
        return;
    }
    cout<<"===================================================="<< endl;
    cout<<"A/c No.            NAME          Balance" << endl ;
    cout<<"====================================================" << endl;
    while(!File.eof() && found==false)
    {
        File.read(reinterpret_cast<char *> (&ac), sizeof(User));
        if(ac.retacno()==n)
        {
            cout << endl ;
            ac.displayData();
            found=true;
            File.close();
        }
    if(found==false)
        cout<<"\n\n Account Not Found ";
    }
}
int main()
{
    char k ;
    int num , p ;
    cout << "---------------------------- WELCOME TO OUR BANK SYSTEM ----------------------------" << endl ;
    Main :
    cout << "DO YOU WANT TO SIGN IN AS A : " << endl ;
    cout << "1. Admin . " << "\n2. User ." << "\n3. Exit ." << endl ;
    cout << "Enter Your Choice : " ;
    cin >> num ;
    switch ( num )
    {
    case 1 :
        cout << "Enter Admin's Password : " ;
        cin >> p ;
        if ( p == pass )
        {
          system("cls") ;
          cout << "---------------------------- WELCOME OUR ADMIN ----------------------------" << endl ;
          Admin :
          cout << "WHAT DO YOU WANT TO DO ? " << endl ;
          cout << "1. Create New Account . " << "\n2. Delete Account ." << "\n3. View All Accounts ." << "\n4. Exit . "<< endl ;\
          int c ;
          cout << "Enter Your Choice : " ;
          cin >> c ;
          switch ( c )
          {
          case 1 :
              write_account ( ) ;
              cout << "\nDone ? (y/n)" ;
              cin >> k ;
              system ("cls") ;
              goto Admin ;
            break ;
          case 2 :
              int n ;
              cout << "Enter Account Number : " ;
              cin >> n ;
              delete_account (n) ;
              display_all () ;
              cout << "\n\nDone ? (y/n) " ;
              cin >> k ;
              system ("cls") ;
              goto Admin ;
            break ;
          case 3 :
              display_all () ;
              cout << "\n\nDone ? (y/n) " ;
              cin >> k ;
              system ("cls") ;
              goto Admin ;
            break ;
          case 4 :
            system("cls") ;
            goto Main ;
            break ;

          }
        }

        else
        {
            cout << "!!!WRONG PASSWORD!!!" << endl ;
            system("cls") ;
            goto Main ;
        }
        break ;
    case 2 :
        system("cls") ;
        cout << "---------------------------- WELCOME OUR USER ----------------------------" << endl ;
        User :
        cout << "WHAT DO YOU WANT TO DO ? " << endl ;
        cout << "1. Deposit . " << "\n2. Withdraw ." << "\n3. View Account Details ." << "\n4. Exit . "<< endl ;
        int c ;
        cout << "Enter Your Choice : " ;
        cin >> c ;
        switch ( c )
        {
        case 1 :
            int n ;
              cout << "Enter Account Number : " ;
              cin >> n ;
              deposit_withdraw( n , 1 ) ;
              cout << "\nDone ? (y/n)" ;
              cin >> k ;
              system ("cls") ;
              goto User ;
            break ;
        case 2 :
            int p ;
              cout << "Enter Account Number : " ;
              cin >> p ;
              deposit_withdraw( p , 2 ) ;
              cout << "\nDone ? (y/n)" ;
              cin >> k ;
              system ("cls") ;
              goto User ;
            break ;
        case 3 :
            int o ;
              cout << "Enter Account Number : " ;
              cin >> o ;
              viewData ( o ) ;
              cout << "\nDone ? (y/n)" ;
              cin >> k ;
              system ("cls") ;
              goto User ;
            break ;

        case 4 :
            system("cls") ;
            goto Main ;
            break ;

        }
        break ;
    case 3 :
        exit (0) ;
        break ;
    }

}

