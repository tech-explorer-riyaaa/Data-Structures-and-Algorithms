class complex {

    private : 
    int real;
    int imag;

    // 3 + 4i

    public : 
    complex(int r, int i) { // hume default garbage values nahi daalni thi
        real = r;
        imag = i;
    }

    void plus(complex const &c2) {
        real = real + c2.real;
        imag = imag + c2.imag;
    }

    void multiply(complex const &c2) {
        int real1 = real;
        real = (real * c2.real) - (imag * c2.imag);
        imag = (real1 * c2.imag) + (imag * c2.real);
    }

    void print() {
        cout << real << " + i" << imag << endl;
    }
};