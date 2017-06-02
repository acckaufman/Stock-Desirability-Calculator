//Calculates a figure for the desirability of a stock for purchase.
//0: Least desirable, 100: Most desirable.

#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
using namespace std;

int main()
{
	char again = 'n';
	string stockName;
	double currentPrice, peRatio, fiftyTwoLow, fiftyTwoHigh, difference, fiftyTwoPercentile,
		divYield, equitySummaryScore, valuation, quality, growthStability, financialHealth, payoutRatio;
	int currentPriceVal, peRatioVal, fiftyTwoRangeVal, divYieldVal, equitySummaryVal, valuationVal,
		qualityVal, growthStabilityVal, financialHealthVal, payoutRatioVal, valTotal;

	//Open an output file in append mode.
	ofstream outFile;
	outFile.open("Stock Desirability Comparisons.txt", ios::app);

	//Header
	cout << "Stock Desirability Calculator" << endl;

	do
	{
		//Ticker Symbol
		cout << endl << "Ticker Symbol: ";
		getline(cin, stockName);
		outFile << stockName << "\tScore: ";

		//Current Price
		cout << "Current Price per Share: $";
		cin >> currentPrice;

		while (currentPrice < 0.01)
		{
			cout << "Error! Price must be at least $0.01 per share.  Please try again." << endl;
			cout << "Current Price per Share: $";
			cin >> currentPrice;
		}

		if (currentPrice >= 0.01 && currentPrice <= 10)
			currentPriceVal = 10;
		else if (currentPrice >= 10.01 && currentPrice <= 20)
			currentPriceVal = 9;
		else if (currentPrice >= 20.01 && currentPrice <= 30)
			currentPriceVal = 8;
		else if (currentPrice >= 30.01 && currentPrice <= 40)
			currentPriceVal = 7;
		else if (currentPrice >= 40.01 && currentPrice <= 50)
			currentPriceVal = 6;
		else if (currentPrice >= 50.01 && currentPrice <= 60)
			currentPriceVal = 5;
		else if (currentPrice >= 60.01 && currentPrice <= 70)
			currentPriceVal = 4;
		else if (currentPrice >= 70.01 && currentPrice <= 80)
			currentPriceVal = 3;
		else if (currentPrice >= 80.01 && currentPrice <= 90)
			currentPriceVal = 2;
		else if (currentPrice >= 90.01 && currentPrice <= 100)
			currentPriceVal = 1;
		else
			currentPriceVal = 0;

		//Debugging:
		cout << "Current Price Value is: " << currentPriceVal << endl;

		//PE Ratio
		cout << "PE Ratio (NMF or negative enter 0): ";
		cin >> peRatio;

		while (peRatio < 0)
		{
			cout << "Error! PE ratio must be at least 0.  Please try again." << endl;
			cout << "PE Ratio (NMF or negative enter 0): ";
			cin >> peRatio;
		}

		if (peRatio == 0)
			peRatioVal = 0;
		else if (peRatio > 0 && peRatio < 5)
			peRatioVal = 3;
		else if (peRatio >= 5 && peRatio < 10)
			peRatioVal = 5;
		else if (peRatio >= 10 && peRatio < 15)
			peRatioVal = 8;
		else if (peRatio >= 15 && peRatio < 25)
			peRatioVal = 10;
		else if (peRatio >= 25 && peRatio < 30)
			peRatioVal = 8;
		else if (peRatio >= 30 && peRatio < 40)
			peRatioVal = 5;
		else if (peRatio >= 40 && peRatio < 60)
			peRatioVal = 3;
		else
			peRatioVal = 0;

		//Debugging:
		cout << "PE Ratio Value is: " << peRatioVal << endl;

		//52-Week Range Percentile
		cout << "52-Week Low: $";
		cin >> fiftyTwoLow;

		while (fiftyTwoLow < 0.01)
		{
			cout << "Error! 52-Week Low must be at least $0.01.  Please try again." << endl;
			cout << "52-Week Low: $";
			cin >> fiftyTwoLow;
		}

		cout << "52-Week High: $";
		cin >> fiftyTwoHigh;

		while (fiftyTwoHigh < 0.01)
		{
			cout << "Error! 52-Week High must be at least $0.01.  Please try again." << endl;
			cout << "52-Week High: $";
			cin >> fiftyTwoHigh;
		}

		difference = fiftyTwoHigh - fiftyTwoLow;
		fiftyTwoPercentile = (currentPrice - fiftyTwoLow) / difference;

		if (fiftyTwoPercentile == 1)
			fiftyTwoRangeVal = 0;
		else if (fiftyTwoPercentile >= 0.9 && fiftyTwoPercentile < 1)
			fiftyTwoRangeVal = 1;
		else if (fiftyTwoPercentile >= 0.8 && fiftyTwoPercentile < .9)
			fiftyTwoRangeVal = 2;
		else if (fiftyTwoPercentile >= 0.7 && fiftyTwoPercentile < .8)
			fiftyTwoRangeVal = 3;
		else if (fiftyTwoPercentile >= 0.6 && fiftyTwoPercentile < .7)
			fiftyTwoRangeVal = 4;
		else if (fiftyTwoPercentile >= 0.5 && fiftyTwoPercentile < .6)
			fiftyTwoRangeVal = 5;
		else if (fiftyTwoPercentile >= 0.4 && fiftyTwoPercentile < .5)
			fiftyTwoRangeVal = 6;
		else if (fiftyTwoPercentile >= 0.3 && fiftyTwoPercentile < .4)
			fiftyTwoRangeVal = 7;
		else if (fiftyTwoPercentile >= 0.2 && fiftyTwoPercentile < .3)
			fiftyTwoRangeVal = 8;
		else if (fiftyTwoPercentile >= 0.1 && fiftyTwoPercentile < .2)
			fiftyTwoRangeVal = 9;
		else
			fiftyTwoRangeVal = 10;

		//Debugging:
		cout << "52-Week Percentile Value is: " << fiftyTwoRangeVal << endl;

		//Dividend Yield
		cout << "Dividend Yield %: ";
		cin >> divYield;

		while (divYield < 0 || divYield > 10)
		{
			cout << "Error! Dividend Yield must be between 0-10%.  Please try again." << endl;
			cout << "Dividend Yield %: ";
			cin >> divYield;
		}

		if (divYield == 0)
			divYieldVal = 0;
		else if (divYield > 0 && divYield <= .5)
			divYieldVal = 1;
		else if (divYield > 0.5 && divYield <= 1)
			divYieldVal = 2;
		else if (divYield > 1 && divYield <= 1.5)
			divYieldVal = 3;
		else if (divYield > 1.5 && divYield <= 2)
			divYieldVal = 4;
		else if (divYield > 2 && divYield <= 2.5)
			divYieldVal = 5;
		else if (divYield > 2.5 && divYield <= 3)
			divYieldVal = 6;
		else if (divYield > 3 && divYield <= 3.5)
			divYieldVal = 7;
		else if (divYield > 3.5 && divYield <= 4)
			divYieldVal = 8;
		else if (divYield > 4 && divYield <= 4.5)
			divYieldVal = 9;
		else if (divYield > 4.5)
			divYieldVal = 10;

		//Debugging:
		cout << "Dividend Yield Value is: " << divYieldVal << endl;

		//Payout Ratio
		cout << "Dividend Payout Ratio %: ";
		cin >> payoutRatio;

		while (payoutRatio < 0 || payoutRatio > 100)
		{
			cout << "Error! Dividend Payout Ratio must be between 0-100%.  Please try again." << endl;
			cin >> payoutRatio;
		}

		if (payoutRatio == 0)
			payoutRatioVal = 0;
		else if (payoutRatio > 0 && payoutRatio < 10)
			payoutRatioVal = 3;
		else if (payoutRatio >= 10 && payoutRatio < 20)
			payoutRatioVal = 5;
		else if (payoutRatio >= 20 && payoutRatio < 40)
			payoutRatioVal = 10;
		else if (payoutRatio >= 40 && payoutRatio < 50)
			payoutRatioVal = 8;
		else if (payoutRatio >= 50 && payoutRatio < 60)
			payoutRatioVal = 5;
		else if (payoutRatio >= 60)
			payoutRatioVal = 3;

		//Debugging:
		cout << "Dividend Payout Ratio Value is: " << payoutRatioVal << endl;

		//Equity Summary Score
		cout << "Equity Summary Score: ";
		cin >> equitySummaryScore;

		while (equitySummaryScore < 0 || equitySummaryScore > 10)
		{
			cout << "Error! Equity Summary Score must be between 0-10.  Please try again." << endl;
			cout << "Equity Summary Score: ";
			cin >> equitySummaryScore;
		}

		equitySummaryVal = equitySummaryScore / 1;

		//Debugging:
		cout << "Equity Summary Score Value is: " << equitySummaryVal << endl;

		//Valuation
		cout << "Valuation (0-100): ";
		cin >> valuation;

		while (valuation < 0 || valuation > 100)
		{
			cout << "Error! Valuation must be between 0-100.  Please try again." << endl;
			cout << "Valuation (0-100): ";
			cin >> valuation;
		}

		if (valuation == 0)
			valuationVal = 0;
		else if (valuation > 0 && valuation <= 10)
			valuationVal = 1;
		else if (valuation > 10 && valuation <= 20)
			valuationVal = 2;
		else if (valuation > 20 && valuation <= 30)
			valuationVal = 3;
		else if (valuation > 30 && valuation <= 40)
			valuationVal = 4;
		else if (valuation > 40 && valuation <= 50)
			valuationVal = 5;
		else if (valuation > 50 && valuation <= 60)
			valuationVal = 6;
		else if (valuation > 60 && valuation <= 70)
			valuationVal = 7;
		else if (valuation > 70 && valuation <= 80)
			valuationVal = 8;
		else if (valuation > 80 && valuation <= 90)
			valuationVal = 9;
		else if (valuation > 90 && valuation <= 100)
			valuationVal = 10;

		//Debugging:
		cout << "Valuation Value is: " << valuationVal << endl;

		//Quality
		cout << "Quality (0-100): ";
		cin >> quality;

		while (quality < 0 || quality > 100)
		{
			cout << "Error! Quality must be between 0-100.  Please try again." << endl;
			cout << "Quality (0-100): ";
			cin >> quality;
		}

		if (quality == 0)
			qualityVal = 0;
		else if (quality > 0 && quality <= 10)
			qualityVal = 1;
		else if (quality > 10 && quality <= 20)
			qualityVal = 2;
		else if (quality > 20 && quality <= 30)
			qualityVal = 3;
		else if (quality > 30 && quality <= 40)
			qualityVal = 4;
		else if (quality > 40 && quality <= 50)
			qualityVal = 5;
		else if (quality > 50 && quality <= 60)
			qualityVal = 6;
		else if (quality > 60 && quality <= 70)
			qualityVal = 7;
		else if (quality > 70 && quality <= 80)
			qualityVal = 8;
		else if (quality > 80 && quality <= 90)
			qualityVal = 9;
		else if (quality > 90 && quality <= 100)
			qualityVal = 10;

		//Debugging:
		cout << "Quality Value is: " << qualityVal << endl;

		//Growth Stability
		cout << "Growth Stability (0-100): ";
		cin >> growthStability;

		while (growthStability < 0 || growthStability > 100)
		{
			cout << "Error! Growth Stability must be between 0-100.  Please try again." << endl;
			cout << "Growth Stability (0-100): ";
			cin >> growthStability;
		}

		if (growthStability == 0)
			growthStabilityVal = 0;
		else if (growthStability > 0 && growthStability <= 10)
			growthStabilityVal = 1;
		else if (growthStability > 10 && growthStability <= 20)
			growthStabilityVal = 2;
		else if (growthStability > 20 && growthStability <= 30)
			growthStabilityVal = 3;
		else if (growthStability > 30 && growthStability <= 40)
			growthStabilityVal = 4;
		else if (growthStability > 40 && growthStability <= 50)
			growthStabilityVal = 5;
		else if (growthStability > 50 && growthStability <= 60)
			growthStabilityVal = 6;
		else if (growthStability > 60 && growthStability <= 70)
			growthStabilityVal = 7;
		else if (growthStability > 70 && growthStability <= 80)
			growthStabilityVal = 8;
		else if (growthStability > 80 && growthStability <= 90)
			growthStabilityVal = 9;
		else if (growthStability > 90 && growthStability <= 100)
			growthStabilityVal = 10;

		//Debugging:
		cout << "Growth Stability Value is: " << growthStabilityVal << endl;

		//Financial Health
		cout << "Financial Health (0-100): ";
		cin >> financialHealth;

		while (financialHealth < 0 || financialHealth > 100)
		{
			cout << "Error! Financial Health must be between 0-100.  Please try again." << endl;
			cout << "Financial Health (0-100): ";
			cin >> financialHealth;
		}

		if (financialHealth == 0)
			financialHealthVal = 0;
		else if (financialHealth > 0 && financialHealth <= 10)
			financialHealthVal = 1;
		else if (financialHealth > 10 && financialHealth <= 20)
			financialHealthVal = 2;
		else if (financialHealth > 20 && financialHealth <= 30)
			financialHealthVal = 3;
		else if (financialHealth > 30 && financialHealth <= 40)
			financialHealthVal = 4;
		else if (financialHealth > 40 && financialHealth <= 50)
			financialHealthVal = 5;
		else if (financialHealth > 50 && financialHealth <= 60)
			financialHealthVal = 6;
		else if (financialHealth > 60 && financialHealth <= 70)
			financialHealthVal = 7;
		else if (financialHealth > 70 && financialHealth <= 80)
			financialHealthVal = 8;
		else if (financialHealth > 80 && financialHealth <= 90)
			financialHealthVal = 9;
		else if (financialHealth > 90 && financialHealth <= 100)
			financialHealthVal = 10;

		//Debugging:
		cout << "Financial Health Value is: " << financialHealthVal << endl;

		//Total
		valTotal = currentPriceVal + peRatioVal + fiftyTwoRangeVal + divYieldVal + payoutRatioVal
			+ equitySummaryVal + valuationVal + qualityVal + growthStabilityVal + financialHealthVal;

		cout << endl << "Total Stock Desirability Value: " << valTotal << endl << endl;
		outFile << setw(4) << right << valTotal << endl;

		cout << "Would you like to run the program again? (y/n): ";
		cin >> again;
		cin.ignore();

	} while (again == 'y' || again == 'Y');

	outFile.close();

	cout << endl;
	system("PAUSE");
	return 0;
}