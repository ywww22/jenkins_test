#include "../inc/sum.h"
#include <fstream>

using namespace std;

void sum(string fName){
    string *name = &fName;
    cout << *name << endl;
    ifstream ifs(*name);
    ifs.close();
}