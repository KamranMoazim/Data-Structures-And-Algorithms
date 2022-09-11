#include<iostream>
#include<cmath>

#include"class.cpp"

using namespace std;


void driverTest(){

    MaxHeap mh1(7);
    MaxHeap mh2(7);

    int i=0;
    int val=0;

    // while(i<7){
    //     // cout<<"enter val ";
    //     // cin>>val;
    //     val = val + 10;
    //     mh1.insert(val);
    //     i++;
    // }
    // while(mh1.removeMax(val)){
    //     cout<<"max is : "<<val<<endl;
    // }


    // int* a = new int[7];
    // a[0] = 10;
    // a[1] = 20;
    // a[2] = 30;
    // a[3] = 40;
    // a[4] = 50;
    // a[5] = 60;
    // a[6] = 70;

    // mh2.buildHeap(a, 7);
    // while(mh2.removeMax(val)){
    //     cout<<"max is : "<<val<<endl;
    // }

}




int main(){

    driverTest();    

    return 0;
}
