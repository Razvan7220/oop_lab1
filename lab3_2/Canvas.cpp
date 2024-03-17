#include "Canvas.h"
#include <iostream>
#include <cmath>
#include <new>
using namespace std;
Canvas::Canvas(int nr_linii, int nr_col)
{
	this->M = new char* [nr_linii];
	for (int i = 0; i < nr_col; ++i)
		this->M[i] = new char[nr_col];

	for (int i = 0; i < nr_linii; ++i)
		for (int j = 0; j < nr_col; ++j)
			this->M[i][j] =' ';

	this-> linii = nr_linii;
	this-> coloane = nr_col;
}
void Canvas::DrawCircle(int x, int y, int r, char ch)
{
	for(int i=0;i<this->linii;i++)
		for (int j = 0; j < this->coloane; j++)
		{
			if ((i - x) *(i-x) + (j - y) *(j-y) >= r*(r - 1) && (i - x) *(i-x) + (j - y) *(j-y)<= r*(r + 1))
				this->M[i][j] = ch;
		}
}
void Canvas::FillCircle(int x, int y, int r, char ch)
{
	for (int i = 0; i < this->linii; i++)
		for (int j = 0; j < this->coloane; j++)
			if(((i - x) * (i - x) + (j - y) * (j - y) <= r * r))
				this->M[i][j] = ch;

}
void Canvas::DrawRect(int x1, int y1, int x2, int y2, char ch)
{
	for (int i = x1; i <= y2; i++)
		this->M[i][y1] = ch;
	for (int i = x1; i <= y2; i++)
		this->M[y1][i] = ch;
	for (int i = y2; i >= x1; i--)
		this->M[i][y2] = ch;
	for (int i = y2; i >= x1; i--)
		this->M[y2][i] = ch;
	
}
void Canvas::FillRect(int x1, int y1, int x2, int y2, char ch)
{
	int ok = 0;
	for (int i = x1 + 1; i < x2; i++)
	{
		if (ok == 1)
			break;
		for (int j = y1 + 1; j < y2; j++)
		{
			if (this->M[i][j] != ' ')
			{
				ok = 1;
				break;
				
			}
			this->M[i][j] = ch;
		}
	}
}
void Canvas::SetPoint(int x,int y,char ch)
{
	this->M[x][y] = ch;
}
void Canvas::DrawLine(int x1, int y1, int x2, int y2, char ch) {
	int deltaX = abs(x2 - x1);
	int deltaY = abs(y2 - y1);
	int xStep = (x1 < x2) ? 1 : -1;
	int yStep = (y1 < y2) ? 1 : -1;

	int error = deltaX - deltaY;

	int currentX = x1;
	int currentY = y1;

	while (currentX != x2 || currentY != y2) {
		SetPoint(currentX, currentY, ch);

		int doubleError = 2 * error;
		if (doubleError > -deltaY) {
			error -= deltaY;
			currentX += xStep;
		}
		if (doubleError < deltaX) {
			error += deltaX;
			currentY += yStep;
		}
	}

	SetPoint(x2, y2, ch); 
}
void Canvas::Print()
{
	for (int i = 1; i <= this->linii; i++)
	{
		for (int j = 1; j <= this->coloane; j++)
			cout << this->M[i][j] << " ";
		cout << '\n';
	}

}
void Canvas::Clear() {
	for (int i = 0; i < this->linii; ++i) {
		delete[] M[i];
	}
	delete[] M;
}