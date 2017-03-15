#include <iostream>

using namespace std;

typedef struct {

       int numerator, 
           denominator;
       
} Rational;

int gcc(int a, int b) {

    if(b == 0) return a;

       else return gcc(b, a % b);
}

void simplify(Rational &r,int divizor) {

     r.numerator /= divizor; 
     r.denominator /= divizor;
}

void checkIreductible(Rational &r) {

     int d = gcc(r.numerator, r.denominator);

     simplify(r, d);
}

void init_number(Rational &r,int a,int b) {

     r.numerator = a; 
     r.denominator = b;
}

Rational solveAddition(Rational number,Rational newRational) {

         Rational sum;

         sum.numerator = number.numerator * newRational.denominator + number.denominator * newRational.numerator;
 
         sum.denominator = number.denominator * newRational.denominator;

         checkIreductible( sum );

      return sum; 
}

Rational solveProduit(Rational a, Rational b) {

         Rational prod;

         prod.numerator = a.numerator * b.numerator;
 
         prod.denominator = a.denominator * b.denominator;

         checkIreductible( prod );

      return prod; 
}

void ordinateur_added_sum(Rational &number) {

     Rational newRational;

     cout<<"Numerator"<<endl;
     cin>>newRational.numerator;

     cout<<"Denominator"<<endl<<"/";
     cin>>newRational.denominator;

     number = solveAddition(number, newRational);
}

void ordinateur_added_produit(Rational &number) {

     Rational newRational;

     cout<<"Numerator"<<endl;
     cin>>newRational.numerator;

     cout<<"Denominator"<<endl<<"/";
     cin>>newRational.denominator;

     number = solveProduit(number, newRational);
}


void display_number_rational(Rational &r) {

     cout<<"---------------------------------"<<endl;
     cout<<r.numerator<<"/"<<r.denominator<<endl;
     cout<<"---------------------------------"<<endl;
}


void runMenu(Rational &number) {

     char ch;

  do {

     display_number_rational( number );

     cout<<"---------------------------------"<<endl;
     cout<<" + Add \n - Sub \n * Product \n / Division \n x EXIT"<<endl;
     cout<<"---------------------------------"<<endl;
     cin>>ch; 
     switch( ch ) {

             case '+': 
             ordinateur_added_sum( number );
             break;

             case '-': 
             break;

             case '*': 
             ordinateur_added_produit( number );
             break;

             case '/': 
             break;
     }

  } while(ch != 'x');
    
}

int main() {

    Rational f;

    init_number(f, 0, 1);

    runMenu( f ); 

return(0);
}
