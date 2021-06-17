template<typename T>
class tree_node {
public:
    tree_node(const T& value) : value_{ value } {}

    void add_child(std::unique_ptr<tree_node<T>> child) {
        child->parent_ptr_ = this;
        children_.push_back(std::move(child));
    }

private:
    T value_;
    tree_node<T>* parent_ptr_ = nullptr;
    std::vector<std::unique_ptr<tree_node<T>>> children_;
};
// ...
int main() {
  
    //create root
    auto root = std::make_unique<my::tree_node<int>>(0);
    
    auto a = std::make_unique<my::tree_node<int>>(7);
    auto b = std::make_unique<my::tree_node<int>>(8);
    auto c = std::make_unique<my::tree_node<int>>(9);

    auto d = std::make_unique<my::tree_node<int>>(15);
    auto e = std::make_unique<my::tree_node<int>>(16);

    auto f = std::make_unique<my::tree_node<int>>(21);
    
    //f is a child of d
    d->add_child(std::move(f));
    
    //d and e are children of a
    a->add_child(std::move(d));
    a->add_child(std::move(e));
    
    //the root has three children: a, b, c
    root->add_child(std::move(a));
    root->add_child(std::move(b));
    root->add_child(std::move(c));
    
    /*demonstration:
                root (0)
                /  \     \
               /    \     \
              a(7)   b(8)  c(9)
             /\ 
            /  \    
       (15)d    e(16)
          /
         /
        f(21)
}
