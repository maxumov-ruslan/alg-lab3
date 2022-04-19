#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"
#include "lis.hpp"
#include "parens.hpp"
#include <vector>



TEST_CASE("Check findLIS", "[LIS]") {
	std::vector<int> seq = {3,4,9,2,5,1};
	std::vector<int> lis = findLIS(seq);
	REQUIRE(lis.size() == 3);

}
TEST_CASE("Check findLISOptimal", "[LIS]") {
	std::vector<int> seq = {3,4,9,2,5,1};
	std::vector<int> lis = findLISOptimal(seq);
	REQUIRE(lis.size() == 3);

}
TEST_CASE("Check parens", "[LIS]") {
	std::vector<int> seq = {3,4,9,2,5,1};
	Parentheses parens(seq);

	REQUIRE(parens.CalculateBest() == 23);
	REQUIRE(parens.printBestOrder() == "(3) + ((4) + ((9) + ((2) + ((5) * (1)))))");
}
