#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include "../DNA.h"
using namespace DNA;

std::vector<std::string> getStrs() {
    std::vector<std::string> str;
    str.push_back("AGAT");
    str.push_back("AATG");
    str.push_back("TATC");
    return str;
}

std::vector<std::string> getGeneratedStrs() {
    std::vector<std::string> str;
    str.push_back("AGAT");
    str.push_back("AATG");
    str.push_back("TATC");
    str.push_back("CATG");
    str.push_back("TTCA");
    str.push_back("ACAG");
    return str;
}

TEST_CASE("DNA Search Handles First Case", "[weight=1]") {
    std::string input = "AGACGGGTTACCATGACTATCTATCTATCTATCTATCTATCTATCTATCACGTACGTACGTATCGAGATAGATAGATAGATAGATCCTCGACTTCGATCGCAATGAATGCCAATAGACAAAA";
    std::unordered_map<std::string, std::vector<int>> map;
    std::vector<int> alice = {5, 2, 9};
    std::vector<int> bob = {3, 7, 4};
    std::vector<int> charlie = {6, 1, 5};
    map.insert(std::pair<std::string, std::vector<int>>("Alice", alice));
    map.insert(std::pair<std::string, std::vector<int>>("Bob", bob));
    map.insert(std::pair<std::string, std::vector<int>>("Charlie", charlie));

    std::string match = findMatch(input, map, getStrs());
    REQUIRE(match == "Alice");
}
TEST_CASE("DNA Search Handles Second Case", "[weight=1]") {
    std::string input = "AACCCTGCGCGCGCGCGATCTATCTATCTATCTATCCAGCATTAGCTAGCATCAAGATAGATAGATGAATTTCGAAATGAATGAATGAATGAATGAATGAATG";
    std::unordered_map<std::string, std::vector<int>> map;

    std::vector<int> alice = {5, 2, 9};
    std::vector<int> bob = {3, 7, 4};
    std::vector<int> charlie = {6, 1, 5};
    map.insert(std::pair<std::string, std::vector<int>>("Alice", alice));
    map.insert(std::pair<std::string, std::vector<int>>("Bob", bob));
    map.insert(std::pair<std::string, std::vector<int>>("Charlie", charlie));

    std::string match = findMatch(input, map, getStrs());
    REQUIRE(match == "Bob");
}
TEST_CASE("DNA Search Handles No Match Case", "[weight=1]") {
    std::string input = "GGTACAGATGCAAAGATAGATAGATGTCGTCGAGCAATCGTTTCGATAATGAATGAATGAATGAATGAATGAATGACACACGTCGATGCTAGCGGCGGATCGTATATCTATCTATCTATCTATCAACCCCTAG";
    std::unordered_map<std::string, std::vector<int>> map;

    std::vector<int> alice = {5, 2, 9};
    std::vector<int> bob = {3, 7, 4};
    std::vector<int> charlie = {6, 1, 5};
    map.insert(std::pair<std::string, std::vector<int>>("Alice", alice));
    map.insert(std::pair<std::string, std::vector<int>>("Bob", bob));
    map.insert(std::pair<std::string, std::vector<int>>("Charlie", charlie));

    std::string match = findMatch(input, map, getStrs());
    REQUIRE(match == "No Match!");
}

TEST_CASE("DNA Search Handles Short Match Case", "[weight=1]") {
    std::string input = "AGATAGAC";
    std::unordered_map<std::string, std::vector<int>> map;

    std::vector<int> alice = {5, 2, 9};
    std::vector<int> bob = {3, 7, 4};
    std::vector<int> charlie = {6, 1, 5};
    std::vector<int> parth = {1, 0, 0};
    map.insert(std::pair<std::string, std::vector<int>>("Alice", alice));
    map.insert(std::pair<std::string, std::vector<int>>("Bob", bob));
    map.insert(std::pair<std::string, std::vector<int>>("Charlie", charlie));
    map.insert(std::pair<std::string, std::vector<int>>("Parth", parth));

    std::string match = findMatch(input, map, getStrs());
    REQUIRE(match == "Parth");
}

TEST_CASE("DNA Search Handles edge Input Case", "[weight=1]") {
    std::string input = "AGA";
    std::unordered_map<std::string, std::vector<int>> map;

    std::vector<int> alice = {5, 2, 9};
    std::vector<int> bob = {3, 7, 4};
    std::vector<int> charlie = {6, 1, 5};
    std::vector<int> parth = {1, 0, 0};
    map.insert(std::pair<std::string, std::vector<int>>("Alice", alice));
    map.insert(std::pair<std::string, std::vector<int>>("Bob", bob));
    map.insert(std::pair<std::string, std::vector<int>>("Charlie", charlie));
    map.insert(std::pair<std::string, std::vector<int>>("Parth", parth));

    std::string match = findMatch(input, map, getStrs());
    REQUIRE(match == "No Match!");
}

