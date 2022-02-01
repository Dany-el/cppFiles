#pragma once
#include <string>
using std::string;

class TV
{
	// Country
	string* country;
	// Model
	string* model;
	// Price
	double price;
	// Existing objects
	static int count; 
public:
	string* getCountry();
	string* getModel();
	double getPrice();

	void setCountry(const string p_country);
	void setModel(const string p_model);
	void setPrice(const double p_price);

	TV();
	TV(const string p_country, const string p_model, const double p_price);
	TV(const TV& tmp);

	static void PrintCount();

	void Print();
	void Input();

	~TV();
};

