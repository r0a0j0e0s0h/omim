#include "../../testing/testing.hpp"

#include "../../base/macros.hpp"

#include "../region2d.hpp"


namespace {

template <class RegionT> struct ContainsChecker
{
  RegionT const & m_region;
  ContainsChecker(RegionT const & region) : m_region(region) {}
  void operator()(typename RegionT::ValueT const & pt)
  {
    TEST(m_region.Contains(pt), ("Region should contain all it's points"));
  }
};

/// Region should have CCW orientation from left, down corner.
template <class PointT>
void TestContainsRectangular(PointT const * arr)
{
  m2::Region<PointT> region;

  size_t const count = 4;
  region.Assign(arr, arr + count);

  for (size_t i = 0; i < count; ++i)
  {
    region.Contains(arr[i]);
    region.Contains((arr[i] + arr[(i + count - 1) % count]) / 2);
  }

  PointT dx(1, 0);
  PointT dy(0, 1);

  TEST(!region.Contains(arr[0] - dx), ());
  TEST(!region.Contains(arr[0] - dy), ());
  TEST(!region.Contains(arr[0] - dx - dy), ());
  TEST(region.Contains(arr[0] + dx + dy), ());

  TEST(!region.Contains(arr[1] + dx), ());
  TEST(!region.Contains(arr[1] - dy), ());
  TEST(!region.Contains(arr[1] + dx - dy), ());
  TEST(region.Contains(arr[1] - dx + dy), ());

  TEST(!region.Contains(arr[2] + dx), ());
  TEST(!region.Contains(arr[2] + dy), ());
  TEST(!region.Contains(arr[2] + dx + dy), ());
  TEST(region.Contains(arr[2] - dx - dy), ());

  TEST(!region.Contains(arr[3] - dx), ());
  TEST(!region.Contains(arr[3] + dy), ());
  TEST(!region.Contains(arr[3] - dx + dy), ());
  TEST(region.Contains(arr[3] + dx - dy), ());
}

template <class RegionT>
void TestContaints()
{
  RegionT region;
  ContainsChecker<RegionT> checker(region);

  // point type
  typedef typename RegionT::ValueT P;

  // rectangular polygon
  {
    P const data[] = { P(1, 1), P(10, 1), P(10, 10), P(1, 10) };
    TestContainsRectangular(data);
  }
  {
    P const data[] = { P(-100, -100), P(-50, -100), P(-50, -50), P(-100, -50) };
    TestContainsRectangular(data);
  }
  {
    P const data[] = { P(-2000000000, -2000000000), P(-1000000000, -2000000000),
                       P(-1000000000, -1000000000), P(-2000000000, -1000000000) };
    TestContainsRectangular(data);
  }
  {
    P const data[] = { P(1000000000, 1000000000), P(2000000000, 1000000000),
                       P(2000000000, 2000000000), P(1000000000, 2000000000) };
    TestContainsRectangular(data);
  }

  // triangle
  {
    P const data[] = {P(0, 0), P(2, 0), P(2, 2) };
    region.Assign(data, data + ARRAY_SIZE(data));
  }
  TEST_EQUAL(region.GetRect(), m2::Rect<typename P::value_type>(0, 0, 2, 2), ());
  TEST(region.Contains(P(2, 0)), ());
  TEST(region.Contains(P(1, 1)), ("point on diagonal"));
  TEST(!region.Contains(P(33, 0)), ());
  region.ForEachPoint(checker);

  // complex polygon
  {
    P const data[] = { P(0, 0), P(2, 0), P(2, 2), P(3, 1), P(4, 2), P(5, 2),
        P(3, 3), P(3, 2), P(2, 4), P(6, 3), P(7, 4), P(7, 2), P(8, 5), P(8, 7),
        P(7, 7), P(8, 8), P(5, 9), P(6, 6), P(5, 7), P(4, 6), P(4, 8), P(3, 7),
        P(2, 7), P(3, 6), P(4, 4), P(0, 7), P(2, 3), P(0, 2) };
    region.Assign(data, data + ARRAY_SIZE(data));
  }
  TEST_EQUAL(region.GetRect(), m2::Rect<typename P::value_type>(0, 0, 8, 9), ());
  TEST(region.Contains(P(0, 0)), ());
  TEST(region.Contains(P(3, 7)), ());
  TEST(region.Contains(P(1, 2)), ());
  TEST(region.Contains(P(1, 1)), ());
  TEST(!region.Contains(P(6, 2)), ());
  TEST(!region.Contains(P(3, 5)), ());
  TEST(!region.Contains(P(5, 8)), ());
  region.ForEachPoint(checker);
}

}

UNIT_TEST(Region)
{
  typedef m2::PointD P;
  P p1[] = { P(0.1, 0.2) };

  m2::Region<P> region(p1, p1 + ARRAY_SIZE(p1));
  TEST(!region.IsValid(), ());

  {
    P p2[] = { P(1.0, 2.0), P(55.0, 33.0) };
    region.Assign(p2, p2 + ARRAY_SIZE(p2));
  }
  TEST(!region.IsValid(), ());

  region.AddPoint(P(34.4, 33.2));
  TEST(region.IsValid(), ());

}

UNIT_TEST(Region_Contains)
{
  TestContaints<m2::RegionU>();
  TestContaints<m2::RegionD>();
  TestContaints<m2::RegionI>();

  // negative triangle
  {
    typedef m2::PointI P;
    m2::Region<P> region;
    P const data[] = { P(1, -1), P(-2, -2), P(-3, 1) };
    region.Assign(data, data + ARRAY_SIZE(data));

    TEST_EQUAL(region.GetRect(), m2::Rect<P::value_type>(-3, -2, 1, 1), ());

    TEST(region.Contains(P(-2, -2)), ());
    TEST(region.Contains(P(-2, 0)), ());
    TEST(!region.Contains(P(0, 0)), ());
  }

  {
    typedef m2::PointI P;
    m2::Region<P> region;
    P const data[] = { P(1, -1), P(3, 0), P(3, 3), P(0, 3), P(0, 2), P(0, 1), P(2, 2) };
    region.Assign(data, data + ARRAY_SIZE(data));

    TEST_EQUAL(region.GetRect(), m2::Rect<P::value_type>(0, -1, 3, 3), ());

    TEST(region.Contains(P(2, 2)), ());
    TEST(region.Contains(P(1, 3)), ());
    TEST(region.Contains(P(3, 1)), ());
    TEST(!region.Contains(P(1, 1)), ());
  }
}

template <class TPoint> class PointsSummator
{
  TPoint & m_res;
public:
  PointsSummator(TPoint & res) : m_res(res) {}
  void operator()(TPoint const & pt)
  {
    m_res += pt;
  }
};

UNIT_TEST(Region_ForEachPoint)
{
  typedef m2::PointF P;
  P const points[] = { P(0.0, 1.0), P(1.0, 2.0), P(10.5, 11.5) };
  m2::Region<P> region(points, points + ARRAY_SIZE(points));

  P res(0, 0);
  region.ForEachPoint(PointsSummator<P>(res));

  TEST_EQUAL(res, P(11.5, 14.5), ());
}
