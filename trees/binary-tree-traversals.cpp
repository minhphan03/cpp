//prioritizing depth -- the naive way... leaves->root 
template<typename T, typename VisitorFunc>
void depth_first_traverse(const binary_tree_node<T>& node, VisitorFunc visitor) {
    if (node.left_uptr_ != nullptr) {
        depth_first_traverse(*(node.left_uptr_), visitor);
    }
    if (node.right_uptr_ != nullptr) {
        depth_first_traverse(*(node.right_uptr_), visitor);
    }

    visitor(node.value_);
}
// ...
std::cout << "Depth-first Traversal: ";
my::depth_first_traverse(*root, [](const std::string& value) {
    std::cout << value << ", ";
});
std::cout << "\n";



//focus on the current nodes (left & right)... leaves->root
template<typename T, typename VisitorFunc>
void breadth_first_traverse(binary_tree_node<T>& node, VisitorFunc visitor) {
    std::queue<binary_tree_node<T>*> remaining_nodes;
    remaining_nodes.push(&node);

    while (!remaining_nodes.empty()) {
        //access the first node
        const binary_tree_node<T>& front = *(remaining_nodes.front());
        remaining_nodes.pop();
        
        //find the left children nodes, if yes, put to the queue (meaning that we are not prioritizing them because we still have the right to do)
        if (front.left_uptr_ != nullptr) {
            remaining_nodes.push(front.left_uptr_.get());
        }
        //find the right children nodes, if yes, put into the queue (we are not prioritizing depth as we have the next deeper level of left -- if available)
        if (front.right_uptr_ != nullptr) {
            remaining_nodes.push(front.right_uptr_.get());
        }
        visitor(front.value_);
    }
}
// ...
std::cout << "Breadth-first Traversal: ";
my::breadth_first_traverse(*root, [](const std::string& value) {
    std::cout << value << ", ";
});
std::cout << "\n";



//just like depth first traversal but reverse order: root -> leaves
template<typename T, typename VisitorFunc>
void pre_order_traverse(binary_tree_node<T>& node, VisitorFunc visitor) {
    visitor(node.value_);

    if (node.left_uptr_ != nullptr) {
        pre_order_traverse(*(node.left_uptr_), visitor);
    }
    if (node.right_uptr_ != nullptr) {
        pre_order_traverse(*(node.right_uptr_), visitor);
    }
}
// ...
std::cout << "Pre-order Traversal: ";
my::pre_order_traverse(*root, [](const std::string& value) {
    std::cout << value << ", ";
});
std::cout << "\n";



//the order is ubiquitous: visit the left node first, the the node itself, then the right node. 
template<typename T, typename VisitorFunc>
void in_order_traverse(binary_tree_node<T>& node, VisitorFunc visitor) {
    if (node.left_uptr_ != nullptr) {
        in_order_traverse(*(node.left_uptr_), visitor);
    }

    visitor(node.value_);
    
    if (node.right_uptr_ != nullptr) {
        in_order_traverse(*(node.right_uptr_), visitor);
    }
}
// ...
std::cout << "In-order Traversal: ";
my::in_order_traverse(*root, [](const std::string& value) {
    std::cout << value << ", ";
});
std::cout << "\n";
