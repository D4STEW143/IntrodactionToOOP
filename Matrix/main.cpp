#include<iostream>

using namespace std;

#define Delimetr "-----------------"

class Matrix
{
	double **matrix;
	int height, width;
	
	
public:
	void set_height(int height)
	{
		this->height = height;
	}
	void set_width(int width)
	{
		this->width = width;
	}
	int get_height()const
	{
		return height;
	}
	int get_width()const
	{
		return width;
	}
	//Constructors
	Matrix()
	{
		int h, w;
		cout << "Введите количество элементов по вертикали: "; cin >> h;
		set_height(h);
		cout << "Введите количество элементов по вертикали: "; cin >> w;
		set_width(w);
		
		matrix = new double*[get_height()];
		for (int i = 0; i < get_height(); i++)
		{
			matrix[i] = new double [get_width()] {};
		}
		
		cout << "Объект по адресу " << this << " создан стандартным конструктором." << endl;
	}
	Matrix(int Size)
	{
		set_height(Size);
		set_width(Size);
	
		matrix = new double* [get_height()];
		for (int i = 0; i < get_height(); i++)
		{
			matrix[i] = new double [get_width()] {};
		}
		cout << "Объект по адресу " << this << " создан c 1 параметром." << endl;
	}
	Matrix(int height, int width)
	{
		set_height(height);
		set_width(width);
		
		matrix = new double* [get_height()];
		for (int i = 0; i < get_height(); i++)
		{
			matrix[i] = new double [get_width()] {};
		}
		cout << "Объект по адресу " << this << " создан c 2 параметрами." << endl;

	}
	Matrix(const Matrix& other)
	{
		for (int i = 0; i < get_height(); i++)
		{
			for (int j = 0; j < get_width(); j++)
			{
				this->matrix[i][j] = other.matrix[i][j];
			}
		}
		cout << "Объект по адресу " << this << " скопирован конструктором." << endl;
	}
	~Matrix()
	{
		for (int i = 0; i < get_height(); i++)
		{
			delete[] matrix[i];
		}
		delete[] matrix;
		cout << "Объект по адресу " << this << " уничтожен." << endl;;
	}
	//Operators
	Matrix& operator=(const Matrix& other)
	{
		for (int i = 0; i < get_height(); i++)
		{
			for (int j = 0; j < get_width(); j++)
			{
				this->matrix[i][j] = other.matrix[i][j];
			}
		}
		cout << "Объект по адресу " << this << " скопирован методом." << endl;
		return *this;
	}
	//Metods
	void print()
	{
		for (int i = 0; i < get_height(); i++)
		{
			for (int j = 0; j < get_width(); j++)
			{
				cout << matrix[i][j] << "\t";
			}
			cout << endl;
		}
		/*for (int i = 0; i < get_height(); i++)
		{
			for (int j = 0; j < get_width(); j++)
			{
				cout.width(4);
				cout << matrix[i][j];
			}
			cout << endl;
		}*/
	}
	void random(int minRand = 1, int maxRand = 10)
	{
		for (int i = 0; i < get_height(); i++)
		{
			for (int j = 0; j < get_width(); j++)
			{
				matrix[i][j] = minRand + rand() % (maxRand - minRand);
			}
		}
	}
};

Matrix operator+(Matrix left, Matrix right)
{
	return 0;
	/*int temp_h, temp_w;
	if (left.get_height() == right.get_height() || left.get_width() == right.get_width())
		{
			int temp_h = left.get_height();
			int temp_w = left.get_width();
		}
		Matrix temp_m(temp_h, temp_w);
		for (int i = 0; i < temp_h; i++)
		{
			for (int j = 0; j < temp_w; j++)
			{
				temp_m[i][j] = left[i][j]+right[i][j];
			}
		}
	else
	{
		cout << "Матрицы не равны." << endl;
		exit;
	}*/
}

void main()
{
	setlocale(LC_ALL, "");
	Matrix A;
	A.random();
	A.print();
	cout << Delimetr << endl;
	Matrix B(5);
	B.print();
	cout << Delimetr << endl;
	Matrix C(2, 2);
	C.random();
	C.print();
	cout << Delimetr << endl;
	Matrix D(2, 2);
	D = C;
	D.print();
	cout << Delimetr << endl;
	Matrix E = C; //Видимо тоже не работает правильно.
	E.print(); //???????????Почему-то не печатает. 
	cout << Delimetr << endl;

}