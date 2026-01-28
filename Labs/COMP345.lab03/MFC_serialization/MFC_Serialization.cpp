// Project3.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include "framework.h"
#include "Project3.h"

#include "stdafx.h"
#include <atlstr.h>
#include "AbstractGeometricObject.h"
#include "DerivedCircleFromAbstractGeometricObject.h"
#include "DerivedRectangleFromAbstractGeometricObject.h"
#include <iostream>
using namespace std;

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

//! @file 
//! @brief Main driver file for the console application.
//!


//! A free function for comparing the areas of two geometric objects
//!
bool equalArea(const GeometricObject& g1, const GeometricObject& g2)
{
	return g1.getArea() == g2.getArea();
}

//! A free function for displaying a geometric object
//!
void displayGeometricObject(const GeometricObject& g)
{
	cout << "The area is " << g.getArea() << endl;
	cout << "The perimeter is " << g.getPerimeter() << endl;
	cout << "The color is " << g.getColor() << endl;

}

//! A free function for displaying a geometric object that demonstrates 
//! the use of dynamic_cast to cast the GenericObject in both a Circle 
//! and a JRectangle. Whichever is successful will be the one displayed 
//!
void displayGeometricObjectDynamicCastDemo(GeometricObject& g)
{
	cout << "The area is " << g.getArea() << endl;
	cout << "The perimeter is " << g.getPerimeter() << endl;

	GeometricObject* p = &g;
	Circle* p1 = dynamic_cast<Circle*>(p);
	JRectangle* p2 = dynamic_cast<JRectangle*>(p);

	if (p1 != NULL)
	{
		cout << "The radius is " << p1->getRadius() << endl;
		cout << "The diameter is " << p1->getDiameter() << endl;
		cout << "The color is " << p1->getColor() << endl;
	}

	if (p2 != NULL)
	{
		cout << "The width is " << p2->getWidth() << endl;
		cout << "The height is " << p2->getHeight() << endl;
		cout << "The color is " << p2->getColor() << endl;

	}
}

//! main() function. Entry point of the program
//!
void mymain()
{
	cout << "HERE!!!!!!!!!!!!!!!" << endl;
	CFile theFile;
	theFile.Open(_T("CArchiveTest.txt"), CFile::modeCreate | CFile::modeWrite);
	CArchive archive(&theFile, CArchive::store);

	Circle* circle = new Circle(5, "black", true);
	JRectangle* JRect = new JRectangle(5, 3, "red", true);

	cout << *circle;
	cout << *JRect;

	circle->Serialize(archive);
	JRect->Serialize(archive);

	cout << "Circle info: " << endl;
	displayGeometricObject(*circle);

	cout << "\nJRectangle info: " << endl;
	displayGeometricObject(*JRect);

	cout << "\nThe two objects have the same area? " <<
		(equalArea(*circle, *JRect) ? "Yes" : "No") << endl;

	cout << "\nCircle info: " << endl;
	displayGeometricObjectDynamicCastDemo(*circle);

	cout << "\nJRectangle info: " << endl;
	displayGeometricObjectDynamicCastDemo(*JRect);

	delete circle;
	delete JRect;
	archive.Close();
	theFile.Close();

	cout << "\nWrite done. Press any key to continue..." << endl; char c;  cin >> c;

	CFile theOtherFile;
	theOtherFile.Open(_T("CArchiveTest.txt"), CFile::modeRead);
	CArchive otherArchive(&theOtherFile, CArchive::load);

	Circle* circle2 = new Circle();
	JRectangle* JRect2 = new JRectangle();

	cout << *circle2;
	cout << *JRect2;

	circle2->Serialize(otherArchive);
	JRect2->Serialize(otherArchive);

	cout << "Circle info: " << endl;
	displayGeometricObject(*circle2);

	cout << "\nJRectangle info: " << endl;
	displayGeometricObject(*JRect2);

	cout << "\nThe two objects have the same area? " <<
		(equalArea(*circle2, *JRect2) ? "Yes" : "No") << endl;

	cout << "\nCircle info: " << endl;
	displayGeometricObjectDynamicCastDemo(*circle2);

	cout << "\nJRectangle info: " << endl;
	displayGeometricObjectDynamicCastDemo(*JRect2);

	cout << "\nRead done. Press any key to stop..." << endl;
	char c1;  cin >> c1;

	delete circle2;
	delete JRect2;
	otherArchive.Close();
	theOtherFile.Close();
}

// The one and only application object

CWinApp theApp;

using namespace std;

int main()
{
    int nRetCode = 0;

    HMODULE hModule = ::GetModuleHandle(nullptr);

    if (hModule != nullptr)
    {
        // initialize MFC and print and error on failure
        if (!AfxWinInit(hModule, nullptr, ::GetCommandLine(), 0))
        {
            // TODO: code your application's behavior here.
            wprintf(L"Fatal Error: MFC initialization failed\n");
            nRetCode = 1;
        }
        else
        {
            mymain(); 
            // TODO: code your application's behavior here.
        }
    }
    else
    {
        // TODO: change error code to suit your needs
        wprintf(L"Fatal Error: GetModuleHandle failed\n");
        nRetCode = 1;
    }

    return nRetCode;
}

