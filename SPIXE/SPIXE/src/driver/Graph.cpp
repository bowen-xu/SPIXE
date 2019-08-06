#include <Graph.h>

namespace spixe
{
	Graph::Graph(uint32 max_nodes, uint32 max_edges)
	{
		_nodes.clear();
		_nodes.set_capacity(max_nodes);

		_edges.clear();
		_edges.set_capacity(max_edges);
	}

	void Graph::addNode(ModelType t)
	{
		_nodes.push_back();
		_nodes.back().type = t;
	}

	Nodes Graph::addNode(uint32 num, ModelType t)
	{
		assert(num < _nodes.capacity() - _nodes.size());
		assert(num > 0);
		addNode(t);
		Nodes n = &(_nodes.back());
		for (uint32 i = 0; i < num - 1; i++)
		{
			addNode(t);
		}
		return n;
	}

	void Graph::connect(uint32 id_prenode, uint32 id_postnode)
	{
		assert(_edges.size() < _edges.capacity());

		_edges.push_back();
		_edges.back().id_prenode = id_prenode;
		_edges.back().id_postnode = id_postnode;

		_nodes[id_prenode].num_postedges++;
		_nodes[id_postnode].num_preedges++;
	}

	void Graph::connect(Nodes& node, uint32 n_prenode, uint32 n_postnode)
	{
		uint32 bias = (uint32)(node - &(_nodes.front()));
		connect(bias + n_prenode, bias + n_postnode);
	}

	void Graph::build()
	{
		// TODO: 
		// ����һ���ڴ�ռ�
		// ����_nodes��_edges�е����ݣ�ȷ��Ҫ���ٵ��ڴ�ռ�Ĵ�С
		// �ڸÿռ��У����ǰ���ڽӱ�����Ž��ʵ��
		// Ҫ���ݽ��id������ÿһ��ʵ����size
		// Ȼ���ڸÿռ���ʵ����ÿһ����㣬����Ҫ�õ���̬����

		// allocate ram for storing the adjacency lists
		uint64 ram_size = 0;
		uint32 num_nodes = _nodes.size() + 1;
		uint32 num_edges = _edges.size();

		ram_size += num_nodes * 2 * sizeof(uint32);
		ram_size += num_edges * 2 * sizeof(uint32);
		ram_size += num_edges * sizeof(uint16);

		uint8* memory = (uint8*)malloc(ram_size);
		uint8* memory_init = memory;

		_pre_adjlist_head.set(num_nodes, memory);
		memory +=  _pre_adjlist_head.unitsize();

		_post_adjlist_head.set(num_nodes, memory);
		memory += _post_adjlist_head.unitsize();

		_pre_adjlist_body.set(num_edges, memory);
		memory += _pre_adjlist_body.unitsize();

		_post_adjlist_body.set(num_edges, memory);
		memory += _post_adjlist_body.unitsize();

		_post_adjlist_preindex.set(num_edges, memory);
		memory += _post_adjlist_preindex.unitsize();

		assert((uint64)(memory - memory_init) == ram_size);
		
		// allocate ram for stroing node instances
		// TODO: code here
		//		 implement a class Accessor to access the instances.
		
		// assign values the lists
		uint32 total;
		uint64 i;
		total = 0;
		for (i = 0; i < _pre_adjlist_head.size() - 1; i++)
		{
			_pre_adjlist_head.at(i) = total;
			total += _nodes[i].num_preedges;
		}
		_pre_adjlist_head.at(i) = total;

		total = 0;
		for (i = 0; i < _post_adjlist_head.size() - 1; i++)
		{
			_post_adjlist_head.at(i) = total;
			total += _nodes[i].num_postedges;
		}
		_post_adjlist_head.at(i) = total;

		// ... ... ����д�����ڽӱ�ı���ֵ�����ݵ���_edges
	}
}

