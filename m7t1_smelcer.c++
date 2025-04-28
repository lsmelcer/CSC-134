#include <iostream>
using namespace std;

// CSC 134
// M7T1 - Restaurant Rating
// smelcerl
// 4/28/25
// Use Restaurant class to store user ratings

// Next time we'll put the class in a separate file
class Restaurant {
  private:
    string name;    // the name
    double rating;  // 0 to 5 stars

  public:
    // constructor
    Restaurant(string n, double r) {
        name = n;
        rating = r;
    }
    Restaurant() {
        
    }
    // getters and setters
    void setName(string n) {
        name = n; 
    }
    void setRating(double r) {
        rating = r;
    }
    string getName() const {
        return name;
    }
    double getRating() const {
        return rating;
    }
    // print a formatted entry
    void showInfo() {
        cout << "Restarant name: " << name << endl;
        cout << "Rating: " << rating << endl;
    }
  
};

int main() {
    cout << "M7T1 - Restaurant Reviews" << endl;
    // create a restaurant
    Restaurant rest1 = Restaurant("Mi Casita", 4);
    
    Restaurant rest2 = Restaurant();
    cout << "Restaurant name: ";
    string name;
    double rating;
    getline(cin, name);
    
    cout << "Restaurant rating: ";
    cin >> rating;
    rest2.setName(name);
    rest2.setRating(rating);
    
    rest1.showInfo();
    rest2.showInfo();

    return 0;

}