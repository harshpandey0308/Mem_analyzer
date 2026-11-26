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
    //int count = 0;

    system("touch new.txt && ps -eo pid=,etimes= >> new.txt");

    std::ifstream file("new.txt");

    //std::vector<int> pid;

    Raw_Data process_log[PROC_ARITY];
    size_t nproc = 0;

    Process_Identity proc_info[PROC_ARITY];
    size_t proc_count = 0;

    while(proc_count < PROC_ARITY && file >> proc_info[proc_count].PID >> proc_info[proc_count].e_time){
        proc_count++;
    }

    cout<<"PID"<<"     "<<"ELAPSED"<<endl;
    for(size_t i=0 ; i<proc_count ; i++){
        cout<<proc_info[i].PID<<"      "<<proc_info[i].e_time<<'\n';
    }

    system("touch info.txt");

    for(size_t i=0 ; i<proc_count ; i++){
        std::string command = "grep -E '^(Name|Pid|PPid|State|VmRSS|VmSize|VmSwap|RssAnon|RssFile|RssShmem):' /proc/" + std::to_string(proc_info[i].PID) + "/status >> info.txt";
        system(command.c_str());

        std::ifstream files("info.txt");

        std::string info_line;
        
        while(std::getline(files , info_line)){
            size_t len = info_line.length();
            string word;
            size_t i = 0;
            while(info_line.at(i) != ':'){
                word.push_back(info_line.at(i));
                i++;
            }

            while(info_line.at(i) == ' '){
                i++;
            }

            string value;
        
            while(i < len && info_line.at(i) != '\n'){
                value.push_back(info_line.at(i));
                i++;
            }


            if(word == "Name"){
                process_log[nproc].proc_name = value;    
            }
            else if(word == "Pid"){
                process_log[nproc].pid = static_cast<pid_t>(std::stoi(value));
            }
            else if(word == "PPid"){
                process_log[nproc].ppid = static_cast<pid_t>(std::stoi(value));
            }
            else if(word == "State"){
                process_log[nproc].state = value[0];
            }
            else if(word == "VmRSS"){
                process_log[nproc].RSS = static_cast<uint64_t>(std::stoll(value));
            }
            else if(word == "VmSize"){
                process_log[nproc].Vmsize = static_cast<uint64_t>(std::stoll(value));
            }
            else if(word == "VmSwap"){
                process_log[nproc].Vm_Swap = static_cast<uint64_t>(std::stoll(value));
            }
            else if(word == "RssAnon"){
                process_log[nproc].RSS_anon = static_cast<uint64_t>(std::stoll(value));
            }
            else if(word == "RssFile"){
                process_log[nproc].Rss_File = static_cast<uint64_t>(std::stoll(value));
            }
            else if(word == "RssShmem"){
                process_log[nproc].Rss_Shmmem = static_cast<uint64_t>(std::stoll(value));
            }

            nproc++;

        }
        cout<<"PROCESS PID : "<<process_log[i].pid<<endl<<"PPID : "<<process_log[i].ppid<<endl;

        files.close();

        system("truncate -s 0 info.txt");

    }
    
    file.close();

    return 0;
}

int main(){
    extract_info();

    return 0;
}