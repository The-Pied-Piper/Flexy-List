# Flexy List

Just another linked list implementation for C++, with a twist. A flexy list can hold multiple data types in the same list.

A typical example might be:

```c++
std::vector<int> vec = {1, 2, 3};
flexylist::Node<int> node1(4);
flexylist::Node<std::string> node2("this node holds a string");
flexylist::Node<std::vector<int>> node3(vec);
node1.set_next(node2);
node2.set_next(node3);

std::cout << node1.get_next().get_data<std::string>() << "\n"; // This node holds a string
```