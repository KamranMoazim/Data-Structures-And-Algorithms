#include<iostream>
#include<fstream>
#include<cstring>

using namespace std;

const int nameLength = 40;


class Student{
    int rollNumber;
    char name[nameLength];
    int numberOfQuizes;
    int* marks;
    int* totalMarks;
    void inputMarks(){
        int temp = 0;
        for(int i=0; i<numberOfQuizes; i++){
            cout<<"Enter total marks for Quiz "<<i+1<<" : ";
            cin>>temp;
            while(temp<=0){
                cout<<"Please greater than 0 in total marks for Quiz "<<i+1<<" : ";
                cin>>temp;
            }
            totalMarks[i] = temp;
            cout<<"Enter obtained marks for Quiz "<<i+1<<" : ";
            cin>>temp;
            while(temp<0 || totalMarks[i] < temp){
                cout<<"Please Enter positive or less than total marks for Quiz "<<i+1<<" : ";
                cin>>temp;
            }
            marks[i] = temp;
            temp = 0;
        }
    }
public:
    Student(){
        rollNumber = 0;
        name[0] = '\0';
        numberOfQuizes = 0;
        marks = NULL;
        totalMarks = NULL;
    }
    Student(int rollNum, char* argName, int numOfQuizes){
        rollNumber = 0;
        strcpy(argName, name);
        numberOfQuizes = numOfQuizes;
        marks = new int[numberOfQuizes];
        for(int i=0; i<numberOfQuizes; i++){
            marks[i] = 0;
        }
        totalMarks = new int[numberOfQuizes];
        for(int i=0; i<numberOfQuizes; i++){
            totalMarks[i] = 0;
        }
    }
    Student(const Student& std){
        rollNumber = std.rollNumber;
        strcpy(name, std.name);
        numberOfQuizes = std.numberOfQuizes;

        marks = new int[numberOfQuizes];
        totalMarks = new int[numberOfQuizes];

        for(int i=0; i<numberOfQuizes; i++){
            marks[i] = std.marks[i];
        }
        for(int i=0; i<numberOfQuizes; i++){
            totalMarks[i] = std.totalMarks[i];
        }
    }
    ~Student(){
        if(marks != NULL){
            delete[] marks;
        }
        if(totalMarks != NULL){
            delete[] totalMarks;
        }
    }
    void getInputFromUser(){
        cout<<"Enter Roll No : ";
        cin>>rollNumber;
        cout<<"Enter Name : ";
        cin>>name;
        cout<<"Enter Number of Quizes : ";
        cin>>numberOfQuizes;
        if(marks != NULL){
            delete[] marks;
        }
        if(totalMarks != NULL){
            delete[] totalMarks;
        }
        marks = new int[numberOfQuizes];
        totalMarks = new int[numberOfQuizes];
        inputMarks();
    }
    void display(){

        int highestPercentageMarks = (marks[0] * 100) / totalMarks[0];

        int lowestPercentageMarks = (marks[0] * 100) / totalMarks[0];

        int percentageOfMarks = 0;

        cout<<"Roll No : "<<rollNumber<<endl;
        cout<<"Name : "<<name<<endl;
        cout<<"Marks Obtained in different Quizes are : ";
        for(int i=0; i<numberOfQuizes; i++){
            cout<<marks[i]<<" ";

            percentageOfMarks = (marks[i] * 100) / totalMarks[i];

            if(percentageOfMarks > highestPercentageMarks){

                highestPercentageMarks = marks[i];
            }
            if(percentageOfMarks < lowestPercentageMarks){

                lowestPercentageMarks = marks[i];
            }
        }
        cout<<endl;

        cout<<"Highest Percentage Marks are : "<<highestPercentageMarks<<endl;
        cout<<"Lowest Percentage Marks are : "<<lowestPercentageMarks<<endl;
    }
    void storeInFile(ofstream& file){
        file.write( reinterpret_cast<char*>(this), sizeof(*this) );
    }
    void readFromFile(ifstream& file, int n){
        (this)->display();
        file.seekg((n-1)*sizeof(Student));
        file.read( reinterpret_cast<char*>(this), sizeof(*this) );
        (this)->marks[0];
        (this)->totalMarks[0];
        (this)->display();
    }
    Student operator= (Student& std){
        rollNumber = std.rollNumber;
        strcpy(name, std.name);
        numberOfQuizes = std.numberOfQuizes;

        if(marks != NULL){
            delete[] marks;
        }
        if(totalMarks != NULL){
            delete[] totalMarks;
        }
        marks = new int[numberOfQuizes];
        totalMarks = new int[numberOfQuizes];

        for(int i=0; i<numberOfQuizes; i++){
            marks[i] = std.marks[i];
        }
        for(int i=0; i<numberOfQuizes; i++){
            totalMarks[i] = std.totalMarks[i];
        }

        return *this;
    }
};


void printStudent(Student std){
    std.display();
}



void driverOne(){

    int numberOfStudents = 0;
    ofstream file;
    file.open("Data.dat", ios::app | ios::out | ios::binary );

    cout<<"Enter Number of Students : ";
    cin>>numberOfStudents;

    while(numberOfStudents<=0){
        cout<<"Please Enter Positive Number : ";
        cin>>numberOfStudents;
    }

    Student* allStudents = new Student[numberOfStudents];

    for(int i=0; i<numberOfStudents; i++){
        cout<<"Getting Information for Student "<<i+1<<" : "<<endl;
        allStudents[i].getInputFromUser();
        allStudents[i].storeInFile(file);
    }

    for(int i=0; i<numberOfStudents; i++){
        cout<<"Showing Information for Student "<<i+1<<" : "<<endl;
        allStudents[i].display();
    }

    file.close();

    delete[] allStudents;
}


void driverTwo(){
    Student std1, std2;
    std1.getInputFromUser();
    std2 = std1;
    std1.display();
    std2.display();
}


int main(){

    driverOne();
    // driverTwo();

    // ofstream file;
    // file.open("Data.dat", ios::app | ios::out | ios::binary );
    // Student std1;
    // std1.getInputFromUser();
    // std1.storeInFile(file);
    // file.close();

    // ifstream file2;
    // file2.open("Data.dat", ios::app | ios::in | ios::binary );
    // Student std2;
    // std2.readFromFile(file2, 1);
    // file2.close();

    return 0;
}
