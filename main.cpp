#include <iostream>
#include<vector>
#include<string>
#include<ctime>
#include<cstdlib>
#include<fstream>
using namespace std;

vector<string> tuVung, giaiNghia ;
void nhapData(){
    ifstream fileTuVung("TCA-english.txt");
    ifstream fileGiaiNghia("TCA-vietnamese.txt");
    if(fileTuVung.is_open()){
        while(!fileTuVung.eof()){
                string word;
            getline(fileTuVung,word);
            tuVung.push_back(word);
        }
    }
    if(fileGiaiNghia.is_open()){
        while(!fileGiaiNghia.eof()){
                string word;
            getline(fileGiaiNghia,word);
            giaiNghia.push_back(word);
        }
    }

}

int choseIndexWord(){
    int len = tuVung.size();
    srand(time(0));
    int indexRandom = rand() % len ;
    return indexRandom;
}

void Screen(){

    while(true){
        int index = choseIndexWord() ;
        string word = tuVung[index];
        string nghia = giaiNghia[index];
        system("cls");
        string vietLaiWord , vietNghia , vietLaiNghia;
        cout << "\t\t\t\tCHAM CHI HOC Tu Vung!\n\n";
        cout << "\tWord: " << word << endl;;
        while(true)
        {
            cout << "\n\tViet lai tu lan 1: " ;
            cin >> vietLaiWord ;
            if(vietLaiWord == word)
                break;
            cout << "\tViet SAI! Moi viet lai: " ;
        }
         while(true)
        {
            cout << "\n\tViet lai tu lan 2: " ;
            cin >> vietLaiWord ;
            if(vietLaiWord == word)
                break;
            cout << "\n\tViet SAI! Moi viet lai:" ;
        }
        cout << "\n\tViet NGHIA cua tu: " ;
        cin.ignore();
        getline(cin,vietNghia);
        if(vietNghia != nghia) cout << "\n\tBan Sai!";
        else cout << "\n\tBan Dung!" ;
        cout << "\tNghia cua tu: " << nghia;
        while(true){
            cout << "\n\tHay viet lai nghia cua tu lan 1: ";
            getline(cin,vietLaiNghia);
            if(vietLaiNghia == nghia) break;
            else continue;
        }
        while(true){
            cout << "\n\tHay viet lai nghia cua tu lan 2: ";
            getline(cin,vietLaiNghia);
            if(vietLaiNghia == nghia) break;
            else continue;
        }
        char playAgain ;
        cout << "\n\tBan muon choi tiep khong? (Y/N) " ;
        cin >> playAgain ;
        if(playAgain == 'n' || playAgain == 'Y') break;
        else continue;
        system("pause");
    }
}

int main()
{
    nhapData();
    Screen();
}
