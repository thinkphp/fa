/* 
 *
 * Calculator Complex Numbers.
 * Adrian Statescu <mergesortv@gmail.com> <http://adrianstatescu.com> 
 * Basic Operations with Complex Numbers.
 * 1. + How to add       (Addition)
 * 2. - How to substract (Substraction)
 * 3. * How to multiply  (Multiplication)
 * 4. / How to divide    (Division)
 *
 */

#include <iostream>
#include <cmath>

using namespace std;

typedef struct {

        float re,
              im;

} ComplexNumber;

void displayComplexNumber(ComplexNumber c) {

     cout<<c.re<<"+"<<c.im<<"i"<<endl;
}

void initComplexNumber(ComplexNumber &c, float re, float im) {

     c.re = re;
     c.im = im;   
}

ComplexNumber solveSum(ComplexNumber com,ComplexNumber com2) {

              ComplexNumber res;

              res.re = com.re + com2.re;  

              res.im = com.im + com2.im;

        return res;
}

ComplexNumber solveMul(ComplexNumber com,ComplexNumber com2) {

              ComplexNumber res;

              res.re = com.re * com2.re - com.im * com2.im;  

              res.im = com.re * com2.im + com.im * com2.re;  

        return res;
}

ComplexNumber solveSub(ComplexNumber com,ComplexNumber com2) {

              ComplexNumber res;

              res.re = com.re - com2.re;  

              res.im = com.im - com2.im;

        return res;
}


ComplexNumber solveDiv(ComplexNumber com,ComplexNumber com2) {

              ComplexNumber res;

              res.re = (com.re * com2.re + com.im * com2.im ) / pow(com2.re, 2) + pow(com2.im, 2); 

              res.im = (com2.re * com.re - com.re * com2.im ) / pow(com2.re, 2) + pow(com2.im, 2); 

        return res;
}


void performSum(ComplexNumber &com) {

     ComplexNumber newComNum;

     cout<<"Enter Real -> ";
     cin>>newComNum.re;   
     cout<<"Enter Imaginary -> ";
     cin>>newComNum.im;

     com = solveSum(com, newComNum); 
}

void performSub(ComplexNumber &com) {

     ComplexNumber newComNum;

     cout<<"Enter Real -> ";
     cin>>newComNum.re;   
     cout<<"Enter Imaginary -> ";
     cin>>newComNum.im;

     com = solveSub(com, newComNum); 
}


void performMul(ComplexNumber &com) {

     ComplexNumber newComNum;

     cout<<"Enter Real -> ";
     cin>>newComNum.re;   
     cout<<"Enter Imaginary -> ";
     cin>>newComNum.im;

     com = solveMul(com, newComNum); 
}


void performDiv(ComplexNumber &com) {

     ComplexNumber newComNum;

     cout<<"Enter Real -> ";
     cin>>newComNum.re;   
     cout<<"Enter Imaginary -> ";
     cin>>newComNum.im;

     com = solveDiv(com, newComNum); 
}

void runMenu(ComplexNumber &com) {
 
     char ch;

     do {

     displayComplexNumber( com );

     cout<<"------"<<endl;     
     cout<<"MENU"<<endl;
     cout<<"------"<<endl;     
     cout<<" + Add \n - Sub \n * Mul \n / Div \n x EXIT"<<endl; 
     cout<<"------"<<endl;     
     cout<<":- "; 
     cin>>ch;

     switch( ch ) {

           case '+':
           performSum( com );
           break;

           case '-':
           performSub( com );
           break;

           case '*':
           performMul( com );
           break;

           case '/':
           performDiv( com );
           break;
     }

     }while(ch != 'x');
}

int main() {

 ComplexNumber c;

 initComplexNumber( c, 0, 0);
 runMenu( c );

 return(0);
}