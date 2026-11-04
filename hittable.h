#ifndef HITTABLE_H
#define HITTABLE_H

#include "ray.h"

class hit_record {
 public:
  point3 p;
  vec3 normal;
  double t;
  bool front_face;

  void init_face_normal(const ray& r, const vec3& outwardNormal) {
    // assumes the normal is a unit vector
    front_face = dot(r.direction(), outwardNormal) < 0;
    // if it's a back face, invert it
    normal = front_face ? outwardNormal : -outwardNormal;
  }
};

class hittable {
 public:
  virtual ~hittable() = default;
  virtual bool hit(const ray& r, double ray_tmin, double ray_tmax, hit_record& rec) const = 0;
};

#endif
