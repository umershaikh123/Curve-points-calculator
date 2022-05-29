#include <iostream>
#include <cstdio>
#include <stdio.h>
#include <math.h>
using namespace std;

class Point
{
private:
    double x, y;

public:
    Point()
    {
    }

    Point(double x, double y)
    {
        this->x = x;
        this->y = y;
    }

    Point(const Point &n)
    {
        this->x = n.x;
        this->y = n.y;
    }

    void SetPoint(double x, double y)
    {
        this->x = x;
        this->y = y;
    }

    int getX()
    {
        return x;
    }

    int getY()
    {
        return y;
    }
};

class Curve
{
private:
    enum Type
    {
    };
    Point *point;
    int l = 50;

public:
    Curve()
    {
        point = new Point[l];
    }
    virtual void ComputePoints() = 0;

    friend ostream &operator<<(ostream &out, const Curve &c);
};

class ParametricCurve : public Curve
{
private:
    int minT;
    int maxT;

public:
    double x, y, c1, c2, c3, c4;
    int l = 50;
    double t[50];
    int counter = -25;
    Point *point;
    ParametricCurve()
    {
        point = new Point[l];
        for (int i = 0; i < 50; i++)
        {
            t[i] = counter;
            counter++;
        }
    }

    void ComputePoints()
    {
        char format = 'A';
        cout << endl
             << "Format : A " << endl;
        cout << "Equation => x = c1  + c2 (t) " << endl;
        cout << "Equation => y = c3  + c4 (t) " << endl;

        cout << endl
             << "Format : B " << endl;
        cout << "Equation => x = c1  + c2 sin(t) " << endl;
        cout << "Equation => y = c3  + c4 sint(t) " << endl;

        cout << endl
             << "Format : C " << endl;
        cout << "Equation => x = c1  + c2 Cos(t) " << endl;
        cout << "Equation => y = c3  + c4 Cos(t) " << endl;

        cout << endl
             << "Format : D " << endl;
        cout << "Equation => x = c1(t)  + c2 sin(t) " << endl;
        cout << "Equation => y = c3 + c4 cos(t) " << endl
             << endl;

        cout << "Select any one Format A, B, C, D" << endl;

        cin >> format;
        switch (format)
        {
        case 'A':
            cout << endl
                 << "You Have selected Format A : " << endl;
            cout << "Equation => x = c1  + c2 t " << endl;
            cout << "Enter c1 : " << endl;
            cin >> c1;
            cout << "Enter c2 : " << endl;
            cin >> c2;
            cout << endl;
            cout << "Equation => y = c3  + c4 t " << endl;
            cout << "Enter c3 : " << endl;
            cin >> c3;
            cout << "Enter c4 : " << endl;
            cin >> c4;
            cout << endl;

            for (int i = 0; i < 50; i++)
            {

                x = c1 + (c2 * t[i]);
                y = c3 + (c4 * t[i]);
                Point p(x, y);
                point[i] = p;
                // Error here
                // In all cases X AND Y results are in double
                // But when it gets stored in point it gets converted to int I DONT understand why
                cout << " X" << i + 1 << " = " << x << endl;
                cout << " Y" << i + 1 << " = " << y << endl;
            }
            break;

        case 'B':
            cout << endl
                 << "You Have selected Format B : " << endl;

            cout << "Equation => x = c1  + c2 sin(t) " << endl;
            cout << "Enter c1 : " << endl;
            cin >> c1;
            cout << "Enter c2 : " << endl;
            cin >> c2;
            cout << endl;
            cout << "Equation => y = c3  + c4 sin(t) " << endl;
            cout << "Enter c3 : " << endl;
            cin >> c3;
            cout << "Enter c4 : " << endl;
            cin >> c4;
            cout << endl;

            for (int i = 0; i < 50; i++)
            {

                x = c1 + (c2 * sin(t[i]));
                y = c3 + (c4 * sin(t[i]));
                Point p(x, y);
                point[i] = p;
                // Error here
                // In all cases X AND Y results are in double
                // But when it gets stored in point it gets converted to int I DONT understand why

                cout << " X" << i + 1 << " = " << x << endl;
                cout << " Y" << i + 1 << " = " << y << endl;
            }
            break;

        case 'C':
            cout << endl
                 << "You Have selected Format C : " << endl;

            cout << "Equation => x = c1  + c2 cos(t) " << endl;
            cout << "Enter c1 : " << endl;
            cin >> c1;
            cout << "Enter c2 : " << endl;
            cin >> c2;
            cout << endl;
            cout << "Equation => y = c3  + c4 cos(t) " << endl;
            cout << "Enter c3 : " << endl;
            cin >> c3;
            cout << "Enter c4 : " << endl;
            cin >> c4;
            cout << endl;

            for (int i = 0; i < 50; i++)
            {

                x = c1 + (c2 * cos(t[i]));
                y = c3 + (c4 * cos(t[i]));
                Point p(x, y);
                point[i] = p;
                // Error here
                // In all cases X AND Y results are in double
                // But when it gets stored in point it gets converted to int I DONT understand why
                cout << " X" << i + 1 << " = " << x << endl;
                cout << " Y" << i + 1 << " = " << y << endl;
            }
            break;

        case 'D':
            cout << endl
                 << "You Have selected Format D : " << endl;

            cout << "Equation => x = c1(t)  + c2 sin(t) " << endl;
            cout << "Enter c1 : " << endl;
            cin >> c1;
            cout << "Enter c2 : " << endl;
            cin >> c2;
            cout << endl;
            cout << "Equation => y = c3  + c4 cos(t) " << endl;
            cout << "Enter c3 : " << endl;
            cin >> c3;
            cout << "Enter c4 : " << endl;
            cin >> c4;
            cout << endl;

            for (int i = 0; i < 50; i++)
            {

                x = c1 + ((c2 * t[i]) * sin(t[i]));
                y = c3 + (c4 * cos(t[i]));
                Point p(x, y);
                point[i] = p;
                // Error here
                // In all cases X AND Y results are in double
                // But when it gets stored in point it gets converted to int I DONT understand why
                cout << " X" << i + 1 << " = " << x << endl;
                cout << " Y" << i + 1 << " = " << y << endl;
            }
            break;
        default:
            cout << "Error";
            break;
        }
    }

