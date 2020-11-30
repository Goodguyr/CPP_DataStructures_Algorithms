#include <iostream>
#include "AVLtree.h"

int startDeleting;
int endDeleting;

int pickHeight(int a, int b){
    return a > b ? a : b;
}

int AVLTree::height(Node* node){
    int h = 0;
    if(node != NULL){
        int left_height = height(node->left);
        int right_height = height(node->right);
        int max_height = pickHeight(left_height, right_height);
        h = max_height + 1;
    }
    return h;
}

int AVLTree::getBalanceFactor(Node* node){
    int left_height = height(node->left);
    int right_height = height(node->right);
    int balance_factor = left_height - right_height;
    return balance_factor;
}

Node* AVLTree::rr_rotation(Node* parent){
    Node* rightNode = parent->right;
    parent->right = rightNode->left;
    rightNode->left = parent;
    return rightNode;
}

Node* AVLTree::ll_rotation(Node* parent){
    Node* leftNode = parent->left;
    parent->left = leftNode->right;
    leftNode->right = parent;
    return leftNode;
}

Node* AVLTree::lr_rotation(Node* parent){
    Node* leftNode = parent->left;
    parent->left = rr_rotation(leftNode);
    return ll_rotation(parent);
}

Node* AVLTree::rl_rotation(Node* parent){
    Node* rightNode = parent->right;
    parent->right = ll_rotation(rightNode);
    return rr_rotation(parent);
}

Node* AVLTree::balance(Node* node){
    int balance_factor = getBalanceFactor(node);
    if(balance_factor > 1){
        if(getBalanceFactor(node->left) > 0){
            node = ll_rotation(node);
        }
        else{
            node = lr_rotation(node);
        }
    }
    else if(balance_factor < -1){
        if(getBalanceFactor(node->right) > 0){
            node = rl_rotation(node);
        }
        else{
            node = rr_rotation(node);
        }
    }
    return node;
}

Node* AVLTree::insert(Node* node, std::string word){
    if(node == NULL){
        node = new Node(word);
        node->left = NULL;
        node->right = NULL;
        return node;
    }
    else if(compareFunction(word, node->word) == -1){
        node->left = insert(node->left, word);
        node = balance(node);
    }
    else if(compareFunction(word, node->word) == 1){
        node->right = insert(node->right, word);
        node = balance(node);
    }
    else if(compareFunction(word, node->word) == 0){
        node->count += 1;
    }
    return node;
}

Node * minValueNode(Node* node){
    return node->left != NULL ? minValueNode(node) : node;
}

Node* AVLTree::deleteNode(Node* node, std::string word){
	if(node == NULL){
        return node;
    }
	if(compareFunction(node->word, word) == 1){
        node->left = deleteNode(node->left, word);
    }
	else if(compareFunction(node->word, word) == -1){
        node->right = deleteNode(node->right, word);
    }
	else{
		if(node->left == NULL || node->right == NULL){
			Node *temp = node->left ? node->left : node->right;
			if(temp == NULL){
				temp = node;
				node = NULL;
			}
			else{
                *node = *temp;
            }
			delete temp;
		}
		else{
			Node* temp = minValueNode(node->right);
			node->word = temp->word;
			node->right = deleteNode(node->right, temp->word);
		}
	}
	if(node == NULL){
        return node;
    }
	node->height = 1 + pickHeight(height(node->left),height(node->right));
	int balance = getBalanceFactor(node);
	if(balance > 1 && getBalanceFactor(node->left) >= 0)
		return rr_rotation(node);
 
	if(balance > 1 && getBalanceFactor(node->left) < 0){
		return lr_rotation(node);
	}
	if(balance < -1 && getBalanceFactor(node->right) <= 0){
        return ll_rotation(node);
    }
	if(balance < -1 && getBalanceFactor(node->right) > 0){
		return rl_rotation(node);
	}
	return node;
}



void AVLTree::get(Node* node, std::string value){
    if(!node){
        std::cout << "(" << value << "," << 0 << ")" << std::endl;
        return;
    }
    if(compareFunction(node->word, value) == 1){
        return get(node->left, value);
    }
    else if(compareFunction(node->word, value) == -1){
        return get(node->right, value);
    }
    else{
        std::cout << "(" << node->word << "," << node->count << ")" << std::endl;
        return;
    }
}

