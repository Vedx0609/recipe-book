#include<iostream>
#include<iomanip>
#include<fstream>
#include<string.h>

using namespace std;

class myrecipes {
    private:
        char title[100];  // Increased size to allow multiple words
        char ingredients[200];  // Increased size to allow multiple words
        char steps[500];  // Increased size to allow multiple lines
    public:
        void accept() {
            cout<<endl<<"Enter the Recipe Title: ";
            cin.ignore(); // Clear any newline character
            cin.getline(title, 100); // To get a single line output with multiple words

            cout<<"Enter the Ingredients: ";
            cin.ignore();
            cin.getline(ingredients, 200);

            cout<<"Enter the Steps (end with an empty line): ";
            cin.ignore();
            steps[0] = '\0';  // Initialize steps as an empty string
            while (true) {
                char temp[100];
                cin.getline(temp, 100); // Get one line of input
                if (strlen(temp) == 0)
                    break; // Break on empty line
            
                strcat(steps, temp);
                strcat(steps, "\n");  // Add a newline to separate lines
            }
        }

        void display() {
            cout<<endl;
            cout<<"Title: " <<endl<<title << endl;
            cout<<"Ingredients: " <<endl<<ingredients << endl;
            cout<<"Steps: " <<endl<<steps << endl;
            cout<<endl;
        }

        friend void add_recipe();
        friend void display_recipe();
        friend void search_recipe();
};
