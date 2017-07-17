#include "Node.h"
#include "Weight.h"

Weight::Weight()
{

}

Weight::Weight(Node * forward, Node * backward, double w)
    : fConnection(forward), bConnection(backward), weight(w)
{

}

Weight::~Weight()
{
    //This is a weird situation it might not need to be freed here.
    //delete fconnection;
    //delete bconnection;
}

void Weight::calculateGradient(double eTotal, double outDer, double learningRate)
{
    updatedWeight = weight - learningRate *
                             bConnection -> value() *
                             eTotal *
                             outDer;
}

void Weight::update()
{
    weight = updatedWeight;
}
