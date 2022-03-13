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

void hashmap::setA(){
  a = 10;
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
    cout << "-----------------" << endl;
    cout << "index = " << i << endl;
    cout << HashTable[i]->firstName<< endl;  
    cout << HashTable[i]->lastName<< endl;  
    cout << HashTable[i]->studentId<< endl;
    cout << HashTable[i]->GPA<< endl;
    cout << "number of items = " << number << endl;
    cout << "-----------------" << endl;  
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
