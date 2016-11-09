// Copyright [2016] <Lucas Mauro de Souza>

#include "./array_list.h"

namespace structures {

template<typename T>
/*!
 * Represents a binary tree that may contain various nodes, but each node may only have two children.
 */
class BinaryTree {
 public:
    /*!
     * Creates a binary tree with an empty root and size 0;
     */
    BinaryTree() {
        this->root = nullptr;
        this->size_ = 0;
    }

    ~BinaryTree() {
        delete this->root;
    }

    /*!
     * Creates a new node on the tree with the given data.
     */
    void insert(const T& data) {
        if (this->root == nullptr)
            this->root = new Node(data);
        else
            this->root->insert(data);
        this->size_++;
    }

    /*!
     * Removes from the three the node which contains given data, if such node exists.
     */
    void remove(const T& data) {
        if (this->root->remove(data))
            this->size_--;
    }

    /*!
     * Returns whether or not the tree contains a node with given data.
     */
    bool contains(const T& data) const {
        return this->root->contains(data);
    }

    /*!
     * Returns whether or not the list is empty.
     */
    bool empty() const {
        return this->size_ == 0;
    }

    /*!
     * Returns the size of the tree.
     */
    std::size_t size() const {
        return this->size_;
    }

    /*!
     * Returns the values in the tree in "pre order":
     * It retrieves the data in the root firstly,
     * the the leftmost descendents secondly,
     * and the rightmost descendents thirdly at last.
     */
    ArrayList<T> pre_order() const {
        ArrayList<T> list { this->size_ };
        if (!this->empty())
            this->root->pre_order(list);
        return list;
    }

    /*!
     * Returns the values in the tree "in order".
     * It retrieves the leftmost descendents firstly,
     * the root secondly,
     * and the rightmost descendents thirdly at last.
     */
    ArrayList<T> in_order() const {
        ArrayList<T> list { this->size_ };
        if (!this->empty())
            this->root->in_order(list);
        return list;
    }

    /*!
     * Returns the values in the tree in "post order"
     * It retrieves the leftmost descendents firstly,
     * the rightmost descendents secondly,
     * and the root thirdly at last.
     */
    ArrayList<T> post_order() const {
        ArrayList<T> list { this->size_ };
        if (!this->empty())
            this->root->post_order(list);
        return list;
    }

 private:
    struct Node {
        explicit Node(const T& data) {
            this->data = data;
            this->left = nullptr;
            this->right = nullptr;
        }

        ~Node() {
            delete this->left;
            delete this->right;
        }

        T data;
        Node* left;
        Node* right;

        void insert(const T& data_) {
            if (data_ < this->data) {
                if (this->left == nullptr)
                    this->left = new Node(data_);
                else
                    this->left->insert(data_);
            } else if (data_ > this->data) {
                if (this->right == nullptr)
                    this->right = new Node(data_);
                else
                    this->right->insert(data_);
            }
        }

        bool remove(const T& data_) {
            return true;
        }

        bool contains(const T& data_) const {
            if (this->data == data_)
                return true;

            if (this->data > data_) {
                if (this->left != nullptr)
                    return this->left->contains(data_);
                else
                    return false;

            } else if (this->data < data_) {
                if (this->right != nullptr)
                    return this->right->contains(data_);
                else
                    return false;

            } else {
                return false;
            }
        }

        void pre_order(ArrayList<T>& v) const {
            v.push_back(this->data);

            if (this->left != nullptr)
                this->left->pre_order(v);

            if (this->right != nullptr)
                this->right->pre_order(v);
        }

        void in_order(ArrayList<T>& v) const {
            if (this->left != nullptr)
                this->left->in_order(v);

            v.push_back(data);

            if (this->right != nullptr)
                this->right->in_order(v);
        }

        void post_order(ArrayList<T>& v) const {
            if (this->left != nullptr)
                this->left->post_order(v);

            if (this->right != nullptr)
                this->right->post_order(v);

            v.push_back(data);
        }
    };

    Node* root;
    std::size_t size_;
};

}  // namespace structures
