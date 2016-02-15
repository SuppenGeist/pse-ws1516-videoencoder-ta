#ifndef GRAPHVIDEO_H
#define GRAPHVIDEO_H

#include <vector>

#include "Graph.h"

namespace Model {

class GraphVideo
{
public:
    GraphVideo();

    void appendGraph(Graph& graph);

    Graph* getGraph(std::size_t index);

    std::size_t getNumberOfGraphs();

private:
    std::vector<Graph>  graphs_;
};

}

#endif // GRAPHVIDEO_H
