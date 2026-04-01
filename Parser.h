#pragma once
#include "DOM.h"
#include <string>

class Parser {
public:
    Node* parseHTML(const std::string& html);
};
