#include "ActivationFunction.h"
#include <cmath> 

namespace BorisNetAi
{
    float LogisticFunction(float x)
    {
        return static_cast<float> (1.0f / (1.0 + pow(E, -x)));
    }
    
    float LogisticFunctionDerivative(float x)
    {
        return LogisticFunction(x) * (1.0f - LogisticFunction(x));
    }

    float TanH(float x)
    {
        return tanh(x);
    }

    float TanHDerivative(float x)
    {
        return 1.0f - (TanH(x) * TanH(x));
    }

    float Relu(float x)
    {
        if (x < 0.0f) return 0.0f;

        return x;
    }

    float ReluDerivative(float x)
    {
        if (x < 0.0f) return 0.0f;

        return 1.0f;
    }
}