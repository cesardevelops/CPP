//
//  textParsing.hpp
//  Graphs
//
//  Created by Cesar Montero on 2/28/21.
//

#ifndef textParsing_hpp
#define textParsing_hpp

#include <stdio.h>

#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

void RemoveChar(std::string &myString, char &char_to_remove);

void RemoveCharacters(std::string &myString, std::vector<char> &list);

std::vector<int> CountWords(std::string myString);

int GetBiggestInt(std::vector<int> &counts);

std::string ReadFile(std::string &path);

#endif /* textParsing_hpp */
