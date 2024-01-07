class student {
    int age;
    // char name[100];
    // dynamic allocation
    // char *name = new char[100]; - not sure about size

    public :

    char *name; // created a character pointer

    public :
    student(int age, char *name) {
        this -> age = age;

        // shallow copy - ideally should not be done
        // this -> name = name; 

        // deep copy
        this -> name = new char[strlen(name) + 1];
        strcpy(this -> name, name);
    }

    // copy constructor
    student(student const &s) { // s reference variable hai jo main k object ko hi point kr rha h
        this -> age = s.age;
        // this -> name = s.name; - shallow copy
        // deep copy
        this -> name = new char[strlen(s.name) + 1];
        strcpy(this -> name, s.name);
    }

    void display() {
        cout << name << " " << age << endl;
    }
};