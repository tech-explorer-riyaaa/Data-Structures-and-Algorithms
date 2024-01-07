class fraction {

    private :

    int numerator;
    int denominator;

    public :

    fraction(int numerator, int denominator){
        this -> numerator = numerator;
        this -> denominator = denominator;
    }

    void print() {
        cout << this -> numerator << " / " << denominator << endl;
        // implicitly bina this k bhi, mtlb wohi hai.
    }

    void simplify(){
        int gcd = 1;
        int j = min(numerator, denominator);
        for(int i = 1; i < j; i++){
            if(numerator % i == 0 && denominator % i == 0){
                gcd = i;
            }
        }
        numerator = numerator / gcd;
        denominator = denominator / gcd;
    }
    void add(fraction const &f2) { // constant reference
        int lcm = denominator * f2.denominator;
        int x = lcm / denominator;
        int y = lcm / f2.denominator;
        int num = (x * numerator) + (y * f2.numerator);
        numerator = num;
        denominator = lcm;

        // to simplify divide num and denom with gcd of theirs
        simplify(); // implicitly it's this -> simplify
    }

    void multiply(fraction const &f2) {
        numerator = numerator * f2.numerator;
        denominator = denominator * f2.denominator;
        simplify();
    }
    
};