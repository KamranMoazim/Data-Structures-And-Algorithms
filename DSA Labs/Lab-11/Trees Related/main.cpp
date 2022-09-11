#include <iostream>

#include"class.cpp"
#include"Student.cpp"

using namespace std;




void menuDisplay(){

    cout<<"1. Insert a value"<<endl;
    cout<<"2. Search a value"<<endl;
    cout<<"3. Remove a value"<<endl;
    cout<<"4. Display values (Pre-order)"<<endl;
    cout<<"5. Display values (In-order)"<<endl;
    cout<<"6. Display values (Post-order)"<<endl;
    cout<<"7. Count Nodes"<<endl;
    cout<<"8. Get Height"<<endl;
    cout<<"9. Test createBalancedTree"<<endl;
    cout<<"10. Quit"<<endl;
}




void driver(){

    BST<int> b1;
    BST<int> b3;

    int val=0, choice=1;
    menuDisplay();

    cout<<"\nEnter your choice: ";
    cin>>choice;

    while(choice != 10){

        switch(choice){
            case 1:
                cout<<"Enter the value to be inserted: ";
                cin >> val;
                b1.insertNode(val);
                break;
            case 2:
                cout<<"Enter the value to be searched: ";
                cin>>val;
                if(b1.iterativeSearch(val)){
                    cout<<val<<" found using iterativeSearch"<<endl;
                } else {
                    cout<<val<<" not found using iterativeSearch"<<endl;
                }
                break;
            case 3:
                cout<<"Enter the value to be removed: ";
                cin>>val;
                if(b1.removeNode(val)){
                    cout<<val<<" removed"<<endl;
                } else {
                    cout<<val<<" not removed"<<endl;
                }
                break;
            case 4:
                cout<<"Tree (pre-order) : ";
                b1.preOrderDisplay();
                cout<<endl;

                break;
            case 5:
                cout<<"Tree (in-order) : ";
                b1.inOrderDisplay();
                cout<<endl;
                break;
            case 6:
                cout<<"Tree (post-order) : ";
                b1.postOrderDisplay();
                cout<<endl;
                break;
            case 7:
                cout<<"Total Nodes in Tree : "<<b1.countNodes()<<endl;
                break;

            case 8:
                cout<<"Height of Tree : "<<b1.getHeight()<<endl;
                break;

            case 9:{
                int arr[11] = {7, 10, 14, 20, 36, 47, 55, 63, 72, 86, 92};
                b1.createBalancedTree(arr, 0, 10);
                cout<<"Tree 3 from Array (in-order) : ";
                b1.inOrderDisplay();
                cout<<endl;
                break;
            }
            case 10:{
                cout<<"EXITING"<<endl;
                break;
            }
            default : {
                cout<<"PLEASE SELECT VALID OPTION"<<endl;
            }
        }
        
        cout<<"\nEnter your choice: ";
        cin>>choice;

    }

}



void driver1(){

    BST<int> b1;
    
    BST<int> b3;
    

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

    cout<<"Total nodes : "<<b1.countNodes()<<endl;
    cout<<"Height : "<<b1.getHeight()<<endl;



    int arr[] = {7, 10, 14, 20, 36, 47, 55, 63, 72, 86, 92};
    int start = 0;
    int end = 10;
    b3.createBalancedTree(arr, start, end);

    cout<<"Tree 3 from Array (in-order) : ";
    b3.inOrderDisplay();
    cout<<endl;

}





void driver3(){

    BST<Student> b1;

    Student std1(1, "ali", 3.71);
    b1.insertNode(std1);

    std1 = Student(2, "kamran", 3.71);
    b1.insertNode(std1);

    std1 = Student(3, "ahmad", 3.91);
    b1.insertNode(std1);
    
    cout<<"\t";
    b1.inOrderDisplay();
    cout<<endl;

    cout<<"\t";
    b1.postOrderDisplay();
    cout<<endl;
}


int main(){

    driver3();

    return 0;
}
