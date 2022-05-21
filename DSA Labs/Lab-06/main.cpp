// Name          Kamran Moazim
// Roll Number   BCS-F19-M-030
// Section       BIT-F20-Afternoon

#include<iostream>

#include"class.cpp"

using namespace std;




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

    Deque dq(dequeSize);

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




// *********************************** TASK 2
int findLargestIndex(int* arr, int start, int end) {

    int index=end;

    if(start < end){
        int gettingIndex = findLargestIndex(arr, start+1, end);
        if(arr[start] > arr[gettingIndex]){
            index = start;
        } else {
            index = gettingIndex;
        }
    }
            
    return index;
}

void driverProgram2(){

    // int arr[6] = {7,1,9,3,15,2};  // returns  4 
    // int arr[6] = {7,1,9,3,5,2};  // returns  2
    int arr[10] = {7,1,9,3,5,2,0,4,8,100};  // returns  9

    // cout<<"Largest Value is at index : "<<findLargestIndex(arr, 0, 6);
    cout<<"Largest Value is at index : "<<findLargestIndex(arr, 0, 10);

    cout<<endl;
}


// *********************************** TASK 3.1
void printZigZag(int* arr, int start, int end) {

    if(start < end){
        cout<<arr[start]<<"\t"<<arr[end]<<"\t";
        start++;
        end--;
    } else if(start == end){
        cout<<arr[start]<<"\t";
        start++;
    } else {
        cout<<endl;
        return;
    }
    printZigZag(arr, start, end);    
}

// *********************************** TASK 3.2
void printZigZagUpdated(int* start, int* end) {

    if(start < end){
        cout<<*start<<"\t"<<*end<<"\t";
        start++;
        end--;
    } else if(start == end){
        cout<<*start<<"\t";
        start++;
    } else {
        cout<<endl;
        return;
    }
    printZigZagUpdated(start, end);

}

void driverProgram3(){

    int arr1[5] = {3,6,2,1,4};    // for odd number of items
    int arr2[6] = {7,1,9,3,5,2};  // for even number of items

    printZigZag(arr1, 0, 4);
    printZigZagUpdated(&arr1[0], &arr1[4]);

    printZigZag(arr2, 0, 5);
    printZigZagUpdated(&arr2[0], &arr2[5]);


}


int main(){

    // driverProgram1();

    // driverProgram2();

    // driverProgram3();


    return 0;
}
