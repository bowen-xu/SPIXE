#include <Testsuites.h>

using namespace spixe;




class NodeTest : public Node
{
	friend class Node;
public:

private:
	static uint8 _type_id;
	
};

uint8 NodeTest::_type_id = (uint8)(-1);

#define model(classname) Node::getType<classname>()

TEST(TestSuite_Graph, TestCase_Store)
{
	Graph g(1e3, 1e6);
	g.setTimegrit((float)0.01);
	ASSERT_TRUE(g.registModel<Node>());
	ASSERT_TRUE(g.registModel<NodeTest>());
	ASSERT_FLOAT_EQ(g.getTimegrit(), (float)0.01);

	Nodes n1 = g.addNode(2, model(Node));
	Nodes n2 = g.addNode(8, model(NodeTest));
	g.connect(0, 1);
	g.connect(1, 9);

	ASSERT_EQ(n1[0].type, model(Node));
	ASSERT_EQ(n2[0].type, model(NodeTest));
	ASSERT_EQ(n1[0].num_postedges, 1);
	ASSERT_EQ(n1[1].num_preedges, 1);
	ASSERT_EQ(n1[1].num_postedges, 1);
	ASSERT_EQ(n2[7].num_preedges, 1);



}


void TestGraph()
{
	testing::FLAGS_gtest_filter = "TestSuite_Graph.*";
}

