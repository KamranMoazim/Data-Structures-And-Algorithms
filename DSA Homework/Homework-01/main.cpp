#include<iostream>
#include<fstream>

#include"MyString.cpp"
#include"any.cpp"

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



class Class1 {
public:
    virtual void f() {
        cout << "Function f() in Class1\n";
    }
    void g() {
        cout << "Function g() in Class1\n";
    }
};
class Class2 {
public:
    virtual void f() {
        cout << "Function f() in Class2\n";
    }
    void g() {
        cout << "Function g() in Class2\n";
    }
};
class Class3 {
public:
    virtual void k() {
        cout << "Function k() in Class3\n";
    }
    virtual void h() {
        cout << "Function h() in Class3\n";
    }
};



void driverThree(){
    Class1 object1, *p;
    Class2 object2;
    Class3 object3;
    p = &object1;
    p->f();
    p->g();
    p = (Class1*) &object2;
    p->f();
    p->g();
    p = (Class1*) &object3;
    p->f();  // possibly abnormal program termination;
    p->g();  
    // p->h();  // h() is not a member of Class1;
}





int main(){

    // driverOne();
    // driverTwo();

    driverThree();

    

    return 0;
}
