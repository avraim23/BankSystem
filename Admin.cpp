#include "Admin.h"
using namespace std ;

void Admin :: createAccount ( void )
{
    cout << "\nEnter The Account No. :" ;
    cin >> acno ;
    cout << "\nEnter The Name of The Account Holder : " ;
    cin.ignore() ;
    cin.getline(name,50) ;
    cout << "\nEnter The Initial Balance :  ";
    cin >> balance;
}
void Admin :: displayData()
{
    cout<<acno<<setw(10)<<" "<<name<<setw(10)<<" "<<balance<<endl;
}
int Admin::retacno()
{
    return acno;
}
void Admin::dep(int x)
{
    balance+=x;
}

void Admin::draw(int x)
{
    if (balance >= x)
    {
        balance-=x ;
    }
    else
    {
        cout << "Balance Don't Allow." << endl ;
    }
}
int Admin::retdeposit()
{
    return balance;
}
