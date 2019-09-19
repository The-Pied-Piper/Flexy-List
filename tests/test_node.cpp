#include <string>
#include <vector>
#include <iostream>

#include "gtest/gtest.h"
#include "flexylist/node.hpp"

TEST(Node, Test_set_next_new)
{
    std::vector<int> vec = {1, 2, 3};
    flexylist::Node<int> node1(4);
    flexylist::Node<std::string> node2("this node holds a string");
    flexylist::Node<std::vector<int>> node3(vec);
    node1.set_next(node2);
    node2.set_next(node3);

    EXPECT_EQ(&(node1.get_next()), &node2);
    EXPECT_EQ(&(node2.get_next()), &node3);
}

TEST(Node, Test_set_next_overwrite)
{
    std::vector<int> vec = {1, 2, 3};
    flexylist::Node<int> node1(4);
    flexylist::Node<std::string> node2("this node holds a string");
    flexylist::Node<std::vector<int>> node3(vec);
    flexylist::Node<float> node4(3.3333);
    node1.set_next(node2);
    node2.set_next(node3);
    node1.set_next(node4);

    EXPECT_EQ(&(node1.get_next()), &node4);
    EXPECT_EQ(&(node2.get_next()), &node3);
    EXPECT_EQ(&(node4.get_next()), nullptr);
}

TEST(Node, Test_get_next)
{
    std::vector<int> vec = {1, 2, 3};
    flexylist::Node<int> node1(4);
    flexylist::Node<std::string> node2("this node holds a string");
    flexylist::Node<std::vector<int>> node3(vec);
    node1.set_next(node2);
    node2.set_next(node3);

    EXPECT_EQ(&(node1.get_next()), &node2);
    EXPECT_EQ(&(node1.get_next().get_next()), &node3);
}

TEST(Node, Test_get_data)
{
    std::vector<int> vec = {1, 2, 3};
    flexylist::Node<int> node1(4);
    flexylist::Node<std::string> node2("this node holds a string");
    flexylist::Node<std::vector<int>> node3(vec);
    node1.set_next(node2);
    node2.set_next(node3);

    EXPECT_EQ(node1.get_next().get_data<std::string>(), "this node holds a string");
    EXPECT_EQ(node1.get_next().get_next().get_data<std::vector<int>>(), vec);
}

TEST(Node, Test_set_data)
{
    std::vector<int> vec = {1, 2, 3};
    flexylist::Node<int> node1(4);
    flexylist::Node<std::string> node2("this node holds a string");
    flexylist::Node<std::vector<int>> node3({1,2,3,4});
    node1.set_next(node2);
    node2.set_next(node3);
    node3.set_data(vec);

    EXPECT_EQ(node1.get_next().get_data<std::string>(), "this node holds a string");
    EXPECT_EQ(node1.get_next().get_next().get_data<std::vector<int>>(), vec);
}

