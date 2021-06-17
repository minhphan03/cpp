template<typename T>
struct binary_tree_node {
    binary_tree_node(const T& value) : value_{ value } {}

    T value_;
    tree_node<T>* parent_ptr_ = nullptr;
    std::unique_ptr<binary_tree_node<T>> left_uptr_ = nullptr;
    std::unique_ptr<binary_tree_node<T>> right_uptr_ = nullptr;
};

template<typename T>
std::size_t binary_tree_height(const binary_tree_node<T>& node) {
    std::size_t left_height = 0;
    if (node.left_uptr_ != nullptr) {
        left_height = binary_tree_height(*(node.left_uptr_)) + 1;
    }

    std::size_t right_height = 0;
    if (node.right_uptr_ != nullptr) {
        right_height = binary_tree_height(*(node.right_uptr_)) + 1;
    }

    return std::max(left_height, right_height);
}
// ...
int main() {
    auto root = std::make_unique<my::binary_tree_node<std::string>>("R");
    auto a = std::make_unique<my::binary_tree_node<std::string>>("A");
    auto b = std::make_unique<my::binary_tree_node<std::string>>("B");

    auto aa = std::make_unique<my::binary_tree_node<std::string>>("AA");
    auto ab = std::make_unique<my::binary_tree_node<std::string>>("AB");

    auto ba = std::make_unique<my::binary_tree_node<std::string>>("BA");
    auto bb = std::make_unique<my::binary_tree_node<std::string>>("BB");

    auto aaa = std::make_unique<my::binary_tree_node<std::string>>("AAA");
    auto aab = std::make_unique<my::binary_tree_node<std::string>>("AAB");

    aa->left_uptr_ = std::move(aaa);
    aa->right_uptr_ = std::move(aab);
    b->left_uptr_ = std::move(ba);
    b->right_uptr_ = std::move(bb);
    a->left_uptr_ = std::move(aa);
    a->right_uptr_ = std::move(ab);
    root->left_uptr_ = std::move(a);
    root->right_uptr_ = std::move(b);

    std::cout << "HEIGHT: " << my::binary_tree_height(*root) << "\n";
}
