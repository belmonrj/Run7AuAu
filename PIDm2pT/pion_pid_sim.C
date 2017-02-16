float isPionLow(float mom, float m2tofw)
{
float x = mom;
float a0 = 0.0184867;
float a1 = 0.00104217;
float a2 = -0.000155555;
float a3 = -0.00489161;
float a4 = 0.0126445;
float mean = a0+a1/x+a2/x/x+a3*exp(sqrt(x))+a4*sqrt(x);
float b0 = -0.0241301;
float b1 = -0.0011061;
float b2 = 1.77837e-06;
float b3 = 0.0551144;
float b4 = -0.114053;
float sigma = b0+b1/x+b2/x/x+b3*exp(sqrt(x))+b4*sqrt(x);
return (m2tofw - mean)/sigma;
}

