#include "Graph.h"

#include <vector>

Model::Graph::Graph() {

}

void Model::Graph::setValue(std::size_t x, double y) {
	if(x>=graph_.size()) {
		for(std::size_t i=graph_.size(); i<x+1; i++) {
			graph_.push_back(-1);
		}
	}
	graph_[x]=y;
}

void Model::Graph::cut(std::size_t x) {
	if(x<graph_.size()) {
		graph_.erase(graph_.begin()+x,graph_.end());
	}
}

double Model::Graph::getValue(std::size_t x) {
	if(x>=graph_.size())
		return -1;
	return graph_[x];
}

std::size_t Model::Graph::getSize() {
	for(std::size_t i=graph_.size(); i!=0; i--) {
		if(graph_[i-1]!=-1)
			return i;
	}
	return 0;
}

void Model::Graph::removeValue(std::size_t x) {
	if(x<graph_.size()) {
		graph_[x]=-1;
	}
}

double Model::Graph::getBiggestValue() {
	double biggestVal=0;
	for(auto val:graph_) {
		if(val>biggestVal) {
			biggestVal=val;
		}
	}
	return biggestVal;
}
