#include <iostream>
#include <fstream>
#include<cctype>
#include<iomanip>
#ifndef ADMIN_H
#define ADMIN_H

class Admin
{
        int acno ;
        char name[50] ;
        int balance ;
    public:
        void createAccount ( void ) ;
        void deleteAccount ( void ) ;
        void displayData ( void ) ;
        int retacno ( void ) ;
        void dep(int);
        void draw(int);
        int retdeposit() ;

};
class User : public Admin
{

};

#endif // ADMIN_H
