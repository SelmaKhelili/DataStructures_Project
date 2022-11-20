#include <iostream>
#include"email.h"
#include"useraccount.h"
#include"mailserver.h"

using namespace std;

int main()
{
MailServer mailserver;
UserAccount user1;
user1.createAccount(mailserver);
UserAccount user2;
cout<<"second user"<<endl;
user2.createAccount(mailserver);
Email mail =user1.CreateEmail();
user1.SendMailToServer(mailserver,mail);
mailserver.SendEmailToDestination();
cout<<user1.LastEmailSent();
cout<<user2.LastEmailRecieved();




    return 0;
}
