#include <bits/stdc++.h> //On CodeSignal this include is not found

using namespace std;

//Problem Link: https://app.codesignal.com/company-challenges/uber/4c3qzzQg8Zg9AfLKH

//It's not necessary a main, the answer is return of closestLocation

string fancyRide(int l, vector<double> fares) {
    
    vector<string> cars {"UberX", "UberXL", "UberPlus", "UberBlack", "UberSUV"};
    
    for(int i=0; i<fares.size(); i++){
        if(l * fares[i] > 20) return cars[i-1];
    }
    
    return cars.back();
}
