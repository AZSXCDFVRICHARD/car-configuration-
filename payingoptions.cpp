#include <iomanip>
//
// Created by richard hague on 20/07/2025.
using namespace std;
#include "payingoptions.h"
#include <iostream>

#include "cars.h"

payingoptions::payingoptions() {

}


void payingoptions::payingfull(cars& car) {
    cout <<"Your total payment is: £"<< car.selectedcar.price + car.selectedupgrade.price;
    cout<< endl;
    cout <<"thank you for shopping with us!";
    cout<< endl;
    cout <<endl;
    cout << "your car should be with you within 3-5 working days";




    }



void payingoptions::payingfinance(cars& car) {
    cout << "Finance is based on 10% APR.\n";
    cout << "Please select a payment period of 1-5 years, or enter 'back' to select a different option:\n";

    bool valid = true;
    while (valid) {

        cout << "please select a valid option :";
        cin >> userinput;

        if (userinput == "back") {
            return;  // User wants to go back
        }

        try {
            int inputasint = stoi(userinput);  // Attempt to convert to int

            if ( inputasint >=1 && inputasint <=5) {
                financeTimePeriod = inputasint;

                cout << "You selected: " << financeTimePeriod << " years." << endl;
                valid = false;
                payingoptions::financeCalculator(car);







            }











            } catch (...) {
                // Catch any conversion errors
                cout << "Invalid input, please enter a numeric value between 1 and 5: " << endl;
            }
        }
    }
void payingoptions::financeCalculator(cars &car) {
    double principal = car.selectedcar.price + car.selectedupgrade.price;
    double intrest= principal * 0.10 * financeTimePeriod;
    double total_repayment = principal + intrest;
    double monthly_payment= total_repayment / (12 * financeTimePeriod);

    cout << "Total payment is: " << total_repayment << endl;
    cout << "Monthly payment is: " << monthly_payment << endl;


}












void payingoptions::payingopt(cars& car) {
    while (true) {
        cout << "Are you paying full or finance: ";
        cin >> userinput;

        if (userinput == "full") {
            payingfull(car);
            return;// exit after function is done


        }
        else if (userinput == "finance") {
            payingfinance(car);
            return; // exit after function is done
        }

        else {
            cout << "Please select a valid option." << endl;
        }
    }
}