#include <iostream>
#include "List.h"
#include "Member.h"
#include <string>
using namespace std;

static int countMembers = 0;
    
    
Member::Member(){

    
    countMembers++;
    id = countMembers;
    followers = new List;
    following = new List;
    
    cout << id << endl;
}

Member::~Member(){
    // << "Member destructer" << endl;
    countMembers--;
}

//a getter to get amount of people this member is following
int Member::numFollowers(){
    return followers->getSize();
}

int Member::numFollowing(){
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
    m.followers->addNode(this);
    //cout << "who do I destroy here?\n"<< Member::count() << endl; 
    countMembers++;
    
    
    
}


void Member::unfollow(Member m){
            
    Member * tmp = &m;

    following->deleteNode(tmp);

    m.followers->deleteNode(this);
    
    //cout << "who do I destroy here?\n"<< Member::count() << endl; 
    countMembers++;
    
}

string Member::getName(){
    return name;
}