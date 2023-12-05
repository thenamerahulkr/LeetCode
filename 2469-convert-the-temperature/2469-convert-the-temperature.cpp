class Solution {
public:
    vector<double> convertTemperature(double Celsius) {
       double Kelvin = Celsius + 273.15;
       double Fahrenheit = Celsius * 1.80 + 32.00;
       vector<double> v;
       v.push_back(Kelvin);
       v.push_back(Fahrenheit);
       return v;
    }
};