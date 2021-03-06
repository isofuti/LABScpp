/***********************************/
/*				   */
/* Code by: Khromov Egor Pavlovich */
/* github.com/SochnoeAnime/LABScpp */
/*		12.2021		   */
/*				   */
/***********************************/
#include <iostream>
#include <string.h>

using namespace std;

class Showroom {

public:
    Showroom() {}
    string car;
    virtual ~Showroom() {}
    virtual void AddCar(string car) = 0;
    virtual string GetCar() = 0;
    virtual int CountCar() = 0;
};

class Showcase : public Showroom {

public:
    using Showroom::Showroom;
    virtual ~Showcase()override {}
    virtual void AddCar(string c)override;
    virtual string GetCar()override;
    virtual int CountCar()override;
};

class Storage : public Showroom {

public:
    using Showroom::Showroom;
    virtual ~Storage()override {}
    virtual void AddCar(string c)override;
    virtual string GetCar()override;
    virtual int CountCar()override;
};


int main() {
    Showcase showcase;
    Storage storage;

    showcase.AddCar("Tesla Model S");
    showcase.AddCar("Tesla Model X");
    showcase.AddCar("Tesla Roadster");

    storage.AddCar("Tesla Model Y");
    storage.AddCar("Tesla Model 3");

    cout << "In the showcase there are: " << showcase.GetCar() << endl;
    cout << "In the storage there are: " << storage.GetCar() << endl;
    cout << "Cars on the showcase: " << showcase.CountCar() << endl;
    cout << "Cars in stock: " << storage.CountCar() << endl;

    return 0;
}

void Storage::AddCar(string c) {
    car.empty() ? car += c : car += ", " + c;
}

string Storage::GetCar() {
    return car;
}

int Storage::CountCar() {
    return (count(car.begin(), car.end(), ',') + 1);
}

void Showcase::AddCar(string c) {
    car.empty() ? car += c : car += ", " + c;
}

string Showcase::GetCar() {
    return car;
}

int Showcase::CountCar() {
    return (count(car.begin(), car.end(), ',') + 1);
}
