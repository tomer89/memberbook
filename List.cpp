#include <iostream>
#include "Member.h"
#include "List.h"
using namespace std;


List::List(){
    head = NULL;
    curr = NULL;
    temp = NULL;
    //cout << "list const" << endl;
}

/*List::nodePtr List::getHead(){
    //for testing stuff
    return head;
}*/

void List::addNode(Member* addData){
    bool flag = true;
    nodePtr n = new node;
    n->data = addData;
    n->next = NULL;
    
    
    if(head == NULL){
        head = n;
        curr = n;
        size++;
    }
    else{
        temp = head;
        while(flag){
            //cout << temp->data->getId() << " == " << addData->getId() << "      flag is: "  << flag << endl;
            if(temp->data->getId() == addData->getId()){
                if(temp->next != NULL){
                    temp = temp->next;
                }
                flag = false;
  
            }
        }
        if(flag){
            //cout << "Zaks";
            size++;
           
            curr->next = n;
            curr = n;
        }
    }
}


void List::deleteNode(Member * delData){
    if(head != NULL){
        if(head->data->getId() == delData->getId()){
            head = NULL;
            size--;
            return ;
        }
        temp = head;
        bool flag = true;
        nodePtr p = head;
        
        while(flag){
            if(temp->next != NULL){
                if(temp->next->data->getId() == delData->getId()){
                    
                    flag = false;
                    if(temp->next->next != NULL){
                        temp->next = temp->next->next;
                    }
                    else{
                        temp->next = NULL;
                    }
                    
                }
                if(temp->next != NULL){
                    temp = temp->next;
                }
            }
            else{
                flag = false;
            }
        }
        
        
        if(!flag){
            size--;
        }
        /*else{
            cout << "Did not find " << delData->getName() << "'s profile in this list";
        }*/
        
    }
}


int List::getSize(){
    //cout << "checking List->getSize() \n";
    return size;
}


Member* List::getMemberOfPosition(int i){
    temp = head;
    Member* pm = temp->data;
    
    if(i == 0){
        return pm;
    }
    int j = 0;
    while(pm != NULL && j > i){
        temp = temp->next;
        pm = temp->data;
        j++;
        if(j == i){
            return pm;
        }
    }
    
    // i was greater than size of list
    return NULL;
}
/*
//did similar to https://www.youtube.com/watch?v=H5lkmKkfjD0 
class List{
    private:
        typedef struct node{
            int data;
            node* next
        }* nodePtr;
        
        nodePtr head;
        nodePtr curr;
        nodePtr temp;
        
    public:
        List();
        void AddNode(int addData);
        void DeleteNode(int delData);
        
        
        
}
*/