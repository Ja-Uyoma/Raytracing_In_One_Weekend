// Boost Software License - Version 1.0 - August 17th, 2003

// Permission is hereby granted, free of charge, to any person or organization
// obtaining a copy of the software and accompanying documentation covered by
// this license (the "Software") to use, reproduce, display, distribute,
// execute, and transmit the Software, and to prepare derivative works of the
// Software, and to permit third-parties to whom the Software is furnished to
// do so, all subject to the following:

// The copyright notices in the Software and this entire statement, including
// the above license grant, this restriction and the following disclaimer,
// must be included in all copies of the Software, in whole or in part, and
// all derivative works of the Software, unless such copies or derivative
// works are solely in the form of machine-executable object code generated by
// a source language processor.

// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE, TITLE AND NON-INFRINGEMENT. IN NO EVENT
// SHALL THE COPYRIGHT HOLDERS OR ANYONE DISTRIBUTING THE SOFTWARE BE LIABLE
// FOR ANY DAMAGES OR OTHER LIABILITY, WHETHER IN CONTRACT, TORT OR OTHERWISE,
// ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
// DEALINGS IN THE SOFTWARE.

#ifndef HITTABLE_LIST_HPP
#define HITTABLE_LIST_HPP

#include "Hittable.hpp"
#include <memory>
#include <vector>

namespace rt::hittable {

class HittableList final : public Hittable
{
public:
  /// Default constructor
  constexpr explicit HittableList() noexcept = default;

  /// Constructor
  /// \param[in] object A std::shared_ptr to the Hittable object to be added to the HittableList instance
  constexpr explicit HittableList(std::shared_ptr<Hittable> const& object) noexcept
  {
    add(object);
  }

  /// Erase all the elements in the HittableList instance
  constexpr void clear() noexcept
  {
    m_objects.clear();
  }

  /// Add a Hittable object to the HittableList instance
  /// \param[in] object A std::shared_ptr to the Hittable object to be added to the HittableList instance
  constexpr void add(std::shared_ptr<Hittable> const& object)
  {
    m_objects.push_back(object);
  }

  /// Check if a ray has intersected any of the Hittable objects in the HittableList instance
  /// \param[in] ray The ray that intersects a Hittable object
  /// \param[in] tMin The lower bound of the distance between the ray and the object that counts as a valid intersection
  /// \param[in] tMax The upper bound of the distance between the ray and the object that counts as a valid intersection
  /// \param[inout] record
  /// \returns true if there was an intersection and false otherwise
  bool hit(ray::Ray const& ray, double tMin, double tMax, HitRecord& record) const noexcept override;

private:
  std::vector<std::shared_ptr<Hittable>> m_objects;
};

}   // namespace rt::hittable

#endif