#include<iostream>
#include<cmath>
#include <typeinfo>

#include"any.cpp"

using namespace std;



// *********** 1

void driverProgram(){

    LinkedList<int> l1;

    char enterMore = 'Y', atStart = 's';
    int val=0, i=0;

    // while(enterMore == 'Y' || enterMore == 'y'){
    while(i<5){

        cout<<"Enter Value : ";
        cin>>val;

        l1.insertAtEnd(val);

        // cout<<"Should insert at start (s) OR end (e) : ";
        // cin>>atStart;

        // if(atStart == 'S' || atStart == 's'){
        //     l1.insertAtStart(val);
        // } else {
        //     l1.insertAtEnd(val); 
        // }

        // cout<<"wants to enter more : ";
        // cin>>enterMore;

        i++;
    }

    cout<<"Simple Display : ";
    l1.displayList();
    cout<<"Reverse Display : ";
    l1.displayReverseListUsingLoop();
    cout<<"Max in List : ";
    cout<<l1.findMax();
    cout<<endl;

}


int main(){

    driverProgram();

    return 0;
}
