#include <iostream>
using namespace std; 

#define HEIGHT 3
#define WIDTH 4

int main() { 
	int table[HEIGHT][WIDTH] = {2,4,6,8,10,12,14,16,18,20,22,24};

	for (int i = 0; i < HEIGHT; i++) {
		for (int j = 0; j < WIDTH; j++) {
			cout << table[i][j] << ' '; 
		}
	}
	cout << endl; 

	for (int i = 0; i < HEIGHT; i++) {
		for (int j = 0; j < WIDTH; j++) {
			cout << *(*(table +i) +j)  << ' '; // using array-to-pointer decay
		}
	}
	cout << endl;

	for (int i = 0; i < HEIGHT*WIDTH; i++) {
		cout << *(*(table+0)+i)  << ' ';       // using array-to-pointer decay
	}
	cout << endl;

	cout << *(*(table + 1)) << endl;          // using array-to-pointer decay
	cout << *(*(table + 1) + 7) << endl;      // using array-to-pointer decay
	cout << *(*(table + 2) - 8) << endl;      // using array-to-pointer decay
	int n; cin >> n;
}