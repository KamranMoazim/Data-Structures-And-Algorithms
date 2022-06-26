// Name          Kamran Moazim
// Roll Number   BCS-F19-M-030
// Section       BIT-F20-Afternoon

#include<iostream>

#include"class.cpp"

using namespace std;




void driver0(){

    SinglyLinkedList l1;

    int val=0;
    int n = 5;

    cout<<"Enter Values : ";
    while(n > 0){
        cin>>val;
        l1.insertAtStart(val);
        n--;
    }

    cout<<"List contain : ";
    l1.displayList();

    cout<<"Number of nodes are : ";
    cout<<l1.countNodes();

    cout<<endl;

}



void driver1(){

    SinglyLinkedList l1;

    int val=0;
    int n = 5;

    cout<<"Enter Values : ";
    while(n > 0){
        cin>>val;
        l1.insertAtStart(val);
        n--;
    }

    cout<<"List contain : ";
    l1.displayList();

    cout<<"Which node you wants to remove : ";
    cin>>n;

    if(l1.removeKthNode(n, val)){
        cout<<"node removed successfully!"<<endl;
        cout<<"the value in that node was : "<<val<<endl;
    } else {
        cout<<"node could NOT be removed!"<<endl;
    }

    cout<<"now List contain : ";
    l1.displayList();
    cout<<endl;

}




void driver2(){

    SinglyLinkedList l1;
    SinglyLinkedList l2;
    SinglyLinkedList l3;

    int val=0;
    int n = 5;

    cout<<"Enter Values for list1 : ";
    while(n > 0){
        cin>>val;
        l1.insertAtStart(val);
        n--;
    }

    n = 5;
    cout<<"Enter Values for list2 : ";
    while(n > 0){
        cin>>val;
        l2.insertAtStart(val);
        n--;
    }

    cout<<"List1 contains : ";
    l1.displayList();

    cout<<"List2 contains : ";
    l2.displayList();

    cout<<"Above was before combining"<<endl;


    l3.combine(l1, l2);

    cout<<"List3 contains : ";
    l3.displayList();


}




void driver3(){

    SinglyLinkedList l1;
    SinglyLinkedList l2;
    SinglyLinkedList l3;

    int val=0;
    int n = 5;

    cout<<"Enter Values for list1 : ";
    while(n > 0){
        cin>>val;
        l1.insertAtStart(val);
        n--;
    }

    n = 5;
    cout<<"Enter Values for list2 : ";
    while(n > 0){
        cin>>val;
        l2.insertAtStart(val);
        n--;
    }

    cout<<"List1 contains : ";
    l1.displayList();

    cout<<"List2 contains : ";
    l2.displayList();

    cout<<"Above was before shuffling"<<endl;


    l3.shuffleMerge(l1, l2);

    cout<<"List3 contains : ";
    l3.displayList();


}




int main(){


    // driver0();
    // driver1();
    // driver2();
    // driver3();

    return 0;
}
