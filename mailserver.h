#ifndef MAILSERVER_H
#define MAILSERVER_H
#include<queue>
#include"UserAccount.h"
#include"Email.h"
#include<map>
#include"BSTUSERS.h"
#include<stack>
class UserAccount; //forward declaration
class Email; //forward declaration


class MailServer
{
   friend class  Email;
   friend UserAccount;
    public:
        MailServer();
        MailServer(MailServer&&); //move constructor
        MailServer(const MailServer&); //copy constructor
        ~MailServer(); //destructor
        void SendEmailToDestination();//look fron send to appropriate according to ID then deque if not reach push it again .
        bool ReachedDestination();
        void KeepCopy();//if didnt reach destination keep copy repuch
        void destroy();
        void NotifyUserofError();
        MailServer& operator =(MailServer&&); // move Assignment operator
        MailServer& operator =(const MailServer &); //  copy Assignment operator
        void Print()const;


    protected:

    private:
      // std::map <long long int ,UserAccount> Users;
       BinarySearchTree BstUsers;
       std:: queue<Email>EmailsTobeSent;
       bool contains(std::stack<Email>,Email);
};

#endif // MAILSERVER_H
