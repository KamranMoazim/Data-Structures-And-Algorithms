// Name          Kamran Moazim
// Roll Number   BCS-F19-M-030
// Section       BIT-F20-Afternoon

#include<iostream>
#include<iomanip>

#include"functions.cpp"

using namespace std;


// function to display simple menu
void displayMenu(){
    
    cout<<setw(40)<<"--------------------"<<endl;
    cout<<setw(32)<<"MENU"<<endl;
    cout<<setw(40)<<"--------------------"<<endl;
    cout<<"1. Sort BowlingFigures using Insertion sort"<<endl;
    cout<<"2. Sort BowlingFigures using Selection sort"<<endl;
    cout<<"3. Sort BowlingFigures by Name (using Bubble sort)"<<endl;
    cout<<"4. Quit"<<endl;
}


int main(){

    int count;                   // to store total players count present in file
    char choice = '1';           // to input choice from user and then use with switch case
    char fileName[50] = "a.txt"; // to input file name from user

    cout<<"Enter the name of input file: ";
    cin>>fileName;

    // calling function to read player's data from file and return pointer (in case of success) 
    BowlingFigures* bf = readFromFile(fileName, count);

    if(bf != NULL){

        cout<<"\n Following "<<count<<" Bowling figures were read from the input file: \n";
        printBowlingFigures(bf, count);  // to print all players wickets - runs - playerName

        displayMenu(); // display Menu defined above

        cout<<"\nEnter your choice: ";
        cin>>choice;

        while(choice != '4'){

            if(choice == '1' || choice == '2' || choice == '3'){

                switch(choice){
                    case '1':
                        sortBowlingFigures1(bf, count);  // sort using Insertion Sort (first on the basis of wickets(descending-order) and then on runs(ascending-order))
                        cout<<"The "<<count<<" Bowling figures after sorting using Insertion sort are:"<<endl;
                        break;
                    case '2':
                        sortBowlingFigures2(bf, count);  // sort using Selection Sort (first on the basis of wickets(descending-order) and then on runs(ascending-order))
                        cout<<"The "<<count<<" Bowling figures after sorting using Bubble sort are:"<<endl;
                        break;
                    case '3':
                        sortByName(bf, count);  // sort using Bubble Sort (on the basis of NAME)
                        cout<<"\nThe "<<count<<" Bowling figures after sorting by NAME are:"<<endl;
                        break;
                }
                printBowlingFigures(bf, count);

            } else {
                cout<<"Please Select from only Valid given choices"<<endl;
            }
            cout<<"\nEnter your choice: ";
            cin>>choice;
        }

        delete[] bf;  // de-allocating memory 
        bf = NULL;

    } else {
        cout<<"Error! File could not be opened!"<<endl;
    }

    return 0;
}
