#ifndef HITTABLE_H
#define HITTABLE_H

#include "interval.h"
#include "ray.h"

class hit_record {
 public:
  point3 p;
  vec3 normal;
  double t;
  bool front_face;

  void init_face_normal(const ray& r, const vec3& outwardNormal) {
    // assumes the normal is a unit vector; it's a front face if the incoming ray is 'against' the normal
    front_face = dot(r.direction(), outwardNormal) < 0;
    // if it's a back face, invert it so that it faces outward at all times
    normal = front_face ? outwardNormal : -outwardNormal;
  }
};

class hittable {
 public:
  virtual ~hittable() = default;
  virtual bool hit(const ray& r, interval ray_t, hit_record& rec) const = 0;
};

#endif
