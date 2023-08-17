#include "heap.hpp"
#include <iostream>
#include <vector>
using namespace std;
#define k 10;
int main(){
    
    int x[8] = {7,6,5,4,3,2,1,9};
    heap h(8,x);
    cout << "\n\n";
    h.imprime();
    cout << "\n\n";

}