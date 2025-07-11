#include<iostream>
#include<string>
#include<fstream>

using namespace std;

int main()
{
    ifstream inFile;
    string str;
    int number;
    char letter;

    inFile.open("people.txt");
    if(inFile.fail())
    {
        cout<<"File not found"<<endl;
    }
    else
    {
        while(!inFile.eof())
        {
            getline(inFile,str);
            cout<<str<<" , ";
            getline(inFile,str);
            number=stoi(str);
            cout<<number<<" , ";
            getline(inFile,str);
            letter=str[0];
            cout<<letter<<endl;

        }
        inFile.close();
    }

    return 0;
}