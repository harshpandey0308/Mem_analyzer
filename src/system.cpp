#include<iostream>
#include<cstdlib>
#include<fstream>
#include<vector>
#include<string>
#include<cstring>
#include"../include/process_data.hpp"

#define PROC_ARITY 100

using namespace std;

void parse_line(std::string line){
    size_t length = line.length();

    for(size_t i=0 ; i<length ; i++){
        if(line.at(i) == 'P'){
            cout<<"the pid parameter is at "<<i<<endl;
        }
    }

}

int extract_info(){
    int count = 0;

    system("touch new.txt && ps -ef >> new.txt");

    std::ifstream file("new.txt");

    std::vector<int> pid;

    std::string line;

    std::getline(file , line);

    parse_line(line);

    cout<<line<<endl;

    cout<<"\n"<<"the total line is "<<count<<endl;

    Process_Identity proc_info[PROC_ARITY];
    size_t proc_count = 0;



    file.close();

    return 0;
}

int main(){
    extract_info();

    return 0;
}