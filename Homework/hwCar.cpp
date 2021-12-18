#include <iostream>

// ������� �����
// - "������"
class Car {
	// ������
	char* model;
	// ������
	char* country;
	// ���
	int year;
	// ����
	double price;
public:
	// ���������
	// �������
	char* getModel() {
		return model;
	}
	char* getCountry() {
		return country;
	}
	int getYear() {
		return year;
	}
	double getPrice() {
		return price;
	}
	// �������
	// �������������� ������
	void setModel(const char* model_p) {
		if (model != nullptr) {
			delete[] model;
		}
		model = new char[strlen(model_p) + 1];
		strcpy_s(model, strlen(model_p) + 1, model_p);
	}
	// �������������� ������
	void setCountry(const char* country_p) {
		if (country != nullptr) {
			delete[] country;
		}
		country = new char[strlen(country_p) + 1];
		strcpy_s(country, strlen(country_p) + 1, country_p);
	}
	// �������������� ���
	void setYear(int year_p) {
		year = year_p;
	}
	// �������������� ����
	void setPrice(int price_p) {
		price = price_p;
	}
	// ����������� �� ���������
	// ��������������
	Car() {
		model = nullptr;
		country = nullptr;
		year = 0;
		price = 0;
	}
	/*
	����������� � �����������(����������)

	@param model_p   - ������, ������ ������������
	@param country_p - ������, ������ ������������
	@param year_p	 - ���, ������ ������������
	@param price_p	 - ����, ������ ������������
	*/
	Car(const char* model_p, const char* country_p, int year_p, double price_p) {
		// ����������� � ������ ���. ����� + 1
		// ��� ��� � ��������� ������ ����� '\0'
		model = new char[strlen(model_p) + 1];
		strcpy_s(model, strlen(model_p) + 1, model_p);
		// ����������� � ������ ���. ����� + 1
		// ��� ��� � ��������� ������ ����� '\0'
		country = new char[strlen(country_p) + 1];
		strcpy_s(country, strlen(country_p) + 1, country_p);
		// �������������� ���
		year = year_p;
		// �������������� ����
		price = price_p;
	}

	/*
	����� ������
	*/
	void Print_car() {
		std::cout << "\nCar: " << model << "\nCountry: " << country;
		std::cout << "\nYear: " << year << "\nPrice: " << price;
		std::cout << std::endl;
	}
	// ��������
	// �������������
	~Car() {
		delete[] model;
		delete[] country;
	}
};

int main() {
	Car* tmp = new Car("Mazda", "Ukraine", 2021, 300.001);
	tmp->Print_car();

	tmp->setModel("Vaz");
	tmp->setCountry("Germany");
	tmp->setPrice(3);
	tmp->setYear(3001);
	tmp->Print_car();
	
	std::cout << std::endl;

	char* str = new char[30];
	std::cout << "Model: ";
	gets_s(str, 30);
	tmp->setModel(str);
	std::cout << "Country: ";
	gets_s(str, 30);
	tmp->setCountry(str);
	int year = 0;
	std::cout << "Year: ";
	std::cin >> year;
	tmp->setYear(year);
	double price = 0;
	std::cout << "Price: ";
	std::cin >> price;
	tmp->setPrice(price);
	tmp->Print_car();

	delete tmp;
	delete[] str;
	return 0;
}