#include <cstdlib>
#include <iostream>
#include <cstring>
#include <fstream>

#include "hash.h"

using namespace std;
  
int main(){
//will keep running until user quits
    int tablesize;
    tablesize = 100;
    hashmap Hashy(tablesize);
while(true){
    int input;
    cout << "Type 1 for add, 2 for print, 3 for delete, or 4 for quit" << endl;
    cin >> input;
    cin.get();
    
     //asks user for details of student 
    if(input == 1){
		cout << "Please enter the student's first name" << endl;
  		char fN[20];
  		cin.get(fN,20);
  		cin.get();
		cout << "Please enter the student's last name" << endl;
  		char lN[20];
  		cin.get(lN,20);
  		cin.get();
		cout << "Please enter the students id number" << endl;
  		int sI;
  		cin >> sI;
  		cin.get();
		cout << "Please enter the student's GPA" << endl;
  		float G;
 		cin >> G;
	  	cin.get();
		Hashy.addStudent(fN, lN, sI, G);
    }
    //prints linked list	
    if(input == 2){
	Hashy.print();

    }
    //deletes an item based on name	
    if(input == 3){
	cout << "Please enter the student's first name that you would like to delete" << endl;    
	char fName[20];
        cin.get(fName,20);
  	cin.get();
	Hashy.removeItem(fName);
    }
    //exits function
    if(input == 4){
      break;
    }
    //random student gen
    if(input == 5){
      cout << "how many students would you like to add?" << endl;
      int num;
      cin >> num;
      cin.get();   
	    
      const int size = 50;
      char correctAnswers[size];
      ifstream correctAnswersFile;
      correctAnswersFile.open("firstNames.txt");
      for (int i = 0; i < size; i++) {
      correctAnswersFile >> correctAnswers[i];
      cout << correctAnswers[i] << endl;
}
    }
  }
  return 0;  	
	
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
