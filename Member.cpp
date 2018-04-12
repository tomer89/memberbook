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
}


void Member::unfollow(Member m){
    Member * tmp = &m;
    following->deleteNode(tmp);
    m.followers->deleteNode(this);
    
}

string Member::getName(){
    return name;
}