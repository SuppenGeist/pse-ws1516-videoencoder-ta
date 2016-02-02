#ifndef MEANSQUAREERRORCALCULATOR_H
#define MEANSQUAREERRORCALCULATOR_H

namespace Model {
    class AVVideo;
    class Graph;
}

class MeanSquareErrorCalculator
{
public:
    MeanSquareErrorCalculator(Model::AVVideo& video1, Model::AVVideo& video2);

    Model::Graph calculate();

private:
    Model::AVVideo*    video1_;
    Model::AVVideo*    video2_;
};

#endif // MEANSQUAREERRORCALCULATOR_H
