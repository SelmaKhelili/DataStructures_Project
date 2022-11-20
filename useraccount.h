#ifndef USERACCOUNT_H
#define USERACCOUNT_H
#include<stack>
#include<string>
#include<iostream>
#include"mailserver.h"
#include"email.h"
#include"BSTUSERS.h"

class Email;
class MailServer;
using std ::string;

class UserAccount
{
    friend BinarySearchTree;
    friend MailServer;
    friend Email;
    public:
        UserAccount(); //constructor
        UserAccount(UserAccount&&);//move constructor
        UserAccount(const UserAccount&); //copy constructor
        ~UserAccount(); //destructor
        void createAccount(MailServer&mailserver);
        string getUserName() const;
        long long int  getUserID() const;
        Email& CreateEmail();
        void SendMailToServer(MailServer& mailserver,Email mail);
        bool operator==(const UserAccount&user2);
        bool operator!=(const UserAccount&user2);
        UserAccount& operator=(const UserAccount&user2);   //copy Assignment overloaded  operator
        UserAccount& operator=(UserAccount && user2);     //move Assignment overloaded operator
        friend std::ostream& operator<<(std::ostream&output,const UserAccount&);
        string LastEmailRecieved();
        string LastEmailSent();



    private:
        //char* m_UserName;
         string m_UserName;
        long long int m_UserID;
        std::stack<Email>Inbox;
        std::stack<Email> Sent;
        // string TimeZone;
        /*this additional data to improve sending email phase if sender and reciever have diffrent timezones then suggsetTimeTosend();
        suggest is an intelligent function that works with machine learning and data collection so it's going to collect data on the time
         when users are more frequently to open their emails then suggest it to sender if sender does not know when to send his email */
        void enterUserName();
        void enterUserID(MailServer& mailserver);

};

#endif // USERACCOUNT_H
