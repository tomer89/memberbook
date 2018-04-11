#ifndef LIST_H
#define LIST_H

class Member; 
//did similar to https://www.youtube.com/watch?v=H5lkmKkfjD0 
class List{
    private:
        typedef struct node{
            Member* data;
            node* next;
        }* nodePtr;
        
        nodePtr head;
        nodePtr curr;
        nodePtr temp;
        
        int size = 0;
        
    public:
        List();
        void addNode(Member* addData);
        void deleteNode(Member* delData);
        int getSize();
        nodePtr getHead();
        
        
};



#endif