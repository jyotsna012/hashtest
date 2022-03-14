#include <cstdlib>
#include <iostream>
#include <cstring>
#include <fstream>
#include <string>


#include "hash.h"

using namespace std;
float RandomFloat(float a, float b);
int main(){
      string first[35];
      string last[35];
      int i = 0;
      int a = 0;
      int currentID = 000001;
      fstream myFile;
	    myFile.open("firstNames.txt", ios::in);
	    if(myFile.is_open()){
	    	string line;
		while(getline(myFile, line)){
			first[i] = line;
			//cout << line << endl;
			i++;
		}
		myFile.close();
	    }    
       fstream myFile2;
	    myFile2.open("lastNames.txt", ios::in);
	    if(myFile2.is_open()){
	    	string line;
		while(getline(myFile2, line)){
			last[a] = line;
			a++;
		//	cout << line << endl;
		}
		myFile2.close();
	    }
//will keep running until user quits
    int tablesize;
    tablesize = 100;
    hashmap Hashy(tablesize);
while(true){
    int input;
    int input2;
    cout << "Would you like to add any random computer generated students? Type 1 for yes and 2 for no" << endl;
    cin >> input2;
    cin.get();
        if(input2 == 2){
   
    }
    //random student gen
    if(input2 == 1){
      cout << "enter the number of computer generated students you would like to enter. " << endl;
      int num;
      cin >> num;
      cin.get(); 
    
      for(int z =0; z < num; z++){
      
      string s1(first[z]);
      char p1[s1.length()];
      int u;    
      for (u = 0; u < sizeof(p1); u++) {
        p1[u] = s1[u];
      }
	    
      string s2(last[z]);
      char p2[s2.length()];
      int v;    
      for (v = 0; v < sizeof(p2); v++) {
        p2[v] = s2[v];
      }
	 float randGPA = RandomFloat(2.00, 5.00);
      	 Hashy.addStudent(p1,p2, currentID, randGPA);
	 currentID = currentID + 1;
      }

    }
    cout << "now its time to manually add students. Type 1 for add, 2 for print, 3 for delete, or 4 for quit" << endl;
    cin >> input;
    cin.get();
    //asks user for details of student 
    cout << "input 2: " << input2 << endl;
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

  }
  return 0;  	
	
}

float RandomFloat(float a, float b) {
    float random = ((float) rand()) / (float) RAND_MAX;
    float diff = b - a;
    float r = random * diff;
    return a + r;
}
