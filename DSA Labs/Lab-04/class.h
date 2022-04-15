// Name          Kamran Moazim
// Roll Number   BCS-F19-M-030
// Section       BIT-F20-Afternoon


#pragma once


#include<iostream>
#include <cstdlib>

using namespace std;



const int PACKET_SIZE = 5;     // Number of characters in a packet
struct Packet {
    int position;              // Packet’s position within the message
    char body[PACKET_SIZE+1];  // Characters contained in the packet including NULL terminator
};


struct LetterInfo {
    char letter;               // The letter (alphabet)
    int freq;                  // Frequency of the above letter
};

int charToInt(string num){
    return stoi(num);
}





void swapper(Packet& a, Packet& b){
    Packet t=a;
    a=b;
    b=t;
}

class PacketManager {
private:
    Packet* packets; // Array which will be used to store the packets read from the file
    int numPackets;  // Number of packets in the above array
    char* message;   // The message that was extracted from the packets
    int msgLength;   // Length of the message
    void sortPacketsBubbleSort();
    void sortPacketsSelectionSort();
public:
    PacketManager(ifstream& fin);
    ~PacketManager();
    void displayPackets() const;
    void extractMessage();
    void displayMessage() const;
};