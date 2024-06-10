#include <bits/stdc++.h>
using namespace std;

//to check validity of input string that it's a text file
bool valid(string s){
    int idx = 0;
    string sub;
    for (int i = s.size() - 1; i >= 0 && idx < 4; --i) {
        sub += s[i];
        idx++;
    }
    return (sub == "txt.");
}

int main(){
    string inFileName;
    fstream inFile;
    cout<<"Please enter name of file you want to load (with extension): ";
    getline(cin,inFileName);
    inFile.open(inFileName,ios::in);
    while(!inFile||!valid(inFileName)){
        cout<<"Invalid Name! Please enter a valid file name (with extension): ";
        getline(cin,inFileName);
        inFile.open(inFileName,ios::in);
    }
    string choice;
    cout<<"Do you want to encrypt or decrypt(A/B):\nA. Encrypt\nB.Decrypt\n";
    getline(cin,choice);
    transform(choice.begin(),choice.end(),choice.begin(),::tolower);
    while(choice != "a" && choice != "b"){
        cout<<"Invalid Choice! Please enter a valid option(A/B):\nA. Encrypt\nB.Decrypt\n";
        getline(cin,choice);
        transform(choice.begin(),choice.end(),choice.begin(),::tolower);
    }
    string outFileName;
    cout<<"Please enter name of file you want to output to (with extension): ";
    getline(cin,outFileName);
    ofstream outFile;
    if(valid(outFileName))
        outFile.open(outFileName,ios::trunc);
    while(!valid(outFileName)) {
        cout << "Invalid Name! Please enter a valid text file name: " << endl;
        getline(cin,outFileName);
        outFile.open(outFileName,ios::trunc);
    }
    if(choice == "a"){
        string line;
        while(!inFile.eof()){
            getline(inFile,line);
            for (int i = 0; i < line.size(); ++i) {
                if(isalpha(line[i])){
                    if(line[i] >= 'a'){
                        int aski = line[i] - 'a';
                        aski += 4;
                        aski %= 26;
                        line[i] = 'a' + aski;
                    }
                    else{
                        int aski = line[i] - 'A';
                        aski += 4;
                        aski %= 26;
                        line[i] = 'A' + aski;
                    }
                }
            }
            outFile << line << endl;
        }
        cout<<"Encryption Completed!"<<endl;
    }
    else{
        string line;
        while(!inFile.eof()){
            getline(inFile,line);
            for (int i = 0; i < line.size(); ++i) {
                if(isalpha(line[i])){
                    if(line[i] >= 'a'){
                        int aski = line[i] - 'a';
                        aski -= 4;
                        if(aski>=0)
                            aski %= 26;
                        else
                            aski = 26 + aski;
                        line[i] = 'a' + aski;
                    }
                    else{
                        int aski = line[i] - 'A';
                        aski -= 4;
                        if(aski>=0)
                            aski %= 26;
                        else
                            aski = 26 + aski;
                        line[i] = 'A' + aski;
                    }
                }
            }
            outFile << line << endl;
        }
        cout<<"Decryption Completed!"<<endl;
    }
    inFile.close();
    outFile.close();
    return 0;
}