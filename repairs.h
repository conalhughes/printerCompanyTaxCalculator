#pragma once
#include "details.h"
class repairs: public details
{
    public:
        repairs();
        repairs(double, Date, Date, double);
        void print();
};