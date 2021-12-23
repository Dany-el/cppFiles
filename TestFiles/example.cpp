#include <iostream>

using std::cout;
using std::cin;
using std::string;

int main(){
	size_t a = 0, b = 0;
	string choise;
	while(true){
		system("cls");
		cout<< "A ->";
		cin >> a;
		cout<< "B ->";
		cin >> b;
		cout<<"Plus / minus / divide / multiply ->";
		cin>>choise;
		if(choise == "plus"){
			cout<< a + b <<'\n';				
		}
		else if(choise == "minus"){
			cout<< a - b <<'\n';				
		}
		else if(choise == "multiply"){
			cout<< a * b <<'\n';				
		}
		else if(choise == "divide"){
			cout<< a / b <<'\n';				
		}
		else if(choise == "exit"){
			break;
		}
	}
	
	return 0;
}
