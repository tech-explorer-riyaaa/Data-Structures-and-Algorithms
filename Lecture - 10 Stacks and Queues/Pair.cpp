template <typename T, typename V> // otherwise compiler will give error - don't know what T is.
class Pair {
    T x;
    // T y;
    V y;

    public :

    void setX(T x) {
        this -> x = x;
    }
    T getX() {
        return x;
    }
    void setY(V y) {
        this -> y = y;
    }
    V getY() {
        return y;
    }
};