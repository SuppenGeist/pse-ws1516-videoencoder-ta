#ifndef MEANSQUAREERRORCALCULATOR_H
#define MEANSQUAREERRORCALCULATOR_H

namespace Model {
class Video;
class Graph;
}

class MeanSquareErrorCalculator {
  public:
	MeanSquareErrorCalculator(Model::Video &video1, Model::Video &video2);

	Model::Graph calculate();

  private:
	Model::Video*    video1_;
	Model::Video*    video2_;
};

#endif // MEANSQUAREERRORCALCULATOR_H
