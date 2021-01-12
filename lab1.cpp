//Divyam Solanki
//201951198
//12 Jan 2021

#include <iostream>
#include <string>
#include <fstream>
#include <stdlib.h>
#include<time.h>
#include <sstream>
 
using namespace std;

ofstream fout;
ifstream fint;

void search(string s1);
void inserting(int j);
void checking();
void issue(string s2);
void returning(string s3);
//Console base program to take up with the LIBRARY management system 
//ASSIGNMENT 1 
//CS262
 

int main () {
   int x;
   
   int i = 100;

for(;;){
    //Taking input choices
    //Never ending loop to make it a console program

    cout << "Enter a choice" << endl;
    cout << "1. Enter the book of choice" << endl;
    cout << "2. Search the book of choice" << endl;
    cout << "3. Check for the book of choice" << endl;
    cout << "4. Issue the book of choice" << endl;
    cout << "5. Return the book of choice" << endl;
    cout << "6. Exit the console" << endl;
    
    
    
    cin >> x;
    
    string s1;
    string s2;
    string s3;
    

   switch(x) {
       //Switch case 1 
       //Entering all the relevent details for the book that is present in the library.
      case 1 :
         cout << "\nWell here is the interface" << endl;
         cout << "You need to add BOOK TITLE " << "PUBLISHER " << "AUTHOR " << "TOTAL " << endl; 
         i++;
         inserting(i++);
         i++;
         break;
         continue;
      case 2 :
         cout << "Well here is the interface" << endl;
         cout << "Enter the value to be searched : " << endl;
        
         cin >> s1;
         search(s1);
         break;           
      case 3 :
         cout << "All the books are given below" << endl;
         checking();
         break;
      case 4 :
         cout << "Choose among the following to issue" << endl;
         checking();
         cout << "\n";

         cout << "Enter the book name to issue it : " << endl;
         cin >> s2;
         issue(s2);
         break;
      case 5 :
         cout << "Enter the book name to return" << endl;
         cin >> s3;
         returning(s3);
         break;
      case 6 :
         exit(1);
      default :
         cout << "Invalid grade" << endl;
   }

    
}
 
   return 0;
}

void inserting(int i){
         
         string Book_title;
         string pub;
         string author;
         int total;
         cout << "BOOKTITLE :" << endl;
         cin >> Book_title;
         cout << "PUBLISHER :" << endl;
         cin >> pub;
         cout << "AUTHOR :" << endl;
         cin >> author;
         cout << "TOTAL BOOKS : " << endl;
         cin >> total;
         //We are using a TEXT file to convert the data from user input to a database storage
         //USing FILE HANDLING in C++

         fint.open("lib.txt");
         fout.open("lib.txt", ios::app);

        // String that will go in the text file
        //  string s1;
        //  s1 = "rand()" + "\t" + "Book_title" + "\t" + "pub" + "\t" + "author" + "\t" + "total"  + "\n";
         
        // TO accompany the following function we are turning all the strings to lowercase //
        //  transform(s1.begin(), s1.end(), s1.begin(), ::tolower); 
        srand(time(0));
         if(fint.is_open())
            fout << rand() << "\t" << Book_title << "\t" << pub << "\t" << author << "\t" << total  <<"\n";
        
         
         cout << "Appended in the file" << endl;

         fint.close();
         fout.close();
         return;
         
         
}

void search(string search){
         fint.open("lib.txt");
        
         bool isFound=0;

         transform(search.begin(), search.end(), search.begin(), ::tolower); 
         //Searching each line until the name is found
         //Finding the name of the given book using while loop 
         while(!fint.eof())
         {
          string temp = "";
          getline(fint,temp);
          for(int i=0;i<search.size();i++)
          {
            if(temp[i]==search[i])
                isFound = 1;
            else
            {
                isFound =0;
                break;
            }
          }

           if(isFound)
                {
                for(int i = search.size()+1;i<temp.size();i++)
                    cout << temp[i];

                break;
                }

            }

            if(fint.eof()&&(!isFound))
            {
                cout << "Name found!\n\n";
            }
            return;

}

void checking() { 
     fint.open("lib.txt");
     string text;

    //We are getting all the books present in the library using the while statement
     while(getline(fint, text)){ 
         //read data from file object and put it into string.
         cout << text << "\n"; 
         //print the data of the string
      }
      text = "";



}

void issue(string s2)
{
    fint.open("lib.txt");
    string line;

    //Let's see what is happening here
    //We are getting the line in which the book name is appearing
    while(getline(fint, line)){
        if(line.find(s2) != string::npos){
            cout << line <<endl;
    }
    //Example L1: 1978713  Alchemist   Harper    Paulo    90
    // In this example the line in which Alchemist appears is L1
    //We are taking the L1 in variable "line"
        
        cout << "Not found" << endl;
    }

    //Finding the last word of the line to decrease the font by 1 
    //Since it is issued

    int len = line.length();
    int i = len - 1;
    while (i >= 0 && line[i] != ' ')
    {
        i--;
    }
    std::string last_word;
    for (int j = i + 1; j < len; j++)
    {
        last_word += line[j];
    }
    
    //last_word is the number of coppies of the book

    stringstream divs(last_word); 
  
    
    int x = 0; 
    divs >> x;
    //Decreasing the number of coppies since it is issued
    x--;
    
    string last_word_new = to_string(x);

    //Now we are finding the last_word again and then changing the value by decreasing its content by 1

    while (getline(fint, line))
    {
        while (true)
        {
            size_t pos = line.find(last_word);
            if (pos != string::npos)
                line.replace(pos, len, last_word_new);
            else 
                break;
        }

        cout << line << '\n';
    }



}
void returning(string s3)
{
    fint.open("lib.txt");
    string line;

    //Let's see what is happening here
    //We are getting the line in which the book name is appearing
    while(getline(fint, line)){
        if(line.find(s3) != string::npos){
            cout << line <<endl;
    }
    //Example L1: 1978713  Alchemist   Harper    Paulo    90
    // In this example the line in which Alchemist appears is L1
    //We are taking the L1 in variable "line"
        
        cout << "Not found" << endl;
    }

    //Finding the last word of the line to increase the font by 1 
    //Since it is returned

    int len = line.length();
    int i = len - 1;
    while (i >= 0 && line[i] != ' ')
    {
        i--;
    }
    std::string last_word;
    for (int j = i + 1; j < len; j++)
    {
        last_word += line[j];
    }
    
    //last_word is the number of coppies of the book

    stringstream divs(last_word); 
  
    
    int x = 0; 
    divs >> x;
    //Increasing the number of coppies since it is returned
    x++;
    
    string last_word_new = to_string(x);

    //Now we are finding the last_word again and then changing the value by increasing its content by 1

    while (getline(fint, line))
    {
        while (true)
        {
            size_t pos = line.find(last_word);
            if (pos != string::npos)
                line.replace(pos, len, last_word_new);
            else 
                break;
        }

        cout << line << '\n';
    }

}