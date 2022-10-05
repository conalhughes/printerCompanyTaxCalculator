#include "details.h"
int details::StransactionID = 1000;
details::details()
{  
    taxRate = 0;

    issueDate.day = 0;
    issueDate.month = 0;
    issueDate.year = 0;

    currentDate.day = 0;
    currentDate.month = 0;
    currentDate.year = 0;

    price = 0;

    transactionID = StransactionID;
    StransactionID++;
}
details::details(double rate, Date issue, Date current, double price)
{  
    taxRate = rate;

    issueDate.day = issue.day;
    issueDate.month = issue.month;
    issueDate.year = issue.year;

    currentDate.day = current.day;
    currentDate.month = current.month;
    currentDate.year = current.year;

    this->price = price;

    transactionID = StransactionID;
    StransactionID++;
}
void details::setDetails(double rate, Date issue, Date current, double price)
{  
    taxRate = rate;

    issueDate.day = issue.day;
    issueDate.month = issue.month;
    issueDate.year = issue.year;

    currentDate.day = current.day;
    currentDate.month = current.month;
    currentDate.year = current.year;

    this->price = price;
}
int details::timeTaken()
{
    // int *days = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31};
    // int *months = {1,2,3,4,5,6,7,8,9,10,11,12};

    int dayCount = 0;
    int day = issueDate.day;
    int month = issueDate.month;
    int year = issueDate.year;

    while(day != currentDate.day || month != currentDate.month || year != currentDate.year)
    {
        // 30 days September, april june and November
        // 28 days February, 29 on leap year
        bool leapYear = (year%4 == 0); // true if leap year
        bool shortMonth = (month == 9 || month == 4 || month == 6 || month == 11) ? true : false;
        day++;
        if(day == 32 || (day == 31 && (shortMonth)) || (day == 30 && (leapYear) && month == 2) || (day == 29 && (!leapYear) && month == 2)) // if end of month
        {
            day = 1;
            month++;
        }
        if(month == 13)
        {
            month = 1;
            year++;
        }
        dayCount++;
    }
    return dayCount;
}
double details::taxDue()
{
    int periods = timeTaken()/28;
    int taxPaid = taxRate*price;
    if(periods == 0)
    {
        return taxPaid;
    }
    return taxPaid*pow(1.02,periods); // compound tax interest
}

double details::getPrice()
{
    return price;
}
Date details::getIssueDate()
{
    return issueDate;
}
int details::getTransactionID()
{
    return transactionID;
}

void details::setPrice(double price)
{
    this->price = price;
}
void details::setTransactionID(int ID)
{
    transactionID = ID;
}

void details::print(){}