#ifndef EMAIL_H
#define EMAIL_H
#include<string>
#include "mailserver.h"

class MailServer;
class Email
{
    friend class UserAccount;
    friend class MailServer;
    public:
        Email();
        Email(const Email&);//copy constructor
        Email(Email&&); //move constructor
        Email(long long int reciever);
        void SetSender();
        void SetReciever();
        void SetObject();
        void SetContent();
        void PrintEmail();
        bool operator==(const Email&);
        bool operator!=(const Email&);
        Email& operator=(Email&&);// move Assignment operator
        Email& operator=(const Email&);// copy Assignment operator




    private:
        long long int From;
        long long int To;
        std::string Object;
        std::string Content;
        int SendingTimes;
};

#endif // EMAIL_H
