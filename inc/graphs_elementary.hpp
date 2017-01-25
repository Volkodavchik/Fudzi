/**
 *	@file graphs_elementary.hpp
 *	@brief Self education project. Focus on interesting algorithms
 *	@author Ivan Deviatkin <devyatkin.ivan@gmail.com>
**/

#include <vector>
#include <array>

#pragma once

template <typename V, typename E> class Vertex; // forward declaration for Edge class

// V - is the content stored by vertices
// E - is the content stored by edges
template <typename V, typename E>
class Edge {
  struct Incidence {
    size_t index;
    Vertex<V,E>& v;
  };
  std::array<Incidence,2> vertices;
  E content;
};

template <typename V, typename E>
class Vertex {
  std::vector<Edge<V,E>*> edges;
};
