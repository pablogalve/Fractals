#include "graphics.h"
#include <iostream>
#include <cstdlib>

// Cantor set //////////////////////////////////////////////////////////////////

void cantor(float depth, float x, float y)
{
	line(x, y, x + depth, y);
	if (depth >= 10) {
		y += 20;
		cantor(depth / 3.0, x, y);
		cantor(depth / 3.0,x + 2.0 * depth / 3.0, y);
	}
}


// Circles /////////////////////////////////////////////////////////////////////

void circles(float x, float y, float radius)
{
	circle(x, y, radius);
	if (radius >= 5) {
		circles(x+radius*0.6, y, radius*0.4);
		circles(x-radius*0.6, y, radius*0.4);
		circles(x, y + radius * 0.6, radius*0.4);
		circles(x, y - radius * 0.6, radius*0.4);
	}
}


// 2D vector utility ///////////////////////////////////////////////////////////

struct vec2
{
	float x, y;
	vec2() : x(0), y(0) {}
	vec2(float X, float Y) :x(X), y(Y) {}
};
vec2 operator+(const vec2 &a, const vec2 &b) { return vec2(a.x + b.x, a.y + b.y); }
vec2 operator-(const vec2 &a, const vec2 &b) { return vec2(a.x - b.x, a.y - b.y); }
vec2 operator-(const vec2 &b) { return vec2(- b.x, - b.y); }
vec2 operator*(float v, const vec2 &a) { return vec2(a.x * v, a.y * v); }
vec2 operator*(const vec2 &a, float v) { return vec2(a.x * v, a.y * v); }
vec2 operator/(const vec2 &a, float v) { return vec2(a.x / v, a.y / v); }
float dot(const vec2 &a, const vec2 &b) { return a.x * b.x + a.y * b.y; }
float length(const vec2 &v) { return sqrt(dot(v, v)); }
vec2 perpendicular(const vec2 &v) { return vec2(v.y, -v.x); }
vec2 normalize(const vec2 &v) { return v / length(v); }


// Sierpinski fractal //////////////////////////////////////////////////////////


void triangle(float x, float y, float side)
{
	line(x, y, x + side, y);
	line(x, y, x + side / 2, y + side);
	line(x + side, y, x + side / 2, y + side);
}

//
// Sierpinski fractal
//
//              top
//               o
//              / \
//           a o---o b
//            /\   /\
//           /  \ /  \
//          o----o----o
//  bottomLeft   c   bottomRight
//
void sierpinski(float side, float x, float y)
{
	triangle(x, y, side);
	if (side >= 10) {
		sierpinski(side*0.5, x, y);
		sierpinski(side*0.5, x+side/2, y);
		sierpinski(side*0.5, x+side/4, y+side/2);
	}
}


// Tree fractal ////////////////////////////////////////////////////////////////

void tree(float depth, float x1, float x2, float y1, float y2)
{
	line(x1, y1, x2, y2);
	if (depth >= 10) {
		tree(depth *0.6, x1*cos(45), x1, y1*cos(45), y2);
		tree(depth *0.6, x1, x2, y1, y2);
	}
}
void vectorTree(float depth, const vec2 &a, const vec2 &b) {
	
}
void star(float x, float y, float side) {
	float tram = side * 0.8 / 2.0;
	line(x - tram, y, x + tram, y); // horitzontal
	line(x, y - tram, x, y + tram); //vertical
	line(x - tram, y - tram, x + tram, y + tram); // diagonal 1
	line(x + tram, y - tram, x - tram, y + tram); // diagonal 2
}
void Stars(float x, float y, float side) {
	star(x, y, side);
	if (side > 2) {
		Stars(x - side * 0.8, y, side*0.15);
		Stars(x + side * 0.8, y, side*0.15);
		Stars(x, y - side * 0.8, side*0.15);
		Stars(x, y + side * 0.8, side*0.15);
		Stars(x - side * 0.8, y - side * 0.8, side*0.15);
		Stars(x + side * 0.8, y + side * 0.8, side*0.15);
		Stars(x + side * 0.8, y - side * 0.8, side*0.15);
		Stars(x - side * 0.8, y + side * 0.8, side*0.15);
	}
}

// Spiky triangle //////////////////////////////////////////////////////////////

void spiky_triangle(float x, float y, float side)
{
	// TODO
}

void square(float x, float y, float side) {
	line(x, y, x + side, y);
	line(x, y, x, y + side);
	line(x + side, y, x + side, y + side);
	line(x, y + side, x + side, y + side);
}

void Squares(float x, float y, float side) {
	square(x, y, side);
	if (side >= 10) {
		float border = side *0.05;
		side = (side -3 * border) / 2; //To calculate the side of next square, we take 3 borders and divide by 2 because we'll have 2 smaller squares at that position
		Squares(x + border, y + border, side);
		Squares(x + side + (2 * border), y + border, side);
		Squares(x + border, y+(2*border)+side, side);		
		Squares(x + side + (2 * border), y + (2 * border) + side, side);
	}
}

// Main function ///////////////////////////////////////////////////////////////

void main()
{
	/*
	Basic drawing functions.
	void putpixel(int x, int y, int color);
	void line(int x1, int y1, int x2, int y2);
	void rectangle(int left, int top, int right, int bottom);
	void circle(int x, int y, int radius);
	*/

	initwindow(1000, 1000, "Graphics");
	//cantor(900, 50, 50);
	//circles(300, 300, 250);
	//sierpinski(700, 50, 50);
	//tree(500, 500, 500, 500, 700);
	//Squares(50, 50, 600);
	Stars(300,300, 300);

	system("pause");
}
