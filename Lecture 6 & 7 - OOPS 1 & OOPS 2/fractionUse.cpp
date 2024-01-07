 #include <iostream>
 using namespace std;
 #include "fraction2.cpp"

 int main() {
    fraction f1(10, 2);
    fraction f2(15, 4);

    fraction const f3; // def const. initialise every data member with garbage value
    
    cout << f3.getNumerator() << " " << f3.getDenominator(); // - garbage values in numerator and denominator
    // can't make any change in the properties through f3

    f3.print();
    // f3.setNumerator(12); //  func is set const, hence will be called but func k andr changes the- not allowed... waha error aayega

    fraction f4 = f1.add2(f2);
    fraction f5 = f1 + f2;
    f1.print();
    f2.print();
    f4.print();
    f5.print();
    fraction f6 = f1 * f2;
    f1.multiply(f2);
    f6.print();
    f1.print();

    if (f1 == f2){
        cout << "Equal" << endl;
    } else {
        cout << "Not Equal" << endl;
    }

    // Pre-increment
    f1.setNumerator(10);
    f1.setDenominator(2);
    f2.setNumerator(15);
    f2.setDenominator(4);
    
    // return type - void
    // f1.print();
    // ++f1;
    // f1.print();
    // // fraction f7 = ++f1; - can't use as its return type is void
    // fraction f7 = ++f1;
    // f7.print();

    /*
    return type - fraction
    f1.print(); // - 10/2
    fraction f8 = ++(++f1);
    f1.print(); // - 6/1
    f8.print(); // - 7/1
    // ++(++f1); - f1 = 10/2
    // f1.print(); - gave 6/1 instead of 7/1
    */

   // return type - fraction&

   f1.print();
   fraction f8 = ++(++f1);
   f1.print();
   f8.print();


   // Post-increment
   fraction f9(10, 2);
   fraction f10(15, 4);

   fraction f11 = f9++;
   f9.print();
   f11.print();

   // += operator
   int i = 5, j = 3;
   (i += j) += j;
   cout << i << " " << j << endl;

   fraction f12(10, 3);
   fraction f13(5, 2);

   (f12 += f13) += f13;
   f12.print();
   f13.print();

}