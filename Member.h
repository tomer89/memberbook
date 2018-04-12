#ifndef MEMBER_H
#define MEMBER_H

class List;

static int count;
class Member{
    public:
        Member();
        ~Member();
        void follow(Member m);
        void unfollow(Member);
        
        //getters:
        int numFollowers();
        int numFollowing();
        int getId();
        static int count();
        std::string getName();

    private:
        List* followers; 
        List* following;
        int numFollowes = 0;
        int id;
        std::string name;

};


#endif