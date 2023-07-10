namespace B {

class Klass {
private: 
int a;

auto getA() {
    return a;
}
};

// POD
struct Dummy{
    int a;
    auto getA(){
        return a;
    }
};



static auto b = 0.0;
auto get(){
    return b;
}

void set(float num){
    b = num;
}
}
