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
void displayMenu(){
    cout<<"1. Insert value at Front"<<endl;
    cout<<"2. Insert value at Back"<<endl;
    cout<<"3. Remove value from Front"<<endl;
    cout<<"4. Remove value from Back"<<endl;
    cout<<"5. Display the Deque"<<endl;
    cout<<"6. Make the Deque Empty"<<endl;
    cout<<"7. Exit"<<endl;
}
void takeInput(int& var){
    cout<<"Enter Number to Insert ";
    cin>>var;
}
// *********************************** TASK 1
void driverProgram1(){

    int dequeSize=0, choice=0, i=0, val=0;

    cout<<"Enter the size of Deque: ";
    cin>>dequeSize;

    if(dequeSize <= 0){
        cout<<"Invalid Queue Size!"<<endl;
        cout<<"Making Queue of size 10."<<endl;
    }

    Deque<int> dq(dequeSize);

    displayMenu();
    cout<<"Enter Choice : ";
    cin>>choice;

    while(choice!=7){

        switch(choice){
            case 1:
                takeInput(val);
                if(!dq.insertAtFront(val)){
                    cout<<"Value could not be inserted, Queue is Full!"<<endl;
                }
                val=0;
                break;
            case 2:
                takeInput(val);
                if(!dq.insertAtBack(val)){
                    cout<<"Value could not be inserted, Queue is Full!"<<endl;
                }
                val=0;
                break;
            case 3:
                if(dq.removeFromFront(val)){
                    cout<<"Removed value is "<<val<<endl;
                } else {
                    cout<<"Queue is Empty!"<<endl;
                }
                val=0;
                break;
            case 4:
                if(dq.removeFromBack(val)){
                    cout<<"Removed value is "<<val<<endl;
                } else {
                    cout<<"Queue is Empty!"<<endl;
                }
                val=0;
                break;
            case 5:
                dq.display();
                break;
            case 6:
                dq.makeEmpty();
            default:
                cout<<"Please Select Valid Choice!"<<endl;
        }

        displayMenu();
        cout<<"Enter Choice : ";
        cin>>choice;
    }
}


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

    // driverProgram1();


    return 0;
}
