#include <string>
#include <vector>
#include "Order.h"
#include "Product.h"
#include <stdexcept>

using namespace std;

unsigned int Order::orderCount{ 0 };

Order::Order() { orderCount++; }

Order::Order(int n, int i, std::vector<Product> p, time_t c) : orderNum(n), custID(i), productNums(p), orderCreationTime(c) { orderCount++; }

Order::~Order() { --orderCount; }

int Order::getOrderNum() { return orderNum; }

void Order::setOrderNum(int n) {
	if (n > 0) {
		orderNum = n;
	}
	else {
		throw invalid_argument(
			"orderNum out of range");
	}
	;
}

int Order::getCustID() { return custID; }

void Order::setCustID(int i) {
	custID = i;
}

vector<Product> Order::getProductNums() { return productNums; }

void Order::setProductNums(std::vector<Product> Products) {
	for (auto prod : Products) {
		productNums.push_back(prod);
	}
}

time_t Order::getOrderCreationTime() { return orderCreationTime; }

void Order::setOrderCreationTime(time_t c) {
	if (c > 0) {
		orderCreationTime = c;
	}
	else {
		throw invalid_argument(
			"orderCreationTime out of range");
	}
	;
}


unsigned int Order::getOrderCount() { return orderCount; }
