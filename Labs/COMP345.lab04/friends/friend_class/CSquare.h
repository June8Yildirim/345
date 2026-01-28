#pragma once

class CSquare
{
private:
	int side;

public:
	void setSide(int a)
	{
		side = a;
	}

	friend class CRectangle;
};