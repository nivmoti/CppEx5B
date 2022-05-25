#include "doctest.h"
#include <iostream>
#include <stdexcept>
#include <vector>
using namespace std;
#include "OrgChart.hpp"
using namespace ariel;
TEST_CASE("Not found the Father"){
    OrgChart organizaion;
    organizaion.add_root("SABA");
    CHECK_THROWS(organizaion.add_sub("ABA","YELED"));

}
TEST_CASE("Changing root+Good OrgChar"){
    OrgChart organizaion;
    CHECK_NOTHROW(organizaion.add_root("SABA"));
    CHECK_NOTHROW(organizaion.add_sub("SABA","ABA1"));
    CHECK_NOTHROW(organizaion.add_sub("SABA","ABA1"));
    CHECK_NOTHROW(organizaion.add_sub("SABA","ABA2"));
    CHECK_NOTHROW(organizaion.add_sub("SABA","ABA3"));
    CHECK_NOTHROW(organizaion.add_sub("ABA1","YELED1"));
    CHECK_NOTHROW(organizaion.add_sub("ABA1","YELED2"));
    CHECK_NOTHROW(organizaion.add_sub("ABA2","YELED3"));
    CHECK_NOTHROW(organizaion.add_sub("ABA3","YELED4"));
    CHECK_NOTHROW(organizaion.add_sub("ABA3","YELED5"));
    CHECK_NOTHROW(organizaion.add_root("SABA2"));
    auto it=organizaion.begin_level_order();
    CHECK((*it)=="SABA2");

}
TEST_CASE("Checking leveL order"){
     OrgChart organizaion;
    organizaion.add_root("SABA");
    organizaion.add_sub("SABA","ABA1");
    organizaion.add_sub("SABA","ABA2");
    organizaion.add_sub("SABA","ABA3");
    organizaion.add_sub("ABA1","YELED1");
    organizaion.add_sub("ABA1","YELED2");
    organizaion.add_sub("ABA2","YELED3");
    organizaion.add_sub("ABA3","YELED4");
    organizaion.add_sub("ABA3","YELED5");
    vector<string> names={"SABA","ABA1","ABA2","ABA3","YELED1","YELED2","YELED3","YELED4","YELED5"};
    unsigned long i=0;
    auto it = organizaion.begin_level_order();
    for (unsigned long i=0;i<9;i++){
        CHECK((*it)==names.at(i));
        ++it;

    }
    vector<string> names2={"YELED1","YELED2","YELED3","YELED4","YELED5","ABA1","ABA2","ABA3","SABA"};
    i=0;
    it = organizaion.begin_reverse_order();
    for (unsigned long i=0;i<9;i++){
        CHECK((*it)==names2.at(i));
        ++it;

    }
    i=0;
    for (auto element : organizaion){
        CHECK(element==names.at(i));
        i++;

    }

}
TEST_CASE("Checking pre Order"){
    OrgChart organizaion;
    organizaion.add_root("SABA");
    organizaion.add_sub("SABA","ABA1");
    organizaion.add_sub("SABA","ABA2");
    organizaion.add_sub("SABA","ABA3");
    organizaion.add_sub("ABA1","YELED1");
    organizaion.add_sub("ABA1","YELED2");
    organizaion.add_sub("ABA2","YELED3");
    organizaion.add_sub("ABA3","YELED4");
    organizaion.add_sub("ABA3","YELED5");
    unsigned long i=0;
    vector<string> names={"SABA","ABA1","YELED1","YELED2","ABA2","YELED3","ABA3","YELED4","YELED5"};
    auto it = organizaion.begin_preorder();
    for (unsigned long i=0;i<9;i++){
        CHECK((*it)==names.at(i));
        ++it;

    }
    

}
