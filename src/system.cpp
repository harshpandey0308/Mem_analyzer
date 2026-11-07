#include<iostream>
#include<cstdlib>
#include<fstream>
#include<string>
#include"../include/process_data.hpp"


using namespace std;

int extract_info(){
    system("touch new.txt && grep -n 7 /proc/meminfo >> new.txt");

    std::ifstream file("new.txt");

    std::string line;

    while(std::getline(file , line)){
        cout<<"Line 1 : "<<line<<endl;
    }

    file.close();

    return 0;
}

int main(){
    extract_info();

    return 0;
}