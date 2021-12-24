#include <iostream>
#include <curses.h>

using std::cout;
using std::cin;

int factioral(int number){
	if(number == 0){
		return 1;
	}
	else if(number > 0){
		int sum = 1;
		for (size_t i = number; i > 0; i--)
		{
			sum *= number;
			number--;
		}	
		return sum;
	}
	return -1;
}

int main(){
	double a = 0, b = 0;
	char choise;
	do
	{
		cout<< "\n--> ";
		cin >> a >> choise >> b;
		if(choise == '+'){
			cout<< a + b <<'\n';				
		}
		else if(choise == '-'){
			cout<< a - b <<'\n';				
		}
		else if(choise == '*'){
			cout<< a * b <<'\n';				
		}
		else if(choise == '/'){
			cout<< a / b <<'\n';				
		}
	} while (choise !=0 );

	int x = 0;
	cin >> x;
	cout << '\n' << factioral(x) << '\n';

	return 0;
}
