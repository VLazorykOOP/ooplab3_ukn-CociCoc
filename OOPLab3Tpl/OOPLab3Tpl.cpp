

// OOPLab3Tpl.cpp : Цей файл містить є шаблоном для 
// виконання лаб. роботи №3. 
// Він містинь функцію "main" з якої починається та закінчується виконання програми.
//

#include <iostream>

// Ваші файли загловки 
//
#include "Lab3Expaple.h"
int main()
{
    std::cout << " Lab #3  !\n";
//  Код виконання завдань
//  Головне меню завдань
//  Функції та класи можуть знаходитись в інших файлах проекту

    int conv = 1;
    if (conv == 1) conv = mainExample1();
    if (conv == 1) conv = mainExample3(); 
    if (conv == 1) conv = mainExample4();

}

//task 1

#include <iostream>
#include <math.h>
using namespace std;
class Сircle{

	double height;
    double weight;  // rectangle
	unsigned int color;
public:
	
	Rectangle() : height(1.0), color(0), weight(1.0) {}
	Rectangle(double ai) : height(ai), color(0), weight(bi) {}
	Rectangle(int ic) : height(1.0) { if (ic >= 0) color = ic; else color = 0; }
	Rectangle(double height, double weight, int c) {
		this->height = height;
        this->weight = weight;

		if (c >= 0) color = c; else color = 0;
	}
	double getHeight() const
	{
		
		return height;
	}
	void setHeight(double height)
	{
		if (height < 0 || height > 1.e+100)
		{
			cout << " Error set a \n";
			return;
		}
		this->height = height;
	}
	double getColor() const
	{
		return color;
	}
	void setColor(int c)
	{
		if (c < 0 || c > 10000)
		{
			cout << " Error set color \n";
			return;
		}
		this->color = c;
	}
	double S() {
		return height * weight;
	}
	double P() {
		return 2 * height + weight;
	}
	
	void printInfo()
	{
		cout << "\n Height= " << weight << "\n color = " << color << " weight = " << weight;
		cout << " S= " << S() << " P = " << P() << endl;
	}
};
int main()
{
	cout << "Object created " << endl;
	Rectangle obj;
	obj.printInfo();
	double in_height; int in_color; ; dounle in_weight
	cout << " Input Height and color and Weight Rectangle "; cin >> in_height >> in_color >> in_weight;
	Rectangle obj1(in_height), obj2(in_color), obj3(in_weight), obj4(in_height, in_color, in_weight);
	obj1.printInfo();
	obj2.printInfo();
	obj3.printInfo();
	obj.setHeight(-5);
	obj.printInfo();
	obj.setHeight(5);
	obj.printInfo();
	obj.setHeight(2.e100);
	obj.printInfo();
	obj.setColor(-10);
	obj.printInfo();
	obj.setColor(10);
	obj.printInfo();
	obj.setColor(10001);
	obj.printInfo();
    
    obj.setWeight(-7);
	obj.printInfo();
	obj.setWeight(7);
	obj.printInfo();
	obj.setWeight(2.e100);
	obj.printInfo();
	cout << " End testing \n";
	return 0;
}




//task 2 
#include <iostream>
#include <math.h>
#include <clocale>
using namespace std;
enum STATE {
	OK, BAD_INIT, BAD_DIV
};


class ComplexNumber {
	float re;
	float im;
	int state;


public: 
	ComplexNumber() : re(0), im(0), state(0){}
	ComplexNumber(float iv) : re(iv), im(iv) {}
	ComplexNumber(float* p) {
		if (p == nullptr) {
			state = 4;
			re = 0;
			im = 0;
		}
		else {
			re = p[0];
			im = p[1];
		}
	}

	ComplexNumber(const ComplexNumber&);
	ComplexNumber :: ComplexNumber(const ComplexNumber& s) {
		if (this == &s) return;
		re = s.re; im = s.im;
		count++;
	}

	void Input();
	void Output();
	bool CompLessAll(ComplexNumber& s);
	static int getCount() {
		if (count <= 0) cout << " Немає об'єктів ComplexNumber ";
		return count;
	}
	int getState() { return state; }

};
	void ComplexNumber::Input() {
		cout << "Input re and im: ";
		cin >> im >> re;

	}


	void ComplexNumber::Otput() {
		cout << "re = " << re << "im = " << im << "state = " << state << endl;
	}

	ComplexNumber ComplexNumber::Add(ComplexNumber& s) {
		ComplexNumber tmp;
		tmp.re = re + s.re;
		tmp.im = im + s.im;
		return tmp;
	}

	ComplexNumber ComplexNumber::Sub(ComplexNumber& s) {
		ComplexNumber tmp;
		tmp.re = re - s.re;
		tmp.im = im - s.im;
		return tmp;
	}
	
	ComplexNumber ComplexNumber::Div(double d) {
		ComplexNumber tmp;
		if (fabs(d) < 1.e-25) {
			tmp.state = BAD_DIV;
			cout << " Error div \n";
			return *this;
		}
		tmp.re = re / d;
		tmp.im = im / d;
		return tmp;
	}
	ComplexNumber ComplexNumber::Mul(double d) {
		ComplexNumber tmp;
		tmp.re = re * d;
		tmp.im = im * d;
		return tmp;
	}
	bool ComplexNumber::CompLessAll(ComplexNumber& s) {
		if (re < s.re && im < s.im) return true;
		return false;

	}

