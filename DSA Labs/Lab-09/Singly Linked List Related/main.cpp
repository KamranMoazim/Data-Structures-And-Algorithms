// Name          Kamran Moazim
// Roll Number   BCS-F19-M-030
// Section       BIT-F20-Afternoon

#include<iostream>

#include"class.cpp"

using namespace std;




void driver(){

    SinglyLinkedList l1;

    int val=0;
    int n = 5;
    int removeVal=0;

    cout<<"Enter Values : ";
    cin >> val;
    l1.insertAtStart(val);
    while (cin.get() != '\n') {
        cin >> val;
        l1.insertAtStart(val);
    }

    cout<<"List contain : ";
    l1.displayList();

    cout<<"which value you wants to remove (all occurences) : ";
    cin>>removeVal;

    cout<<l1.removeAll(removeVal)<<" occurences are removed of value "<<removeVal<<endl;

    cout<<"now List contain : ";
    l1.displayList();

    cout<<endl;

}



int main(){


    driver();

    return 0;
}
