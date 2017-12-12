#ifndef DISPATCHER_H
#define DISPATCHER_H

#include <list>
#include<stdio.h>
#include<iostream>
#include<algorithm>
#include <objbase.h>
#include "TopologyPainter.h"
#include "Tools.h"

using namespace std;

class Dispatcher
{
public:
    Dispatcher();

    void autoCompute();
};

#endif // TESTDEMO_H
