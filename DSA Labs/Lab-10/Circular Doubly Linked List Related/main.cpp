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

    CDLLD l1;
    CDLLD l2;
    CDLLD l3;

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
                    CDLLD l3 = l1;
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


void driver1(){

    CDLLD l1;
    CDLLD l2;
    CDLLD l3;

    int val;

    cout<<"Enter Values for list1 : ";
    cin >> val;
    l1.insertAtEnd(val);
    while (cin.get() != '\n') {
        cin >> val;
        l1.insertAtEnd(val);
    }


    cout<<"Enter Values for list2 : ";
    cin >> val;
    l2.insertAtEnd(val);
    while (cin.get() != '\n') {
        cin >> val;
        l2.insertAtEnd(val);
    }

    cout<<"list1 : ";
    l1.display();
    cout<<"list2 : ";
    l2.display();

    l3.combine(l1, l2);


    cout<<"list3 : ";
    l3.display();


    cout<<"list1 : ";
    l1.display();
    cout<<"list2 : ";
    l2.display();
}



void driver2(){

    CDLLD l1;
    CDLLD l2;
    CDLLD l3;

    int val;

    cout<<"Enter Values for list1 : ";
    cin >> val;
    l1.insertAtEnd(val);
    while (cin.get() != '\n') {
        cin >> val;
        l1.insertAtEnd(val);
    }


    cout<<"Enter Values for list2 : ";
    cin >> val;
    l2.insertAtEnd(val);
    while (cin.get() != '\n') {
        cin >> val;
        l2.insertAtEnd(val);
    }

    cout<<"list1 : ";
    l1.display();
    cout<<"list2 : ";
    l2.display();

    l3.shuffleMerge(l1, l2);


    cout<<"list3 : ";
    l3.display();


    cout<<"list1 : ";
    l1.display();
    cout<<"list2 : ";
    l2.display();
}



void driver3(){

    CDLLD l1;
    CDLLD l2;
    CDLLD l3;

    int val;

    cout<<"Enter Values for list1 : ";
    cin >> val;
    l1.insertAtEnd(val);
    while (cin.get() != '\n') {
        cin >> val;
        l1.insertAtEnd(val);
    }


    cout<<"list1 : ";
    l1.display();

    l1.splitList(l2, l3);

    cout<<"list2 : ";
    l2.display();
    cout<<"list3 : ";
    l3.display();

    cout<<"list1 : ";
    l1.display();
}



void driver4(){

    CDLLD l1;
    CDLLD l2;
    CDLLD l3;

    int val;

    cout<<"Enter Values for list1 : ";
    cin >> val;
    l1.insertAtEnd(val);
    while (cin.get() != '\n') {
        cin >> val;
        l1.insertAtEnd(val);
    }


    cout<<"list1 : ";
    l1.display();

    if(l1.isSorted()){
        cout<<"List is Sorted"<<endl;
    } else {
        cout<<"List is NOT Sorted"<<endl;
    }

}


void driver5(){

    CDLLD l1;
    CDLLD l2;
    CDLLD l3;

    int val;

    cout<<"Enter Values for list1 : ";
    cin >> val;
    l1.insertAtEnd(val);
    while (cin.get() != '\n') {
        cin >> val;
        l1.insertAtEnd(val);
    }


    cout<<"list1 : ";
    l1.display();

    int c = 1;

    while(c > 0){

        if(l1.removeLastNode(val)){
            cout<<"removed : "<<val<<endl;
        }
        c--;
    }

    cout<<"list1 : ";
    l1.display();
}


void driver6(){

    CDLLD l1;
    CDLLD l2;
    CDLLD l3;

    int val;

    cout<<"Enter Values for list1 : ";
    cin >> val;
    l1.insertAtEnd(val);
    while (cin.get() != '\n') {
        cin >> val;
        l1.insertAtEnd(val);
    }


    cout<<"list1 : ";
    l1.display();

    int c = 1;

    while(c > 0){

        if(l1.removeSecondLastNode(val)){
            cout<<"removed : "<<val<<endl;
        }
        c--;
    }

    cout<<"list1 : ";
    l1.display();
}


void driver7(){

    CDLLD l1;
    CDLLD l2;
    CDLLD l3;

    int val;

    cout<<"Enter Values for list1 : ";
    cin >> val;
    l1.insertAtEnd(val);
    while (cin.get() != '\n') {
        cin >> val;
        l1.insertAtEnd(val);
    }


    cout<<"list1 : ";
    l1.display();

    int c = 1;

    while(c > 0){

        cout<<"which node you wants to remove : ";
        cin>>val;

        if(l1.removeKthNode(val, val)){
            cout<<"removed : "<<val<<endl;
        }
        c--;
    }

    cout<<"list1 : ";
    l1.display();
}





void driver8(){

    CDLLD l1;
    CDLLD l2;
    CDLLD l3;

    int val;

    cout<<"Enter Values for list1 : ";
    cin >> val;
    l1.insertAtEnd(val);
    while (cin.get() != '\n') {
        cin >> val;
        l1.insertAtEnd(val);
    }


    cout<<"Enter Values for list2 : ";
    cin >> val;
    l2.insertAtEnd(val);
    while (cin.get() != '\n') {
        cin >> val;
        l2.insertAtEnd(val);
    }

    cout<<"list1 : ";
    l1.display();
    cout<<"list2 : ";
    l2.display();

    l3.merge(l1, l2);


    cout<<"list3 : ";
    l3.display();


    // cout<<"list1 : ";
    // l1.display();
    // cout<<"list2 : ";
    // l2.display();
}


void driver9(){

    CDLLD l1;
    CDLLD l2;
    CDLLD l3;

    int val;

    cout<<"Enter Values for list1 : ";
    cin >> val;
    l1.insertAtEnd(val);
    while (cin.get() != '\n') {
        cin >> val;
        l1.insertAtEnd(val);
    }


    cout<<"list1 : ";
    l1.display();
    

    l1.mergeSort();


    // cout<<"list1 : ";
    // l1.display();
}



void driver10(){

    CDLLD l1;
    CDLLD l2;
    CDLLD l3;

    int val;

    cout<<"Enter Values for list1 : ";
    cin >> val;
    l1.insertAtEnd(val);
    while (cin.get() != '\n') {
        cin >> val;
        l1.insertAtEnd(val);
    }


    cout<<"list1 : ";
    l1.display();
    

    l1.reverse();


    cout<<"\nlist1 : ";
    l1.display();
}


void driver11(){

    CDLLD l1;
    CDLLD l2;
    CDLLD l3;

    int val;

    cout<<"Enter Values for list1 : ";
    cin >> val;
    l1.insertAtEnd(val);
    while (cin.get() != '\n') {
        cin >> val;
        l1.insertAtEnd(val);
    }


    cout<<"list1 : ";
    l1.display();
    

    l1.insertionSort();


    cout<<"\nlist1 : ";
    l1.display();
}



void driver12(){
    JosephusList jl1(5);
    JosephusList jl2(5);
    JosephusList jl3(5);

    int winner = jl1.getWinner(0);
    cout<<"winner is for 0 is : "<<winner<<endl;

    winner = jl2.getWinner(1);
    cout<<"winner is for 1 is : "<<winner<<endl;

    winner = jl3.getWinner(2);
    cout<<"winner is for 2 is : "<<winner<<endl;
}


int main(){

    // driver1();
    // driver2();
    // driver3();
    // driver4();
    // driver5();
    // driver6();
    // driver7();



    // driver8();
    driver9();
    // driver10();
    // driver11();
    // driver12();


    return 0;
}
