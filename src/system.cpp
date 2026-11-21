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

    system("touch new.txt && ps -eo pid >> new.txt");

    std::ifstream file("new.txt");

    //std::vector<int> pid;

    std::string line ;

    Process_Identity proc_info[PROC_ARITY];
    size_t proc_count = 0;

    file.seekg(8 , ios::beg);

    while(std::getline(file , line)){
        auto offs = file.tellg();
        cout<<"offs = "<<offs<<endl;
        proc_info[proc_count++].PID = static_cast<pid_t>(std::stoi(line));
        if(proc_count >= PROC_ARITY){
            break;
        }
        //cout<<line<<endl;
        count++;
    }

    cout<<"PID"<<endl;
    for(size_t i=0 ; i<proc_count ; i++){
        cout<<proc_info[i].PID<<endl;
        system("/proc/proc_info[i].PID/stat >> new.txt");
    }

    file.clear();

    std::string line1;

    file.seekg(8 , ios::beg);

    auto pos = file.tellg();
    
    cout<<"file offset position : "<<pos<<endl;

    proc_count = 0;

    while(std::getline(file , line1)){
        proc_info[proc_count++].
    }

    file.close();

    return 0;
}

int main(){
    extract_info();

    return 0;
}