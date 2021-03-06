#include <iostream>
using namespace std;

#include "Member.h"


Member avi, beni, chana;

void test1() {
	cout << "entered test1" << endl;
	Member dana;
	chana.follow(dana);
	dana.follow(avi);
	cout << "  " << chana.numFollowers() << " " <<  chana.numFollowing() << endl; // 0 1
	cout << "  " << avi.numFollowers() << " " <<  avi.numFollowing() << endl; // 1 0
	cout << "  " << Member::count() << endl; // 4
	
}
/*
void unfollow_without_following(){
	cout << "entered test2" << endl;
	Member Shira;
	Shira.unfollow(avi);
}*/

int main() {

/*	{
		Member* tomer;
		
		tomer = &avi;
		
		cout << "111\n" <<Member::count() << endl; 
		tomer->follow(beni);
		
		cout << "222\n"<< Member::count() << endl; 
		tomer->unfollow(beni);
		cout << "333\n"<< Member::count() << endl; 
	}*/
	cout << avi.numFollowers() << " " << avi.numFollowing() << endl; // 0 0
	cout << avi.getId() << endl;
	cout << beni.getId() << endl;
	avi.follow(beni); 
	cout << avi.numFollowers() << " " << avi.numFollowing() << endl; // 0 1
	cout << beni.numFollowers() << " " << beni.numFollowing() << endl; // 1 0
	
	cout << Member::count() << endl; // 3
	cout << endl;
	
	avi.follow(beni); // duplicate follow has no effect
	cout << avi.numFollowers() << " " << avi.numFollowing() << endl; // 0 1
	
		
	avi.unfollow(beni);	
	cout << avi.numFollowers() << " " << avi.numFollowing() << endl; // 0 0
	
	cout << endl;

	cout << chana.numFollowers() << " " <<  chana.numFollowing() << endl; // 0 0
	test1();
	//unfollow_without_following();
	
	cout << chana.numFollowers() << " " <<  chana.numFollowing() << endl; // 0 0
	cout << avi.numFollowers() << " " <<  avi.numFollowing() << endl; // 0 0
	cout << Member::count() << endl; // 3
	
}