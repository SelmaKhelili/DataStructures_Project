#include "mailserver.h"
#include"email.h"
#include<iostream>
#include<alg.h>
#include<functional>
using namespace std;

MailServer :: MailServer(MailServer&&mailserver)
{
EmailsTobeSent=std::move (mailserver.EmailsTobeSent);
Users=std::move(mailserver.Users);
}
MailServer :: MailServer(const MailServer& mailserver)
{
  EmailsTobeSent=(mailserver.EmailsTobeSent);

    Users=(mailserver.Users);

}
MailServer ::MailServer(){}
MailServer :: ~MailServer(){}


 void MailServer :: SendEmailToDestination()
{
    Email mail=EmailsTobeSent.front(); //emails are going to be sent by order the one that came first to server to be sent first

    UserAccount reciever =Users[mail.To];

    UserAccount sender =Users[mail.From];

    ((reciever).Inbox).push(mail);       // mailserver will send email to reciever's inbox

     mail.SendingTimes++;

     if(!ReachedDestination())
    {    KeepCopy();

        EmailsTobeSent.pop();
        return;

    }      //if it did not reach destination keep a copy of it repush it to queue

    if(mail.SendingTimes==3 && !ReachedDestination())
    {
        destroy();   //if conditions are satisfied the email will be destroyed
        return;
    }
    (sender).Sent.push(mail);         // mail serevr add sent email to sent of sender when succesfully sent
    EmailsTobeSent.pop();                  //after sending succesfully we remove it from Emailstobesent because it's already successfully sent
    cout<<"email sent successfully"<<endl;
}
bool MailServer :: ReachedDestination()
{

    Email mail=EmailsTobeSent.front();    // we always deal with the email which is first in the queue

    UserAccount reciever=Users[mail.To];   //reciever

    return contains(reciever.Inbox,mail); // look in the reciever inbox if the email is there

}
bool MailServer::  contains(stack<Email>target,Email mail)
{
    while(!target.empty()&&target.top()!= mail)
    {
        target.pop();
    }
    if(target.empty())
    {
        return false;
    }
    return true;
   /*this function look for an email if it exist in stack of emails it takes
   a copy of the stack and pop and check the top if it's the email or not if at the end
   we find it empty then it did not find the email otherwise it found it.*/
  }

void MailServer :: KeepCopy()
{
    Email mail=EmailsTobeSent.front(); // to keep copy push it again to the queue

    EmailsTobeSent.push(mail);
}
void MailServer :: destroy()
{

    EmailsTobeSent.pop();

    NotifyUserofEror();
}

void MailServer ::NotifyUserofEror()
{
cout<<"your email did not reach destination"<<endl;
}


MailServer& MailServer :: operator =(MailServer && mailserver)
{
    std ::swap(*this,mailserver);

    return mailserver;
}

MailServer& MailServer :: operator =(const MailServer& mailserver)
{
    MailServer Copy=mailserver;

    std ::swap(*this,Copy);

    return *this;
}
std::ostream& operator<<(std::ostream&,const MailServer&mailserver){

//ap<long long int,UserAccount>::iterator cursor;
cout<<"Users present in the server are"<<endl;
for(auto i=mailserver.Users.begin();i!=mailserver.Users.end();i++)
{
cout<<(i->second)<<endl;
}
}




