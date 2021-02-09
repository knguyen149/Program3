#pragma once
#ifndef ORDER_H
#define ORDER_H

#include <string>
#include <vector>
#include "Customer.h"
#include "Product.h"


class Order
{
	friend class Customer;
	friend class Product;
	friend void outPutReport(std::vector<Order>, std::vector<Customer>, std::vector<Product>);
public:
	Order();
	Order(int, int, std::vector<Product>, time_t);
	~Order();
	int getOrderNum();
	void setOrderNum(int);
	int getCustID();
	void setCustID(int);
	std::vector<Product> getProductNums();
	void setProductNums(std::vector<Product>);
	time_t getOrderCreationTime();
	void setOrderCreationTime(time_t);
	static unsigned int getOrderCount();

private:
	int orderNum{ 0 };
	int custID{ 0 };
	std::vector<Product> productNums;
	time_t orderCreationTime{ 0 };
	static unsigned int orderCount;	
};

#endif // ORDER_H