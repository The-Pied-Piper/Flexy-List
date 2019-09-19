# Flexy List

Just another linked list implementation for C++, with a twist. A flexy list can hold multiple data types in the same list!

A typical use might be:

```c++
#include <iostream>
#include <vector>

#include <flexylist/node.hpp>

std::vector<int> vec = {1, 2, 3};
flexylist::Node<int> node1(4);
flexylist::Node<std::string> node2("this node holds a string");
flexylist::Node<std::vector<int>> node3(vec);
node1.set_next(node2);
node2.set_next(node3);

std::cout << node1.get_data() << "\n"; // Output 4;
std::cout << node1.get_next().get_data<std::string>() << "\n"; // Output: This node holds a string\n
std::cout << node1.get_next().get_next().get_data<std::vector<int>>()[1] << "\n"; // Output: 2\n
```

### Note: I wrote Flexy list only as an intellectual excerscise, as a way to teach myself C++. It is not really intended for serious use, although, anyone who wishes to is welcome to do so at their own risk.
