#ifndef ACTIVATION_FUNCTION
#define ACTIVATION_FUNCTION

namespace BorisNetAi
{
    static const double E = 2.7182818284590452353602875;

    float LogisticFunction(float x);

    float LogisticFunctionDerivative(float x);

    float TanH(float x);

    float TanHDerivative(float x);

    float Relu(float x);
    
    float ReluDerivative(float x);

}


#endif