TEST_CASE("DNA Search Handles insufficient Input Case", "[weight=1]") {
    std::string input = "CCAGAT";
    std::unordered_map<std::string, std::vector<int>> map;

    std::vector<int> alice = {5, 2, 9};
    std::vector<int> bob = {3, 7, 4};
    std::vector<int> charlie = {6, 1, 5};
    std::vector<int> parth = {1, 0, 0};
    map.insert(std::pair<std::string, std::vector<int>>("Alice", alice));
    map.insert(std::pair<std::string, std::vector<int>>("Bob", bob));
    map.insert(std::pair<std::string, std::vector<int>>("Charlie", charlie));
    map.insert(std::pair<std::string, std::vector<int>>("Parth", parth));

    std::string match = findMatch(input, map, getStrs());
    REQUIRE(match == "Parth");
}

TEST_CASE("DNA Search Handles generated Input Case # 1", "[weight=1]") {
    std::string input = "CTTCATATCAGATAATGCATGGTAAGATTTCACGTTCACATGCATGTTCATCATGTTCACATGGCATGCATGTTATC";
    std::unordered_map<std::string, std::vector<int>> map;

    std::vector<int> alice = {6, 2, 2, 2, 1, 2};
    std::vector<int> bob = {2, 1, 2, 7, 5, 0};
    std::vector<int> charlie = {0, 7, 0, 1, 4, 7};
    std::vector<int> parth = {6, 4, 4, 5, 4, 5};
    std::vector<int> george = {3, 2, 2, 1, 2, 3};
    std::vector<int> john = {0, 0, 2, 0, 1, 4};
    std::vector<int> thomas = {2, 2, 5, 4, 4, 6};
    std::vector<int> james = {3, 0, 3, 4, 1, 6};
    std::vector<int> andrew = {6, 6, 1, 3, 5, 7};
    std::vector<int> abraham = {2, 3, 4, 7, 4, 7};
    std::vector<int> theodore = {6, 1, 2, 3, 5, 3};
    std::vector<int> franklin = {2, 5, 3, 6, 0, 5};
    std::vector<int> harry = {7, 0, 2, 4, 6, 0};
    std::vector<int> dwight = {5, 3, 7, 6, 2, 6};
    
    map.insert(std::pair<std::string, std::vector<int>>("Alice", alice));
    map.insert(std::pair<std::string, std::vector<int>>("Bob", bob));
    map.insert(std::pair<std::string, std::vector<int>>("Charlie", charlie));
    map.insert(std::pair<std::string, std::vector<int>>("Parth", parth));
    map.insert(std::pair<std::string, std::vector<int>>("George", george));
    map.insert(std::pair<std::string, std::vector<int>>("John", john));
    map.insert(std::pair<std::string, std::vector<int>>("Thomas", thomas));
    map.insert(std::pair<std::string, std::vector<int>>("James", james));
    map.insert(std::pair<std::string, std::vector<int>>("Andrew", andrew));
    map.insert(std::pair<std::string, std::vector<int>>("Abraham", abraham));
    map.insert(std::pair<std::string, std::vector<int>>("Theodore", theodore));
    map.insert(std::pair<std::string, std::vector<int>>("Franklin", franklin));
    map.insert(std::pair<std::string, std::vector<int>>("Harry", harry));
    map.insert(std::pair<std::string, std::vector<int>>("Dwight", dwight));
    

    std::string match = findMatch(input, map, getGeneratedStrs());
    REQUIRE(match == "Bob");
}

TEST_CASE("DNA Search Handles generated Input Case # 2", "[weight=1]") {

    std::string input = "TTCAAGATTTCAAGATTTCAAATGCAATGAGATAGATAATGCATGTATCACTATCAGATAACATGAAGATTATCTATCTCCATGACATGCATGATACACCATG";
    std::vector<std::string> names = {"Alice", "Bob", "Charlie", "Parth", "George", "John", "Thomas", "James", "Andrew", "Abraham", "Theodore", "Franklin", "Harry", "Dwight"};
    std::vector<std::vector<int>> occurences = {{1, 0, 1, 6, 5, 3},{3, 4, 1, 0, 7, 4},{6, 3, 4, 6, 3, 0},{4, 6, 7, 4, 7, 7},{1, 5, 1, 5, 0, 6},{2, 2, 6, 4, 1, 3},
    {7, 4, 6, 5, 5, 0},{4, 0, 6, 5, 3, 3},{5, 6, 1, 4, 6, 0},{3, 1, 2, 3, 3, 7},{4, 6, 4, 5, 2, 7},{3, 4, 4, 3, 6, 5},{4, 6, 6, 5, 3, 6},{1, 0, 2, 0, 5, 2}};
    

    std::string match = findMatch(input, occurences, names, getGeneratedStrs());
    REQUIRE(match == "Charlie");
}

