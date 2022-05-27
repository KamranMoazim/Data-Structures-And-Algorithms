#include<iostream>
#include<cmath>
#include <typeinfo>

#include"any.cpp"

using namespace std;



// *********** 1

void driverProgram(){

    LinkedList<int> l1;

    char enterMore = 'Y', atStart = 's';
    int val=0;

    while(enterMore == 'Y' || enterMore == 'y'){

        cout<<"Enter Value : ";
        cin>>val;

        // cout<<"Should insert at start (s) OR end (e) : ";
        // cin>>atStart;

        if(atStart == 'S' || atStart == 's'){
            l1.insertAtStart(val);
        } else {
            l1.insertAtEnd(val);
        }

        cout<<"wants to enter more : ";
        cin>>enterMore;

    }

    l1.displayList();
    l1.displayReverseListUsingLoop();

}


int main(){

    driverProgram();

    return 0;
}
