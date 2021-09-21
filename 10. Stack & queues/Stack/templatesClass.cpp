template <typename T, typename V>
class Pair{
private:
    T a;
    V b;
public:
    void setA(T a){
        this->a = a;
    }
    void setB(V b){
        this->b = b;
    }
    T getA(){
        return a;
    }
    V getB(){
        return b;
    }
};