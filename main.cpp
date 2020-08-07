#include <iostream>
#include<vector>
#include<string>
#include<ctime>
#include<cstdlib>
#include<fstream>
using namespace std;

vector<string> tuVung, giaiNghia ;
int lengthWord ;

void nhapDataTA123(){
    tuVung.clear();
    giaiNghia.clear();
    ifstream fileTuVung("TA123-english.txt");
    ifstream fileGiaiNghia("TA123-vietnamese.txt");
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
    lengthWord = tuVung.size();
}

void nhapDataTCADK(){
    tuVung.clear();
    giaiNghia.clear();
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
    lengthWord = tuVung.size();
}

int choseIndexWord(){
    srand(time(0));
    int indexRandom = rand() % lengthWord ;
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

            getline(cin,vietLaiWord);
            if(vietLaiWord == word)
                break;
            cout << "\tViet SAI! Moi viet lai: " ;
        }
         while(true)
        {
            cout << "\n\tViet lai tu lan 2: " ;
            getline(cin,vietLaiWord);
            if(vietLaiWord == word)
                break;
            cout << "\n\tViet SAI! Moi viet lai:" ;
        }
        cout << "\n\tViet NGHIA cua tu: " ;
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
        cin.ignore();
        if(playAgain == 'n' || playAgain == 'N') break;
        else continue;
        system("pause");
    }
}

void MenuApp(){
    while(true){
        system("cls");
        cout << "\t\tMenu List Word";
        cout << "\n\t1: TCA-Words";
        cout << "\n\t2: TA123-Words";
        cout << "\n\t0: Thoat!";
        char select;
        while(true){
            cout << "\n\tLua chon cua ban: ";
            cin >> select;
            cin.ignore();
            if(select == '1'){
                nhapDataTCADK();
                Screen();
                break;
            }
            else if(select == '2'){
                nhapDataTA123();
                Screen();
                break;
            }
            else if(select == '0')
                return;
            continue;
        }

        system("pause");
    }

}

int main()
{
    MenuApp();

    return 0;
}
