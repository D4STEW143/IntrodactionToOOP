#include<iostream>

using namespace std;

class Point	//Cтруктура которая будет описывать точки на плоскости.
{
	double x;
	double y;
public:
	double get_x()const
	{
		return x;
	}
	double get_y()const
	{
		return y;
	}
	void set_x(double x)
	{
		this->x = x;
	}
	void set_y(double y)
	{
		this->y = y;
	}
	//Methods
	double distance(Point other)
	{
		double x_distance = this->x - other.x;
		double y_distance = this->y - other.y;
		double distance = sqrt(x_distance * x_distance + y_distance * y_distance);
		return distance;
	}
};

double Distance(Point A, Point B);


//#define STRUCT_POINT

void main()
{
	setlocale(LC_ALL, "");
#ifdef STRUCT_POINT
	int a; // Объявление переменной а типа инт 
	Point A; //Объявление переменной А типа Поинт
	//Создание объекта A структуры Point 
	//Создание экземпляра структуры Point 
	A.x = 2;
	A.y = 3;
	cout << A.x << "\t" << A.y << endl;

	Point* pA = &A;
	cout << (*pA).x << "\t" << (*pA).y << endl;
	cout << pA->x << "\t" << pA->y << endl;
#endif // STRUCT_POINT
	int cor_xA, cor_yA, cor_xB, cor_yB;
	cout << "Укажите координаты точки А. Координата Х: ";
	cin >> cor_xA;
	cout << "Координата Y: ";
	cin >> cor_yA;
	cout << "Укажите координаты точки B. Координата Х: ";
	cin >> cor_xB;
	cout << "Координата Y: ";
	cin >> cor_yB;

	Point A, B;
	A.set_x(cor_xA);
	A.set_y(cor_yA);
	B.set_x(cor_xB);
	B.set_y(cor_yB);

	cout << A.get_x() << "\t" << A.get_y() << endl;
	cout << B.get_x() << "\t" << B.get_y() << endl;

	cout << "Расстояние от точки А до точки В: " << A.distance(B) << endl;
	cout << "Расстояние от точки А до точки В: " << B.distance(A) << endl;
	cout << "Расстояние между точками А и В: " << Distance(A, B) << endl;
	cout << "Расстояние между точками В и А: " << Distance(A, B) << endl;
}

double Distance(Point A, Point B)
{
	double x_distance = A.get_x() - B.get_x();
	double y_distance = A.get_y() - B.get_y();
	double distance = sqrt(x_distance * x_distance + y_distance * y_distance);
	return distance;
}