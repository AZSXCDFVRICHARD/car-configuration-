#include <iomanip>
#include <locale>
#include <iostream>
#include"payingoptions.h"
using namespace std;

cars::cars() {
    selectedupgrade = {0, 0,"", "", 0};
    selectedcar = {0,0, ""};
    carlist.push_back({1,5000, "Skoda Octavia "}); // car list
    carlist.push_back({2,250000, "maybach "});
    carlist.push_back({3,10000, "skoda superb "});
}




void cars::listupgrades() {
    upgradelist.push_back({1,1,"standard package ", "no extras ", 0} );
    upgradelist.push_back({1,2,"TechologySE ", "10' satnav, bluetooth 6 and upgraded speakers ", 9100});
    upgradelist.push_back({1,3,"winter package ", "heated seats, heated steerling wheel, plus all from technology SE ", 10000});
    upgradelist.push_back({2,1,"sport package ", "AMG SPORT suspension and 4L twin turbo engine ", 15000});
    upgradelist.push_back({2,2,"vip","maybach package",300000});
    upgradelist.push_back({3,1,"off road package ", "23' wheels and air suspension ", 15000});
    upgradelist.push_back({3,2,"luxury package "," leather seats and upgraded interior ",300000});
}












void cars::listcars() {
    cout << "Available cars are: " << endl;
    cout << "__________________________________" << endl;
    cout << "ID |     MODEL     | PRICE: " << endl;
    cout << "___|_______________|________________" << endl;

    for (const auto& car : carlist) {
        cout << setw(2) << right << car.ID << " | "
        << setw(14) << left<< car.model << "| £";

        cout.imbue(std::locale("en_GB.UTF-8")); // or another suitable locale
        cout << put_money(static_cast<long double>(car.price * 100)) << endl;

    }

}
void cars::chooseOption() {
    cout << "Please enter the ID number of the car you want to buy: "  ;
    //Fails with letters/words
    bool valid = false;
    while (!valid) {
        if (!(cin >> selectedcar.ID)) {
            cin.clear(); // clear error state
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // discard input
            cout << "Please enter a valid ID." ;

        } else {
            bool found = false;
            for (const auto& car : carlist) {
                //fails with intigers
                if (car.ID == selectedcar.ID) {
                    selectedcar = car;// assigns whole struct
                    valid = true;
                    found = true;
                    cout << "you picked " << car.model << "costing £" << car.price << endl;
                    cout << endl;
                    break;
                }
            }
            if (!found) {
                cout << "No valid upgrade found with that ID for the selected car.\n";
            }
        }
    }
}






void cars::CarOptions() {
    cout<< "Available upgrades for " << selectedcar.model <<" are : " ;
    cout << endl;
    for (const auto& upgrade: upgradelist) {
        if (upgrade.carID == selectedcar.ID) {
            cout<<upgrade.uniquecarID<<" | "<<upgrade.name_of_package<<"| "<< upgrade.description<<"| £"<< upgrade.price<<endl;

        }

    }


    bool valid = false;


    while (!valid) {
        cout<< endl;
        cout<<"please select an upgrade package: ";
        if (!(cin >> selectedupgrade.uniquecarID)) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout<< endl;
        }

            for (const auto& upgrade : upgradelist) {
                if (upgrade.carID == selectedcar.ID&& upgrade.uniquecarID == selectedupgrade.uniquecarID) {
                    selectedupgrade = upgrade;
                    valid = true;
                    cout << "you selected " << upgrade.name_of_package<< upgrade.description << "for £"<<upgrade.price;
                    cout << endl;
                    cout <<endl;
                    cout<< "your total price is £"<< selectedcar.price + selectedupgrade.price;
                    cout<< endl;


                }


            }


        }
    }

