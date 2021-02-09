#pragma once
#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <string>
#include <vector>
#include "Order.h"

class Customer
{
	friend class Order;
	friend class Product;
	friend void outPutReport(std::vector<Order>, std::vector<Customer>, std::vector<Product>);
public:
	Customer();
	Customer(int, std::string, std::string, std::vector<Order>, time_t);
	~Customer();
	int getCustID();
	void setCustID(int);
	std::string getName();
	void setName(std::string);
	std::string getAddress();
	void setAddress(std::string);
	std::vector<Order> getOrderNums();
	void setOrderNums(std::vector<Order>);
	time_t getCustomerCreationTime();
	void setCustomerCreationTime(time_t);
	static unsigned int getCustomerCount();

private:
	int custID{ 0 };
	std::string name;
	std::string address;
	std::vector<Order> orderNums;
	time_t customerCreationTime{ 0 };
	static unsigned int customerCount;
};

#endif // !CUSTOMER_H