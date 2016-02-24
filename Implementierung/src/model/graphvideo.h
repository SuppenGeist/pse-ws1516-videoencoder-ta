#ifndef GRAPHVIDEO_H
#define GRAPHVIDEO_H

#include <vector>
#include <memory>

#include "Graph.h"

namespace Model {

class GraphVideo {
  public:
	GraphVideo(int fps=1);

	void appendGraph(std::unique_ptr<Graph> graph);

	Graph* getGraph(std::size_t index);

	std::size_t getNumberOfGraphs();

	int getFps();

	void setFps(int fps);

	bool isComplete();

	void setIsComplete(bool isComplete);

  private:
	std::vector<std::unique_ptr<Graph>>  graphs_;
	int fps_;
	bool isComplete_;
};

}

#endif // GRAPHVIDEO_H
