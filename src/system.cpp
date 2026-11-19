#include<iostream>
#include<cstdlib>
#include<fstream>
#include<vector>
#include<string>
#include<cstring>
#include"../include/process_data.hpp"

#define PROC_ARITY 100

using namespace std;

int extract_info(){
    int count = 0;

    system("touch new.txt && ps -eo pid,ppid,stime >> new.txt");

    std::ifstream file("new.txt");

    std::vector<int> pid;

    std::string line ;

    while(std::getline(file , line)){
        auto offs = file.tellg();
        cout<<"offs = "<<offs<<endl;
        cout<<line<<endl;
        count++;
    }

    file.seekg(0 , ios::beg);

    //cout<<"\n"<<"the total line is "<<count<<endl;

    //Process_Identity proc_info[PROC_ARITY];
    //size_t proc_count = 0;

    file.seekg(44 , ios::beg);
    
    file.close();

    return 0;
}

int main(){
    extract_info();

    return 0;
}