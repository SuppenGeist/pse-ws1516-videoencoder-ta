#ifndef GRAPHVIDEO_H
#define GRAPHVIDEO_H

#include <vector>
#include <memory>

#include "Graph.h"

namespace Model {

class GraphVideo
{
public:
    GraphVideo();

    void appendGraph(std::unique_ptr<Graph> graph);

    Graph* getGraph(std::size_t index);

    std::size_t getNumberOfGraphs();

private:
    std::vector<std::unique_ptr<Graph>>  graphs_;
};

}

#endif // GRAPHVIDEO_H