int main()
{
   
	setlocale(LC_CTYPE, "ukr");
	cout << "Тестування створенного класу \n";
	cout << "Тестування конструкторiв \n";
	ComplexNumber ObjCDef;
	ObjCDef.Output();
	ComplexNumber ObjP1(10.0);

	ObjP1.Output();
	double a = 1.0, b = 2.0;
	ComplexNumber ObjP2(a, b);
	ObjP2.Output();
	ComplexNumber ObjCopy(ObjP2);
	double* v = nullptr, v2[] = { 1.2, 3.3 };
	ComplexNumber ObjP3(v2);
	if (ObjP3.getState() != OK) cout << " ObjP3 re= 0 im= 0 \n";
	ComplexNumber ObjP4(v2);
	if (ObjP4.getState() != OK) cout << " ObjP4 re= 0 im= 0 \n";
	cout << " Кiлькiсть створених об'єктiв Vec2 " << ComplexNumber::getCount() << endl;
	cout << "Тестування введення \n";
	ObjCDef.Input();
	cout << "Тестування функцiй \n";
	ObjCDef = ObjCDef.Add(ObjP2);
	ObjCDef.Output();
	cout << " \n Кiлькiсть створених об'єктiв ComplexNumber до Sub " << ComplexNumber::getCount() << endl;
	ObjCDef = ObjCDef.Sub(ObjP2);
	cout << " \n Кiлькiсть створених об'єктiв ComplexNumber пiсля Sub " << ComplexNumber::getCount() << endl;
	ObjCDef.Output();
	ObjCDef = ObjCDef.Mul(5);
	ObjCDef.Output();
	ObjCDef = ObjCDef.Div(1.3);
	if (ObjCDef.getState() == STATE::BAD_DIV) cout << "BAD_DIV \n";
	ObjCDef.Output();
	ObjCDef = ObjCDef.Div(0.0);
	if (ObjCDef.getState() == STATE::BAD_DIV) cout << "BAD_DIV \n";
	ObjCDef.Output();
	cout << "ObjCopy state " << ObjCopy.getState() << endl;
	if (ObjCopy.CompLessAll(ObjCDef)) cout << "ObjCopy less ObjDef " << endl;
	cout << "Завершення тестування \n";
	return 1;
}


//task 3
#include <iostream>
using namespace std;

class Vector {
    long* v;
    short size = 2;
public:
    Vector(): Vector(2){}
    Vector(int n) {
        if (n <= 0) size = 2;
        else size = n;
        v = new long[size];
        for (int i = 0; i < size; i++) v[i] = 1;

    }
    void pr() {
        for (int i = 0; i < size; i++) cout << v[i] << "\t";
    }

};

class Matrix {
    Vector* t;
    short size = 2;
public: 
    Matrix(){}
    Matrix(int n) {}
    Matrix(int n, int m){
        if (n <= 2) size = 2;
        size = n;
        t = new Vector[size];
    }
    void mr() {
        for (int i = 0; i < size; i++) { t[i].pr(); cout << endl; }
    }
};

bool Vector::Vector(Vector& size) {
    if (n < size) return true;
    return false;
}

void Vector::Input() {
    if (size == 0) {
        if (v) delete[] v;
        do {
            cout << "Input size Vec\n";
            cin >> size;
        } while (size <= 0);
        v = new Vector[size];
    }
    for (int i = 0; i < num; i++) {
        cout << " v [ " << i << " ] real img "; cin >> v[i] >> v[i]._Val[_IM];
    }

}


Vector Vector::Add(Vector& s) {
    Vector tmp;
    tmp.v = v + s.v;
    return tmp;
}
Vector Vector::Sub(Vector& s) {
    Vector tmp;
    tmp.v = v - s.v;
    return tmp;
}
Vector Vector::Div(double d) {
    Vector tmp;
    if (fabs(d) < 1.e-25) {
        tmp.state = BAD_DIV;
        cout << " Error div \n";
        return *this;
    }
    tmp.v = v / d;
    return tmp;
}
Vector Vector::Mul(double d) {
    Vector tmp;
    tmp.v = v * d;
    return tmp;
}


Vector Vector::Add(Vector& s) {
    Vector tmp;
    tmp.v = v + s.v;
    return tmp;
}

int main()
{
    Matrix a(3, 4);
    a.mr();
    return 0;
}
