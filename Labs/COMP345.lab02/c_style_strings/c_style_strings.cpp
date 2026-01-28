#include <iostream>
#include <string>
#include <cstring>

using namespace std;

int main() {
    char str1[] = "Hello";
    // fix 2 (see strcat below) : 
    // char str1[20] = "Hello";
    char str2[] = "World";
    char str3[] = "";
    // fix 1 (see strcpy below) :
    // char str3[20] = "";
    int len;
    int resp;

    // strcpy: copy str1 into str3
    //
    // Note: this does not work with VS2019, as strcat is deprecated. 
    // It works with g++ though. 
    //
    // this appears to work, but is in fact implementing a buffer overflow,
    // as the destination string size (0) cannot contain the source string (size 5),
    // the writing operation overflows into another variable's memory space.
    // In this case, it will overwrite ontl the content of str2.
    // A solution here is to make str3 at least the size of str1.
    strcpy(str3, str1);
    cout << "strcpy(str3, str1) : " << str3 << endl;

    // strcpy_s is more secure, as it would throw an exception on the buffer overflow
    // but it is not available in g++...
    //resp = strcpy_s(str3, sizeof(str3), str1);
    //cout << "strcpy_s(str3, sizeof(str3), str1) : " << str3 << endl;

    // strcat: concatenates str1 and str2
    //
    // Note: this does not work with VS2019, as strcat is deprecated. 
    // It works with g++ though. 
    //
    // This should work, but the buffer overflow above (strcpy) has already written on top
    // of the value of str2. Moreover, even if it appears to work after we fix the 
    // size of str3 above, it also implements a buffer overflow, writing a part of the 
    // resulting concatenated string beyond the space allocated to str1. 
    // A solution here would be to increase the size of memory allocated to str1. 
    // c-style strings can be very tricky!
    strcat(str1, str2);
    cout << "strcat(str1, str2): " << str1 << endl;

    // strcpy_s is more secure, as it would throw an exception on the buffer overflow
    // but it is not available in g++...
    //resp = strcat_s(str1, sizeof(str1), str2);
    //cout << "strcat_s(str1, sizeof(str1), str2) : " << str1 << endl;

    // total lenghth of str1 after concatenation
    len = strlen(str1);
    // strlen counts characters until the \0 end marker that was added by strcpy 
    // at then end of the buffer overflowed operation.
    cout << "strlen(str1) : " << len << endl;

    return 0;
}
