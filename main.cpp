#include <iostream>

#include "payingoptions.h"
using namespace std;
#include "cars.h"





int main() {
    string again;
    do {
        cars mycar;
        payingoptions mypay;
        mycar.listcars();
        mycar.listupgrades();
        cout << endl;
        mycar.chooseOption();
        cout << endl;
        mycar.CarOptions();
        cout << endl;
        mypay.payingopt(mycar);
        cout << endl;
        cout << endl;

        cout <<"Would you like to buy another car? just type 'back' ";
        cout << endl;
        cout<<"if you would like exit the program press 'exit' ";
        cout << endl;
        cin >> again;
        while (again != "back" && again != "exit") {
            cout << "Please enter 'back' to buy another car or 'exit' to terminate the program";
            cin >> again;
        }
    }
    while (again == "back");


    return 0;

}