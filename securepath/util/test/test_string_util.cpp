#include <external/catch/catch.hpp>
#include <securepath/test_frame/test_utils.hpp>
#include <securepath/util/string_util.hpp>
#include <securepath/util/conversions.hpp>

namespace securepath::test {

TEST_CASE("string_util hex", "[string_util]") {

	octet_vector vec1 = securepath::test::random_octet_vector((std::size_t)20);
	octet_vector vec2 = securepath::test::random_octet_vector((std::size_t)20);

	REQUIRE(vec1 != vec2);

	std::string str_res1 = to_hex(std::string(vec1.begin(), vec1.end()), "");
	std::string vec_res1 = to_hex(vec1);

	std::string str_res2 = to_hex(std::string(vec2.begin(), vec2.end()), "");
	std::string vec_res2 = to_hex(vec2);

	CHECK(vec_res1 == str_res1);
	CHECK(vec_res2 == str_res2);
	CHECK(vec_res1 != vec_res2);

}

TEST_CASE("string_util hex separator", "[string_util]") {

	CHECK("30" == to_hex("0", ""));
	CHECK("41-42" == to_hex("AB", "-"));
	CHECK("41ABC41" == to_hex("AA", "ABC"));
	CHECK("" == to_hex("", "X"));

}

TEST_CASE("string_util check to_hex characters", "[string_util]") {

	std::string s = to_hex(securepath::test::random_octet_vector((std::size_t)100));
	bool b = true;
	for(char c : s) {
		if(c < '0' || (c > '9' && c < 'A') || c > 'F') {
			b = false;
		}
	}
	CHECK(b);

}


TEST_CASE("string_util split_view", "[string_util]") {

	CHECK(split_view("") == std::vector<std::string_view>{});
	CHECK(split_view("a b c") == std::vector<std::string_view>{"a", "b", "c"});
	CHECK(split_view("a b c ") == std::vector<std::string_view>{"a", "b", "c", ""});
	CHECK(split_view(" a b c") == std::vector<std::string_view>{"", "a", "b", "c"});
	CHECK(split_view("a.b.c", ".") == std::vector<std::string_view>{"a", "b", "c"});
	CHECK(split_view("a...b.c", ".") == std::vector<std::string_view>{"a", "", "", "b", "c"});
}

}
