#include <iostream>
#include "Group.h"

int main(){
	Group* group = new Group();
	
	group->Input();

	delete group;
	
	return 0;
}
