#pragma warning(disable : 4996)
#include<iostream>
#include<string>
#include<vector>
#include<array>
#include "Order.h"
#include "Product.h"
#include "Customer.h"
using namespace std;

void getTime(int&, int&);
void outPutReport(vector<Order>, vector<Customer>, vector<Product>);

int main() {
	cout << "This proram simulates simple product ordering system. \n \n" << "It provides the functionality to allow you to create new customers, new products, and new orders. \n \n";
	cout << "Customer will have orders. Order will have product. \n \n";
	cout << "To get started, let's create some products to be included in an order. \n \n";
	cout << "Product info entails # of specific products, its name, its description, and the time the product is created. \n \n";
	std::string pName, pDescription;
	string cName, cAddress;
	int pNum, productObjNum{ 0 }, orderObjNum{ 0 }, customerObjNum{ 0 };
	int oNum, cID{ 0 }, productsNum, j, ordersNum, ccID;
	cout << "Please enter how many products you would like to create: \n \n";
	cin >> productObjNum;
	vector<Product> Products(productObjNum);
	for (int i = 0; i < productObjNum; i++) {
		cout << "Please enter how many products there are for Product " << i+1 << " : \n \n";
		cin >> pNum;
		Products[i].setProductNum(pNum);
		cout << "Please enter the product name: \n \n";
		cin >> pName;
		Products[i].setProductName(pName);
		cout << "Please enter the product description: \n\n";
		cin >> ws;
		getline(cin, pDescription);
		Products[i].setProductDescription(pDescription);
		Products[i].setProductCreationTime(time(0));
		cout << "Identifying number for this product: " << i << "\n \n";
	}
	cout << "\n \nProducts info obtained. \n \n";
	cout << "Order info entails order number, customter ID, list of products in the order, and the time the order is created . \n \n";
	cout << "Please enter how many orders you would like to create: \n \n";
	cin >> orderObjNum;
	vector<Order> Orders(orderObjNum);
	for (int i = 0; i < orderObjNum; i++) {
		cout << "Please enter how many orders there are for Order " << i + 1 << " : \n \n";
		cin >> oNum;
		Orders[i].setOrderNum(oNum);
		cout << "Please enter the customer ID: \n \n";
		cin >> cID;
		Orders[i].setCustID(cID);
		cout << "Please enter how many products there are in this order: \n\n";
		cin >> productsNum;
		vector<Product> productNames(productsNum);
		cout << "Please enter the identifying number for the products in this order. \n\n";
		cin >> j;
		productNames.push_back(Products[j]);
		bool cont = true;
		string selection;
		while (cont)
		{
			cout << "Would you like to enter another identifying number for products in this order. \n\n";
			cin >> selection;
			if (selection != "y")
				break;
			cout << "Please enter the identifying number for the products in this order. \n\n";
			cin >> j;
			productNames.push_back(Products[j]);
		}
		Orders[i].setProductNums(productNames);
		Orders[i].setOrderCreationTime(time(0));
		cout << "Identifying number for this order: " << i << "\n \n";
	}
	cout << "\n\n Orders info obtained. \n\n";
	cout << "Customer info entails customer ID, name, address, list of orders from the customer, and the time the customer is created. \n \n";
	cout << "Please enter how many customers you would like to create: \n \n";
	cin >> customerObjNum;
	vector<Customer> Customers(customerObjNum);
	for (int i = 0; i < customerObjNum; i++) {
		cout << "Please enter customer ID: \n\n";
		cin >> ccID;
		Customers[i].setCustID(ccID);
		cout << "Please enter customer name: \n\n";
		cin >> ws;
		getline(cin, cName);
		Customers[i].setName(cName);
		cout << "Please enter customer address: \n\n";
		cin >> ws;
		getline(cin, cAddress);
		Customers[i].setAddress(cAddress);
		cout << "Please enter how many orders there are for this customer: \n\n";
		cin >> ordersNum;
		vector<Order> orderList(ordersNum);
		cout << "Please enter the identifying order number for the orders for this customer. \n\n";
		cin >> j;
		orderList.push_back(Orders[j]);
		bool cont = true;
		string selection;
		while (cont)
		{
			cout << "Would you like to enter another identifying number for orders for this customer. \n\n";
			cin >> selection;
			if (selection != "y")
				break;
			cout << "Please enter the identifying number for the orders for this customer. \n\n";
			cin >> j;
			orderList.push_back(Orders[j]);
		}
		Customers[i].setOrderNums(orderList);
		Customers[i].setCustomerCreationTime(time(0));
	}
	int countCustomer = Customers[0].getCustomerCount();
	int countOrder = Orders[0].getOrderCount();
	int countProduct = Products[0].getProductCount();
	cout << "Here->" << countCustomer << countOrder << countProduct;
	outPutReport(Orders,Customers, Products);
	return 0;


}
// I was unsure how to implement this one...
//definition is from example
//I understand how to use it, but I don't know how it would fit into this program
void getTime(int& month, int& year)
{
	time_t now = time(0);
	tm* tm_ptr = localtime(&now);
	month = tm_ptr->tm_mon;
	year = tm_ptr->tm_year + 1900;
}

void outPutReport(vector<Order> o, vector<Customer> c, vector<Product> p) {
	for (Customer customers : c) {
		cout << "Customer ID: " << customers.getCustID();
		cout << "\t Customer Name: " << customers.getName();
		cout << "\t Customer Address: " << customers.getAddress();
		cout << "\t Customer Creation Time: " << customers.getCustomerCreationTime();
		cout << "\t Customer Count: " << customers.getCustomerCount() << endl;
	}
	for (Order orders : o) {
		cout << "Order Num: " << orders.getOrderNum();
		cout << "\t Customer ID: " << orders.getCustID();
		cout << "\t Order Creation Time: " << orders.getOrderCreationTime();
		cout << "\t Order Count: " << orders.getOrderCount() << endl; //not working
	}
	for (Product products : p) {
		cout << "Product Num: " << products.getProductNum();
		cout << "\tProduct Name: " << products.getProductName();
		cout << "\tProduct Description: " << products.getProductDescription();
		cout << "\tProduct Creation Time: " << products.getProductCreationTime();
		cout << "\tProduct Count: " << products.getProductCount() << endl;
	}


}
