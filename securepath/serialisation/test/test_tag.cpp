#include <external/catch/catch.hpp>

#include "util.hpp"
#include "types.hpp"

namespace securepath::serialisation::test {

TEST_CASE("tag basic serialisation", "[tag][serialisation]") {
	CHECK(check<t1>(t1{}));
	CHECK(check<t2>(t2{}));
}

}
