/*This program will be used to book visitors and send them an otp to present at the gate.*/
#include<iostream>
#include<random>
#include<fstream>
#include<string>
using namespace std;
int generate_otp();
int main(){
    fstream visitors;
    string name;
    cout<<"Enter the name of the expected visitor:";
    getline(cin,name);
    int code=generate_otp();
    visitors.open("C:\\Users\\yusuf\\OneDrive\\Documents\\Visitor_records.txt", ios::app);
    if(visitors.is_open()){
        visitors<<name<<" "<<code<<endl;
    }else{
        cerr<<"File not found."<<endl;
    }
    visitors.close();
    return 0;
}
int generate_otp(){
    random_device rd;
    uniform_int_distribution<int> dist(1,400000000);
    return dist(rd);
}