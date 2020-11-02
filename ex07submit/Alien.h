struct Alien{
    Alien(int n): value(n), parent(nullptr), left(nullptr), right(nullptr){};
    int value;
    Alien* parent;
    Alien* left;
    Alien* right;
    Alien* getRootNode(){
        if(this->parent){
            return this->parent->getRootNode();
        }
        return this;
    }
};