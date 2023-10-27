#include "./include/storage/internals/DiskManager.h"
#include "./include/storage/table/Tuple.h"
#include<iostream>
#include<vector>


using namespace std;

using namespace demo;
int main() {
    /*
    //Disk Manager
    demo::DiskManager X("hello.txt", 32);
    char x[100];
     X.WritePage(0, "hello");
    X.ReadPage(0, x);
    cout << x[0];
    */
   vector<Value>testInput;
   vector<Column>columns;
   for (int i = 0; i < 5; i++) {
    testInput.push_back(Value(i));
    Column y;
    columns.push_back(y);
   }

   Schema x(columns);
   
   Tuple childTuple(testInput, &x);

}