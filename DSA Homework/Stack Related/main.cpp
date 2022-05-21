#include<iostream>
#include<cmath>
#include <typeinfo>

#include"any.cpp"

using namespace std;



// *********** 1
void decimalToOtherConversion(){
    // *********** decimal to other conversion ***********

    int number=0, base=2;
    int binaryNum=0;
    cout<<"Enter Number : ";
    cin>>number;
    cout<<"Enter which base you wants to convert: ";
    cin>>base;

    Stack<int> binaryStack(ceil(log10(number)/log10(base)));

    while(number != 0){
        binaryStack.push(number%base);
        number /= base;
    }

    while(binaryStack.pop(binaryNum)){
        cout<<binaryNum;
    }
    cout<<endl;
}

// *********** 2
void delimiterMatching(string exp="([]{{}}[])"){
    // *********** delimiter checking ***********

    char symb;
    bool success = true;

    Stack<char> delimiterStack(exp.length());

    for(int i=0; i<exp.length(); i++){
        if(exp[i] == '{' || exp[i] == '[' || exp[i] == '('){
            delimiterStack.push(exp[i]);
        } else if(exp[i] == '}' || exp[i] == ']' || exp[i] == ')'){
            delimiterStack.pop(symb);

            if(symb == '('){
                if(exp[i] == ')'){
                    success = true;
                } else {
                    success = false;
                    break;
                }
            } else if(symb == '{'){
                if(exp[i] == '}'){
                    success = true;
                } else {
                    success = false;
                    break;
                }
            } else if(symb == '['){
                if(exp[i] == ']'){
                    success = true;
                } else {
                    success = false;
                    break;
                }
            }
        }
    }

    if(success){
        cout<<"Expression is Valid!"<<endl;
    } else {
        cout<<"Expression is Invalid!"<<endl;
    }

}

