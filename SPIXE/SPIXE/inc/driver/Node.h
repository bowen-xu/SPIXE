#ifndef _NODE_H_
#define _NODE_H_

#include <spixe_driver_types.h>

namespace spixe
{
	class Node
	{
	public:

		template <class _Model = Node>
		static inline bool setType(uint8 type_id);
		template <class _Model = Node>
		static inline uint8 getType();
		template <class _Model = Node>
		static inline bool isTypeRegistered();
		template <class _Model = Node>
		static inline void resetType(uint8 type_id);
	private:
		static uint8 _type_id;
	};
	template <class _Model>
	inline bool Node::setType(uint8 type_id)
	{
		if (isTypeRegistered<_Model>())
		{
			return false;
		}
		else
		{
			resetType<_Model>(type_id);
			return true;
		}

	}
	template <class _Model>
	inline uint8 Node::getType()
	{
		return _Model::_type_id;
	}
	template <class _Model>
	inline bool Node::isTypeRegistered()
	{
		return getType<_Model>() != (uint8)(-1);
	}
	template <class _Model>
	inline void Node::resetType(uint8 type_id)
	{
		_Model::_type_id = type_id;
	}
}



#endif // !_NODE_H_
