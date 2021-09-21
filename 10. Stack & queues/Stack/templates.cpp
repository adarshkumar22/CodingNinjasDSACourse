#include<iostream>
using namespace std;
#include "templatesClass.cpp"
int main(){
    Pair<int, double> p2;
    Pair<Pair<int, double>, char> p;
    p.setB('l');
    
    p2.setA(10);
    p2.setB(10.10);
    p.setA(p2);

    return 0;
}