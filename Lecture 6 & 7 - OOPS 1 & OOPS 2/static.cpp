class student{

    static int totalStudents;

    public :

    int rollNumber;
    int age;

    // static int totalStudents; // total number of stduents present
    // this property deosn't belong to the object, it belong to the class
    
    student() {
        totalStudents++; 
    }

    int getRollNumber() {
        return rollNumber;
    }

    static int getTotalStudents() { //  not this func belongs to the entire class
        return totalStudents;
    }
};

int student :: totalStudents = 0; // initilaize static data members

