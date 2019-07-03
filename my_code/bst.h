#include <iostream>

void indent(int level) {
    // indent more at each level:
    for (int i = 0; i < level; i++) std::cout << "  ";
}

template <typename T>
class Bst {
    friend void print_bst(const Bst<T>& bst, int level=0) {
        indent(level);
        level++;
        
        std::cout << "data: " << bst.data << std::endl;
        indent(level + 1);
        std::cout << "left: ";
        
        if (!bst.left) std::cout << "nullptr\n";
        else {
            std::cout << "\n";
            indent(level);
            print_bst(*bst.left, level);
        }
        indent(level + 1);
        std::cout << "right: ";
        if (!bst.right) std::cout << "nullptr\n";
        else {
            std::cout << "\n";
            indent(level);
            print_bst(*bst.right, level);
        }
        std::cout << std::endl;
    }

    public:
        Bst(T d, Bst* l=nullptr, Bst* r=nullptr)
            : data(d), left(l), right(r) {}
    
    T get_val() {
        if (this) {
            return data;
        }
        else {
            return NULL;
        }
    }
    
    Bst<T>* search(T d) {
        if (d == this->data) return this;
        else if (d < this->data) {
            if (this->left) return this->left->search(d);
        }
        else {
            if (this->right) return this->right->search(d);
        }
        return nullptr;
    }
    
    T min() {
        if (!(this->left)) return this->data;
        else {
            return this->left->min();
        }
    }
    
    T max() {
        if (!(this->right)) return this->data;
        else {
            return this->right->max();
        }
    }
    
    void insert(T d) {
        if (this->data < d) {
            if (!this->right) {
                this->right = new Bst(d);
                return;
            }
            else {
                this->right->insert(d);
            }
        }
        else {
            if (!this->left) {
                this->left = new Bst(d);
                return;
            }
            else {
                this->left->insert(d);
            }
        }
    }
    Bst<T>* predecessor(T data) {
        Bst<T>* node = this->search(data);
        Bst<T>* root = this;
        if (node->left) return node->search(node->left->max());
        else {
            Bst<int>* pred = nullptr;
            
            while (root) {
                if (root->data > node->data) {
                    root = root->left;
                }
                else if (root->data < node->data) {
                    pred = root;
                    root = root->right;
                }
                else { break; }
            }
            return pred;
        }
    }
//
    Bst<T>* successor(T data) {
        Bst<T>* node = this->search(data);
        Bst<T>* root = this;
        if (node->right) return node->search(node->right->min());
        else {
            Bst<int>* succ = nullptr;
            
            while (root) {
                if (root->data > node->data) {
                    succ = root;
                    root = root->left;
                }
                else if (root->data < node->data) {
                    root = root->right;
                }
                else { break; }
            }
            return succ;
        }
        return nullptr;
    }
    private:
        T data;
        Bst* left;
        Bst* right;
};


template <typename T>
void print_bst(const Bst<T>& bst) {
    std::cout << "data: " << bst.data << "; left: ";

    if (!bst.left) std::cout << "nullptr ";
    else {
        std::cout << "\t\n";
        print_bst(bst.left);
    }
    std::cout << "; right: ";
    if (!bst.right) std::cout << "nullptr ";
    else {
        std::cout << "\t\n";
        print_bst(bst.right);
    }
    std::cout << std::endl;
}


