// Name          Kamran Moazim
// Roll Number   BCS-F19-M-030
// Section       BIT-F20-Afternoon

#include<iostream>
#include<fstream>

#include"class.cpp"

using namespace std;






void letterCounterIncrementer(LetterInfo li[], char ch){
    switch(ch){
        case 'a':
            li[0].freq += 1;
            break;
        case 'b':
            li[1].freq += 1;
            break;
        case 'c':
            li[2].freq += 1;
            break;
        case 'd':
            li[3].freq += 1;
            break;
        case 'e':
            li[4].freq += 1;
            break;
        case 'f':
            li[5].freq += 1;
            break;
        case 'g':
            li[6].freq += 1;
            break;
        case 'h':
            li[7].freq += 1;
            break;
        case 'i':
            li[8].freq += 1;
            break;
        case 'j':
            li[9].freq += 1;
            break;
        case 'k':
            li[10].freq += 1;
            break;
        case 'l':
            li[11].freq += 1;
            break;
        case 'm':
            li[12].freq += 1;
            break;
        case 'n':
            li[13].freq += 1;
            break;
        case 'o':
            li[14].freq += 1;
            break;
        case 'p':
            li[15].freq += 1;
            break;
        case 'q':
            li[16].freq += 1;
            break;
        case 'r':
            li[17].freq += 1;
            break;
        case 's':
            li[18].freq += 1;
            break;
        case 't':
            li[19].freq += 1;
            break;
        case 'u':
            li[20].freq += 1;
            break;
        case 'v':
            li[21].freq += 1;
            break;
        case 'w':
            li[22].freq += 1;
            break;
        case 'x':
            li[23].freq += 1;
            break;
        case 'y':
            li[24].freq += 1;
            break;
        case 'z':
            li[25].freq += 1;
            break;
    }
}

void letterCounter(LetterInfo li[], char ch){
    if(isalpha(ch)){
        if(isupper(ch)){
            letterCounterIncrementer(li, char(int(ch)+32));
        } else {
            letterCounterIncrementer(li, ch);
        }
    }
}

void swapper(LetterInfo& a, LetterInfo& b){
    LetterInfo t=a;
    a=b;
    b=t;
}

void insertionSort(LetterInfo* arr, int size){

    int i=1, j=0;

    while(i < size){

        j=i;

        while(j>=1 && arr[j].freq > arr[j-1].freq){
            swapper(arr[j-1], arr[j]);

            j--;
        }

        i++;
    }
}






void driverProgram(){

    string fileName="";
    ifstream fs;


    cout<<"Enter name of the input file : ";
    getline(cin, fileName);

    fs.open(fileName, ios::in);

    while(fs.fail()){
        cout<<"File could not be opened!"<<endl;
        cout<<"Please Enter name of the input file again : ";
        getline(cin, fileName);

        fs.open(fileName, ios::in);
    }

    PacketManager packetManagerObject(fs);

    
    cout<<"Packets originally read from the file are:"<<endl;
    packetManagerObject.displayPackets();


    packetManagerObject.extractMessage();
    cout<<"The order of packets after extracting the message: "<<endl;
    packetManagerObject.displayPackets();

    cout<<"The extracted message is: "<<endl;
    packetManagerObject.displayMessage();

}


void driverProgram2(){

    string line;
    cout<<"Enter String to create packets : ";
    getline(cin, line);
    cout<<line<<endl;

    string fileName="";
    ofstream fs;
    cout<<"Enter name of the output file : ";
    getline(cin, fileName);
    fs.open(fileName, ios::out);

    int totalPackets = line.length()/PACKET_SIZE;
    totalPackets += line.length()%PACKET_SIZE==0?0:1;
    // fs<<totalPackets<<" "<<endl;

    totalPackets = 1;
    for(int i=0; i<line.length(); i+=PACKET_SIZE){
        fs<<to_string(totalPackets)<<" "<<line.substr(i, PACKET_SIZE)<<endl;
        totalPackets++;
    }

    fs.close();
}


void driverProgram3(){
    string fileName="";
    ifstream fs;
    char ch;

    cout<<"Enter name of the input file : ";
    getline(cin, fileName);

    fs.open(fileName, ios::in);

    while(fs.fail()){
        cout<<"File could not be opened!"<<endl;
        cout<<"Please Enter name of the input file again : ";
        getline(cin, fileName);

        fs.open(fileName, ios::in);
    }

    LetterInfo allLetters[26];
    for(int i=97, j=0; i<123; i++, j++){
        allLetters[j].letter = char(i);
        allLetters[j].freq = 0;
    }

    while (fs >> ch) {
        letterCounter(allLetters, ch);
    }

    cout<<"Applying insertion sort in descending order : "<<endl;
    insertionSort(allLetters, 26);

    for(int i=0; i<26; i++){
        cout<<"Letter : "<<allLetters[i].letter<<", Frequency : "<<allLetters[i].freq<<endl;
    }
}



int main(){

    // driverProgram();

    // driverProgram2();

    // driverProgram3();


    return 0;

}
