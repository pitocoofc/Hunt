#pragma once
#include <string>
#include <vector>

struct Node {
    std::string tag;
    std::string text;

    int x = 0;
    int y = 0;
    int width = 0;
    int height = 0;

    std::vector<Node*> children;
};
