// Name          Kamran Moazim
// Roll Number   BCS-F19-M-030
// Section       BIT-F20-Afternoon



#include<iostream>

#include"class.cpp"

using namespace std;



// ********************************** TASK 1.3
void menuDisplay(){
    cout<<"\t1. Insert values"<<endl;
    cout<<"\t2. Remove a value"<<endl;
    cout<<"\t3. Search a value"<<endl;
    cout<<"\t4. Display the Linked List"<<endl;
    cout<<"\t5. Sort the Linked List"<<endl;
    cout<<"\t6. Reverse the Linked List"<<endl;
    cout<<"\t7. Empty the Linked List"<<endl;
    cout<<"\t8. Exit"<<endl;
}
void driverProgram(){

    LinkedList l1;

    int val=0, choice=1;
    menuDisplay();

    cout<<"\nEnter your choice: ";
    cin>>choice;

    while(choice != 8){

        switch(choice){
            case 1:
                cout<<"Enter the values to be inserted: ";
                cin >> val;
                l1.insert(val);
                while (cin.get() != '\n') {
                    cin >> val;
                    l1.insert(val);
                }
                break;
            case 2:
                cout<<"Enter the value to be removed: ";
                cin>>val;
                if(l1.remove(val)){
                    cout<<val<<" has been removed from the list"<<endl;
                } else {
                    cout<<"ERROR: "<<val<<" is not found in the linked list"<<endl;
                }
                break;
            case 3:
                cout<<"Enter the value to be searched: ";
                cin>>val;
                if(l1.search(val)){
                    cout<<"The number "<<val<<" is present in the linked list!"<<endl;
                } else {
                    cout<<"ERROR: "<<val<<" is not found in the linked list"<<endl;
                }
                break;
            case 4:
                l1.display();
                break;
            case 5:
                l1.sort();
                l1.display();
                break;
            case 6:
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
        
        cout<<"\nEnter your choice: ";
        cin>>choice;

    }
    cout<<"Bye bye!"<<endl;
}





int main(){

    driverProgram();

    return 0;
}
