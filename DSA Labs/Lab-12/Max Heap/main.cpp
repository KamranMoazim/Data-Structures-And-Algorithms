#include<iostream>
#include<cmath>

#include"class.cpp"
#include"Student.cpp"

using namespace std;


void driverTest(){

    MaxHeap<int> mh1(7);
    MaxHeap<int> mh2(7);

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




void driver1(){

    MaxHeap<Student> mh(7);
    Student std1;

    int roll = 0;
    double cgpa = 0.0;

    cout<<"Enter Student Roll No : ";
    cin>>roll;
    cout<<"Enter Student CGPA : ";
    cin>>cgpa;




}


void driver(){

    StudentMaxHeap mh(7);

    int roll = 0;
    double cgpa = 0.0;


    mh.insert(1, 3.56);
    mh.insert(2, 3.56);
    mh.insert(3, 3.6);

    mh.levelOrder();
    cout<<mh.height()<<endl;

    while(mh.removeBestStudent(roll, cgpa)){
        cout<<"removing  - ";
        cout<<"roll : "<<roll<<" cgpa : "<<cgpa<<endl;
    }


}





int main(){

    // driverTest();
    driver();    

    return 0;
}
