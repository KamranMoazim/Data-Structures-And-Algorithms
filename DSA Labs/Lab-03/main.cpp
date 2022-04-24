#include<iostream>


#include"any.cpp"
#include"functions.cpp"

using namespace std;



void driverOne(){
    UnsortedList ul(7);
    UnsortedList list2(4);
    list2.insertVal(19);
    list2.insertVal(89);
    list2.insertVal(9);
    list2.display();
    ul.insertVal(7);
    ul.insertVal(8);
    ul.insertVal(2);
    ul.insertVal(4);
    ul.insertVal(5);
    ul.insertVal(1);
    //ul.insertVal(8);
    ul.display();

    // TASK 1.1
    // UnsortedList intersectionedList1 = ul.intersection(list2);
    // intersectionedList1.display();
    // UnsortedList intersectionedList2 = list2.intersection(ul);
    // intersectionedList2.display();

    // TASK 3.1
    // cout<<"ul is subset of list2 : "<<ul.isSubset(list2)<<endl;
    // cout<<"list2 is subset of ul : "<<list2.isSubset(ul)<<endl;

    // TASK 4.1
    // UnsortedList differencedList1 = ul.difference(list2);
    // differencedList1.display();
    // UnsortedList differencedList2 = list2.difference(ul);
    // differencedList2.display();

    // TASK 5.1
    // UnsortedList unionedList1 = ul.unionFunc(list2);
    // unionedList1.display();
    // UnsortedList unionedList2 = list2.unionFunc(ul);
    // unionedList2.display();
}



void driverTwo(){
    SortedList sl(7);
    sl.insertVal(2);
    sl.insertVal(3);
    sl.insertVal(4);
    sl.insertVal(5);
    sl.insertVal(7);
    cout<<"sl    ==> ";
    sl.display();

    SortedList list2(7);
    list2.insertVal(4);
    list2.insertVal(5);
    list2.insertVal(7);
    list2.insertVal(1);
    cout<<"list2 ==> ";
    list2.display();

    // TASK 1.2
    // SortedList intersectionedList1 = sl.intersection(list2);
    // intersectionedList1.display();
    // SortedList intersectionedList2 = sl.intersection(list2);
    // intersectionedList2.display();

    // TASK 3.1
    // cout<<"sl is subset of list2 : "<<sl.isSubset(list2)<<endl;
    // cout<<"list2 is subset of sl : "<<list2.isSubset(sl)<<endl;

    // TASK 4.1
    SortedList differencedList1 = sl.difference(list2);
    differencedList1.display();
    SortedList differencedList2 = list2.difference(sl);
    differencedList2.display();

    // TASK 5.1
    // SortedList unionedList1 = sl.unionFunc(list2);
    // unionedList1.display();
    // SortedList unionedList2 = list2.unionFunc(sl);
    // unionedList2.display();

}



void driverThree(){
    UnsortedList ul(7);
    ul.insertVal(7);
    ul.insertVal(3);
    ul.insertVal(2);
    ul.insertVal(4);
    ul.insertVal(5);
    ul.insertVal(1);
    ul.display();

    cout<<findKthLargest(ul.getArr(), ul.getCurrentSize(), 1)<<endl;
    cout<<findKthLargest(ul.getArr(), ul.getCurrentSize(), 2)<<endl;
    cout<<findKthLargest(ul.getArr(), ul.getCurrentSize(), 3)<<endl;
    cout<<findKthLargest(ul.getArr(), ul.getCurrentSize(), 4)<<endl;
    
}


int main(){

    // driverOne();
    driverTwo();
    // driverThree();

    // selectionSortTest();
    // insertionSortTest();


    return 0;
}
