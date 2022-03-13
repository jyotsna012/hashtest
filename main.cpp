#include <cstdlib>
#include <iostream>
#include <cstring>

#include "hash.h"

using namespace std;

int main(){
     int tablesize;
    tablesize = 100;
    hashmap Hashy(tablesize);
 cout << "Welcome to the Student List." << endl;
 cout << "You can ADD, PRINT, DELETE, or QUIT" << endl;
 cout << "ADD -> Creates a new entry for student" << endl;
 cout << "PRINT -> Prints the current students stored" << endl;
 cout << "DELETE -> Deletes entry based on student ID" << endl;
 cout << "QUIT -> Exits the program" << endl;
 int loop = 0;
 //program keeps running until user quits
 while(loop == 0){
  cout << "What would you like to do?" << endl;
  cout << "Enter the action you would like to do by entering the coressponding number." << endl;
  cout << "ADD = 0" << endl;
  cout << "PRINT = 1" << endl;
  cout << "DELETE = 2" << endl;
  cout << "QUIT = 3" << endl;
  int choice;
  cin >> choice;
   //add students
  if(choice == 0){
    cout << "What is the first name of the student" << endl;
          char fN[20];
  		cin.get(fN,20);
  		cin.get();
    cout << "What is the last name of the student" << endl;
          char lN[20];
  		cin.get(lN,20);
  		cin.get();
    cout << "What is the Student ID" << endl;
         	int sI;
  		cin >> sI;
  		cin.get();
    cout << "What is the students GPA" << endl;
          float G;
 		cin >> G;
	  	cin.get();
   
    Hashy.addStudent(fN, lN, sI, G);
  }
   //prints vector
  if(choice == 1){  
     Hashy.print();
  }
   //delete student
  if(choice == 2){  
  }
   //quits program
  if(choice == 3){
    loop = 1;
    break;
  }
  }
  
}
  

/*void rehash(int tablesize, hashmap Hashy){
int oldtablesize = tablesize;
tablesize = tablesize+tablesize;
hashmap HashyTwo(tablesize);
for(int i =0; i < oldtablesize; i++){
  char newfirstName[80];
  char newlastName[80];
  int newid;
  float newgpa;
  if(Hashy.HashTable[i]->studentId != 0){
    strcpy(newfirstName, Hashy.HashTable[i]-> firstName);  
    strcpy(newlastName, Hashy.HashTable[i]->lastName);  
    newid = Hashy.HashTable[i]->studentId;
    newgpa = Hashy.HashTable[i]->GPA;
    HashyTwo.addStudent(newfirstName, newlastName, newid, newgpa); 
  }
}
   HashyTwo.print();
}*/

    /*Hashy.addStudent("Paul", "Locha", 1, 1.11);
    Hashy.addStudent("Kim", "Iced Mocha", 2, 2.22);
    Hashy.addStudent("Emma", "Strawberry Smoothie", 3, 3.33);
    Hashy.addStudent("Annie", "Hot Chocolate", 4, 4.44);
    Hashy.addStudent("Sarah", "Passion Tea", 5, 5.55);
    Hashy.addStudent("Pepper", "Caramel Mocha", 6, 6.66);
    Hashy.addStudent("Mike", "Chai Tea", 7, 7.77);
    Hashy.addStudent("Steve", "Apple Cider", 8, 8.88);
    Hashy.addStudent("Bill", "Root Beer", 9, 9.99);
    Hashy.addStudent("Marie", "Skinny Latte", 11, 1.123);
    Hashy.addStudent("Susan", "Water", 12, 2.123);
    Hashy.addStudent("Joe", "Green Tea", 13, 3.123);*/
