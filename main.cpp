//Movie Theater Seating Challenge
//Walmart Global Tech
//By Sava Glisic
#include <iomanip>
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int main() {
    //Accepting Input File Path - translating to vector
    string path;
    string line;
    vector <string> vinput;
    cout << "Paste Input File Path Here: " << endl;
    getline(cin, path);
    ifstream input(path);
    while(getline(input, line)){
        vinput.push_back(line);}

    //Generates Vector of Reservation Numbers
    vector <string> vreservation;
    string allText;
    for(int i = 0; i < vinput.size(); i++){
        allText = vinput[i];
        string resNum = allText.substr(0, allText.find(' '));
        vreservation.push_back(resNum);
    }

    //Generates Vector of Party Sizes
    vector <int> partySize;
    for(int i = 0; i < vinput.size(); i++){
        allText = vinput[i];
        allText = allText.substr(allText.find(' ') + 1, allText.size());
        int pSize = stoi(allText);
        partySize.push_back(pSize);
    }

    //Generating Vectors Representing Each Row and Column of Seating
    //Improving Customer Experience by starting with center row seating
    string vrows [10] = {"D", "E", "F", "G", "C", "H", "I", "J", "B", "A"};
    string vcols [20] = {"1", "2","3","4","5","6","7","8","9","10","11","12","13","14","15","16","17","18","19","20"};
    queue <string> allSeats;

    for(int i = 0; i < 20; i++){string row=vrows[0];row+=vcols[i];allSeats.push(row);}
    for(int i = 0; i < 20; i++){string row=vrows[1];row+=vcols[i];allSeats.push(row);}
    for(int i = 0; i < 20; i++){string row=vrows[2];row+=vcols[i];allSeats.push(row);}
    for(int i = 0; i < 20; i++){string row=vrows[3];row+=vcols[i];allSeats.push(row);}
    for(int i = 0; i < 20; i++){string row=vrows[4];row+=vcols[i];allSeats.push(row);}
    for(int i = 0; i < 20; i++){string row=vrows[5];row+=vcols[i];allSeats.push(row);}
    for(int i = 0; i < 20; i++){string row=vrows[6];row+=vcols[i];allSeats.push(row);}
    for(int i = 0; i < 20; i++){string row=vrows[7];row+=vcols[i];allSeats.push(row);}
    for(int i = 0; i < 20; i++){string row=vrows[8];row+=vcols[i];allSeats.push(row);}
    for(int i = 0; i < 20; i++){string row=vrows[9];row+=vcols[i];allSeats.push(row);}

    //Generating output path
    string outPath = path;
    string extension = outPath.substr(outPath.find('.'),outPath.size());
    outPath = outPath.substr(0, outPath.find('.'));
    outPath += "output";
    outPath += extension;

    //Assigning Seats and writing to file
    std::ofstream myfile(outPath);
    int sizeSeats = allSeats.size();
    for(int i = 0; i<vinput.size();i++){
        int numPeople = partySize[i];
        int x = 0;
        myfile << vreservation[i] << " ";
        while(x < numPeople){
             /*if(numPeople > sizeSeats){
                myfile << "Insufficient Seating for this party :(";
                cout << sizeSeats << endl;
                break;
            } */
             if(x == (numPeople - 1)){
                myfile << allSeats.front();
                allSeats.pop();
                x++;
                sizeSeats--;
                //numPeople--;
                cout << sizeSeats << endl;
            }
            else{
            myfile << allSeats.front() << ",";
            allSeats.pop();
            x++;
            sizeSeats--;
            //numPeople--;
            cout << sizeSeats << endl; }

        }
        myfile << endl;
        //Social Distancing - Public Safety - skipping 3 seats
        allSeats.pop();
        allSeats.pop();
        allSeats.pop();
    }

    //cout << sizeSeats << endl;
    cout << "Output File Path: " <<endl;
    cout << outPath << endl;
    myfile.close();
    myfile.close();
    return 0;
}
