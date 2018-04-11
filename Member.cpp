#include <iostream>
#include "List.h"
#include "Member.h"
#include <string>
using namespace std;

static int countMembers = 0;
    
    
Member::Member(){

    id = countMembers;
    countMembers++;
    followers = new List;
    following = new List;
    //cout << "basic constructor with id " << id << "\n"; 
}


int Member::numFollowers(){
    //cout << "checking Member->numFollowers() \n";
    return followers->getSize();
}

int Member::numFollowing(){
    //cout << "checking Member->numFollowing() \n";
    return following->getSize();
}

int Member::getId(){
    return id;
}

int Member::count(){
    return countMembers;
}

//AVI -> BENI
void Member::follow(Member m){
    Member * tmp = &m;
    following->addNode(tmp);
    //cout << " going to add the follower \n";
    m.followers->addNode(this);
}


void Member::unfollow(Member m){
    Member * tmp = &m;
    //cout << "before deleting from following" << endl;
    following->deleteNode(tmp);
    
    //cout << "before deleting from followers" << endl;
    m.followers->deleteNode(this);
    
}

string Member::getName(){
    return name;
}
/*        
class Member{
    public:
        Member(){
            id = countMembers;
            countMembers++;
            cout << "basic constructor with id " << id << "\n";
        }
        int numFollowers(){
            return numFollowes;
        }
        void follow(Member m){
            
        }

    private:

        int numFollowes = 0;
        int id;
        

};


// since this is a small helper class I did not see a reason to create a new file for it
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
        void AddNode(int addData){
            
        }
        
        
}

*/
/*


int main() {
    Member avi;
    Member avi1;
    Member avi2;
    Member avi3;
    //for(int i = 0 ; i < 5 ;i++){
        //Member i;
    //}
    cout << avi.numFollowers();
}*/