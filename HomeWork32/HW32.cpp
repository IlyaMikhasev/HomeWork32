#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>
struct route {
	int number = 0;
	std::string _type_trans;
	std::string _trans_stop_begin;
	std::string _trans_stop_end;
	int price_ticket = 18;
}bus, tram{25,"трамвай","Дворец молодежи","ЖБИ"};
template <typename T>
void delArr(T**& arr, int num1, int num2);
template <typename T>
void FillArr(T**& arr, int num1, int num2, int begin, int end);
template <typename T>
void show_arr(T** &arr,int num1,int num2);
template <typename T>
void forwarding(T** &ppn, int num1, int num2);
void insert_sym(std::string& str, char sym1, char sym2);
void show_trans(route &object);
inline int fare(route &object, int num_pers);
int main() {
	setlocale(LC_ALL, "Russian");
	int n, m;
	int** Arr = nullptr;
	//задача 1.функция на переадресовку указателя , на двумерный массив
	std::cout << "Задача 1\nВведите два числа: высоту и длинну двумерного массива -> ";
	try{
		std::cin >> n >> m; 
		forwarding(Arr, n, m);
		FillArr(Arr, n, m, 10, 50);		
		show_arr(Arr, n, m);
		delArr(Arr, n, m);
	}
	catch (const std::out_of_range& ex){
		std::cout << "Ошибка: " << ex.what() << '\n';
	}
	//Задача 2. Функция меняет искомый на заданный символ в строке
	std::cout << "\nЗадача 2.\nВведите строку -> ";
	std::string str;
	char sym1, sym2;
	std::cin.ignore();
	getline(std::cin, str);
	std::cout << "Введите символ который хотите заменить -> ";
	std::cin >> sym1;
	std::cout << "Введите символ на который хотите заменить -> ";
	std::cin >> sym2;
	insert_sym(str, sym1, sym2);
	std::cout << "Измененая строка: " << str << "\n\n";
	//Задача 3. Структура - транспорт
	std::cout << "Задача 3.\n";
	bus.number = 32;
	bus._type_trans = "Автобус";
	bus._trans_stop_begin = "ЦПКиО";
	bus._trans_stop_end = "Ж/Д вокзал";
	route trolleybus = { 17,"Троллейбус","Площадь победы","Городское кладбище" };
	show_trans(bus);
	show_trans(tram);
	show_trans(trolleybus);
	std::cout << "Введите сколько человек поедет -> ";
	std::cin >> n;
	std::cout << "Стоимость проезда для " << n << " человек, составит = " << fare(bus, n)<<'\n';

	return 0;
}
//направляет указатель на двумерный массив

template <typename T>
void forwarding(T** &arr, int num1, int num2) {
	if (num1 <= 0 || num2 <= 0)
		throw std::out_of_range("Длинны массива должны быть положительными!");
	arr = new T*[num1];
	for (int i = 0; i < num1; i++)
		arr[i] = new T[num2];
}
template <typename T>
void delArr(T**& arr, int num1, int num2) {	
	for (int i = 0; i < num1; i++)
		delete[] arr[i];
	delete[] arr;
}
//Меняет символы в строке
void insert_sym(std::string& str, char sym1, char sym2) {
	for (int i = 0; i < str.length(); i++)
		if (str[i] == sym1)
			str[i] = sym2;
}
//выводит информацию о объкте структуры
void show_trans(route &object) {
	std::cout << "Номер маршрута = " << object.number << '\n';
	std::cout << "Вид транспорта = " << object._type_trans << '\n';
	std::cout << "Остановка отправления = " << object._trans_stop_begin << '\n';
	std::cout << "Конечная остановка = " << object._trans_stop_end << '\n';
	std::cout << "Стоимость проезда = " << object.price_ticket <<'\n' << std::endl;
}
//вычислает стоимость проезда на группу людей
inline int fare(route &object, int num_pers) {
	return object.price_ticket * num_pers;
}
//вывод массива
template <typename T>
void show_arr(T** &arr,int num1,int num2) {
	for (int i = 0; i < num1; i++) {
		std::cout << "[";
		for (int j = 0; j < num2; j++)
			std::cout << arr[i][j] << ", ";
		std::cout << "\b\b]\n";
	}
	std::cout << "\n";
}
//заполнение массива
template <typename T>
void FillArr(T** &arr,int num1,int num2, int begin, int end)
{
	srand(time(NULL));
	for (int i = 0; i < num1; i++)
		for (int j = 0; j < num2; j++)
			arr[i][j] =begin+ rand() % (end-begin);
}