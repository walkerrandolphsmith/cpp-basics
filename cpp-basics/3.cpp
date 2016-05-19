#include <iostream>
using namespace std;

const int MAX = 3;

int main () {

		cout << "\n" << "Pointer to an integer references the value at an address." << "\n\n";

	int var = 10;
	int *ip;

	ip = &var;

	cout << "Value of var: " << var << endl;

	cout << "Address stored in ip: " << ip << endl;

	cout << "Value held at the address pointed to by ip: " << *ip << endl;


	cout << "\n" << "Pointer Arthimetic to iterate over an array by starting the value of the pointer at the address of the array and then altering the address of a pointer." << "\n\n";

	int array[MAX] = {10, 100, 1000};
	int *ptr;

	ptr = array;
	for(int i = 0; i < MAX; i++){
		cout << "Address of array[" << i << "] = ";
		cout << ptr << endl;

		cout << "Value of array[" << i << "] = ";
		cout << *ptr << endl;
		ptr++;
	}

	cin >> var;

	return 0;
}