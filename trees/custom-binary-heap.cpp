template<typename T, typename Comparator>
class binary_heap {
public:
    binary_heap(Comparator comparator) : comparator_{ comparator } {}

    std::size_t size() { return data_.size(); }
    bool empty() { return data_.empty(); }

    void insert(const T& value) {
        data_.push_back(value);

        // cascade up
        auto n = data_.size() - 1;
        auto parent = get_parent(n);
        while (n > 0 && !comparator_(data_[parent], data_[n])) {
            std::swap(data_[n], data_[parent]);
            n = parent;
            parent = get_parent(n);
        }
    }

    void remove() {
        std::swap(data_[0], data_[data_.size() - 1]);
        data_.pop_back();
        
        // cascade down
        std::size_t n = 0;
        auto left = get_left_child(n);
        auto right = get_right_child(n);
        while ((left < data_.size() && !comparator_(data_[n], data_[left])) || (right < data_.size() && !comparator_(data_[n], data_[right]))) {
            // find the largest child
            auto largest = left;
            if ((right < data_.size()) && comparator_(data_[right], data_[largest])) {
                largest = right;
            }

            // swap with larger child
            std::swap(data_[n], data_[largest]);
            n = largest;
            left = get_left_child(n);
            right = get_right_child(n);
        }
    }

    T& root() { return data_.front(); }

private:
    Comparator comparator_;
    std::vector<T> data_;

    std::size_t get_left_child(std::size_t n) { return 2 * n + 1; }
    std::size_t get_right_child(std::size_t n) { return 2 * n + 2; }
    std::size_t get_parent(std::size_t n) { return (n - 1) / 2; }
};
