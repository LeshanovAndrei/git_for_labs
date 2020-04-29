#include "header.h"
#include "shape.h"

void Shape::SetColor(int dR, int dG, int dB)
{
    r = dR;
    g = dG;
    b = dB;
}

Shape::Shape():
    centerX(0),
    centerY(0),
    radius(50),
    track(0),
    r(0),
    g(0),
    b(0)
{
    Show();
}

Shape::Shape(const Shape& n):
    centerX(n.centerX),
    centerY(n.centerY),
    radius(n.radius),
    track(0),
    r(0),
    g(0),
    b(0)
{
    Show();
}

void Shape::Show()
{
    SetColor(0, 0, 0);
    Draw();
}

void Shape::Hide()
{
    SetColor(255, 255, 255);
    Draw();
}

void Shape::Move(int dX, int dY)
{
    Hide();
    centerX += dX;
    centerY += dY;
    Show();
}

void Shape::Increase()
{
    Hide();
    radius += 5;
    Show();
}

void Shape::Reduce()
{
    Hide();
    radius -= 5;
    Show();
}

void Shape::Track()
{
    track = 1;
}

void Shape::Draw()
{

}

int Shape::GetX()
{
    return centerX;
}

int Shape::GetY()
{
    return centerY;
}

int Shape::GetRadius()
{
    return radius;
}