TEST_CASE("DNA Search Handles generated Input Case # 3", "[weight=1]") {

    std::string input = "GTAGATCATGACAGTATCTATCACAGAGATTTCAACAGCATGCATGAATGGTTCACATACAGAATGTATCCATGGAATGCATGCCATGTATCTTATCAACAGGTATCACAGACAG";
    std::vector<std::string> names = {"Alice", "Bob", "Charlie", "Parth", "George", "John", "Thomas", "James", "Andrew", "Abraham", "Theodore", "Franklin", "Harry", "Dwight"};
    std::vector<std::vector<int>> occurences = {{2, 0, 1, 7, 2, 2}, {4, 7, 7, 2, 3, 5}, {4, 3, 0, 7, 2, 3}, {4, 3, 5, 3, 1, 5}, {4, 0, 7, 3, 1, 3}, {2, 2, 1, 7, 2, 6}, {1, 4, 1, 0, 6, 0},
    {2, 3, 6, 6, 2, 7}, {4, 0, 5, 3, 6, 1}, {2, 3, 7, 0, 0, 6}, {6, 2, 4, 1, 2, 2}, {6, 2, 7, 6, 1, 2}, {7, 1, 0, 6, 4, 6}, {7, 7, 1, 5, 2, 3}};
    

    std::string match = findMatch(input, occurences, names, getGeneratedStrs());
    REQUIRE(match == "James");
}

TEST_CASE("DNA Search Handles generated Input Case # 4", "[weight=1]") {
    std::string input = "ACAGAGATCATGAATGACATGGACAGCATGAATGAGATAATGAATGCATGAAATGCATGGAATGTTCAATATCTTCAAGTTCACAGATTTATCTATCCTATCTATCAGATTATCCGAGATAGATTATCAGATATCCATG";
    std::vector<std::string> names = {"Alice", "Bob", "Charlie", "Parth", "George", "John", "Thomas", "James", "Andrew", "Abraham", "Theodore", "Franklin", "Harry", "Dwight"};
    std::vector<std::vector<int>> occurences = {{1, 6, 5, 1, 3, 1}, {7, 6, 8, 6, 3, 3}, {3, 0, 6, 2, 4, 0}, {4, 5, 4, 3, 2, 7}, {2, 5, 3, 1, 6, 7}, {3, 2, 3, 5, 3, 5}, {7, 3, 4, 7, 6, 1},
    {3, 6, 4, 0, 5, 7}, {6, 0, 6, 4, 4, 7}, {3, 2, 0, 4, 5, 6}, {0, 4, 7, 0, 3, 3}, {4, 4, 7, 6, 1, 1}, {7, 3, 7, 1, 7, 2}, {6, 1, 3, 0, 2, 6}};
    

    std::string match = findMatch(input, occurences, names, getGeneratedStrs());
    REQUIRE(match == "Bob");
}

TEST_CASE("DNA Search Handles generated Input Case # 5", "[weight=1]") {
    std::string input = "AATGAGATAAATGCATGCATGTTCAACAGTATCTTCACATGTATCTTCAGAGATCATGAGATACAGTTCATTCAAATGCATGAACAGCATGTCCATGTATCAGATAGATGACAGACAGGCACAGATTACAG";
    std::vector<std::string> names = {"Alice", "Bob", "Charlie", "Parth", "George", "John", "Thomas", "James", "Andrew", "Abraham", "Theodore", "Franklin", "Harry", "Dwight"};
    std::vector<std::vector<int>> occurences = {{4, 2, 1, 1, 7, 1}, {1, 7, 5, 1, 1, 5}, {3, 5, 5, 5, 2, 4}, {4, 6, 1, 0, 6, 3}, {3, 7, 3, 3, 0, 5}, {5, 1, 3, 3, 5, 4}, {2, 5, 0, 7, 4, 0}, {6, 3, 3, 7, 5, 7},
    {1, 0, 5, 7, 6, 7}, {3, 3, 4, 5, 3, 1}, {4, 0, 7, 2, 7, 0}, {1, 5, 1, 7, 3, 6}, {6, 0, 5, 6, 0, 5}, {1, 1, 7, 0, 2, 5}};

    std::string match = findMatch(input, occurences, names, getGeneratedStrs());
    REQUIRE(match == "James");
}