#include<iostream>
#include<cmath>
#include <typeinfo>

#include"any.cpp"

using namespace std;



// *********** 1
void menuDisplay(){
    cout<<"1. Insert values"<<endl;
    cout<<"2. Remove a value"<<endl;
    cout<<"3. Search a value"<<endl;
    cout<<"4. Display the Linked List"<<endl;
    cout<<"5. Sort the Linked List"<<endl;
    cout<<"6. Reverse the Linked List"<<endl;
    cout<<"7. Empty the Linked List"<<endl;
    cout<<"8. Exit"<<endl;
}
void driverProgram(){

    LinkedList l1;

    int val=0, choice=1;
    int n=0;

    menuDisplay();
    cin>>choice;

    while(choice != 8){

        switch(choice){
            case 1:
                cout<<"Enter Values : ";
                while(n<7){
                    cin>>val;
                    l1.insert(val);
                    n++;
                }
                n=0;
                break;
            case 2:
                cout<<"Enter Value to remove : ";
                cin>>val;
                l1.remove(val);
                break;
            case 3:
                cout<<"Enter Value : ";
                cin>>val;
                if(l1.search(val)){
                    cout<<"The number "<<val<<" is present in the linked list!"<<endl;
                }
                break;
            case 4:
                l1.display();
                break;
            case 5:
                cout<<"The list has been sorted!"<<endl;
                l1.sort();
                l1.display();
                break;
            case 6:
                cout<<"The list has been reversed!"<<endl;
                l1.reverse();
                l1.display();
                break;
            case 7:
                l1.emptyList();
                cout<<"All the values have been removed from the linked list!"<<endl;
                break;
            default:
                cout<<"PLEASE SELECT VALID OPTION"<<endl;
        }
        
        menuDisplay();
        cin>>choice;

    }
    cout<<"Bye Bye!"<<endl;
}


int main(){

    driverProgram();

    return 0;
}
