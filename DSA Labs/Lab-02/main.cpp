#include<iostream>


#include"any.cpp"
#include"functions.cpp"

using namespace std;

void driverOne(){
    UnsortedList ul(7);
    ul.display();
    ul.insertVal(4);
    ul.insertVal(7);
    ul.insertVal(7);
    ul.insertVal(3);
    ul.insertVal(3);
    ul.insertVal(1);
    ul.insertVal(1);
    ul.display();
    // ul.removeAllOccurencesAndShiftLeft(1);
    // ul.removeAllOccurencesWithNewArray(1);
    // ul.removeAllOccurencesAndPlaceLastElementOnThesePlaces(7);
    // ul.removeAllOccurencesWITHOUTNewArray(4);
    // ul.removeSingleOccurenceAndPlaceLastElementOnThisPlaces(0);  // give index
    // ul.removeSingleOccurenceAndShiftLeft(0);   // give index
    ul.display();
}




void driverTwo(){
    SortedList sl(7);
    sl.display();
    sl.insertVal(3);
    sl.insertVal(1);
    sl.insertVal(2);
    sl.insertVal(-4);
    sl.insertVal(5);
    sl.uniqueInsertVal(6);
    sl.uniqueInsertVal(-4);
    // sl.display();
    // sl.removeAllOccurencesAndShiftLeft(7);
    // sl.removeAllOccurencesWithNewArray(1);
    // sl.removeAllOccurencesWITHOUTNewArray(4);
    // sl.removeSingleOccurenceAndShiftLeft(3);   // give index
    sl.display();
    cout<<binarySearch(sl.getArr(), sl.getCurrentSize(), -4)<<endl;
}




int main(){

    driverOne();


    return 0;
}
