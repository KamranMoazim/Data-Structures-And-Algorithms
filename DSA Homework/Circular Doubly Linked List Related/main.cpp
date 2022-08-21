#include<iostream>
#include<cmath>
#include <typeinfo>

#include"any.cpp"

using namespace std;



// *********** 1
void menuDisplay(){
    cout<<"1. to insert at start"<<endl;
    cout<<"2. to insert at end"<<endl;
    cout<<"3. to insert at before a particular ( sortedInsert ) "<<endl;
    cout<<"4. to insert at after a particular ( uniqueSortedInsert ) "<<endl;
    cout<<"5. to remove ( sortedRemove ) "<<endl;
    cout<<"6. to remove ( unsortedRemove ) "<<endl;
    cout<<"7. to DISPLAY"<<endl;
    cout<<"8. Testing of Copy Constructor"<<endl;
    cout<<"9. Testing of Assignment Operator"<<endl;
    cout<<"10. to EXIT"<<endl;
}

const int toEXIT = 10;

void driverProgram(){

    CDLLD<int> l1;
    CDLLD<int> l2;
    CDLLD<int> l3;

    int val=0, choice=1;

    menuDisplay();
    cin>>choice;

    while(choice != toEXIT){

        switch(choice){
            case 1:
                cout<<"Enter Values : ";
                cin >> val;
                l1.insertAtStart(val);
                while (cin.get() != '\n') {
                    cin >> val;
                    l1.insertAtStart(val);
                }
                break;
            case 2:
                cout<<"Enter Values : ";
                cin >> val;
                l1.insertAtEnd(val);
                while (cin.get() != '\n') {
                    cin >> val;
                    l1.insertAtEnd(val);
                }
                break;
            case 3:
                cout<<"Enter Value : ";
                cin>>val;
                l1.sortedInsert(val);
                break;
            case 4:
                cout<<"Enter Value : ";
                cin>>val;
                // l1.uniqueSortedInsert(val);
                break;
            case 5:
                cout<<"Enter Value (which you wants to remove) : ";
                cin>>val;
                l1.sortedRemove(val);
                break;
            case 6:
                cout<<"Enter Value (which you wants to remove) : ";
                cin>>val;
                l1.unsortedRemove(val);
                break;
            case 7:
                l1.display();
                break;
            case 8:
                cout<<"Testing of Copy Constructor : ";
                {
                    CDLLD<int> l3 = l1;
                    l3.display();
                }
                break;
            case 9:
                cout<<"Testing of Assingment Operator : "<<endl;
                cout<<"Before "<<endl;
                l2.display();
                l2 = l1;
                cout<<"After "<<endl;
                l2.display();
                break;
            case toEXIT:
                break;
            default:
                cout<<"PLEASE SELECT VALID OPTION"<<endl;
        }
        
        // menuDisplay();
        cout<<"Enter choice : ";
        cin>>choice;

    }

}


int main(){

    driverProgram();

    return 0;
}
