#pragma once

#include "godot_cpp/classes/node3d.hpp"
#include "godot_cpp/core/class_db.hpp"
#include "godot_cpp/variant/array.hpp"

using namespace godot;

class DistanceSort : public Object {
	GDCLASS(DistanceSort, Object);

public:
	static void sort_by_distance(Array nodes, Node3D *target);

protected:
	static void _bind_methods();
};