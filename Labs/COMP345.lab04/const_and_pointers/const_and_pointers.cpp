// How to read variable declarations. 
// You may want to use the Clockwise/Spiral method: http://c-faq.com/decl/spiral.anderson.html
int main() {
	{int x; } // x is an int
	{int* x; } // x is a pointer to an int
	{int** x; } // x is a pointer to a pointer to an int
	{const int** x; } // x is a pointer to a pointer to a constant int 
	{int const x = 0;} // x is a constant int
	{const int x = 0;} // const and the type it applies to can appear in any order. x is a constant int
	{int const* x;} // x is a pointer to a constant int
	{const int* x;} // x is a pointer to a constant int
	{int* const x = nullptr;} // x is a constrant pointer to an int
	{const int* const x = nullptr;} // x is a constrant pointer to a constant int
	{int const* const x = nullptr; } // x is a constrant pointer to a constant int
	{int* const* const x = nullptr; } // x is a constrant pointer to a constant pointer to an int
}