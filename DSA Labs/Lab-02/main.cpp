#include<iostream>


#include"any.cpp"
#include"functions.cpp"

using namespace std;

void driverTwo(){
    int maxInList=0;
    UnsortedList ul(7);
    UnsortedList list2(2);
    list2.insertVal(1);
    list2.insertVal(6);
    // list2.display();
    ul.insertVal(7);
    ul.insertVal(3);
    ul.insertVal(2);
    ul.insertVal(4);
    ul.insertVal(5);
    ul.insertVal(1);
    ul.insertVal(7);
    ul.display();
    ul.reverse();
    ul.display();
    ul.combineList(list2);
    ul.display();
    ul.removeMax(maxInList);
    cout<<maxInList<<endl;
    ul.display();
}




void driverOne(){
    // cout
    SortedList sl(7);
    sl.insertVal(3);
    sl.insertVal(1);
    sl.insertVal(2);
    sl.insertVal(4);
    sl.insertVal(5);
    sl.display();
    sl.replace(3, -1);
    sl.display();
    sl.replace(1, 10);
    sl.display();
    sl.replace(5, 100);
    sl.display();
    cout<<sl.binarySearch(0)<<endl;
    cout<<sl.binarySearch(100)<<endl;
    cout<<sl.binarySearch(5)<<endl;
}



void driverThree(){
    int minInList=0;
    UnsortedList ul(7);
    ul.insertVal(7);
    ul.insertVal(3);
    ul.insertVal(2);
    ul.insertVal(4);
    ul.insertVal(5);
    ul.insertVal(1);
    ul.insertVal(7);
    ul.display();
    ul.removeAllOccurencesWITHOUTNewArray(1);
    ul.display();
    ul.removeMin(minInList);
    cout<<minInList<<endl;
    ul.display();
    ul.removeLastOccurrence(7);
    ul.display();
}


void driverFour(){
    int n=15;
    int c=0;
    int j=0;
    int i=1;
    for(i=1; i<=n; i++){
        cout<<"OUTER-LOOP --> for i="<<i<<"\t";
        cout<<"INNER-LOOP --> for j=";
        for(j=1; j<=n; j=j+i){
            cout<<" "<<j;
            c++;
        }
        cout<<"\tINNER-LOOP-RAN --> c="<<c;
        c=0;
        cout<<endl;
    }
    cout<<"OUTER-LOOP --> for i="<<i<<"\n";
}


void driverFive(){
    int n=7;
    int c=0;
    int j=0;
    int i=1;
    for(i=1; i<=n; i=i*2){
        cout<<"OUTER-LOOP --> for i="<<i<<"\t";
        cout<<"INNER-LOOP --> for j=";
        for(j=0; j<i; j++){
            cout<<" "<<j;
            c++;
        }
        cout<<" "<<j;
        cout<<"\tINNER-LOOP-RAN --> c="<<c;
        c=0;
        cout<<endl;
    }
    cout<<"OUTER-LOOP --> for i="<<i<<"\n";
}


void driverSix(){
    int n=50;
    int c=0;
    int j=0;
    int i=1;
    for(i=1; i<n; i++){
        cout<<"OUTER-LOOP --> for i="<<i<<"\t";
        cout<<"INNER-LOOP --> for j=";
        for(j=1; j<=i; j=j*2){
            cout<<" "<<j;
            c++;
        }
        cout<<" "<<j;
        cout<<"\tINNER-LOOP-RAN --> c="<<c;
        c=0;
        cout<<endl;
    }
    cout<<"OUTER-LOOP --> for i="<<i<<"\n";
}



int main(){

    // driverOne();
    // driverTwo();
    // driverThree();

    // driverFour();
    // driverFive();
    driverSix();

    return 0;
}
