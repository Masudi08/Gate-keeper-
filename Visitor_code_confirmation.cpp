#include<iostream>
#include<fstream>
#include<string>
using namespace std;
string confirm_code(string target_code){
    fstream visitors;
    visitors.open("C:\\Users\\yusuf\\OneDrive\\Documents\\Visitor_records.txt", ios::in);
    if(visitors.is_open()){
        string line;
       while(getline(visitors,line)){
            //Checks if the variable line is empty.
            if(line.empty()) continue;
            //find the position of the last space which separated the name and the code.
            size_t last_space=line.find_last_of(' ');
            //check if the current line doesn't contain a space. Meaning it's not in the right order.
            if(last_space==string::npos) continue;
            //Get the code. Line substring from last_space to the end of the file.
            string current_code=line.substr(last_space+1);
            //Get the name in the current line. Substring of the line from the start to last_space.
            string current_name=line.substr(0,last_space);
            if(target_code==current_code){
                return current_name;
                visitors.close();
            }
       }
    }else{
        cerr<<"File is not opened."<<endl;
    }
}
int main(){
    //This program will be accepting user-provided code and returning the related name.
    string code,name;
    cout<<"Enter the code sent to the visitor:";
    cin>>code;
    cout<<endl;
    cout<<"Enter the name of the visitor provided on any official document:";
    cin>>name;
    cout<<"The name used to generate the otp was "<<confirm_code(code)<<endl;
    cout<<"Please confirm that the names match before allowing the visitor inside the premises."<<endl;
    return 0;
}
