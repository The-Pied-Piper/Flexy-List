#ifndef FLEXYLIST_NODE_H
#define FLEXYLIST_NODE_H

namespace flexylist
{

class NodeBase
{

private:
    static void *operator new(std::size_t);   // #1: To prevent allocation of scalar objects
    static void *operator new[](std::size_t); // #2: To prevent allocation of array of objects

protected:
    /**
     * @brief A pointer to the next node in the list
     *
     */
    NodeBase *next = nullptr;

    NodeBase *head = nullptr;

public:
    /**
     * @brief Destroy the NodeBase object
     *
     */
    virtual ~NodeBase()
    {
    }

    /**
     * @brief Getter for the node's data
     *
     * @tparam Tdata
     * @return const Tdata&
     */
    template <typename Tdata>
    const Tdata &get_data() const;

    /**
     * @brief Setter for the node's data
     *
     * @tparam Tdata The node's data type
     * @param new_data The data to store in the node
     */
    template <typename Tdata>
    void set_data(Tdata const &new_data);

    /**
     * @brief Set the next node in the list
     *
     * @param next The next node in the list
     */
    void set_next(NodeBase &next);

    /**
     * @brief Get the next node in the list
     *
     * @return A reference to the next node in the list
     */
    const NodeBase &get_next() const;

};

template <typename Tdata>
class Node : public NodeBase
{
private:
    /**
     * @brief The data to store in the node
     *
     */
    Tdata data;

public:
    /**
     * @brief Construct a new Node object
     *
     * @param data The data to store in the node
     */
    Node(Tdata data, NodeBase * list_head=nullptr)
        : data(data)
    {
        head = (list_head == nullptr) ? this : list_head;
    }

    /**
     * @brief Getter the node's data
     *
     * @return The data stored in the node
     */
    const Tdata &get_data() const;

    /**
     * @brief Setter for the node's data
     *
     * @param new_data The data to store in the node
     */
    void set_data(Tdata const &new_data);
};

// Define `NodeBase` functions

template <typename Tdata>
const Tdata &NodeBase::get_data() const
{
    return dynamic_cast<const Node<Tdata> *>(this)->get_data();
}

template <typename Tdata>
void NodeBase::set_data(Tdata const &new_data)
{
    Node<Tdata>::set_data(new_data);
}

void NodeBase::set_next(NodeBase &next_node)
{
    next_node.head = head;
    next = &next_node;
}

const NodeBase &NodeBase::get_next() const
{
    return *next;
}

// Define `Node` functions

template <typename Tdata>
const Tdata &Node<Tdata>::get_data() const
{
    return data;
}

template <typename Tdata>
void Node<Tdata>::set_data(Tdata const &new_data)
{
    data = new_data;
}

} // namespace flexylist

#endif