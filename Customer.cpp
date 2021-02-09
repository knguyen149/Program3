#include <string>
#include <vector>
#include "Customer.H"
#include <stdexcept>

using namespace std;

unsigned int Customer::customerCount{ 0 };

Customer::Customer() { ++customerCount; }

Customer::Customer(int c, std::string n, std::string a, std::vector<Order> oN, time_t t) : custID(c), name(n), address(a), orderNums(oN), customerCreationTime(t) { ++customerCount; }

Customer::~Customer() { --customerCount; }

int Customer::getCustID() { return custID; }

void Customer::setCustID(int c) {
		custID = c;
}

string Customer::getName() { return name; }

void Customer::setName(std::string n) {
	name = n;
}

std::string Customer::getAddress() { return address; }

void Customer::setAddress(std::string a) {
	address = a;
}

std::vector<Order> Customer::getOrderNums() { return orderNums; }

void Customer::setOrderNums(std::vector<Order> Orders) {
	for (auto ords : Orders) {
		orderNums.push_back(ords);
	}
}

time_t Customer::getCustomerCreationTime() { return customerCreationTime; }

void Customer::setCustomerCreationTime(time_t t) {
	customerCreationTime = t;
	;
}

unsigned int Customer::getCustomerCount() { return customerCount; }