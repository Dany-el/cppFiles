#include "TV.h"
#include <iostream>

using std::cout;
using std::cin;

// Getters

/**
 * @brief Getter Country
 * 
 * @return string* 
 */
string* TV::getCountry()
{
	return country;
}

/**
 * @brief Getter Model
 * 
 * @return string* 
 */
string* TV::getModel()
{
	return model;
}

/**
 * @brief Getter Price
 * 
 * @return double 
 */
double TV::getPrice()
{
	return price;
}

// Setters

/**
 * @brief Set name of Country
 * 
 * @param p_country - user name of country
 */
void TV::setCountry(const string p_country)
{
	delete country;
	country = new string(p_country);
}

/**
 * @brief Set name of Model
 * 
 * @param p_model - user name of model
 */
void TV::setModel(const string p_model)
{
	delete model;
	model = new string(p_model);
}

/**
 * @brief Set price of TV
 * 
 * @param p_price - user price of TV
 */
void TV::setPrice(const double p_price)
{
	price = p_price;
}

/**
 * @brief Construct a new TV::TV object
 * 
 */
TV::TV()
{
	count++;
	country = new string();
	model = new string();
	price = 0;
}

/**
 * @brief Construct a new TV::TV object
 * 
 * @param p_country - user name of country
 * @param p_model   - user name of model
 * @param p_price   - user price of TV
 */
TV::TV(const string p_country, const string p_model, const double p_price)
{
	count++;
	country = new string(p_country);
	model = new string(p_model);
	price = p_price;
}

/**
 * @brief Construct a new TV::TV object
 * To copy from one project to another 
 * 
 * @param tmp - temporary oject
 */
TV::TV(const TV& tmp){
	count++;
	country = new string(*tmp.country);
	model = new string(*tmp.model);
	price = tmp.price;
}

/**
 * @brief Print amount of existing objects
 * 
 */
void TV::PrintCount()
{
	cout << "\nCount: " << count << '\n';
}

/**
 * @brief Print info about TV
 * 
 */
void TV::Print()
{
	cout << "\n---Print---\n";
	cout << "Country: " << *country << '\n';
	cout << "Model: " << *model << '\n';
	cout << "Price: " << price << '\n';
}

/**
 * @brief Input info about TV
 * 
 */
void TV::Input()
{
	cout << "\n---Input---\n";
	// Country
	string p_country;
	cout << "Country: ";
	cin >> p_country;
	delete country;
	country = new string(p_country);
	// Model
	string p_model;
	cout << "Model: ";
	cin >> p_model;
	delete model;
	model = new string(p_model);
	// Price
	cout << "Price: ";
	cin >> price;
}

/**
 * @brief Destroy the TV::TV object
 * 
 */
TV::~TV()
{
	count--;
	delete country;
	delete model;
}
