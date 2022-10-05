#pragma once
#include <string>
#include <cmath>
#include <iostream>
using namespace std;
struct Date
{
    int day;
    int month;
    int year;
};
class details
{
    double taxRate;
    Date issueDate;
    Date currentDate;
    double price;
    int transactionID;
    
    public:
        static int StransactionID;
        details();
        details(double, Date, Date, double);

        void setDetails(double, Date, Date, double);
        int timeTaken();
        double taxDue();

        double getPrice();
        int getTransactionID();
        Date getIssueDate();

        void setPrice(double);
        void setTransactionID(int);

        virtual void print();
};