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
}bus, tram{25,"�������","������ ��������","���"};
template <typename T>
void fill_arr(T arr[], const int length, T begin, T end);
template <typename T>
void show_arr(T arr[], const int length);
template <typename T>
void forwarding(T** ppn, int num1, int num2);
void insert_sym(std::string& str, char sym1, char sym2);
void show_trans(route object);
inline int fare(route object, int num_pers);
int main() {
	setlocale(LC_ALL, "Russian");
	int n, m;
	int* pn = &n;
	//������ 1.������� �� ������������� ��������� , �� ��������� ������
	std::cout << "������ 1\n������� ��� �����: ������ � ������ ���������� ������� -> ";
	try{
		std::cin >> n >> m;
		forwarding(&pn, n, m);
	}
	catch (const std::out_of_range& ex){
		std::cout << "������: " << ex.what() << '\n';
	}
	//������ 2. ������� ������ ������� �� �������� ������ � ������
	std::cout << "\n������ 2.\n������� ������ -> ";
	std::string str;
	char sym1, sym2;
	std::cin.ignore();
	getline(std::cin, str);
	std::cout << "������� ������ ������� ������ �������� -> ";
	std::cin >> sym1;
	std::cout << "������� ������ �� ������� ������ �������� -> ";
	std::cin >> sym2;
	insert_sym(str, sym1, sym2);
	std::cout << "��������� ������: " << str << "\n\n";
	//������ 3. ��������� - ���������
	std::cout << "������ 3.\n";
	bus.number = 32;
	bus._type_trans = "�������";
	bus._trans_stop_begin = "�����";
	bus._trans_stop_end = "�/� ������";
	route trolleybus = { 17,"����������","������� ������","��������� ��������" };
	show_trans(bus);
	show_trans(tram);
	show_trans(trolleybus);
	std::cout << "������� ������� ������� ������ -> ";
	std::cin >> n;
	std::cout << "��������� ������� ��� " << n << " �������, �������� = " << fare(bus, n)<<'\n';

	return 0;
}
//���������� ��������� �� ��������� ������
template <typename T>
void forwarding(T** ppn, int num1, int num2) {
	if (num1 <= 0 || num2 <= 0)
		throw std::out_of_range("������ ������� ������ ���� ��������������!");
	T** arr = new T*[num1];
	for (int i = 0; i < num1; i++)
		arr[i] = new T[num2];
	ppn = arr;
}
//������ ������� � ������
void insert_sym(std::string& str, char sym1, char sym2) {
	for (int i = 0; i < str.length(); i++)
		if (str[i] == sym1)
			str[i] = sym2;
}
//������� ���������� � ������ ���������
void show_trans(route object) {
	std::cout << "����� �������� = " << object.number << '\n';
	std::cout << "��� ���������� = " << object._type_trans << '\n';
	std::cout << "��������� ����������� = " << object._trans_stop_begin << '\n';
	std::cout << "�������� ��������� = " << object._trans_stop_end << '\n';
	std::cout << "��������� ������� = " << object.price_ticket <<'\n' << std::endl;
}
//��������� ��������� ������� �� ������ �����
inline int fare(route object, int num_pers) {
	return object.price_ticket * num_pers;
}
//����� �������
template <typename T>
void show_arr(T arr[], const int length) {
	std::cout << "[";
	for (int i = 0; i < length; i++)
		std::cout << arr[i] << ", ";
	std::cout << "\b\b]\n";
}
//���������� �������
template <typename T>
void fill_arr(T arr[], const int length, T begin, T end) {
	srand(time(NULL));
	for (int i = 0; i < length; i++)
		arr[i] = begin + rand() % (begin - end);
}