void AVLTree::locate(Node* node, std::string value){
    Node* temp = node;
    std::string path = "*";
    while(temp != NULL){
        if(compareFunction(temp->word, value) == 1){
            path.push_back('L');
            temp = temp->left;
        }
        else if(compareFunction(temp->word, value) == -1){
            path.push_back('R');
            temp = temp->right;
        }
        else if(compareFunction(temp->word, value) == 0){
            std::cout << path << std::endl;
            return;
        }
    }
    std::cout << "N" << std::endl;
}

void AVLTree::dump(Node* node, std::string start, std::string end){
    startDeleting = (start == "_" || startDeleting == 1) ? 1 : 0;
    // std::cout << "start status -" << startDeleting << std::endl;
    endDeleting = (end != "_" || endDeleting == 1) ? 1 : 0;
    if(node == NULL){return;}
    dump(node->left, start, end);
    if(start == node->word){startDeleting = 1;};
    if(end == node->word){endDeleting = 1;}
    if(!startDeleting && endDeleting && end != "_"){return;}
    if(startDeleting && !endDeleting){
        std::cout << "(" << node->word << "," << node->count << ")" << " ";
    }
    dump(node->right, start, end);
}

bool isUpper(char n){
    if((int)n > 64 && (int)n < 91){
        return true;
    }
    return false;
}


int lexicographicalCompare(std::string word, std::string otherWord){
    if(word == otherWord){
        return 0;
    }
    int minLength = (word.length() > otherWord.length()) ? otherWord.length() : word.length();
    for(int i = 0; i < minLength; i++){
        if(isUpper(word[i]) && !isUpper(otherWord[i])){
            if(word[i] != (char)(otherWord[i] - 32)){
                if(word[i] > (char)(otherWord[i] - 32)){
                    return 1;
                }
                return -1;
            }
        }
        else if(!isUpper(word[i]) && isUpper(otherWord[i])){
            if((char)(word[i] - 32) != otherWord[i]){
                if((char)(word[i] - 32) > otherWord[i]){
                    return 1;
                }
                return -1;
            }
        }
        else{
            if(word[i] != otherWord[i]){
                if(word[i] > otherWord[i]){
                    return 1;
                }
                return -1;
            }
        }
    }
    if(word.length() != otherWord.length()){
        return word.length() > otherWord.length() ? 1 : -1;
    }
    for(int i = 0; i < minLength; i++){
        if(isUpper(word[i]) && !isUpper(otherWord[i])){
            return -1;
        }
        if(!isUpper(word[i]) && isUpper(otherWord[i])){
            return 1;
        }
    }
    return 0;
}

int shortlexCompare(std::string word, std::string otherWord){
    // Returns 1 if string word comes after otherWord
    if(word.size() > otherWord.size()){
        return 1;
    }
    // Returns -1 if string word comes before otherWord
    if(word.size() < otherWord.size()){
        return -1;
    }
    // Returns 0 if string word is the same length otherWord
    return lexicographicalCompare(word, otherWord);
}

int colexCompare(std::string word, std::string otherWord){
    int shortestLength = word.length() < otherWord.length() ? word.length() : otherWord.length();
    for(int i = 1; i <= shortestLength; i++){
        if(isUpper(word[word.length() - i]) && !isUpper(otherWord[otherWord.length() - i])){
            if(word[word.length() - i] != (char)(otherWord[otherWord.length() - i] - 32)){
                if(word[word.length() - i] > (char)(otherWord[otherWord.length() - i] - 32)){
                    return 1;
                }
                return -1;
            }
        }
        else if(!isUpper(word[word.length() - i]) && isUpper(otherWord[otherWord.length() - i])){
            if((char)(word[word.length() - i] - 32) != otherWord[otherWord.length() - i]){
                if((char)(word[word.length() - i] - 32) > otherWord[otherWord.length() - i]){
                    return 1;
                }
                return -1;
            }
        }
        else{
            if(word[word.length() - i] != otherWord[otherWord.length() - i]){
                if(word[word.length() - i] > otherWord[otherWord.length() - i]){
                    return 1;
                }
                return -1;
            }
        }
    }
    if(word.length() != otherWord.length()){
        return (word.length() == shortestLength) ? -1 : 1;
    }
    return 0;
}
