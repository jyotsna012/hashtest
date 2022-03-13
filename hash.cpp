#include <cstdlib>
#include <iostream>
#include <cstring>

#include "hash.h"

using namespace std;

hashmap::hashmap(int ntableSize){
  char emptys[] = "empty";
  for(int i = 0; i < tableSize; i++){
    HashTable[i] = new Student;
    strcpy(HashTable[i]->firstName, emptys);  
    strcpy(HashTable[i]->lastName, emptys);  
    HashTable[i]->studentId = 0;
    HashTable[i]->GPA = 0.00;
    HashTable[i]->next = NULL;
  }
}

void hashmap::addStudent(char* firstName, char* lastName, int studentId, float GPA){
  
  int index = Hash(firstName);
  if(HashTable[index]->studentId == 0){
    strcpy(HashTable[index]->firstName, firstName);  
    strcpy(HashTable[index]->lastName, lastName);  
    HashTable[index]->studentId = studentId;
    HashTable[index]->GPA = GPA;
    HashTable[index]->next = NULL;

  }
  else{
  
    Student* ptr = HashTable[index];
    Student* n = new Student;
    strcpy(n->firstName, firstName);  
    strcpy(n->lastName, lastName);  
    n -> studentId = studentId;
    n -> GPA = GPA;
    n->next = NULL;
    while(ptr -> next != NULL){
      ptr = ptr -> next;
    }
    
    ptr -> next = n;
  
  }
  
  if(numItemsIndex(index) >= 4){

    cout << "needs to be rehased" << endl;
  }
}

int hashmap::numItemsIndex(int index){
  int count = 0;
  if(HashTable[index]->studentId == 0){
    return 0;
  }
  
  else{
  
    count ++;
    Student* ptr = HashTable[index];
    while(ptr -> next != NULL){
        count ++;
        ptr = ptr -> next;
    }
    return count;
  }
}


void hashmap::print(){

  int number;
  for(int i = 0; i < tableSize; i++){
    number = numItemsIndex(i);
    if(number == 0){
    cout << "-----------------" << endl;
    cout << "index = " << i << endl;
    cout << HashTable[i]->firstName<< endl;  
    cout << HashTable[i]->lastName<< endl;  
    cout << HashTable[i]->studentId<< endl;
    cout << HashTable[i]->GPA<< endl;
    cout << "number of items = " << number << endl;
    cout << "-----------------" << endl;  
    }
    if(number == 1){
    cout << "-----------------" << endl;
    cout << "index = " << i << endl;
    cout << HashTable[i]->firstName<< endl;  
    cout << HashTable[i]->lastName<< endl;  
    cout << HashTable[i]->studentId<< endl;
    cout << HashTable[i]->GPA<< endl;
    cout << "number of items = " << number << endl;
    cout << "-----------------" << endl;  
    }
    if(number == 2){
    cout << "-----------------" << endl;
    cout << "index = " << i << endl;
    cout << HashTable[i]->firstName<< endl;  
    cout << HashTable[i]->lastName<< endl;  
    cout << HashTable[i]->studentId<< endl;
    cout << HashTable[i]->GPA<< endl;
    cout << "number of items = " << number << endl;
    cout << "-----------------" << endl;  
    cout << "-----------------" << endl;
    cout << "index = " << i << endl;
    cout << HashTable[i]->next->firstName << endl;  
    cout << HashTable[i]->next->lastName << endl;  
    cout << HashTable[i]->next->studentId << endl;
    cout << HashTable[i]->next->GPA << endl;
    cout << "number of items = " << number << endl;
    cout << "-----------------" << endl;  
    }
    if(number == 3){
    cout << "-----------------" << endl;
    cout << "index = " << i << endl;
    cout << HashTable[i]->firstName<< endl;  
    cout << HashTable[i]->lastName<< endl;  
    cout << HashTable[i]->studentId<< endl;
    cout << HashTable[i]->GPA<< endl;
    cout << "number of items = " << number << endl;
    cout << "-----------------" << endl;  
    cout << "-----------------" << endl;
    cout << "index = " << i << endl;
    cout << HashTable[i]->next->firstName << endl;  
    cout << HashTable[i]->next->lastName << endl;  
    cout << HashTable[i]->next->studentId << endl;
    cout << HashTable[i]->next->GPA << endl;
    cout << "number of items = " << number << endl;
    cout << "-----------------" << endl;  
    cout << "-----------------" << endl;
    cout << "index = " << i << endl;
    cout << HashTable[i]->next->next->firstName << endl;  
    cout << HashTable[i]->next->next->lastName << endl;  
    cout << HashTable[i]->next->next->studentId << endl;
    cout << HashTable[i]->next->next->GPA << endl;
    cout << "number of items = " << number << endl;
    cout << "-----------------" << endl;  
    }
  }

}

int hashmap::Hash(char* key){
  int hash = 0;
  int index;
  
  index = strlen(key);
  
  for(int i =0; i < strlen(key); i++){
    hash = hash + (int)key[i];
  }
  
  index = hash % tableSize;
  return index;
  
}

void hashmap::removeItem(int sID){
  int index = Hash(findName(sID));
  item* delPtr;
  item* P1;
  item* P2;


}
char* hashmap::findName(int sID){
  int index = Hash(fname);
  bool foundID = false;
  char fName[20];  
  
  item* Ptr = HashTable[index];
  while(Ptr != NULL){
    if(Ptr->studentId == sID){
      foundID = true;
      strcpy(fName, Ptr->firstName); 
    }
    Ptr = Ptr->next;  
  }
  
  if(foundID == true){
    return fName;
  }
}

