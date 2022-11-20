#include "useraccount.h"
#include<iostream>
#include"mailserver.h"
#include<string>
#include"algorithm"
#include<iomanip>
using namespace std;
class MailServer;

UserAccount:: UserAccount()//: m_UserName(nullptr)
:m_UserID(0)
{
}
void UserAccount :: createAccount(MailServer&mailserver){
       enterUserName();
       enterUserID(mailserver);
      (mailserver.BstUsers).insert(*this);// when the user create a valid ID (ID is unique)we add it to users of the mail server
     //(mailserver.Users)[m_UserID]=*this;
}


void UserAccount:: SendMailToServer( MailServer&mailserver,Email mail)
{
   // mail.From=m_UserID;
    mailserver.EmailsTobeSent.push(mail);
}
Email& UserAccount::CreateEmail()
{
    cout<<m_UserName<<" ";
    cout<<"you are creating an email"<<endl;
    Email mail;
    mail.SetSender();
    while(mail.From!=this->m_UserID){
    cout<<"Wrong Id"<<endl;
     mail.SetSender();}
    mail.SetReciever();
    mail.SetObject();
    mail.SetContent();
    mail.SendingTimes=0;

 return mail;
}


UserAccount :: UserAccount(UserAccount&&user)
{
    m_UserName=std::move (user.m_UserName);
    m_UserID=std::move(user.m_UserID);
    Inbox=std::move(user.Inbox);
    Sent =std::move(user.Sent);

}
UserAccount ::UserAccount(const UserAccount&user)
{

    m_UserName=user.m_UserName;
    m_UserID=(user.m_UserID);
    Inbox=(user.Inbox);
    Sent =(user.Sent);

}

UserAccount ::~UserAccount()
{
   // delete [] m_UserName;
//    m_UserName=NULL;

}
void UserAccount :: enterUserName ()
{
    //m_UserName=new char[100];
    //cin.getline(m_UserName,100);
    cin.sync();
    std::cout<<"enter your full Name :"<<endl;
    std::getline(std::cin,m_UserName);
     return;
}

void UserAccount :: enterUserID( MailServer& mailserver)
{
   std:: cout<<"enter a valid UserID :"<<endl;
   std:: cin>> m_UserID;
    while((mailserver.BstUsers).contains(m_UserID))
    {
        cout<<"Id already taken try another one "<<endl;
         std::cin>> m_UserID;
    }
return;
}


string UserAccount ::getUserName() const
{
    return m_UserName;
}

long long int UserAccount:: getUserID() const
{
    return m_UserID;
}

bool UserAccount:: operator==(const UserAccount&user2)
{

    if(m_UserID==user2.m_UserID)
    {
        return true;
    }
    else return false;
}

bool UserAccount::operator!=(const UserAccount&user2)
{
    return  !(*this==user2);
}


UserAccount& UserAccount :: operator=(UserAccount && user2)
{
    std::swap(*this,user2);
    return *this;
}
UserAccount& UserAccount :: operator=(const UserAccount&user2)
{
    UserAccount Copy=user2;
    std ::swap(*this,Copy);
    return *this;

}
std::ostream& operator<<(std::ostream&output,const UserAccount&user){

output<<"UserName :"<<setw(35)<<"UserID:"<<std::endl;
output<<user.m_UserName<<setw(35)<<user.m_UserID<<std::endl;
return output;

}

 string UserAccount :: LastEmailRecieved(){return Inbox.top().Object;}

string UserAccount :: LastEmailSent(){return Sent.top().Object;}




