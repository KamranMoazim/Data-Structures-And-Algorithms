#include <iostream>

#include"class.cpp"

using namespace std;







void driver1(){

    BST<int> b1;
    

    int val;

    cout<<"Enter values for tree : ";
    cin >> val;
    b1.insertNode(val);
    while (cin.get() != '\n') {
        cin >> val;
        b1.insertNode(val);
    }



    cout<<"Tree (pre-order) : ";
    b1.preOrderDisplay();
    cout<<endl;

    cout<<"Tree (in-order) : ";
    b1.inOrderDisplay();
    cout<<endl;

    cout<<"Tree (post-order) : ";
    b1.postOrderDisplay();
    cout<<endl;

    cout<<"Tree (level-order) : ";
    b1.levelOrderDisplay();
    cout<<endl;

    cout<<"Max val of Tree : ";
    cout<<b1.findMax();
    cout<<endl;

    cout<<"Min val of Tree : ";
    cout<<b1.findMin();
    cout<<endl;


    if(b1.iterativeSearch(val)){
        cout<<val<<" found using iterativeSearch"<<endl;
    } else {
        cout<<val<<" not found using iterativeSearch"<<endl;
    }

    if(b1.recursiveSearch(val+3)){
        cout<<val+3<<" found using recursiveSearch"<<endl;
    } else {
        cout<<val+3<<" not found using recursiveSearch"<<endl;
    }

    cout<<"Enter value you wants to remove : ";
    cin>>val;
    if(b1.removeNode(val)){
        cout<<val<<" removed"<<endl;
    } else {
        cout<<val<<" not removed"<<endl;
    }

    cout<<"again Tree (level-order) : ";
    b1.levelOrderDisplay();
    cout<<endl;


    BST<int> b2(b1);
    cout<<"TESTING COPY CONSTRUCTOR - Tree (level-order) : ";
    b2.levelOrderDisplay();
    cout<<endl;

}






int main(){

    driver1();

    return 0;
}
