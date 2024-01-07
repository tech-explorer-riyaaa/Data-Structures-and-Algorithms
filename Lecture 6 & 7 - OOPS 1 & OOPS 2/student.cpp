class student {

    public : // public k neeche jitni bhi prop & functions hai, sbka access modifier set ho gya public

    ~student() {
        cout << "dESTRUCTOR cALLED!" << endl;
    }
    

    // Default Constructor - will initialise data members with the default values
    // empty wala - same as inbuilt one
    student() {
        cout << "Constructor called!" << endl;
    }
    
    // Parameterized constructor - as it takes arguments
    student(int rollNumber){
        cout << "Constructor 2 called!" << endl;
        this -> rollNumber = rollNumber;
        // or (*this).rollNumber = rollNumber; 
    }

    student(int a, int r){
        cout << "Constructor 3 called!" << endl;
        this -> age = a; // optional to write "this" here
        rollNumber = r;
        cout << "this value : " << this << endl;
    }
    int rollNumber;

    private : // ab age private ho gya

    int age;    

    public :

    void display(){
        cout << age << " " << rollNumber << endl;
    }

    // getter function
    int getAge() {
        return age;
    }

    // setter function
    void setAge(int a, int password){
        if (a < 0 || password != 1234){
            return; // will not update the value of age
        }
        age = a;
    }
};
  
