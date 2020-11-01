struct Alien{
    Alien(int n): value(n), parent(nullptr), left(nullptr), right(nullptr){};
    int value;
    Alien* parent;
    Alien* left;
    Alien* right;
    int getRootValue(){
        Alien* temp = this;
        while(temp->parent){
            temp = parent;
        }
        return temp->value;
    }
};