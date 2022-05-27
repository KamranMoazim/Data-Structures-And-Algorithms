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

    // int arr[6] = {70,1,90,3,15,20};  // returns  4 
    // int arr[6] = {7,1,9,3,5,2};  // returns  2
    int arr[10] = {7,1,9,3,5,2,0,4,8,100};  // returns  9

    cout<<"Largest Value is at index : "<<findLargestIndex(arr, 4, 7);

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





// *********************************** TASK 4
int power(int a, int b) {
    if(b == 1){
        return a;
    }

    return a * power(a, --b);
}




// *********************************** TASK 5
int product (int a, int b)  {
    if(b == 1){
        return a;
    }

    return a + product(a, --b);
}





// *********************************** TASK 6
// *********** 6.1
void printChar(char ch, int n){
    cout<<ch;
    n--;
    if(n <= 0){
        cout<<endl;
        return;
    }
    printChar(ch, n);
}
// *********** 6.2
void printPattern1(char ch, int n){
    printChar(ch, n);
    n--;
    if(n <= 0){
        cout<<endl;
        return;
    }
    printPattern1(ch, n);
}
// *********** 6.3
void printPattern2 (char ch, int n){

    if(n <= 0){
        return;
    }
    
    int k=n-1;
    printPattern2(ch, k);
    printChar(ch, n);
}






// *********************************** TASK 7
int quotient (int num, int den) {

    if(num < den){
        return 0;
    }

    return 1 + quotient(num-den, den);

}





// *********************************** TASK 8
int findLargestValue(int* arr, int start, int end) {

    int val=arr[end];

    if(start < end){
        int gettingVal = findLargestValue(arr, start+1, end);
        if(arr[start] > gettingVal){
            val = arr[start];
        } else {
            val = gettingVal;
        }
    }
            
    return val;
}




// *********************************** TASK 9
bool areArraysEqual (int* a, int aSize, int* b, int bSize) {

    if(aSize == bSize){

        if(aSize == 0){
            return a[aSize] == b[bSize] ? true : false;
        }


        if(a[aSize-1] == b[bSize-1]){
            bool cond = areArraysEqual(a, --aSize, b, --bSize);
            return true && cond;
        } else {
            return false;
        }

    } else {
        return false;
    }

}




// *********************************** TASK 10
int countVowels (char* str, int length) {

    if(length > 0){
        if((str[length-1] == 'a' || str[length-1] == 'e' || str[length-1] == 'i' || str[length-1] == 'o' || str[length-1] == 'u' || str[length-1] == 'A' || str[length-1] == 'E' || str[length-1] == 'I' || str[length-1] == 'O' || str[length-1] == 'U')){
            return 1 + countVowels(str, --length);
        } else {
            return 0 + countVowels(str, --length);
        }
    }

    return 0;
}



int main(){

    // driverProgram1();

    // driverProgram2();

    // driverProgram3();




    // cout<<power(2,3);
    // cout<<power(4,2);

    // cout<<product(2,3);
    // cout<<product(4,2);

    // cout<<quotient(7,2);
    // cout<<quotient(70,7);
    // cout<<quotient(69,7);

    // int arr1[6] = {70,1,90,3,15,20};
    // int arr2[6] = {70,1,90,3,15,20};
    // cout<<areArraysEqual(arr1, 6, arr2, 6);

    // char name[] = "Kamran";
    char name[] = "Fiazan";
    cout<<countVowels(name, 6);

    cout<<endl;

    return 0;
}
