#include<iostream>
#include<exception>

class Foo {
private:
	static size_t id_gen;
	size_t id_num;
public:
	Foo() { 
		id_num = ++id_gen;
		std::cout << "Creation an object #" << id_num << '\n';
	}
	~Foo() { std::cout << "Уничтожение объекта #" << id_num << '\n'; }
};
// объявим статическую переменную:
size_t Foo::id_gen = 0;
// объявим глобальную переменную:
Foo g_var;
// объявим глобальный массив из трех объектов класса Foo:
Foo g_array[3]{};


int main() {
	std::cout << "Task 20\n";
	setlocale(LC_ALL, "RU");
	// объявим локальную переменную и массив из двух объектов типа Foo:
	Foo l_var;
	Foo l_array[2];
	// объявим статическую переменную и массив из двух объектов типа Foo:
	static Foo s_var;		// данная переменная уничтожится раньше чем локальные переменная и массив.
	static Foo s_array[2];	// данный массив уничтожится раньше чем локальные переменная и массив.

	try {
		int N;
		std::cout << "Введите размер массива -> ";
		std::cin >> N;
		if (N > 10)
			throw std::length_error("Заданный размер массива слишком большой!");
		if (N < 0)
			throw std::length_error("Заданный размер массива отрицательный!");
		// создадим динамический массив:
		Foo* d_array = new Foo[N];
		// Работа с объектами...
		std::cout << "Работа с объектами класса Foo\n";
		// уничтожение динамич. массива с объектами Foo:
		delete[] d_array;
	}
	catch (std::length_error& exc) {
		std::cout << "Error: " << exc.what() << '\n';
	}

	return 0;
}