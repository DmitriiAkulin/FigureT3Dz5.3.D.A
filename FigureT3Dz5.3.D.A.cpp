// FigureT3Dz5.3.D.A

#include <iostream>

using std::cout;
using std::endl;
using std::string;

class Figure {
protected:
    int _side_count;//число сторон
    string  name = "фигура:";

    int a, b, c, d;//длины сторон
    int A, B, C, D;//величины углов

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
    //убраны переменные  в фигуру
    Triangle(int a, int b, int c, int A, int B, int C) {
        this->a = a;
        this->b = b;
        this->c = c;
        this->A = A;
        this->B = B;
        this->C = C;
    }


public:
    Triangle() :Triangle(10, 20, 30, 50, 60, 70) { name = "треугольник:"; _side_count = 3; }//Изменено - тут я ввожу что хочу где цифры...
  
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

///прямоугольный треугольник
class RectangularTriangle : public Triangle {
protected:

    RectangularTriangle(int a, int b, int c, int A, int B) :Triangle() {
        name = "прямоугольный треугольник:";
        //изменено
        this->a = a;
        this->b = b;
        this->c = c;
        this->A = A;
        this->B = B;
        this->C = 90;
    }

public:

    RectangularTriangle() : RectangularTriangle(10, 20, 30, 50, 60) {}//вводим все кроме угла С

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

    IsoscelesTriangle(int a, int b, int A, int B) :Triangle() {
        name = "равнобедренный треугольник:";
        this->a = a;
        this->b = b;
        this->c = a;//изменено
        this->A = A;
        this->B = B;
        this->C = A;//изменено
    }
public:

    IsoscelesTriangle() :IsoscelesTriangle(10, 20, 50, 60) {}//вводим размеры равнобедренного тр-ка без угла С и стороны с

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


    EquilateralTriangle(int a) :Triangle() {
        name = "равноcторонний треугольник:";
        this->a = a;//изменено
        this->b = a;//изменено
        this->c = a;//изменено
        this->A = 60;//изменено
        this->B = A;//изменено
        this->C = A;//изменено
    }

public:
    EquilateralTriangle() :EquilateralTriangle(30) {}

    bool check() override {
        return ((A == B)&&(B == C) && (a == b)&& (b == c) && Triangle::check());
    }

    void print_info() override {
        Triangle::print_info();
    }
};


class Quadrangle : public Figure {
protected:

    Quadrangle(int a, int b, int c, int d, int A, int B, int C, int D) {
        this->a = a;
        this->b = b;
        this->c = c;
        this->d = d;
        this->A = A;
        this->B = B;
        this->C = C;
        this->D = D;
    }
public:

    Quadrangle() :Quadrangle(10, 20, 30, 40, 50, 60, 70, 80) { name = "четырехугольник:"; _side_count = 4; }

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
    Parallelogram(int a, int b, int A, int B) :Quadrangle() {
        name = "параллелограмм:";
        //изменено
        this->a = a;
        this->b = b;
        this->c = a;
        this->d = b;
        this->A = A;
        this->B = B;
        this->C = A;
        this->D = B;
    }
public:
    Parallelogram() : Parallelogram(20, 30, 30, 40) {}

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
    _Rectangle(int a, int b) :Parallelogram() {
        name = "прямоугольник:";
        //изменено
        this->a = a;
        this->b = b;
        this->c = a;
        this->d = b;
        this->A = 90;
        this->B = A;
        this->C = A;
        this->D = A;
    }
public:
    _Rectangle() : _Rectangle(10, 20) {}

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



    _Square(int a) :_Rectangle() {
        name = "квадрат:";
        //изменено 
        this->a = a;
        this->b = a;
        this->c = a;
        this->d = a;
    }
public:
    _Square() : _Square(20) {}

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

    Romb(int a, int A, int B) :Parallelogram() {
        name = "ромб:";
        this->a = a;
        this->b = a;
        this->c = a;
        this->d = a;
        this->A = A;
        this->B = B;
        this->C = A;
        this->D = B;

    }

public:
    Romb() : Romb(30, 30, 40) {}

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

