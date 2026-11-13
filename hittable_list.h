#ifndef HITTABLE_LIST_H
#define HITTABLE_LIST_H

#include "hittable.h";

#include <memory>
#include <vector>

using std::make_shared;
using std::shared_ptr;

class hittable_list : public hittable {
 public:
  std::vector<shared_ptr<hittable>> hittables;

  hittable_list() {}

  void clear() { hittables.clear(); }

  void add(shared_ptr<hittable> obj) { hittables.push_back(obj); }

  bool hit(const ray& r, double ray_tmin, double ray_tmax, hit_record& rec) const override {
    hit_record temp_rec;
    bool hit_anything;
    auto closest = ray_tmax;

    for (const auto& hittable : hittables) {
      if (hittable->hit(r, ray_tmin, closest, temp_rec)) {
        closest = temp_rec.t;
        hit_anything = true;
        rec = temp_rec;
      }
    }

    return hit_anything;
  }
};

#endif
