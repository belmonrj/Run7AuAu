float isPionLow(float pT, float m2tofw)
{
float x = pT;
float a0 = 0.0159735;
float a1 = 0.00165467;
float a2 = -0.000175107;
float a3 = -0.00952275;
float a4 = 0.0288279;
float mean = a0+a1/x+a2/x/x+a3*exp(sqrt(x))+a4*sqrt(x);
float b0 = -0.0432359;
float b1 = 0.00644942;
float b2 = -0.000809058;
float b3 = 0.0391918;
float b4 = -0.0568094;
float sigma = b0+b1/x+b2/x/x+b3*exp(sqrt(x))+b4*sqrt(x);
return (m2tofw - mean)/sigma;
}

