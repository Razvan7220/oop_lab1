#include "Canvas.h"
#include<iostream>
using namespace std;

int main() {
    Canvas O(30,50);
    O.DrawCircle(10, 10, 7, '$');
    O.FillCircle(10, 10, 7, '.');
    O.DrawRect(20, 20, 40,26, '#');
    O.FillRect(20, 20, 40, 26, '.');
    O.SetPoint(10, 45,'@');
    O.SetPoint(10, 10, '+');
    O.DrawLine(3, 37, 14, 29, '~');
    O.Print();
    return 0;
}
