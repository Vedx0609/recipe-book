#include<iostream>
#include<string.h>
#include<fstream>
#include "myrecipes.cpp" // cpp program for accept and display using data abstraction
using namespace std;

myrecipes obj;

void add_recipe();
void display_recipe();
void search_recipe();

int main() {
    int flag=1; // to terminate while loop
    int choice;
    while(flag) {
        cout<<endl<<"Enter 1 to Add a new Recipe"<<endl;
        cout<<"Enter 2 to Display all Recipies"<<endl;
        cout<<"Enter 3 to Search a particular recipe"<<endl;
        cout<<"Enter any other number to exit"<<endl;
        cout<<"Enter your choice : ";
        cin>>choice;
        switch(choice) {
            case 1 : 
                add_recipe();
                break;
            case 2 : 
                display_recipe();
                break;
            case 3 : 
                search_recipe();
                break;
            default :
                flag=0;
        }
    }
    return 0;
}

void add_recipe() {
    fstream rd; // rd is the read object of the class fstream used to open the file
    rd.open("myrecipebook.txt", ios::in); // being openend for input operations (reading data from file)
    rd.seekg(0,ios::end); // used to set file position to eof
    int size = rd.tellg()/sizeof(obj); // using eof position we can find file size
    rd.seekg(0,ios::beg); // used to set file is positioned at beginning to perform read operations

    obj.accept(); // accpets new recipe input
    fstream wr; // used to open file in append mode / write mode
    wr.open("myrecipebook.txt",ios::app);
    wr.write((char*)&obj, sizeof(obj)); // writes the new recipe in the file
    wr.close();
    cout<<"Recipe added"<<endl;
}

void display_recipe() {
    fstream rd;
    rd.open("myrecipebook.txt",ios::in);
    rd.seekg(0,ios::end);
    int size = rd.tellg()/sizeof(obj);
    cout<<endl<<"Number of Recipes : "<<size<<endl;
    rd.seekg(0,ios::beg);
    cout<<endl;
    for(int i=1;i<=size;i++) { // iterates through the recipes and displays it
        rd.read((char *)&obj, sizeof(obj));
        obj.display();
    }
}

void search_recipe() {
    char title[50];
    cout<<"Enter the Recipe Title to be searched : "<<endl; // user input to search recipe
    cin.ignore();
    cin.getline(title,50);
    fstream rd;
    rd.open("myrecipebook.txt",ios::in);
    rd.seekg(0,ios::end);
    int size = rd.tellg()/sizeof(obj);
    rd.seekg(0,ios::beg);
    int flag=0; // to check if recipe is present
    for(int i=1;i<=size;i++) { // iterates through recipe and compares the titles
        rd.read((char*)&obj,sizeof(obj));
        if(strcmp(obj.title,title)==0) {
            flag=1;
            break;
        }
    }
    if(flag)
        obj.display();
    else
        cout<<"Recipe not found"<<endl;
}