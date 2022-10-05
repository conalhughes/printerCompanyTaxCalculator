#pragma once
#include "details.h"
class printer: public details
{
    public:
        printer();
        printer(double,Date,Date,double);
        void print();
};