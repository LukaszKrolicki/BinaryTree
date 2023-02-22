#include <iostream>
using namespace std;
class MinHeap{
    private:
        int* kopiec;
        int capacity;
        int size;
    public:
        MinHeap(int c);            //tworzy pusty kopiec o pojemnoœci c
        bool empty();
        bool full();
        int getLeft(int i);                    //zwraca pozycjê lewego syna
        int getRight(int i);                //zwraca pozycjê prawego syna
        int getParent(int i);                //zwraca pozycjê ojca
        int getSize();                        //zwraca rozmiar kopca
        void setSize(int s);                //ustawia rozmiar kopca na s
        int getValue(int i);                //zwraca wartoœæ z pozycji i
        void setValue(int i, int x);        //ustawia wartoœæ x na pozycji i

        void insert(int x);
        void bottomUp(int i);                //przywraca w³asnoœæ kopca metod¹ wynurzania

        void delMin();
        void topDown(int i);                //przywraca w³asnoœæ kopca metod¹ zatapiania

        void del(int i);

        void build();

        friend std::ostream& operator<<(std::ostream& out, MinHeap& h);
};

MinHeap::MinHeap(int c){
    kopiec = new int[c]{35, 60, 64, 46, 43, 47, 40, 98};
    capacity = c;
    size=8;
}

bool MinHeap::empty()
{
    if(size==0)
        return true;
    else
        return false;
}

bool MinHeap::full(){
    if(size==capacity)
        return true;
    else
        return false;
}

int MinHeap::getLeft(int i){
    if(2*i+1<size){
        return 2*i+1;
    }
    else
        return -1;
}

int MinHeap::getRight(int i){
    if(2*i+2<size){
        return 2*i+2;
    }
    else{
        return -1;
    }
}

int MinHeap::getParent(int i){
    if(i==0)
        return -1;
    else{
        return (i-1)/2;
    }

}

int MinHeap::getSize(){
    return size;
}

void MinHeap::setSize(int s){
    size=s;
}

int MinHeap::getValue(int i){
    if(i>0 && i<size){
        return kopiec[i];
        }
}


void MinHeap::insert(int x){
    if(!full()){
        kopiec[size]=x;
        bottomUp(size);
        size++;
    }
}

void MinHeap::bottomUp(int i){
    if(i>0){
        int parent =getParent(i);
        if(kopiec[parent]<kopiec[i]){
            swap(kopiec[parent], kopiec[i]);
            bottomUp(parent);
        }
    }

}

void MinHeap::delMin(){
    if(!empty()){
        size--;
        swap(kopiec[0], kopiec[size]);
        topDown(0);
    }
}

void MinHeap::topDown(int i)
{
    int l = getLeft(i);
    int r= getRight(i);
    int g=i;

    if(l!=-1 && kopiec[g]<kopiec[l]){
        g=l;
    }

    if(r!=-1 && kopiec[g]<kopiec[r]){
        g=r;
    }

    if(g != i){
        swap(kopiec[i], kopiec[g]);
        topDown(g);
    }
}

void MinHeap::del(int i){
    if(!empty())
    {
        size--;
        swap(kopiec[i],kopiec[size]);
        topDown(i);
    }
}

void MinHeap::build(){
    for(int i = size/2; i>=0; i--){
        topDown(i);
    }
}

ostream& operator<<(std::ostream& out, MinHeap& h){
    for(int i=0; i<h.size; i++){
        out<<h.kopiec[i]<<" ";
    }

    out<<endl;
}
int main(){
    MinHeap h(20);
    h.build();
    cout<<h<<endl;
    h.del(1);
    cout<<h;
}
