//  Retail_Assistant.cpp
//  Retail Sales Assistant Program
//  Programmer: Santiago Benitez
//  Date: September 29, 2019
//  Description:  This program calculates sales tax for a series of products.

#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
	double cashDrawer = 100.00;
	int productID = 0;
	int quantity = 0;
	double price = 0.0;
	double subtotal = 0.0;
	double salesTax = 0.0;
	double totalSale = 0.0;
	double taxRate = 0.0;
	int anotherSale = 0;

	// Loop for repeat sales
	do
	{

	// Enter the first Product ID for the first sale (-1 to exit)
	cout << endl << "Enter the first Product ID (Enter -1 to finish sale): ";
	cin >> productID;

	// Main loop for each sale
	while (productID != -1)
	{
		// Enter the quantity
		cout << "Enter the quantity: ";
		cin >> quantity;

		// Switch statement to determine the price, and calculate sales tax, if any, for the item.
		switch (productID)
		{
		case 101:
			price = 3.95;
			taxRate = 0.0;
			break;
		case 102:
			price = 1.85;
			taxRate = 0.075;
			break;
		case 103:
			price = 2.49;
			taxRate = 0.075;
			break;
		case 104:
			price = 5.19;
			taxRate = 0.075;
			break;
		case 105:
			price = 4.99;
			taxRate = 0.0;
			break;
		case 106:
			price = 3.25;
			taxRate = 0.075;
			break;
		case 107:
			price = 4.85;
			taxRate = 0.0;
			break;
		case 108:
			price = 3.99;
			taxRate = 0.075;
			break;
		case 109:
			price = 1.99;
			taxRate = 0.0;
			break;
		case 110:
			price = 5.25;
			taxRate = 0.075;
			break;

		default:
			cout << "ERROR: Product ID must be between 101 and 110." << endl;
			price = 0.0;
			quantity = 0;
		}

		// Add to subtotal and sales tax
		subtotal += quantity * price;
		salesTax += taxRate * quantity * price;

		// Get next Product ID
		cout << "Enter the next Product ID (Enter -1 to finish sale): ";
		cin >> productID;

	} // End main loop for this sale

	totalSale = subtotal + salesTax; // Add the subtotal and sales tax to get total sale

	// Print properly formatted receipt (Subtotal, Tax, Total Sale) for each sale
	cout << endl << "  Subtotal: $ " << fixed << setw(8) << setprecision(2) << subtotal << endl;
	cout << " Sales Tax: $ " << setw(8) << setprecision(2) << salesTax << endl;
	cout << "Total Sale: $ " << setw(8) << setprecision(2) << totalSale << endl << endl;

	// Add total sale to the cashdrawer
	cashDrawer += totalSale;

	// Reset for next sale
	subtotal = 0.0;
	salesTax = 0.0;
	totalSale = 0.0;

	// Another sale?
	cout << "Enter -1 to do another sale or 0 to exit: " << endl;
	cin >> anotherSale;

	} while (anotherSale != 0);// End loop for repeat sale

	// Display how much is in the cash drawer at the end
	cout << endl << "Cash Drawer Total: $" << setw(9) << setprecision(2) << cashDrawer << endl;

	system("pause");
}
