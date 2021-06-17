template<typename T>
class tree_node {
public:
    tree_node(const T& value) : value_{ value } {}

    void add_child(std::unique_ptr<tree_node<T>> child) {
        child->parent_ptr_ = this;
        children_.push_back(std::move(child));
    }
    
    //finding number of nodes in a subtree
    std::size_t size() const {
        std::size_t size = 1;

        for (const std::unique_ptr<tree_node<T>>& child : children_) {
            size += child->size();
        }

        return size;
    }
    
    //the distance from the node to the farthest away leaf
    std::size_t height() const {
        std::size_t height = 0;

        if (!children_.empty()) {
            //put the heights of each child subtree into a vector
            std::vector<std::size_t> heights;
            std::transform(std::cbegin(children_), std::cend(children_), std::back_inserter(heights), [](const NodeUptr& child) {
                return child->height();
            });
            //find the tallest height among all children
            height = *(std::max_element(std::cbegin(heights), std::cend(heights)));

            height++;
        }

        return height;
    }
    
    //find the depth (from the bottom up)
    std::size_t depth() const {
        std::size_t depth = 0;

        if (parent_ptr_ != nullptr) {
            depth = parent_ptr_->depth();
            depth++;
        }

        return depth;
    }
    
    //the maximum number of children in any subnode
    std::size_t degree() const {
        std::size_t degree = 0;

        if (!children_.empty()) {
            std::vector<std::size_t> degrees;
            //for every children vector, we are going to compare the children vector itself (the number of children of the parent node) 
            //and the number of children of each children
            std::transform(std::cbegin(children_), std::cend(children_), std::back_inserter(degrees), [](const NodeUptr& child) {
                return child->degree();
            });
            auto max_sub_degree = *(std::max_element(std::cbegin(degrees), std::cend(degrees)));
            //WARNING: std::max vs std::max_element
            degree = std::max(children_.size(), max_sub_degree);
        }
        
        return degree;
    }
    
    //number of leaves (no child node) of the tree
    std::size_t breadth() const {
        if (children_.empty()) {
            return 1;
        }

        std::size_t sub_leaves = 0;
        for (const NodeUptr& child : children_) {
            sub_leaves += child->breadth();
        }
        return sub_leaves;
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
