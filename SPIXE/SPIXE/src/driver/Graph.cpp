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
}

