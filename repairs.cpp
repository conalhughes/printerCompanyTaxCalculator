#include "repairs.h"
repairs::repairs(){}

repairs::repairs(double rate, Date issue, Date current, double price):details(rate, issue, current, price){}

void repairs::print()
{
    Date issueDate = getIssueDate();
    cout << "Transaction ID: " << getTransactionID() << endl;
    cout << "Repair price: €" << getPrice() << endl;
    cout << "Date of issue: " << issueDate.day << "/" << issueDate.month << "/" << issueDate.year << endl;
    cout << "Days since invoice: " << timeTaken() << endl;
    cout << "Tax due at 13%: €" << taxDue() << endl << endl;
}