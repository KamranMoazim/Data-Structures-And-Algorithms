// Name    : MALIK ARBAZ AKRAM
// Roll No : BCSF19M004
// Section : MORNING 

#include <iostream>
#include "Stack.cpp"
using namespace std;


int precedence(char oper){

	if(oper == '*' || oper == '/'){
		return 5;
	} else if(oper == '+' || oper == '-'){
		return 4;
	} else {
		// if(oper == '('){
		// 	return 6;
		// } else {
		// 	return 3;
		// }
		return 3;
	}
}


char* infixToPostfix(string infixExpression = "A*(B+C)/D"){
	
	char* postfixExpression = new char[infixExpression.length()+20];
	int j=0;
	Stack<char> operatorsStack(20);


	for(int i=0; i<infixExpression.length(); i++){

		char nextChar = infixExpression[i];
		

		if(!(nextChar == '(' || nextChar == ')' || nextChar == '+' || nextChar == '-' || nextChar == '*' || nextChar == '/' )){
			// postfixExpression[j++] = ' ';
			postfixExpression[j++] = nextChar;
			cout<<"letter pushed "<<postfixExpression[j-1]<<endl;
		} else {

			if(!operatorsStack.isEmpty() && nextChar == '(' && operatorsStack.stackTop() != '('){
				operatorsStack.push(nextChar);
				cout<<"oper pushed "<<nextChar<<endl;
				continue;
			}

			while(!operatorsStack.isEmpty() && precedence(operatorsStack.stackTop()) > precedence(nextChar)){
				// cout<<nextChar<<endl;
				char ch = operatorsStack.pop();
				if(ch != '('){
					// cout<<ch<<endl;
					// postfixExpression[j++] = ' ';
					postfixExpression[j++] = ch;
					cout<<"oper poped "<<postfixExpression[j-1]<<endl;
				}
			}

			if(!operatorsStack.isEmpty() && operatorsStack.stackTop() == '('){
				operatorsStack.push(nextChar);
				cout<<"oper pushed "<<nextChar<<endl;
				continue;
			}

			if(nextChar != ')'){
				// cout<<"here2 "<<nextChar<<endl;
				operatorsStack.push(nextChar);
				cout<<"oper pushed "<<nextChar<<endl;
			} else if(nextChar == ')'){
				char ch = operatorsStack.pop();
				cout<<"oper poped "<<ch<<endl;
				// postfixExpression[j++] = ' ';
				postfixExpression[j++] = ch;
				cout<<postfixExpression[j-1]<<endl;
			}
		}

	}

	// postfixExpression[j] = '\0';
	// for(int i=0; i<j; i++){
	// 	cout<<postfixExpression[i]<<" ";
	// }

	return postfixExpression;
}


void driverProgram(){
	Stack<int> stack1(5);

	stack1.push(4);
	stack1.push(3);
	stack1.push(2);
	stack1.push(1);

	while(!stack1.isEmpty()){
		cout<<stack1.pop()<<"\t";
	}

	cout<<endl;

}



int main(){

	// driverProgram();

	// string str = "KA";
	// str.append("MRAN");
	// cout<<str<<endl;

	// cout<<infixToPostfix()<<endl;
	infixToPostfix();

	return 0;
}