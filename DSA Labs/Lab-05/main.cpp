// Name          Kamran Moazim
// Roll Number   BCS-F19-M-030
// Section       BIT-F20-Afternoon

#include<iostream>

#include"class.cpp"

using namespace std;

const int LENGTH = 40;


void addingLargeNumbers(char num1[], char num2[]){

    int carry = 0;
    int pop1 = 0;
    int pop2 = 0;
    int result = 0;
    int howManyZeros = 0;
    int num1Length = strlen(num1);
    int num2Length = strlen(num2);
    int largerSize = num1Length > num2Length ? num1Length : num2Length;

    Stack<int> stackForNumber1(largerSize);
    Stack<int> stackForNumber2(largerSize);
    Stack<int> additionResultStack(largerSize*2);

    if(num1Length < num2Length){

        howManyZeros = num2Length - num1Length;
        while(howManyZeros > 0){
            stackForNumber1.push(0);
            howManyZeros--;
        }
        
    } else if(num1Length > num2Length){

        howManyZeros = num1Length - num2Length;
        while(howManyZeros > 0){
            stackForNumber2.push(0);
            howManyZeros--;
        }
    }

    for(int i=0; i<num1Length; i++){
        stackForNumber1.push((int)(num1[i]) - 48);
    }


    for(int i=0; i<num2Length; i++){
        stackForNumber2.push((int)(num2[i]) - 48);
    }


    while(stackForNumber1.pop(pop1) && stackForNumber2.pop(pop2)){
        if(pop1+pop2+carry <= 9){
            additionResultStack.push(pop1+pop2+carry);
            carry = 0;
        } else {
            additionResultStack.push(pop1+pop2+carry-10);
            carry = 1;
        }
    }

    if(carry != 0){
        additionResultStack.push(carry);
    }

    while(additionResultStack.pop(result)){
        cout<<result;
    }
    cout<<endl;

}


void driverProgram(){
    char num1[LENGTH] = ""; 
    char num2[LENGTH] = "";

    cout<<"Enter 1st number: ";
    cin>>num1;
    cout<<"Enter 2nd number: ";
    cin>>num2;

    cout<<"Sum of the two numbers is: ";
    addingLargeNumbers(num1, num2);
}

int main(){

    driverProgram();

    // cout<<strlen("123456789246911110246911110")<<endl;
    // cout<<strlen("123456789246911110246911110")<<endl;
    // 1111111111111111111111111110
    // 1111111111111111111111111110

    return 0;
}
