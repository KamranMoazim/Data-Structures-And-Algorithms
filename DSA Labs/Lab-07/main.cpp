// Name          Kamran Moazim
// Roll Number   BCS-F19-M-030
// Section       BIT-F20-Afternoon

#include<iostream>

#include"class.cpp"

using namespace std;






void printArray(int* arr, int size){
    for(int i=0; i<size; i++){
        cout<<arr[i]<<"\t";
    }
    cout<<endl;
}


// *********************************** TASK 0
int findLargestIndex(int* arr, int start, int end) {

    int index=end;

    if(start < end){
        int gettingIndex = findLargestIndex(arr, start+1, end);
        if(arr[start] > arr[gettingIndex]){
            index = start;
        } else {
            index = gettingIndex;
        }
    }
            
    return index;
}




// *********************************** TASK 1
void reverseSubArray(int* arr, int start, int end){

    if(start < end){
        int temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;
        start++;
        end--;
        reverseSubArray(arr, start, end);
    }

}





// *********************************** TASK 2
void pancakeSortIter(int* arr, int start, int end){

    int tempEnd = end;

    for(int i=start;i<end ;i++){
        int largestIndex = findLargestIndex(arr, start, tempEnd);
        reverseSubArray(arr, 0, largestIndex);
        reverseSubArray(arr, 0, tempEnd);
        tempEnd--;
    }

}



// *********************************** TASK 3
void pancakeSortRec(int* arr, int start, int end){

    if(start <= end){
        int largestIndex = findLargestIndex(arr, start, end);
        reverseSubArray(arr, 0, largestIndex);
        reverseSubArray(arr, 0, end);
        end--;
        pancakeSortRec(arr, start, end);
    }

}



// int arr3[5] = { 5, 8, 2, 7, 3 };  end = 5;

bool checkSumFromRemaining(int* arr, int start, int end, int k, int l){
    
    if(start < end){
        // cout<<(arr[start]+l)<<"\t";
        if((arr[start]+l) == k){
            // cout<<endl;
            // cout<<"returning true\n";
            return true;
        } else {
            return checkSumFromRemaining(arr, ++start, end, k, l);
        }
    }
    
    return false;

}

// *********************************** TASK 4
bool checkSum(int* arr, int start, int end, int k){

    // cout<<endl<<start;

    if(start<end){

        // cout<<endl;

        start++;
        bool condition = checkSumFromRemaining(arr, start, end, k, arr[start-1]);
        if(condition){
            // cout<<"checkSum true"<<endl;
            return true;
        }
        return condition || checkSum(arr, start, end, k);
    }

    // cout<<"getting here"<<endl;

    return false;
}




int main(){


    int arr1[6] = {70,1,90,3,15,20};
    int arr2[7] = {70,1,90,3,15,20,78};

    // linearSearchRecursive checking
    // if(linearSearchRecursive(arr1, 0, 6, 15)){
    //     cout<<"Found"<<endl;
    // } else {
    //     cout<<"Not Found"<<endl;
    // }

    // even checking 
    // printArray(arr1, 6);
    // reverseSubArray(arr1, 0, 5);
    // printArray(arr1, 6);
    // reverseSubArray(arr1, 2, 5);
    // printArray(arr1, 6);

    // 1 Testing
    // printArray(arr2, 7);
    // pancakeSortRec(arr2, 0, 6);
    // printArray(arr2, 7);

    // 2 Testing
    // printArray(arr2, 7);
    // pancakeSortIter(arr2, 0, 6);
    // printArray(arr2, 7);

    // ***********

    // odd checking
    // printArray(arr2, 7);
    // reverseSubArray(arr2, 0, 6);
    // printArray(arr2, 7);

    // 1 Testing
    // printArray(arr1, 6);
    // pancakeSortRec(arr1, 0, 5);
    // printArray(arr1, 6);

    // 2 Testing
    // printArray(arr1, 6);
    // pancakeSortIter(arr1, 0, 5);
    // printArray(arr1, 6);


    int arr3[5] = { 5, 8, 2, 7, 3 };


    if(checkSum(arr3, 0, 5, 8)){      // 
    // if(checkSum(arr3, 0, 5, 9)){      // 
    // if(checkSum(arr3, 0, 5, 50)){      // 
        cout<<"Found"<<endl;
    } else {
        cout<<"Not Found"<<endl;
    }


    // cout<<endl;

    return 0;
}
