#include <iostream>
using namespace std;

class My2DArray {
private:
	int** theArray;
	int xsize;
	int ysize;
public:
	My2DArray();
	My2DArray(My2DArray& toCopy);
	~My2DArray();
	My2DArray(int xsize, int ysize);
	My2DArray& resize(int xsize, int ysize);
	My2DArray& operator=(My2DArray& toAssign);
	My2DArray& operator+(My2DArray& toAdd);
	friend ostream& operator<<(ostream& stream, My2DArray &array);
};

My2DArray::My2DArray() : xsize(0), ysize(0), theArray(0) {
	cout << "[()]"; 
}

My2DArray::My2DArray(My2DArray& toCopy) {
	cout << "[(copy)]"; 
	this->xsize = toCopy.xsize;
	this->ysize = toCopy.ysize;
	this->theArray = new int* [xsize];
	for (int x = 0; x < xsize; x++) {
		this->theArray[x] = new int[ysize];
		for (int y = 0; y < ysize; y++) {
			this->theArray[x][y] = toCopy.theArray[x][y];
		}
	}
}

My2DArray::My2DArray(int xsize, int ysize) {
	cout << "[(xy)]";
	this->xsize = xsize;
	this->ysize = ysize;
	this->theArray = new int*[xsize];
	for (int x = 0; x < xsize; x++) {
		this->theArray[x] = new int[ysize];
		for (int y = 0; y < ysize; y++) {
			this->theArray[x][y] = ((x+1)*10)+y;
		}
	}
}

My2DArray& My2DArray::resize(int newxsize, int newysize) {
	cout << "[resize]"; 
	int** resizedArray = new int*[newysize];
	for (int x = 0; x < newxsize; x++) {
		resizedArray[x] = new int[newysize];
		for (int y = 0; y < newysize; y++) {
			if (x <= xsize-1 && y <= ysize-1)
				resizedArray[x][y] = this->theArray[x][y];
			else
				resizedArray[x][y] = 0; 
		}
	}
	this->theArray = resizedArray; 
	this->xsize = newxsize; 
	this->ysize = newysize;
	return *this; 
}

My2DArray& My2DArray::operator+(My2DArray& toAdd){
	cout << "[+]"; 
	My2DArray* result = new My2DArray(); 
	result->xsize = xsize;
	result->ysize = ysize;
	result->theArray = new int* [xsize];
	for (int x = 0; x < xsize; x++) {
		result->theArray[x] = new int[ysize];
		for (int y = 0; y < ysize; y++) {
			result->theArray[x][y] = this->theArray[x][y] + toAdd.theArray[x][y];
		}
	}
	return *result; 
}

My2DArray::~My2DArray() {
	cout << "[~]"; 
	for (int x = 0; x < xsize; x++){
		delete[] theArray[x];
	}
	delete[] theArray;
}

My2DArray& My2DArray::operator=(My2DArray& const toAssign) {
	cout << "[=]"; 
	this->xsize = toAssign.xsize;
	this->ysize = toAssign.ysize;
	this->theArray = new int* [xsize];
	for (int x = 0; x < xsize; x++) {
		this->theArray[x] = new int[ysize];
		for (int y = 0; y < ysize; y++) {
			this->theArray[x][y] = toAssign.theArray[x][y];
		}
	}	return *this;
}

ostream& operator<<(ostream& stream, My2DArray& array) {
	cout << "[<<]" << endl; 
	stream << "xsize: " << array.xsize << endl;
	stream << "ysize: " << array.ysize << endl;
	for (int x = 0; x < array.xsize; x++) {
		for (int y = 0; y < array.ysize; y++) {
			stream << array.theArray[x][y] << " " ;
		}
		stream << endl;
	}
	return stream; 
}

int main() {
	cout << endl << endl << "My2DArray a1(2,3);" << endl;
	My2DArray a1(2,3);
	cout << endl << endl << "My2DArray a2(a1);" << endl;
	My2DArray a2(a1);
	cout << endl << endl << "My2DArray a3(2, 3);" << endl;
	My2DArray a3(4,5);
	cout << endl << endl << "My2DArray a4 = a1 + a3;" << endl;
	My2DArray a4 = a1 + a3;
	cout << endl << endl << "My2DArray a5;" << endl;
	My2DArray a5;
	cout << endl << endl << "a5 = a1 + a3;" << endl;
	a5 = a1 + a3;

	cout << endl << "a1: " << endl << a1 << endl;
	cout << endl << "a2: " << endl << a2 << endl;
	cout << endl << "a3: " << endl << a3 << endl;
	cout << endl << "a4: " << endl << a4 << endl;
	cout << endl << "a5: " << endl << a5 << endl;

	a5.resize(10, 10);
	cout << endl << "a5: " << endl << a5 << endl;

	a5.resize(2, 2);
	cout << endl << "a5: " << endl << a5 << endl;

	// Something is wrong with the + operator
	// My2DArray a6 = a5.resize(8, 8) + a4;
	// cout << endl << "a6: " << endl << a6 << endl;

}