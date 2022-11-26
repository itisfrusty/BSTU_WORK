#include "Neuron.h"

void Neuron::active() {
    output = function->active(input);
}

double Neuron::derivative() {
    return function->derivative(input, output);
}