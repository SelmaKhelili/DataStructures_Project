#include "email.h"
#include<iostream>
#include "MailServer.h"
using namespace std;
class MailServer;

Email::Email():To(0),From(0),Object("No OBJECT"),Content("No Content")
{
}
 Email:: Email(const Email&E)
{
    From=(E.From);
    To=(E.To);
    Object=(E.Object);
    Content=(E.Content);


}
Email::Email(Email &&E)
{
    From=std::move(E.From);
    To=std::move(E.To);
    Object=std::move(E.Object);
    Content =std::move(E.Content);
}

void Email :: SetSender()
{
    cout<<"enter your email ID"<<endl;
    cin>>From;

}
void Email ::SetReciever()
{
    cout<<"enter email ID of the reciever "<<endl;
    cin>>To;
}
void Email ::SetContent()
{
    cin.sync();
    cout<<"Enter the content of your email when you finish enter  endl then 'end'  :"<<endl;
    string line;
    do
    {

        getline(cin, line);
        Content += line + "\n";
    }
    while (line!="end");
}
void Email :: SetObject()
{
    cin.sync();
    cout<<"Enter the object of your Email :"<<endl;
    getline(cin,Object);
}
bool Email ::operator==(const Email &mail)
{
    if(From==mail.From && To==mail.To && Content==mail.Content && Object==mail.Object)
        return true;

    return false;
}

 bool Email:: operator!=(const Email&mail){return{!(*this==mail)};};


void Email :: PrintEmail()
{
    cout<<"From :"<<From<<endl;
    cout<<"-------------------------------------------------------------------------------------"<<endl;
    cout<<"To :"<<To<<endl;
    cout<<"-------------------------------------------------------------------------------------"<<endl;
    cout<<"Object:"<<Object<<endl;
    cout<<"-------------------------------------------------------------------------------------"<<endl;
    cout<<"Content :"<<endl<<Content<<endl;
    cout<<"-------------------------------------------------------------------------------------"<<endl;

}

Email& Email :: operator=(Email &&email)
{
    std:: swap(*this,email);
    return *this;
}
Email& Email :: operator=(const Email&email )
{
    Email Copy=email;
    std ::swap(*this,Copy);
    return *this;
}

