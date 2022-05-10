#include <iostream>
using namespace std;

/*
    playing with pointers, single,double,triple
*/

void pointerTester(){
    int num = 2;
    // good
    int* ptr;
    ptr = &num;
    cout << "ptr:" << ptr << endl;
    cout << "*ptr:" << *ptr << endl;

    // good
    int* ptr2 = &num;
    cout << "ptr2:" << ptr2 << endl;
    cout << "*ptr2:" << *ptr << endl;

    // bad, produces seg fault!!!
    int* ptr3;
    *ptr3 = num; // seg falut here
    cout << "pt3:" << ptr3 << endl;
    cout << "*ptr3:" << *ptr3 << endl;
}

/* shows how pointer works, pointer is address to something else, 
   &pointer is  the block of meomery where the pointer is located, 
   "home of pointer"
*/
void ptrTester(){
    int num = 5;
    
    // single pointer
    int* ptr;
    ptr = &num;
    cout << "&num ::::" << &num << endl;
    cout << "*ptr ::::" << *ptr << endl;
    cout << "*&num :::" << *&num << endl; 
    cout << "ptr :::::" << ptr << endl;
    cout << "&ptr ::::" << &ptr << endl;
    cout << "*&ptr :::" << *&ptr << endl;
    cout << "**&ptr ::" << **&ptr << endl;

    // double pointer
    int** ptr2 = &ptr;
    cout << "&ptr2 :::" << &ptr2 << endl;
    cout << "ptr2 ::::" << ptr2 << endl;
    cout << "*ptr2 :::" << *ptr2 << endl;
    cout << "**ptr2 ::" << **ptr2 << endl;
    
    // triple pointer
    int*** ptr3 = &ptr2;
    cout << "&ptr3 :::" << &ptr3 << endl;
    cout << "ptr3 ::::" << ptr3 << endl;
    cout << "*ptr3 :::" << *ptr3 << endl;
    cout << "**ptr3 ::" << **ptr3 << endl;
    cout << "***ptr3 :" << ***ptr3 << endl;

}

int main(){
    //pointerTester();
    ptrTester();
return 0;
}

/* Output for prtTester() function
slav007@Slavs-MacBook-Pro DataStructures % ./pointerTester
&num ::::0x7ffeedaa294c
*ptr ::::5
*&num :::5
ptr :::::0x7ffeedaa294c
&ptr ::::0x7ffeedaa2940
*&ptr :::0x7ffeedaa294c
**&ptr ::5
&ptr2 :::0x7ffeedaa2938
ptr2 ::::0x7ffeedaa2940
*ptr2 :::0x7ffeedaa294c
**ptr2 ::5
&ptr3 :::0x7ffeedaa2930
ptr3 ::::0x7ffeedaa2938
*ptr3 :::0x7ffeedaa2940
**ptr3 ::0x7ffeedaa294c
***ptr3 :5
*/
