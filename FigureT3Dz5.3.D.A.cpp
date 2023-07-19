// FigureT3Dz5.3.D.A

#include <iostream>

using std::cout;
using std::endl;
using std::string;

class Figure {
protected:
    int _side_count;//число сторон
    string  name = "фигура:";

    Figure(int _side_count) : _side_count(_side_count) {}//конструктор с параметром

public:
    Figure() :Figure(0) {}//конструктор
    int get_sides_count() { return _side_count; }//метод для доступа к полю _side_count      
    string get_name() { return name; }//метод для доступа к полю name
    string correct;

    virtual bool check() {
      return (_side_count == 0);
    }
    
    virtual void print_info() {
        if (check() == true) correct = "правильная"; else correct = "неправильная";
        cout << name << endl << correct << endl << "количество сторон: " << _side_count << endl;
    }
};

//треугольник
class Triangle : public Figure {
protected:
    int a, b, c;//длины сторон
    int A, B, C;//величины углов     
    Triangle(int a, int b, int c, int A, int B, int C) : a(a), b(b), c(c), A(A), B(B), C(C)
    {}

public:
    Triangle() :Triangle(a = 10, b = 20, c = 30, A = 50, B = 60, C = 70) { name = "треугольник:"; _side_count = 3; }
  
    bool check() {
        return (((A+B+C) == 180)&&_side_count == 3);
    }

    void print_info() override {
        cout << endl;
        Figure::print_info();
        cout << "Стороны: " << "а=" << a << " b=" << b << " c="
            << c << endl << "Углы:    " << "A=" << A << " B=" << B << " C=" << C
            << endl << endl;
    }
};

//прямоугольный треугольник
class RectangularTriangle : public Triangle {
protected:
    const int C_ = C = 90;
    RectangularTriangle(int a, int b, int c, int A, int B) :Triangle() { name = "прямоугольный треугольник:"; }

public:

    RectangularTriangle() : RectangularTriangle(a, b, c, A, B) {}

    bool check() override { 
        return ((C == 90) && Triangle::check());
    }

    void print_info() override {
        Triangle::print_info();
    }
};

//Равнобедренный треугольник
class IsoscelesTriangle : public Triangle {
protected:
    const int Side = c = a;
    const int Angle = C = A;

    IsoscelesTriangle(int a, int b, int A, int B) :Triangle() {
        name = "равнобедренный треугольник:";
    }

public:
    IsoscelesTriangle() :IsoscelesTriangle(a, b, A, B) {}

    bool check() override {
        return ((A == C)&&(a == c)&& Triangle::check());
    }

    void print_info() override {
        Triangle::print_info();
    }
};

//Равносторонний треугольник
class EquilateralTriangle : public Triangle {
protected:
    const int Side = c = b = a = 30;
    const int Angle = C = B = A = 60;

    EquilateralTriangle(int a) :Triangle() {
        name = "равноcторонний треугольник:";
    }

public:
    EquilateralTriangle() :EquilateralTriangle(a) {}

    bool check() override {
        return ((A == B)&&(B == C) && (a == b)&& (b == c) && Triangle::check());
    }

    void print_info() override {
        Triangle::print_info();
    }
};


//четырехугольник
class Quadrangle : public Figure {
protected:
    int a, b, c, d;//длины сторон
    int A, B, C, D;//величины углов

    Quadrangle(int _a, int _b, int _c, int _d, int _A, int _B, int _C, int _D) : a(_a), b(_b), c(_c), d(_d), A(_A), B(_B), C(_C),
        D(_D)
    {}
public:

    Quadrangle() :Quadrangle(a = 10, b = 20, c = 30, d = 40, A = 50, B = 60, C = 70, D = 80)
                         {   name = "четырехугольник:"; _side_count = 4; }

    bool check() {
        return (((A + B + C + D) == 360) && _side_count == 4);
    }

    void print_info() override {
        cout << endl;
        Figure::print_info();
        cout << "Стороны: " << "а=" << a << " b=" << b << " c="
            << c << " d=" << d << endl << "Углы:    " << "A=" << A << " B=" << B << " C=" << C << " D=" << D
            << endl << endl;
    }    
};

//  параллелограмм
class Parallelogram : public Quadrangle {
protected:
    const int a_c = c = a = 20;
    const int b_d = d = b = 30;
    const int A_C = C = A = 30;
    const int B_D = D = B = 40;

    Parallelogram(int a, int b, int A, int B) :Quadrangle() { name = "параллелограмм:"; }
public:
    Parallelogram() : Parallelogram(a_c, b_d, A_C, B_D) {}

    bool check() override {
        return ((A == C) && (B == D) && (b == d) && (a == c) && Quadrangle::check());
    }

    void print_info() override {
        Quadrangle::print_info();
    }
};

// прямоугольник
class _Rectangle : public Parallelogram {
protected:
    const int Angle = A = B = C = D = 90;
    const int a_c = c = a = 10;
    const int b_d = d = b = 20;
    _Rectangle(int a, int b, int A) :Parallelogram() {
        name = "прямоугольник:";
    }

public:
    _Rectangle() : _Rectangle(a_c, b_d, Angle) {}

    bool check() override {
        return ((A == B) && Parallelogram::check());
    }

    void print_info() override {
        Quadrangle::print_info();
    }
};

//квадрат
class _Square : public _Rectangle {
protected:
    const int Side = d = c = b = a = 20;
    const int Angle = A = B = C = D = 90;


    _Square(int a, int A) :_Rectangle() { name = "квадрат:"; }

public:
    _Square() : _Square(Side, Angle) {}

    bool check() override {
        return ((a == b) && _Rectangle::check());
    }

    void print_info() override {
        Quadrangle::print_info();
    }
};

//ромб
class Romb : public Parallelogram {
protected:
    const int Side = d = c = b = a = 30;
    const int A_C = C = A = 30;
    const int B_D = D = B = 40;

    Romb(int a, int A, int B) :Parallelogram() { name = "ромб:"; }

public:
    Romb() : Romb(Side, A_C, B_D) {}

    bool check() override {
        return ((a == b) && Parallelogram::check());
    }

    void print_info() override {
        Quadrangle::print_info();
    }
};

int main()
{
    setlocale(LC_ALL, "rus");

    Figure figure; 
    Figure *pointer_t;
    figure.print_info();
    // треугольники
    Triangle triangle;    pointer_t = &triangle;    pointer_t->print_info();
    RectangularTriangle rec_triangle; pointer_t = &rec_triangle; pointer_t->print_info();    
    IsoscelesTriangle iso_triangle; pointer_t = &iso_triangle; pointer_t->print_info();
    EquilateralTriangle equi_triangle; pointer_t = &equi_triangle; pointer_t->print_info();

    //четырехугольники
    Quadrangle quadrangle; pointer_t = &quadrangle; pointer_t->print_info();
    _Rectangle rectangle; pointer_t = &rectangle; pointer_t->print_info();
    _Square squar; pointer_t = &squar; pointer_t->print_info();
    Parallelogram parall; pointer_t = &parall; pointer_t->print_info();
    Romb romb; pointer_t = &romb; pointer_t->print_info();
    
    return 0;
}

