#include "../inc/sum.h"
#include <fstream>
#include <tuple>

using namespace std;

void sum(string fName){
    int x,y,z;
    tuple<int,int,int> t = make_tuple(1,2,3);
    tie(x,y,z) = t;
    fstream ifs;
    ifs.open(fName);
}