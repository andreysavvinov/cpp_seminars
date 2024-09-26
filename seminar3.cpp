
struct A{
    int y;
    int f(int x){//int A::f(A* this, int x){...}
        y=x; //this->y=x;
        return 1;
    }
};
int main(){
    
    return 1;
}