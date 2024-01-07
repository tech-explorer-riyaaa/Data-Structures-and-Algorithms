class fraction {
    private :

    int numerator;
    int denominator;

    public :

    fraction() {

    }
    fraction(int numerator, int denominator) {
        this -> numerator = numerator;
        this -> denominator = denominator;
    }

    int getNumerator() const {
        return numerator;
    }

    int getDenominator() const {
        return denominator;
    }

    void setNumerator(int n) {
        numerator = n;
    }

    void setDenominator(int d) {
        denominator = d;
    }

    void print() const {
        cout << this -> numerator << " / " << denominator << endl;
    }

    void simplify() {
        int gcd = 1;
        int j = min(this -> numerator, this -> denominator);
        for(int i = 1; i <= j; i++) {
            if(this -> numerator % i == 0 && this -> denominator % i == 0) {
                gcd = i;
            }
        }
        this -> numerator = this -> numerator / gcd;
        this -> denominator = this -> denominator / gcd;
    }

    
    void add(fraction const &f2) {
        int lcm = denominator * f2.denominator;
        int x = lcm / denominator;
        int y = lcm / f2.denominator;

        int num = x * numerator + (y * f2.numerator);

        numerator = num;
        denominator = lcm;
        simplify();
    }
    
   fraction add2(fraction const &f2) {
    int lcm = denominator * f2.denominator;
    int x = lcm / denominator;
    int y = lcm / f2.denominator;

    int num = x * numerator + (y * f2.numerator);
    fraction fNew(num, lcm);
    fNew.simplify();
    return fNew;
   }

   fraction operator+(fraction const &f2) const {
    int lcm = denominator * f2.denominator;
    int x = lcm / denominator;
    int y = lcm / f2.denominator;

    int num = x * numerator + (y * f2.numerator);
    fraction fNew(num, lcm);
    fNew.simplify();
    return fNew;

   }

   fraction operator* (fraction const &f2) const{
    int n = numerator * f2.numerator;
    int d = denominator * f2.denominator;
    fraction fNew(n, d);
    fNew.simplify();
    return fNew;
   }

    void multiply(fraction const &f2) {
        numerator = numerator * f2.numerator;
        denominator = denominator * f2.denominator;

        simplify();
    }

    bool operator==(fraction const &f2) const{
        return (numerator == f2.numerator && denominator == f2.denominator);
    }

    // pass argument as a constant reference - avoid copying and illegal changes

    // Pre-increment
    fraction& operator++() {
        numerator = getNumerator() + getDenominator();
        simplify();
        // return this; // this is pointer jiske pass object ka address pada hai
        return *this; // this k poore block ko hi return krdo

    }

    // Post-increment
    fraction operator++(int) {
          fraction fNew(numerator, denominator);
          numerator = numerator + denominator;
          simplify();
          fNew.simplify();
          return fNew;
    }

    // += operator
    fraction& operator+=(fraction const &f2){
       int lcm = denominator * f2.denominator;
       int x = lcm / denominator;
       int y = lcm / f2.denominator;

       int num = x * numerator + (y * f2.numerator);
       numerator = num;
       denominator = lcm;
       simplify();
       return *this;
    }

};