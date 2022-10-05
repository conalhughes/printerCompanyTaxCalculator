#include "printer.h"
#include "repairs.h"

double taxBill(details **d)
{
    double bill = 0;
    for(int p = 0; p < 4; p++)
    {
        bill += d[p]->taxDue();
    }
    return bill;
}
int main()
{
    int currentDay, currentMonth, currentYear;
    bool leapYear = false;
    cout << "Enter todays date in the form DD MM YYYY\n";
    cin >> currentDay >> currentMonth >> currentYear;

    if(currentYear%4 == 0)
        leapYear = true;

    if(currentMonth > 12)
    {
        do
        {
            cout << "Invalid date, please enter month again\n";
            cin >> currentMonth;
        } while (currentMonth > 12);
    }
    if((currentMonth == 9 || currentMonth == 4 || currentMonth == 6 || currentMonth == 11) && currentDay > 30) // 30 days has September, April, June and November
    {
        do
        {
            cout << "Invalid date, please enter day again\n";
            cin >> currentDay;
        } while (currentDay > 30);
    }
    else if(currentMonth == 2 && (currentDay > 29 && leapYear)) // if its february and a leap year
    {
        do
        {
            cout << "Invalid date, please enter day again\n";
            cin >> currentDay;
        } while (currentDay > 29);
    }
    else if(currentMonth == 2 && currentDay > 28)
    {
        do
        {
            cout << "Invalid date, please enter day again\n";
            cin >> currentDay;
        } while (currentDay > 28);
    }
    else
    {
        do
        {
            cout << "Invalid date, please enter day again\n";
            cin >> currentDay;
        } while (currentDay > 31);
    }

    Date todaysDate = {currentDay, currentMonth,currentYear};

    details *incomeArray[4];

    cout << "\n\nEnter sale or repairs details for 4 jobs\n";
    for(int p = 0; p < 4; p++)
    {
        cout << "\nEnter P for printer sale or R for repair job, and the price\n";
        char c;
        int price, day, month, year;
        cin >> c >> price;
        cout << "Enter the date of issue(DD MM YYYY)\n";
        cin >> day >> month >> year;
        Date issueDate = {day, month, year};
        switch(c)
        {
            case 'P':
                incomeArray[p] = new printer(0.23, issueDate, todaysDate, price);
                break;
            case 'R':
                incomeArray[p] = new repairs(0.13, issueDate, todaysDate, price);
                break;
            default:
                p--;
                cout <<"Invalid information. Please try again.\n";
                break;
        }
    }

    for(int p = 0; p < 4; p++)
    {
        incomeArray[p]->print();
    }

    cout << "\nTotal tax bill: €" << taxBill(incomeArray) << endl;
    // delete rep;
    // // delete rep2;
    // delete pr;
    // // delete pr2;
    // delete[] polyPr;
    // delete[] polyRep;
}