
#include<iostream>

#include"class.h"

using namespace std;



void menu(){
    cout<<"1. Insert a name"<<endl;
    cout<<"2. Search for a name"<<endl;
    cout<<"3. Remove a name"<<endl;
    cout<<"4. Display the table"<<endl;
    cout<<"5. Display the load factor of the table"<<endl;
    cout<<"6. Exit"<<endl;
    cout<<endl;
}


void driver(){

    int size, choice;
    string name = "";

    cout<<"Enter the size of the hash table: ";
    cin>>size;
    cout<<endl;

    menu();

    HashTable ht(size);

    while(choice != 6){

        cout<<"Enter Your Choice : ";
        cin>>choice;

        cin.ignore();

        switch(choice){
            case 1:{
                cout<<"Enter Name to insert : ";
                getline(cin, name);
                if(ht.insert(name)){
                    cout<<"Name inserted Successfully"<<endl;
                } else {
                    cout<<"Unfortunately Name could not inserted!"<<endl;
                }
                break;
            }
            case 2:{
                cout<<"Enter Name to search : ";
                getline(cin, name);
                if(ht.search(name)){
                    cout<<"Name found"<<endl;
                } else {
                    cout<<"Unfortunately Name could not found!"<<endl;
                }
                break;
            }
            case 3:{
                cout<<"Enter Name to remove : ";
                getline(cin, name);
                if(ht.remove(name)){
                    cout<<"Name removed Successfully"<<endl;
                } else {
                    cout<<"Unfortunately Name could not found (so not removed)!"<<endl;
                }
                break;
            }
            case 4:{
                ht.display();
                break;
            }
            case 5:{
                cout<<"Load Factor is : "<<ht.loadFactor();
                cout<<endl;
                break;
            }
            case 6:{
                cout<<"EXITING...."<<endl;
                break;
            }
            default:{
                cout<<"Please SELECT from Given Options only !"<<endl;
            }
        }
    }


}


void tempDriver(){

    int size;
    cout<<"Enter the size of the hash table: ";
    cin>>size;

    // menu();

    HashTable ht(size);

    int i = 0;
    ht.insert("ali");
    ht.insert("ahmad");
    ht.insert("bill");
    ht.insert("tim");
    ht.insert("harry");
    ht.insert("kim");
    // ht.insert("ali");
    // ht.insert("ali");
    ht.insert("ali");
    ht.insert("ali");

    ht.display();

    cout<<"-----------------------------"<<endl;
    ht.remove("ali");
    ht.display();

    cout<<"-----------------------------"<<endl;
    ht.remove("ali");
    ht.display();
}







int main(){

    
    // tempDriver();
    driver();

    return 0;
}
