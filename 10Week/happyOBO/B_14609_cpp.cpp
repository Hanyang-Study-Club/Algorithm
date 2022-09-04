#include <bits/stdc++.h>

using namespace std;


struct LinearExp
{
	double degree; // 차수
	double coeffi; // 계수
};


const double MAX_EPSILON = 0.0001;
const double TERM_EPSILON = 0.000001;

class IntegralCalculator
{
public:
	static double CalcIntegral(double a, double b, vector<LinearExp>& vexp)
	{
		double result = 0.0;
		for (auto& lexp : vexp)
		{
			result += CalcLinearIntegral(a, b, lexp);
		}
		return result;
	}

	static double CalcLinearIntegral(double a, double b, LinearExp& Lexp)
	{
		return Lexp.coeffi * ((pow(b, Lexp.degree + 1.0) - pow(a, Lexp.degree + 1.0)) / (Lexp.degree + 1.0));
	}
};


class SigmaCalculator
{
public:
	static double CalcSigma(vector<LinearExp>& vexp, double a, double b, double n, double curr_epsilon)
	{
		double result = 0.0;

		double param;
		double delta_x;
		for (int k = 0; k < n; k++)
		{
			delta_x = (b - a) / n;
			param = a + (double)k * delta_x + curr_epsilon;

			result += CalcExpWithParam(param, vexp) * delta_x;

		}

		return result;
	}

	static double CalcExpWithParam(double param, vector<LinearExp>& vexp)
	{
		double result = 0.0;
		for (auto& lexp : vexp)
		{
			result += CalcLinearExpWithParam(param, lexp);
		}
		return result;
	}

	static double CalcLinearExpWithParam(double param, LinearExp& Lexp)
	{
		return pow(param, Lexp.degree) * Lexp.coeffi;
	}

};

// 0 : similar , 1 : ActualValue < MeasuredValue , -1 : ActualValue > MeasuredValue
static int IsSimilar(double ActualValue, double MeasuredValue)
{
	double AbsoluteError = abs(ActualValue - MeasuredValue);
	double RelativeError = AbsoluteError / ActualValue;
	if (AbsoluteError <= MAX_EPSILON || RelativeError <= MAX_EPSILON) // 절대 오차 || 상대 오차
		return 0;
	else if (ActualValue < MeasuredValue)
		return 1;
	else
		return -1;
}

double BinarySearch(double target, double a, double b, double n, vector<LinearExp>& vexp)
{
	double start = 0.0;
	double end = (b - a) / n;
	double mid;

	double curr_sigma;
	int sim_result;

	while (start <= end)
	{
		mid = (start + end) / 2.0;
		curr_sigma = SigmaCalculator::CalcSigma(vexp, a, b, n, mid);

		sim_result = IsSimilar(target, curr_sigma);

		if (sim_result == 0)
		{
			return mid;
		}
		else if (sim_result == 1) // 계수에는 양수만 올수 있으므로 입실론을 감소 
		{
			end = mid - TERM_EPSILON;
		}
		else
		{
			start = mid + TERM_EPSILON;
		}
	}

	return -1;
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	vector<LinearExp> vexps;
	int K;
	double a, b, N;
	cin >> K;
	for (int i = K; 0 <= i; i--)
	{
		LinearExp Lexp;
		Lexp.degree = (double)i;
		cin >> Lexp.coeffi;
		vexps.push_back(Lexp);
	}

	cin >> a >> b >> N;

	double target = IntegralCalculator::CalcIntegral(a, b, vexps);

	double result = BinarySearch(target, a, b, N, vexps);
	if (result < 0) cout << -1;
	else cout << result;

	return 0;
}

