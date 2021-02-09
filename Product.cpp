#include <string>
#include <stdexcept>
#include "Product.h"

using namespace std;

unsigned int Product::productCount{ 0 };
Product::Product() { ++productCount; }

Product::Product(int p, std::string n, std::string d, time_t t) : productNum(p), productName(n), productDescription(d), productCreationTime(t) { ++productCount;}

Product::~Product() { --productCount; }

int Product::getProductNum() { return productNum; }

void Product::setProductNum(int p) {
	if (p > 0) {
		productNum = p;
	}
	else {
		throw invalid_argument(
			"orderNum out of range");
	}
	;
}

std::string Product::getProductName() { return productName; }

void Product::setProductName(std::string n) {
	productName = n;
}

std::string Product::getProductDescription() { return productDescription; }

void Product::setProductDescription(std::string d) {
	productDescription = d;
}

time_t Product::getProductCreationTime() { return productCreationTime; }

void Product::setProductCreationTime(time_t t) {
	if (t > 0) {
		productCreationTime = t;
	}
	else {
		throw invalid_argument(
			"orderNum out of range");
	}
	;
}

unsigned int Product::getProductCount() { return productCount; }