// *********** 3
void addingLargeNumbers(){

    string num1 = "111111111111111111111111111111";
    string num2 = "22222222222222222222";

    int carry = 0;
    int pop1 = 0;
    int pop2 = 0;
    int result = 0;
    int howManyZeros = 0;
    int largerSize = num1.length() > num2.length() ? num1.length() : num2.length();

    Stack<int> stackForNumber1(largerSize);
    Stack<int> stackForNumber2(largerSize);
    Stack<int> additionResultStack(largerSize);

    if(num1.length() < num2.length()){

        howManyZeros = num2.length() - num1.length();
        while(howManyZeros > 0){
            stackForNumber1.push(0);
            howManyZeros--;
        }
    } else if(num1.length() > num2.length()){

        howManyZeros = num1.length() - num2.length();
        while(howManyZeros > 0){
            stackForNumber2.push(0);
            howManyZeros--;
        }
    }

    for(int i=0; i<num1.length(); i++){
        stackForNumber1.push((int)(num1[i]) - 48);
    }
    // stackForNumber1.print();


    for(int i=0; i<num2.length(); i++){
        stackForNumber2.push((int)(num2[i]) - 48);
    }
    // stackForNumber2.print();


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


// *********** 4
int operatorWorker(string oper, string a, string b){

    int result = 0;

    if(oper == "+"){
        result = stoi(a) + stoi(b);
    } else if(oper == "-"){
        result = stoi(a) - stoi(b);
    } else if(oper == "*"){
        result = stoi(a) * stoi(b);
    } else if(oper == "/"){
        result = stoi(a) / stoi(b);
    } else if(oper == "%"){
        result = stoi(a) % stoi(b);
    }

    return result;
}
void paranthsizedExpressionEvaluation(string exp="(60/(30-10+10))"){

    Stack<string> stackForExpresssion(exp.length());
    string tempA, tempB, oper, tmp_string;
    int expressionEvaluationResult=0;
    int num=0;

    for(int i=0; i<exp.length(); i++){
        
        if(exp[i] == ')'){
            while(true){
                if(stackForExpresssion.pop(tempB) && tempB == "("){
                    break;
                }
                if(stackForExpresssion.pop(oper) && oper == "("){
                    stackForExpresssion.push(tempB);
                    break;
                }
                stackForExpresssion.pop(tempA);
                expressionEvaluationResult = operatorWorker(oper, tempA, tempB);

                string numInStringForm = to_string(expressionEvaluationResult);
                stackForExpresssion.push(numInStringForm);
            }
            continue;
        }

        if(isdigit(exp[i])){
            int j=0;
            num=(int)(exp[i]) - 48;
            i++;
            while(isdigit(exp[i])){
                num *= 10;
                num += (int)(exp[i]) - 48;
                i++;
            }
            i--;

            string numInStringForm = to_string(num);
            stackForExpresssion.push(numInStringForm);
            num = 0;

        } else {
            tmp_string.push_back(exp[i]);
            stackForExpresssion.push(tmp_string);
            tmp_string = "";
        }
    }

    // stackForExpresssion.print();
    stackForExpresssion.pop(tmp_string);
    cout<<"Result is : "<<tmp_string<<endl;
}

// *********** 5
int operatorsPrecedence(string oper){

    if(oper == "!"){ // || oper == "-" 
        return 1;
    } else if(oper == "*" || oper == "/" || oper == "%"){
        return 2;
    } else if(oper == "+" || oper == "-"){
        return 3;
    } else if(oper == "<" || oper == "<=" || oper == ">" || oper == ">="){
        return 4;
    } else if(oper == "==" || oper == "!="){
        return 5;
    } else if(oper == "&&"){
        return 6;
    } else { // if(oper == "||"){
        return 7;
    }

}


string infixToPostfixConvertor(string infix="(10+12*300)+2") {   //    10/11-12+13*14-10*15

    Stack<string> stackForOperator(infix.length());
    string stackTopOper, pushingOper;
    int num=0;

    for(int i=0; i<infix.length(); i++){

        if(isdigit(infix[i])){
            int j=0;
            num=(int)(infix[i]) - 48;
            i++;
            while(isdigit(infix[i])){
                num *= 10;
                num += (int)(infix[i]) - 48;
                i++;
            }
            i--;

            cout<<num<<"\t";
            num = 0;
            continue;
        }

        if(infix[i] == '('){
            pushingOper = "";
            pushingOper.push_back(infix[i]);
            stackForOperator.push(pushingOper);
        } else if(infix[i] == ')'){
            while(stackForOperator.pop(stackTopOper)){
                if(stackTopOper == "("){
                    
                } else {
                    cout<<stackTopOper<<"\t";
                }
            }
        } else {

            pushingOper = "";
            pushingOper.push_back(infix[i]);

            if(!stackForOperator.getTop(stackTopOper)){
                stackForOperator.push(pushingOper);
            } else {
                while((stackForOperator.getTop(stackTopOper))){

                    if(stackTopOper == "("){
                        break;
                    }

                    // 3 < 2
                    if(!(operatorsPrecedence(stackTopOper) < operatorsPrecedence(pushingOper))){
                        stackForOperator.push(pushingOper);
                        break;
                    } else {
                        stackForOperator.pop(stackTopOper);
                        cout<<stackTopOper<<"\t";
                    }
                }
            }

        }        

        // stackForOperator.print();
    }
    // stackForOperator.print();


    while(stackForOperator.pop(stackTopOper)){
        cout<<stackTopOper<<"\t";
    }

    cout<<endl;

    return "";
}

int main(){

    // paranthsizedExpressionEvaluation("(1000+12)");
    infixToPostfixConvertor();

    // string k = "fsdjf";
    // for(int i=0; i<k.length(); i++){
    //     // cout<<k[i]<<"\t";
    //     cout << typeid(k[i]).name() << '\n';
    // }
    // cout<<endl;

    return 0;
}
