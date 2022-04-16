// file name degree.h 
// Author Mohamed Roble
// Date 09/12/2019
#pragma once
#include <string>
enum DegreeType {SECURITY, NETWORK, SOFTWARE};//The three types of degree programs

//The following array of strings is useful for printing labels equivalent to the enumerated values
static const std::string degreeTypeStrings[] = { "SECURITY, NETWORKING, SOFTWARE" };

//You simply use the enumerated value as an index; for example,
//degreeTypeStrings[NETWORKING] yields the string "NETWORKING" and
//degreeTypeStrings[SOFTWARE] yields "SOFTWARE"
