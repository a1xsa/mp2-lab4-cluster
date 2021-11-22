#include "pch.h"

#include "../base/cluster.h"


TEST(TCluster, can_create_cluster_with_ok_parameter)
{
	ASSERT_NO_THROW(TCluster p(5,5,5,0.5));
}


TEST(TCluster, cant_create_cluster_with_wrong_parameter)
{
	ASSERT_ANY_THROW(TCluster p(2, -1, 2, 0));
}