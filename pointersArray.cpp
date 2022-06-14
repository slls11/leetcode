#include <iostream>
using namespace std;

/*
    playing with pointers in arrays and char
    Note: char and char* arr[] have different proprties than normal pointers and arrays
*/

void fun(char* argv[]){
    cout << "---Fun---   :" << endl;
    cout << "argv[2]     :" << argv[2] << endl;
    cout << "*(argv+2)   :" << *(argv+2) << endl;
    cout << "**(argv+2)  :" <<  **(argv+2) << endl;
    cout << "---Fun---   :" << endl;
}

int main(){

    char c0 = 'a';
    char c1 = 'b';
    char c2 = 'c';

    char* a = &c0;
    char* b = &c1;
    char* c = &c2;

    char* argv[] = {a,b,c};

    cout << "&a:         :" << &a << endl;
    cout << "(void *) a  :" << (void *) a << endl;
    cout << "(void *) &c0:" << (void *) &c0 << endl;
    cout << "&argv       :" << &argv << endl;

    fun(argv);

    cout << "--------------" << endl;

    int arr[] = {1,2,3,4};

    cout << "&arr        :" << &arr << endl;
    cout << "&arr[0]     :" << &arr[0] << endl;
    cout << "arr         :" << arr << endl;

    cout << "*arr[0]     :" << *&arr[0] << endl;
    cout << "*arr        :" << *arr << endl;

    cout << "*(arr+1)    :" << *(arr+1) << endl;
    cout << "arr[1]      :" << arr[1] << endl;

    cout << "arr+3       :" << arr+3 << endl;
    cout << "*(arr+3)    :" << *(arr+3) << endl; 

    int* ptr3 = arr+1;

    cout << "ptr3        :" << ptr3 << endl;
    cout << "ptr3        :" << *ptr3 << endl;
    cout << "ptr3        :" << *(ptr3+2) << endl;

return 0;
}

/*
slav007@Slavs-MacBook-Pro Testster % g++ -std=c++17 pointersArray.cpp -o test
slav007@Slavs-MacBook-Pro Testster % ./test
&a:         :0x7ffee51469e0
(void *) a  :0x7ffee51469eb
(void *) &c0:0x7ffee51469eb
&argv       :0x7ffee5146a00
---Fun---   :
argv[2]     :cba
*(argv+2)   :cba
**(argv+2)  :c
---Fun---   :
--------------
&arr        :0x7ffee51469f0
&arr[0]     :0x7ffee51469f0
arr         :0x7ffee51469f0
*arr[0]     :1
*arr        :1
*(arr+1)    :2
arr[1]      :2
arr+3       :0x7ffee51469fc
*(arr+3)    :4
ptr3        :0x7ffee51469f4
ptr3        :2
ptr3        :4
*/