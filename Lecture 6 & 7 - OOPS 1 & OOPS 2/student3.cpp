class student {

    public :

    int age;
    const int rollNumber; // value once given, will not be changed.
    int &x; // age reference variable // will require intitialisation list to initialise at the time of creation
    // int &x = age;

    /*
    student(int r) {
        rollNumber = r; // rollNumber mei already garbage jaa chuka h; int rollNumber = r; hona chaiye tha
        // memory allocation k time hi value deni pdegi
    }
    */

   /*
   student(int r) : rollNumber(r) {
   }
   */

   student(int r, int age) : rollNumber(r), age(age), x(this -> age) { // no need to use "this" here
   }

   /*
   student() : rollNumber(101){
    ye bhi kr skte h - but useless here
   }*/
};