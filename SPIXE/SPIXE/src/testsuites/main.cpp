#include <stdio.h>
#include <stdlib.h>
#include <Testsuites.h>

#define attribute(name, member) &name::member

#define forloop(i, n) \
	for (i = 0; i < n; i++)	

#define type(nodeclass) nodeclass::type_id

#define Model_begin(ClassName, ParentName)	\
	class ClassName:  ParentName			\
	{											\
	public:										\
		static int type_id;				

#define Model_end(ClassName) \
	};							\
	int ClassName::type_id = -1;

template <class _ModelType>
void registModel()
{
	static int total = 0;
	type(_ModelType) = total;
	total++;
}

class TestClass
{
public:
	//virtual void ttt() {}
	TestClass()
	{
		printf("new TestClass\n");
	}
	//static int type_id;

	template <class _ClassType>
	int addNode(_ClassType c)
	{
		int size = sizeof(_ClassType);
		return size;
	}
};

struct TestClass2
{
public:
	//static int type_id;
};

//int TestClass::type_id = -1;
//int TestClass2::type_id = -1;

Model_begin(TestClass3, public TestClass)

Model_end(TestClass3)


void main()
{
	printf("Running Testsuits...\n");

	testing::InitGoogleTest();
	TestGraph();
	RUN_ALL_TESTS();


	system("pause");
}