#include "printer.h"
printer::printer(){}

printer::printer(double rate, Date issue, Date current, double price):details(rate, issue, current, price){}

void printer::print()
{
    Date issueDate = getIssueDate();
    cout << "Transaction ID: " << getTransactionID() << endl;
    cout << "Printer price: €" << getPrice() << endl;
    cout << "Date of issue: " << issueDate.day << "/" << issueDate.month << "/" << issueDate.year << endl;
    cout << "Days since invoice: " << timeTaken() << endl;
    cout << "Tax due at 23%: €" << taxDue() << endl << endl;
}