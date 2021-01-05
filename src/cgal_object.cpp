#include "cgal_object.h"

Segments_3 Polygon_3::edges_3() const
{
    auto segments_3 = Segments_3{};
    auto num = _points_3.size();
    assert(num >= 3);
    segments_3.push_back(Segment_3{_points_3[num - 1], _points_3[0]});
    for (size_t i = 1; i < num; i++)
        segments_3.push_back(Segment_3{_points_3[i - 1], _points_3[i]});
    return segments_3;
}


Polygons_3 generate_poly_3(size_t num)
{
    auto rand = CGAL::Random{0};
    auto polys_3 = Polygons_3{};

    const double RADIUS = 1.0;
    int N = 5;
    boost::mt19937 gen;
    gen.seed(0u);
    while (num--)
    {
        Points_2 v;
        auto plane = Plane_3{
            FT{rand.get_double(-1, 1)},
            FT{rand.get_double(-1, 1)},
            FT{rand.get_double(-1, 1)},
            FT{rand.get_double(-0.5, 0.5)}};
        random_convex_hull_in_disc_2(N, RADIUS, gen, std::back_inserter(v), K());
        polys_3.push_back(Polygon_3{plane, v});
    }

    return polys_3;
}

Polygons_3 generate_box()
{
    auto polys_3 = Polygons_3{};
    const double RADIUS = 0.5;
    const double S = 0.5;
    int N = 15;
    boost::mt19937 gen;
    gen.seed(0u);
    {
        auto plane = Plane_3{1, 0, 0, S};
        Points_2 v;
        random_convex_hull_in_disc_2(N, RADIUS, gen, std::back_inserter(v), K());
        polys_3.push_back(Polygon_3{plane, v});
    }
    {
        auto plane = Plane_3{1, 0, 0, -S};
        Points_2 v;
        random_convex_hull_in_disc_2(N, RADIUS, gen, std::back_inserter(v), K());
        polys_3.push_back(Polygon_3{plane, v});
    }
    {
        auto plane = Plane_3{0, 1, 0, S};
        Points_2 v;
        random_convex_hull_in_disc_2(N, RADIUS, gen, std::back_inserter(v), K());
        polys_3.push_back(Polygon_3{plane, v});
    }
    {
        auto plane = Plane_3{0, 1, 0, -S};
        Points_2 v;
        random_convex_hull_in_disc_2(N, RADIUS, gen, std::back_inserter(v), K());
        polys_3.push_back(Polygon_3{plane, v});
    }
    {
        auto plane = Plane_3{0, 0, 1, S};
        Points_2 v;
        random_convex_hull_in_disc_2(N, RADIUS, gen, std::back_inserter(v), K());
        polys_3.push_back(Polygon_3{plane, v});
    }
    {
        auto plane = Plane_3{0, 0, 1, -S};
        Points_2 v;
        random_convex_hull_in_disc_2(N, RADIUS, gen, std::back_inserter(v), K());
        polys_3.push_back(Polygon_3{plane, v});
    }
    return polys_3;
}
