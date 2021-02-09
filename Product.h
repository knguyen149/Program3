#pragma once
#ifndef PRODUCT_H
#define PRODUCT_H

#include <string>
#include <vector>


class Product
{
	friend class Customer;
	friend class Order;
	friend void outPutReport(std::vector<Order>, std::vector<Customer>, std::vector<Product>);
public:
	Product();
	Product(int, std::string, std::string, time_t);
	~Product();
	int getProductNum();
	void setProductNum(int);
	std::string getProductName();
	void setProductName(std::string);
	std::string getProductDescription();
	void setProductDescription(std::string);
	time_t getProductCreationTime();
	void setProductCreationTime(time_t);
	unsigned static int getProductCount();
private:
	int productNum{ 0 };
	std::string productName;
	std::string productDescription;
	time_t productCreationTime{ 0 };
	unsigned static int productCount;
};

#endif // PRODUCT_H