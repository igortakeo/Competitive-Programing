#include <stdio.h>
#include <iostream>
#include <math.h>

using namespace std;

double p, q, r, s, t, u;
	
double f(double x){ 
	return p * exp(-x) + q * sin(x) + r * cos(x) + s * tan(x) + t * x * x + u;
}

int main(){
	
	while(scanf("%lf%lf%lf%lf%lf%lf", &p, &q, &r, &s, &t, &u) != EOF){
				
		if(f(0)*f(1) > 0) printf("No solution\n");
		else{
			double a=1e-6, b=1;
			double c = (a+b)/2;
			double zero = 0.0000001;
			while(true){
				
				if(b-a <= zero) break;
				else{
					if(f(a)*f(c) < 0){
						b = c;
					}
					else a=c;
				}
				
				c = (a+b)/2;	
			}
			
			printf("%.4lf\n", c);
		}
	
	}
	
	
	return 0;
}
