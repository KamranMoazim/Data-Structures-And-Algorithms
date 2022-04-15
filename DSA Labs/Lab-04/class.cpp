// Name          Kamran Moazim
// Roll Number   BCS-F19-M-030
// Section       BIT-F20-Afternoon

#pragma once

#include "class.h"
#include<iostream>
#include<fstream>
#include<cstring>
#include<string>

using namespace std;

PacketManager::PacketManager(ifstream& fin) {
    string eachLine;
    int count=0;

    getline(fin, eachLine);
    numPackets = charToInt(eachLine.substr(0, eachLine.find(" ")));
    packets = new Packet[numPackets];

    while(getline(fin, eachLine)){

        packets[count].position = charToInt(eachLine.substr(0, eachLine.find(" ")));

        eachLine = eachLine.substr(2);

        // way 1
        // strcpy(packets[count].body, eachLine.c_str());
        
        // way 2
        for(int i=0; i<eachLine.length(); i++){
            packets[count].body[i] = eachLine[i];
        }
        count++;
    }

    message = NULL;
    msgLength = 0;

    fin.close();
}


PacketManager::~PacketManager() {
    if(message != NULL){
        delete[] message;
        message = NULL;
    }
    if(packets != NULL){
        delete[] packets;
        packets = NULL;
    }
}


void PacketManager::displayPackets() const {
    for(int i=0; i<numPackets; i++){
        cout<<packets[i].position<<" "<<packets[i].body<<endl;
    }
}


void PacketManager::sortPacketsBubbleSort(){
    // void bubbleSort(int* arr, int n)

    int i=numPackets-1;

    while(i > 0){

        for(int j=0; j<i; j++){
            if(packets[j].position > packets[j+1].position){
                swapper(packets[j], packets[j+1]);
            }
        }

        i--;
    }
}


void PacketManager::sortPacketsSelectionSort(){
    // void selectionSort(int* arr, int n)

    int i=0, j=0, smallestIndex=0;
    int smallest=0;

    while(i < numPackets){

        smallest=packets[i].position;
        smallestIndex=i;

        for(j=i; j<numPackets; j++){
            if(packets[j].position<smallest){
                smallest=packets[j].position;
                smallestIndex=j;
            }
        }

        swapper(packets[i], packets[smallestIndex]);
        i++;
    }
}


void PacketManager::extractMessage() {

    char choice;

    cout<<"Which sorting algorithm do you want to use?"<<endl;
    cout<<"\tEnter 'B' or 'b' for Bubble sort"<<endl;
    cout<<"\tEnter 'S' or 's' for Selection sort"<<endl;
    cout<<"Enter your choice: ";
    cin>>choice;

    while(!(choice == 'b' || choice == 'B' || choice == 's' || choice == 'S')){
        cout<<"Please Select Valid Option: ";
        cin>>choice;
    }

    if(choice == 'b' || choice == 'B'){
        sortPacketsBubbleSort();
    } else if(choice == 's' || choice == 'S'){
        sortPacketsSelectionSort();
    }

    msgLength = 0;
    for(int i=0; i<numPackets; i++){
        msgLength += strlen(packets[i].body);
    }

    message = new char[msgLength+1];

    for(int i=0, j=0; i<numPackets; i++){
        for(int k=0; k<strlen(packets[i].body); k++){
            message[j] = packets[i].body[k];
            j++;
        }
    }    
}


void PacketManager::displayMessage() const {
    if(msgLength != 0){
        for(int i=0; i<msgLength; i++){
            cout<<message[i];
        }
        cout<<endl;
    } else {
        cout<<"Message has not extracted yet!"<<endl;
    }
}