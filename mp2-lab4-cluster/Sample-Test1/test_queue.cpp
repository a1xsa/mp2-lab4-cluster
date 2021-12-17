#include "pch.h"

#include "../base/queue.h"


TEST(TQueue, can_create_queue_with_positive_length)
{
	ASSERT_NO_THROW(TQueue<int> q(5));
}

TEST(TQueue, cant_create_queue_with_negative_or_zero_length)
{
	ASSERT_ANY_THROW(TQueue<int> q(0), q1(-1));
}

TEST(TQueue, cant_create_queue_with_too_much_length)
{
	ASSERT_ANY_THROW(TQueue<int> q(101));
}

TEST(TQueue, true_queue_full)
{
	TQueue<int> q(1);
	q.Push(3);
	EXPECT_EQ(true, q.Full());
}
TEST(TQueue, true_queue_emtpy)
{
	TQueue<int> q(1);
	EXPECT_EQ(true, q.Empty());
}
TEST(TQueue, true_queue_get_size)
{
	TQueue<int> q(2);
	EXPECT_EQ(2, q.GetSize());
}
TEST(TQueue, true_queue_get_count)
{
	TQueue<int> q(2);
	EXPECT_EQ(0, q.GetCount());
}
TEST(TQueue, can_push_elem)
{
	TQueue<int> q(2);
	ASSERT_NO_THROW(q.Push(5););
}
TEST(TQueue, can_get_info_li_elem)
{
	TQueue<int> q(2);
	q.Push(3);
	EXPECT_EQ(3,q.InfoLi());
}
TEST(TQueue, can_set_size_elem)
{
	TQueue<int> q(2);
	q.setsize(4);
	EXPECT_EQ(4, q.GetSize());
}



