#include "distance_sort.h"
#include <algorithm>

using namespace godot;

void DistanceSort::_bind_methods() {
    ClassDB::bind_static_method("DistanceSort", D_METHOD("sort_by_distance", "nodes", "target"), &DistanceSort::sort_by_distance);
}

void DistanceSort::sort_by_distance(Array nodes, Node3D *target) {
    if (!target)
        return;

    Vector3 base = target->get_global_position();

    std::vector<std::pair<real_t, Object *>> sortable;
    sortable.reserve(nodes.size());

    for (int i = 0; i < nodes.size(); ++i) {
        auto obj = Object::cast_to<Node3D>(nodes[i]);
        ERR_FAIL_COND_MSG(!obj, "All elements must be Node3D");
        real_t d = base.distance_squared_to(obj->get_global_position());
        sortable.emplace_back(d, obj);
    }

    std::sort(
            sortable.begin(),
            sortable.end(),
            [](auto &a, auto &b) { return a.first < b.first; });

    for (int i = 0; i < sortable.size(); ++i) {
        nodes[i] = sortable[i].second;
    }

    return;
}