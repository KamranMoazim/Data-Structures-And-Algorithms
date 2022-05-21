#include<iostream>
#include<cmath>

#include"any.cpp"

using namespace std;


void driver1(){

    Queue<int> myQueue(5);

    int val = 0;

    myQueue.enqueue(5);
    myQueue.enqueue(3);
    myQueue.enqueue(1);
    myQueue.print();


    myQueue.enqueue(0);
    myQueue.enqueue(90);
    myQueue.print();


    myQueue.dequeue(val);
    cout<<val<<endl;
    myQueue.print();

    myQueue.enqueue(900);
    myQueue.print();

    myQueue.enqueue(700); // it will not be queued as it is already full
    myQueue.print();
    
}

// *********** 1


int main(){

    // int total = 10;

    // int front = 0;
    // cout<<"Enqueue"<<endl;
    // cout<<total<<endl;
    // for(int i=0; i<14; i++){
    //     cout<<front<<endl;
    //     front = ((front+1)%(total));
    // }

    // int rear = 0;
    // cout<<"Dequeue"<<endl;
    // cout<<total<<endl;
    // for(int i=0; i<14; i++){
    //     cout<<rear<<endl;
    //     rear = ((rear+1)%(total));
    // }

    driver1();


    return 0;
}
