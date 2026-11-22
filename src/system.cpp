#include<iostream>
#include<cstdlib>
#include<fstream>
#include<vector>
#include<string>
#include<cstring>
#include"../include/process_data.hpp"

#define PROC_ARITY 100

using namespace std;

void min_sec(std::string time){

}

int extract_info(){
    int count = 0;

    system("touch new.txt && ps -eo pid=,etimes= >> new.txt");

    std::ifstream file("new.txt");

    //std::vector<int> pid;

    std::string line ;

    Process_Identity proc_info[PROC_ARITY];
    size_t proc_count = 0;

    while(proc_count < PROC_ARITY && file >> proc_info[proc_count].PID >> proc_info[proc_count].e_time){
        proc_count++;
    }

    cout<<"PID"<<"     "<<"ELAPSED"<<endl;
    for(int i=0 ; i<proc_count ; i++){
        cout<<proc_info[i].PID<<"      "<<proc_info[i].e_time<<'\n';
    }

    file.close();

    return 0;
}

int main(){
    extract_info();

    return 0;
}