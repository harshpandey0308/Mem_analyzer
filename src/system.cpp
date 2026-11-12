#include<iostream>
#include<cstdlib>
#include<fstream>
#include<vector>
#include<string>
#include"../include/process_data.hpp"


using namespace std;

int extract_info(){
    int count = 0;

    system("touch new.txt && ps -ef >> new.txt");

    std::ifstream file("new.txt");

    std::vector<int> pid;

    std::string line;

    while(std::getline(file , line)){
        cout<<"Line  : "<<line<<endl;
        count++;
    }

    cout<<"\n"<<"the total line is "<<count<<endl;

    for(int i=0 ; i<5; i++){
        if()
    }

    file.close();

    return 0;
}

int main(){
    extract_info();

    return 0;
}