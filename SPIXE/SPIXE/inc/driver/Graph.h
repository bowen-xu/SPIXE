#ifndef _GRAPH_H_
#define _GRAPH_H_

#include <vector>
#include <boost/circular_buffer.hpp>

#include <spixe_driver_types.h>

#include <Node.h>


namespace spixe
{
	using std::vector;
	using boost::circular_buffer;

	// used to store node's info before build the graph. see Graph::build().
	struct GraphNode
	{
		uint8 type;
		uint16 num_preedges = 0;
		uint32 num_postedges = 0;
	};

	// used to store edge's info before build the graph. see Graph::build().
	struct GraphEdge
	{
		uint16 id_prenode;
		uint16 id_postnode;
	};

	typedef circular_buffer<GraphNode> GraphNodes;
	typedef circular_buffer<GraphEdge> GraphEdges;
	typedef GraphNode* Nodes;

	class Graph
	{
	public:
		Graph(uint32 max_nodes = 1000, uint32 max_edges = 1000000);

		template <class _Model>
		bool registModel();

		inline void setTimegrit(float grit);
		inline float getTimegrit();

		Nodes addNode(uint32 num, ModelType t);
		void addNode(ModelType t);

		void connect(uint32 id_prenode, uint32 id_postnode);

		void step();
		void step(uint32 num);

		template <typename _ParamType>
		void setNode(Node& node, void* addr, _ParamType param);

		void build();

	private:
		// used when register a model. see @registerModel().
		uint8 _total_type_id = 0;

		float _timegrit = (float)0.001;

		GraphNodes _nodes;
		GraphEdges _edges;
	};

	template <class _Model>
	bool Graph::registModel()
	{
		bool success = _Model::setType<_Model>(_total_type_id);
		_total_type_id++;
		return success;
	}

	inline void Graph::setTimegrit(float grit)
	{
		_timegrit = grit;
	}
	inline float Graph::getTimegrit()
	{
		return _timegrit;
	}
}

#endif // !_GRAPH_H_