    friend ostream &operator<<(ostream &out, const ParametricCurve &c)
    {
        for (int i = 0; i < 50; i++)
        {
            out << " ( x , y ) at t = " << c.t[i] << " = "
                << " ( " << c.point[i].getX() << " , " << c.point[i].getY() << " ) " << endl;
        }
    }
};

int main()
{
    ParametricCurve p;
    p.ComputePoints();
    cout << p;
    return 0;
}

/*

    void Calculate_X()
    {
        for (int i = 0; i < 50; i++)
        {
            t[i] = counter;
            counter++;
        }

        cout << "Equation => x = c1  + c2 t " << endl;
        cout << "Enter c1 : " << endl;
        cin >> c1;
        cout << "Enter c2 : " << endl;
        cin >> c2;
        cout << endl;
        for (int i = 0; i < 50; i++)
        {
            x = c1 + (c2 * t[i]);
            cout << " X" << i + 1 << " = " << x << endl;
        }
    }

    void Calculate_Y()
    {
        for (int i = 0; i < 50; i++)
        {
            t[i] = counter;
            counter++;
        }

        cout << "Equation => y = c3  + c4 t " << endl;
        cout << "Enter c3 : " << endl;
        cin >> c3;
        cout << "Enter c4 : " << endl;
        cin >> c4;
        cout << endl;
        for (int i = 0; i < 50; i++)
        {
            y = c1 + (c2 * t[i]);
            cout << " Y" << i + 1 << " = " << x << endl;
        }
    }



          cout << " ( x , y ) = "
                 << " ( " << point[i].getX() << " , " << point[i].getY() << " ) " << endl;



        cout << "Equation => x = c1  + c2 t " << endl;
        cout << "Enter c1 : " << endl;
        cin >> c1;
        cout << "Enter c2 : " << endl;
        cin >> c2;
        cout << endl;
        cout << "Equation => y = c3  + c4 t " << endl;
        cout << "Enter c3 : " << endl;
        cin >> c3;
        cout << "Enter c4 : " << endl;
        cin >> c4;
        cout << endl;
        for (int i = 0; i < 50; i++)
        {

            x = c1 + (c2 * t[i]);
            y = c3 + (c4 * t[i]);
            Point p(x, y);
            point[i] = p;
        }
*/