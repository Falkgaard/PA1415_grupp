#include "catch.hpp"
#include "Warehouse.h"

TEST_CASE("Warehouses can be constructed", "[Warehouse]") {
	Warehouse warehouse0;
	Warehouse warehouse1;
	Warehouse warehouse2;

	SECTION("Warehouse id gets assigned properly"){
		REQUIRE(warehouse0.getId() == 0);
		REQUIRE(warehouse1.getId() == 1);
		REQUIRE(warehouse2.getId() == 2);
	}
}
