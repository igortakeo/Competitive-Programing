#include <bits/stdc++.h> //On CodeSignal this include is not found
#define ll long long
#define pds pair<double, string>

using namespace std;

struct Point{
    double x, y;

    Point(double x, double y){
        this->x = x;
        this->y = y;
    }

    Point operator+(const Point& b) const{
        return Point(x+b.x, y+b.y);
    }

    Point operator-(const Point& b) const{
        return Point(x-b.x, y-b.y);
    }

    //dot - produto escalar
    ll operator*(const Point& b) const{
        return x*b.x + y*b.y; 
    }

    ll operator^(const Point &b) const{
        return x*b.y - y*b.x;
    }

    ll norm(){
        return sqrt(x*x+y*y);
    }

};

double MinDist(Point a, Point b, Point point){
    Point BA = b-a, CA = point-a, CB = point-b, AB = a-b; 
    if(BA*CA >= 0 && CB*AB >= 0){
        ll area = BA^CA;
        ll h = area/BA.norm();
        return h;
    }
    else{
        return min(CA.norm(), CB.norm());
    }
}

bool check(string address, vector<string>p){
    transform(address.begin(), address.end(), address.begin(), ::tolower);
    
    for(string a : p){
        
        transform(a.begin(), a.end(), a.begin(), ::tolower);
        
        if(a.size() == address.size()){
            if(a == address) return true;
            int diff = 0;
            for(int i=0; i<address.size(); i++){
                if(a[i] != address[i]) diff++;
            }
            if(diff <= 1) return true;
        }
        else if(a.size() > address.size()){
            int j=0;
            for(int i=0; i<a.size(); i++){
                if(a[i] == address[j]) j++;
            }
            if(j == address.size()) return true;
        }
        else{
            int j=0;
            for(int i=0; i<address.size(); i++){
                if(a[j] == address[i]) j++;
            }
            if(j == a.size()) return true;
        }
    }
    
    return false;
}

double EuclideanDistance(double x_1, double y_1, double x_2, double y_2){
    return sqrt((x_1- x_2)*(x_1- x_2) + (y_1-y_2)*(y_1-y_2));
}

//It's not necessary a main, the answer is return of closestLocation

string closestLocation(string address, vector<vector<int>> objects, vector<string> names) {
    string init(100, 'a');
    pds ans;
    ans.second = init;

    double x_1 = 0.0;
    double y_1 = 0.0;
    
    for(int i=0; i<names.size(); i++){
        string s = names[i];
        
        if(s.size() < address.size()-1) continue;
        
        vector<string>p;
        
        for(int i=-1; i<=1; i++){
            p.push_back(s.substr(0, address.size()+i));
        }
    
        bool flag = check(address, p);
        double dist = 0.0;
        
        for(string i : p){
            cout << i << endl;
        }
        
        cout << flag << ' ' << s << endl;
        
        if(!flag) continue;
        
        if(objects[i].size() == 2){
            double x_2 = objects[i][0];
            double y_2 = objects[i][1];
            dist = EuclideanDistance(x_1, y_1, x_2, y_2);
        }
        else{
            Point a(objects[i][0], objects[i][1]);
            Point b(objects[i][2], objects[i][3]);
            Point c(x_1, y_1);
            
            dist = MinDist(a, b, c);
        }
        
        if(ans.second == init){
            ans.first = dist;
            ans.second = s;
        }
        
        if(dist < ans.first){
            ans.first = dist;
            ans.second = s;
        }
        
    }
    
    
    return ans.second;
}
