#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <istream>
#include <string>
#include <sstream>
#include <iterator>
#include <algorithm>

using namespace std;

//Forward declarations: compiler needs to know function prototype when function call is compiled.
vector<string> split(const string &s, char delim);
float CalculateWaveAmplitude(vector<float> dataVector);
float AssignWaveAmplitude(vector<float> dataVectorr);
void extractFrameID(ifstream &in, ofstream &of);
bool isFloat(string myString);

float tempFloatStorage;
string firstLineInFile;
string secondLineInFile;
string thirdLineInFile;


vector<float> amplitudeStorage;
vector<vector<float>> vectorStorage;

vector<float> scaleStorage;
vector<float> sadAmplitudeStorage;



int main() {
	//Create a vector to hold all the mocap data values in float form.
	vector<float> floatTokens;
	//Create a vector to hold an entire frame (the data and the words).
	vector<string> oneFrame;

#pragma region bodyVectors
	vector<float>lowerBackXVector;
	vector<float>lowerBackYVector;
	vector<float>lowerBackZVector;
	vector<float>upperBackXVector;
	vector<float>upperBackYVector;
	vector<float>upperBackZVector;
	vector<float>thoraxXVector;
	vector<float>thoraxYVector;
	vector<float>thoraxZVector;
	vector<float>lowerNeckXVector;
	vector<float>lowerNeckYVector;
	vector<float>lowerNeckZVector;
	vector<float>upperNeckXVector;
	vector<float>upperNeckYVector;
	vector<float>upperNeckZVector;
	vector<float>headXVector;
	vector<float>headYVector;
	vector<float>headZVector;
	vector<float>rClavicleYVector;
	vector<float>rClavicleZVector;
	vector<float>rHumerusXVector;
	vector<float>rHumerusYVector;
	vector<float>rHumerusZVector;
	vector<float>rRadiusXVector;
	vector<float>rWristYVector;
	vector<float>rHandXVector;
	vector<float>rHandYVector;
	vector<float>rFingersXVector;
	vector<float>rThumbXVector;
	vector<float>rThumbZVector;
	vector<float>lClavicleYVector;
	vector<float>lClavicleZVector;
	vector<float>lHumerusXVector;
	vector<float>lHumerusYVector;
	vector<float>lHumerusZVector;
	vector<float>lRadiusXVector;
	vector<float>lWristYVector;
	vector<float>lHandXVector;
	vector<float>lHandYVector;
	vector<float>lFingersXVector;
	vector<float>lThumbXVector;
	vector<float>lThumbZVector;
	vector<float>rFemurXVector;
	vector<float>rFemurYVector;
	vector<float>rFemurZVector;
	vector<float>rTibiaXVector;
	vector<float>rFootXVector;
	vector<float>rFootZVector;
	vector<float>rToesXVector;
	vector<float>lFemurXVector;
	vector<float>lFemurYVector;
	vector<float>lFemurZVector;
	vector<float>lTibiaXVector;
	vector<float>lFootXVector;
	vector<float>lFootZVector;
	vector<float>lToesXVector;


#pragma endregion Vector to store all the data values. Used to calculate  peak-to-peak amplitudes.

#pragma region Amplitudes

	float lowerBackXAmplitude;
	float lowerBackYAmplitude;
	float lowerBackZAmplitude;
	float upperBackXAmplitude;
	float upperBackYAmplitude;
	float upperBackZAmplitude;
	float thoraxXAmplitude;
	float thoraxYAmplitude;
	float thoraxZAmplitude;
	float lowerNeckXAmplitude;
	float lowerNeckYAmplitude;
	float lowerNeckZAmplitude;
	float upperNeckXAmplitude;
	float upperNeckYAmplitude;
	float upperNeckZAmplitude;
	float headXAmplitude;
	float headYAmplitude;
	float headZAmplitude;
	float rClavicleYAmplitude;
	float rClavicleZAmplitude;
	float rHumerusXAmplitude;
	float rHumerusYAmplitude;
	float rHumerusZAmplitude;
	float rRadiusXAmplitude;
	float rWristYAmplitude;
	float rHandXAmplitude;
	float rHandYAmplitude;
	float rFingersXAmplitude;
	float rThumbXAmplitude;
	float rThumbZAmplitude;
	float lClavicleYAmplitude;
	float lClavicleZAmplitude;
	float lHumerusXAmplitude;
	float lHumerusYAmplitude;
	float lHumerusZAmplitude;
	float lRadiusXAmplitude;
	float lWristYAmplitude;
	float lHandXAmplitude;
	float lHandYAmplitude;
	float lFingersXAmplitude;
	float lThumbXAmplitude;
	float lThumbZAmplitude;
	float rFemurXAmplitude;
	float rFemurYAmplitude;
	float rFemurZAmplitude;
	float rTibiaXAmplitude;
	float rFootXAmplitude;
	float rFootZAmplitude;
	float rToesXAmplitude;
	float lFemurXAmplitude;
	float lFemurYAmplitude;
	float lFemurZAmplitude;
	float lTibiaXAmplitude;
	float lFootXAmplitude;
	float lFootZAmplitude;
	float lToesXAmplitude;

	amplitudeStorage.push_back(lowerBackXAmplitude);
	amplitudeStorage.push_back(lowerBackYAmplitude);
	amplitudeStorage.push_back(lowerBackZAmplitude);
	amplitudeStorage.push_back(upperBackXAmplitude);
	amplitudeStorage.push_back(upperBackYAmplitude);
	amplitudeStorage.push_back(upperBackZAmplitude);
	amplitudeStorage.push_back(thoraxXAmplitude);
	amplitudeStorage.push_back(thoraxYAmplitude);
	amplitudeStorage.push_back(thoraxZAmplitude);
	amplitudeStorage.push_back(lowerNeckXAmplitude);
	amplitudeStorage.push_back(lowerNeckYAmplitude);
	amplitudeStorage.push_back(lowerNeckZAmplitude);
	amplitudeStorage.push_back(upperNeckXAmplitude);
	amplitudeStorage.push_back(upperNeckYAmplitude);
	amplitudeStorage.push_back(upperNeckZAmplitude);
	amplitudeStorage.push_back(headXAmplitude);
	amplitudeStorage.push_back(headYAmplitude);
	amplitudeStorage.push_back(headZAmplitude);
	amplitudeStorage.push_back(rClavicleYAmplitude);
	amplitudeStorage.push_back(rClavicleZAmplitude);
	amplitudeStorage.push_back(rHumerusXAmplitude);
	amplitudeStorage.push_back(rHumerusYAmplitude);
	amplitudeStorage.push_back(rHumerusZAmplitude);
	amplitudeStorage.push_back(rRadiusXAmplitude);
	amplitudeStorage.push_back(rWristYAmplitude);
	amplitudeStorage.push_back(rHandXAmplitude);
	amplitudeStorage.push_back(rHandYAmplitude);
	amplitudeStorage.push_back(rFingersXAmplitude);
	amplitudeStorage.push_back(rThumbXAmplitude);
	amplitudeStorage.push_back(rThumbZAmplitude);
	amplitudeStorage.push_back(lClavicleYAmplitude);
	amplitudeStorage.push_back(lClavicleZAmplitude);
	amplitudeStorage.push_back(lHumerusXAmplitude);
	amplitudeStorage.push_back(lHumerusYAmplitude);
	amplitudeStorage.push_back(lHumerusZAmplitude);
	amplitudeStorage.push_back(lRadiusXAmplitude);
	amplitudeStorage.push_back(lWristYAmplitude);
	amplitudeStorage.push_back(lHandXAmplitude);
	amplitudeStorage.push_back(lHandYAmplitude);
	amplitudeStorage.push_back(lFingersXAmplitude);
	amplitudeStorage.push_back(lThumbXAmplitude);
	amplitudeStorage.push_back(lThumbZAmplitude);
	amplitudeStorage.push_back(rFemurXAmplitude);
	amplitudeStorage.push_back(rFemurYAmplitude);
	amplitudeStorage.push_back(rFemurZAmplitude);
	amplitudeStorage.push_back(rTibiaXAmplitude);
	amplitudeStorage.push_back(rFootXAmplitude);
	amplitudeStorage.push_back(rFootZAmplitude);
	amplitudeStorage.push_back(rToesXAmplitude);
	amplitudeStorage.push_back(lFemurXAmplitude);
	amplitudeStorage.push_back(lFemurYAmplitude);
	amplitudeStorage.push_back(lFemurZAmplitude);
	amplitudeStorage.push_back(lTibiaXAmplitude);
	amplitudeStorage.push_back(lFootXAmplitude);
	amplitudeStorage.push_back(lFootZAmplitude);
	amplitudeStorage.push_back(lToesXAmplitude);

#pragma endregion  creating the floats for the amplitudes and pushing them into storage.

#pragma region SadAmplitudes

	float lowerBackXSadAmplitude = 10.4275;
	float lowerBackYSadAmplitude = 5.40621;
	float lowerBackZSadAmplitude = 19.0675;
	float upperBackXSadAmplitude = 8.63414;
	float upperBackYSadAmplitude = 6.84698;
	float upperBackZSadAmplitude = 8.81153;
	float thoraXSadXSadAmplitude = 7.73112;
	float thoraXSadYSadAmplitude = 3.19445;
	float thoraXSadZSadAmplitude = 9.05597;
	float lowerNeckXSadAmplitude = 21.9366;
	float lowerNeckYSadAmplitude = 16.9116;
	float lowerNeckZSadAmplitude = 8.89939;
	float upperNeckXSadAmplitude = 53.4304;
	float upperNeckYSadAmplitude = 24.9013;
	float upperNeckZSadAmplitude = 35.5834;
	float headXSadAmplitude = 21.3462;
	float headYSadAmplitude = 12.7843;
	float headZSadAmplitude = 11.6639;
	float rClavicleYSadAmplitude = 2.99394e-13;
	float rClavicleZSadAmplitude = 2.67167e-13;
	float rHumerusXSadAmplitude = 20.3488;
	float rHumerusYSadAmplitude = 42.7468;
	float rHumerusZSadAmplitude = 38.023;
	float rRadiusXSadAmplitude = 12.9095;
	float rWristYSadAmplitude = 29.7143;
	float rHandXSadAmplitude = 22.2526;
	float rHandYSadAmplitude = 19.0163;
	float rFingersXSadAmplitude = 0;
	float rThumbXSadAmplitude = 21.4077;
	float rThumbZSadAmplitude = 359.81;
	float lClavicleYSadAmplitude = 2.99394e-13;
	float lClavicleZSadAmplitude = 2.67167e-13;
	float lHumerusXSadAmplitude = 30.2579;
	float lHumerusYSadAmplitude = 38.4497;
	float lHumerusZSadAmplitude = 35.5538;
	float lRadiusXSadAmplitude = 26.4449;
	float lWristYSadAmplitude = 42.4645;
	float lHandXSadAmplitude = 23.3543;
	float lHandYSadAmplitude = 20.6229;
	float lFingersXSadAmplitude = 0;
	float lThumbXSadAmplitude = 22.3846;
	float lThumbZSadAmplitude = 19.7215;
	float rFemurXSadAmplitude = 58.9005;
	float rFemurYSadAmplitude = 47.7804;
	float rFemurZSadAmplitude = 43.0787;
	float rTibiaXSadAmplitude = 70.6249;
	float rFootXSadAmplitude = 85.2768;
	float rFootZSadAmplitude = 58.9425;
	float rToesXSadAmplitude  = 91.5382;
	float lFemurXSadAmplitude = 74.0648;
	float lFemurYSadAmplitude = 39.0441;
	float lFemurZSadAmplitude  = 30.332;
	float lTibiaXSadAmplitude = 80.027;
	float lFootXSadAmplitude = 63.4335;
	float lFootZSadAmplitude = 66.3571;
	float lToesXSadAmplitude = 107.862;

	sadAmplitudeStorage.push_back(lowerBackXSadAmplitude);
	sadAmplitudeStorage.push_back(lowerBackYSadAmplitude);
	sadAmplitudeStorage.push_back(lowerBackZSadAmplitude);
	sadAmplitudeStorage.push_back(upperBackXSadAmplitude);
	sadAmplitudeStorage.push_back(upperBackYSadAmplitude);
	sadAmplitudeStorage.push_back(upperBackZSadAmplitude);
	sadAmplitudeStorage.push_back(thoraXSadXSadAmplitude);
	sadAmplitudeStorage.push_back(thoraXSadYSadAmplitude);
	sadAmplitudeStorage.push_back(thoraXSadZSadAmplitude);
	sadAmplitudeStorage.push_back(lowerNeckXSadAmplitude);
	sadAmplitudeStorage.push_back(lowerNeckYSadAmplitude);
	sadAmplitudeStorage.push_back(lowerNeckZSadAmplitude);
	sadAmplitudeStorage.push_back(upperNeckXSadAmplitude);
	sadAmplitudeStorage.push_back(upperNeckYSadAmplitude);
	sadAmplitudeStorage.push_back(upperNeckZSadAmplitude);
	sadAmplitudeStorage.push_back(headXSadAmplitude);
	sadAmplitudeStorage.push_back(headYSadAmplitude);
	sadAmplitudeStorage.push_back(headZSadAmplitude);
	sadAmplitudeStorage.push_back(rClavicleYSadAmplitude);
	sadAmplitudeStorage.push_back(rClavicleZSadAmplitude);
	sadAmplitudeStorage.push_back(rHumerusXSadAmplitude);
	sadAmplitudeStorage.push_back(rHumerusYSadAmplitude);
	sadAmplitudeStorage.push_back(rHumerusZSadAmplitude);
	sadAmplitudeStorage.push_back(rRadiusXSadAmplitude);
	sadAmplitudeStorage.push_back(rWristYSadAmplitude);
	sadAmplitudeStorage.push_back(rHandXSadAmplitude);
	sadAmplitudeStorage.push_back(rHandYSadAmplitude);
	sadAmplitudeStorage.push_back(rFingersXSadAmplitude);;
	sadAmplitudeStorage.push_back(rThumbXSadAmplitude);
	sadAmplitudeStorage.push_back(rThumbZSadAmplitude);
	sadAmplitudeStorage.push_back(lClavicleYSadAmplitude);
	sadAmplitudeStorage.push_back(lClavicleZSadAmplitude);
	sadAmplitudeStorage.push_back(lHumerusXSadAmplitude);
	sadAmplitudeStorage.push_back(lHumerusYSadAmplitude);
	sadAmplitudeStorage.push_back(lHumerusZSadAmplitude);
	sadAmplitudeStorage.push_back(lRadiusXSadAmplitude);
	sadAmplitudeStorage.push_back(lWristYSadAmplitude);
	sadAmplitudeStorage.push_back(lHandXSadAmplitude);
	sadAmplitudeStorage.push_back(lHandYSadAmplitude);
	sadAmplitudeStorage.push_back(lFingersXSadAmplitude);
	sadAmplitudeStorage.push_back(lThumbXSadAmplitude);
	sadAmplitudeStorage.push_back(lThumbZSadAmplitude);
	sadAmplitudeStorage.push_back(rFemurXSadAmplitude);
	sadAmplitudeStorage.push_back(rFemurYSadAmplitude);
	sadAmplitudeStorage.push_back(rFemurZSadAmplitude);
	sadAmplitudeStorage.push_back(rTibiaXSadAmplitude);
	sadAmplitudeStorage.push_back(rFootXSadAmplitude);
	sadAmplitudeStorage.push_back(rFootZSadAmplitude);
	sadAmplitudeStorage.push_back(rToesXSadAmplitude);
	sadAmplitudeStorage.push_back(lFemurXSadAmplitude);
	sadAmplitudeStorage.push_back(lFemurYSadAmplitude);
	sadAmplitudeStorage.push_back(lFemurZSadAmplitude);
	sadAmplitudeStorage.push_back(lTibiaXSadAmplitude);
	sadAmplitudeStorage.push_back(lFootXSadAmplitude);
	sadAmplitudeStorage.push_back(lFootZSadAmplitude);
	sadAmplitudeStorage.push_back(lToesXSadAmplitude);

#pragma endregion Used to store all the amplitudes from existing sad mocap data, these will be used with the retrieved amplitudes to create a scale factor for each data value.





//Create an input file stream
ifstream in("105_sadwalk100Frames.amc", ios::in);
const float scaleFactor = 1.0;




//define an output stream object
ofstream outputTestFile;
//creating the output file
outputTestFile.open("105_normalwalk100FramesModified.amc");
//cases to handle the first 3 lines of the file (first 3 lines contain no data, but are necessary)
//extracts each line into an object and writes them to the top of the output file
getline(in, firstLineInFile);
getline(in, secondLineInFile);
getline(in, thirdLineInFile);
//outputTestFile << firstLineInFile << endl;
//outputTestFile << secondLineInFile << endl;
//outputTestFile << thirdLineInFile << endl;

//loop until the end of the file is reached
while (in.eof() == 0) {
	//create a buffer to store each frame
	stringstream buffer;
	//write the frameID to the file.
	extractFrameID(in, outputTestFile);
	//loop around the 29 lines in a frame, push each line into the vector.
	for (int i = 0; i < 29; i++) {
		string tempString;
		getline(in, tempString);

		if (tempString.empty()) {

			vectorStorage.push_back(lowerBackXVector);
			vectorStorage.push_back(lowerBackYVector);
			vectorStorage.push_back(lowerBackZVector);
			vectorStorage.push_back(upperBackXVector);
			vectorStorage.push_back(upperBackYVector);
			vectorStorage.push_back(upperBackZVector);
			vectorStorage.push_back(thoraxXVector);
			vectorStorage.push_back(thoraxYVector);
			vectorStorage.push_back(thoraxZVector);
			vectorStorage.push_back(lowerNeckXVector);
			vectorStorage.push_back(lowerNeckYVector);
			vectorStorage.push_back(lowerNeckZVector);
			vectorStorage.push_back(upperNeckXVector);
			vectorStorage.push_back(upperNeckYVector);
			vectorStorage.push_back(upperNeckZVector);
			vectorStorage.push_back(headXVector);
			vectorStorage.push_back(headYVector);
			vectorStorage.push_back(headZVector);
			vectorStorage.push_back(rClavicleYVector);
			vectorStorage.push_back(rClavicleZVector);
			vectorStorage.push_back(rHumerusXVector);
			vectorStorage.push_back(rHumerusYVector);
			vectorStorage.push_back(rHumerusZVector);
			vectorStorage.push_back(rRadiusXVector);
			vectorStorage.push_back(rWristYVector);
			vectorStorage.push_back(rHandXVector);
			vectorStorage.push_back(rHandYVector);
			vectorStorage.push_back(rFingersXVector);
			vectorStorage.push_back(rThumbXVector);
			vectorStorage.push_back(rThumbZVector);
			vectorStorage.push_back(lClavicleYVector);
			vectorStorage.push_back(lClavicleZVector);
			vectorStorage.push_back(lHumerusXVector);
			vectorStorage.push_back(lHumerusYVector);
			vectorStorage.push_back(lHumerusZVector);
			vectorStorage.push_back(lRadiusXVector);
			vectorStorage.push_back(lWristYVector);
			vectorStorage.push_back(lHandXVector);
			vectorStorage.push_back(lHandYVector);
			vectorStorage.push_back(lFingersXVector);
			vectorStorage.push_back(lThumbXVector);
			vectorStorage.push_back(lThumbZVector);
			vectorStorage.push_back(rFemurXVector);
			vectorStorage.push_back(rFemurYVector);
			vectorStorage.push_back(rFemurZVector);
			vectorStorage.push_back(rTibiaXVector);
			vectorStorage.push_back(rFootXVector);
			vectorStorage.push_back(rFootZVector);
			vectorStorage.push_back(rToesXVector);
			vectorStorage.push_back(lFemurXVector);
			vectorStorage.push_back(lFemurYVector);
			vectorStorage.push_back(lFemurZVector);
			vectorStorage.push_back(lTibiaXVector);
			vectorStorage.push_back(lFootXVector);
			vectorStorage.push_back(lFootZVector);
			vectorStorage.push_back(lToesXVector);

			//check to make sure the vector of peak-to-peak amplitudes and vector of vectors are the same size
			//if (amplitudeStorage.size() == vectorStorage.size()) {
			sadAmplitudeStorage.reserve(vectorStorage.size());
			for (int i = 0; i < amplitudeStorage.size(); i++) {
				amplitudeStorage[i] = AssignWaveAmplitude(vectorStorage[i]);
				if (isnan((amplitudeStorage[i] / sadAmplitudeStorage[i]))) {
					scaleStorage.push_back(0);
				}
				else {
					scaleStorage.push_back(amplitudeStorage[i] / sadAmplitudeStorage[i]);
				}
				//cout << amplitudeStorage[i] << endl;
				//cout << sadAmplitudeStorage[i] << endl;
				cout << scaleStorage[i] << endl;
				//outputTestFile << amplitudeStorage[i] << endl;
			}
			
			
				//}
				//}
			


				//lowerBackXAmplitude = CalculateWaveAmplitude(lowerBackXVector);
				//lowerBackYAmplitude = CalculateWaveAmplitude(lowerBackYVector);
				//lowerBackZAmplitude = CalculateWaveAmplitude(lowerBackZVector);
				//rFemurXAmplitude = CalculateWaveAmplitude(rFemurXVector);
				//rFemurYAmplitude = CalculateWaveAmplitude(rFemurYVector);
				//rFemurZAmplitude = CalculateWaveAmplitude(rFemurZVector);
				/*cout << lowerBackXAmplitude << endl;
				cout << lowerBackYAmplitude << endl;
				cout << lowerBackZAmplitude << endl;
				cout << rFemurXAmplitude << endl;
				cout << rFemurYAmplitude << endl;
				cout << rFemurZAmplitude << endl;*/
				cout << "Modification complete";
				cin.get(); //Keep program open until "enter" is pressed
				return 0;
			}

			oneFrame.push_back(tempString);
		}
		//populate the buffer with the vector.
		copy(oneFrame.begin(), oneFrame.end(), ostream_iterator<string>(buffer, "\n"));

		//split the buffer up into tokens(objects) and store them into a vector 
		vector<string> mainTokenVector = split(buffer.str(), ' ');

		//defining 
		vector<float> floatTokenVector;
		vector<string> stringTokenVector;


		

			//loop to split up the token vector into strings and floats, and store them in vectors
			for (int i = 0; i < mainTokenVector.size(); i++) {
				//if the token is a string, put it in the string vector
				if (isFloat(mainTokenVector[i]) == 0) {
					stringTokenVector.push_back(mainTokenVector[i]);
				}
				//if the token is a float, put it in the float vector
				else if (isFloat(mainTokenVector[i]) == 1) {
					floatTokenVector.push_back(stof(mainTokenVector[i]));
				}

			}
			//loop through all the data values and scale it by a defined factor.
			//start from 6 because the first 6 values are root data, which should not be modified.
			for (int i = 6; i < floatTokenVector.size(); i++) {
				//floatTokenVector[i] = floatTokenVector[i] * scaleFactor;
				floatTokenVector[i] = floatTokenVector[i] * scaleStorage[i-6];
			}
	
		

		//pushing all data values to their responding vectors in order to calculate each data values' amplitude.
		lowerBackXVector.push_back(floatTokenVector[6]);
		lowerBackYVector.push_back(floatTokenVector[7]);
		lowerBackZVector.push_back(floatTokenVector[8]);
		upperBackXVector.push_back(floatTokenVector[9]);
		upperBackYVector.push_back(floatTokenVector[10]);
		upperBackZVector.push_back(floatTokenVector[11]);
		thoraxXVector.push_back(floatTokenVector[12]);
		thoraxYVector.push_back(floatTokenVector[13]);
		thoraxZVector.push_back(floatTokenVector[14]);
		lowerNeckXVector.push_back(floatTokenVector[15]);
		lowerNeckYVector.push_back(floatTokenVector[16]);
		lowerNeckZVector.push_back(floatTokenVector[17]);
		upperNeckXVector.push_back(floatTokenVector[18]);
		upperNeckYVector.push_back(floatTokenVector[19]);
		upperNeckZVector.push_back(floatTokenVector[20]);
		headXVector.push_back(floatTokenVector[21]);
		headYVector.push_back(floatTokenVector[22]);
		headZVector.push_back(floatTokenVector[23]);
		rClavicleYVector.push_back(floatTokenVector[24]);
		rClavicleZVector.push_back(floatTokenVector[25]);
		rHumerusXVector.push_back(floatTokenVector[26]);
		rHumerusYVector.push_back(floatTokenVector[27]);
		rHumerusZVector.push_back(floatTokenVector[28]);
		rRadiusXVector.push_back(floatTokenVector[29]);
		rWristYVector.push_back(floatTokenVector[30]);
		rHandXVector.push_back(floatTokenVector[31]);
		rHandYVector.push_back(floatTokenVector[32]);
		rFingersXVector.push_back(floatTokenVector[33]);
		rThumbXVector.push_back(floatTokenVector[34]);
		rThumbZVector.push_back(floatTokenVector[35]);
		lClavicleYVector.push_back(floatTokenVector[36]);
		lClavicleZVector.push_back(floatTokenVector[37]);
		lHumerusXVector.push_back(floatTokenVector[38]);
		lHumerusYVector.push_back(floatTokenVector[39]);
		lHumerusZVector.push_back(floatTokenVector[40]);
		lRadiusXVector.push_back(floatTokenVector[41]);
		lWristYVector.push_back(floatTokenVector[42]);
		lHandXVector.push_back(floatTokenVector[43]);
		lHandYVector.push_back(floatTokenVector[44]);
		lFingersXVector.push_back(floatTokenVector[45]);
		lThumbXVector.push_back(floatTokenVector[46]);
		lThumbZVector.push_back(floatTokenVector[47]);
		rFemurXVector.push_back(floatTokenVector[48]);
		rFemurYVector.push_back(floatTokenVector[49]);
		rFemurZVector.push_back(floatTokenVector[50]);
		rTibiaXVector.push_back(floatTokenVector[51]);
		rFootXVector.push_back(floatTokenVector[52]);
		rFootZVector.push_back(floatTokenVector[53]);
		rToesXVector.push_back(floatTokenVector[54]);
		lFemurXVector.push_back(floatTokenVector[55]);
		lFemurYVector.push_back(floatTokenVector[56]);
		lFemurZVector.push_back(floatTokenVector[57]);
		lTibiaXVector.push_back(floatTokenVector[58]);
		lFootXVector.push_back(floatTokenVector[59]);
		lFootZVector.push_back(floatTokenVector[60]);
		lToesXVector.push_back(floatTokenVector[61]);



		//recreating the frame file structure
		string rootData = stringTokenVector[0] + " " + to_string(floatTokenVector[0]) + " " + to_string(floatTokenVector[1]) + " " + to_string(floatTokenVector[2])
			+ " " + to_string(floatTokenVector[3]) + " " + to_string(floatTokenVector[4]) + " " + to_string(floatTokenVector[5]);
		string lowerbackData = stringTokenVector[1] + " " + to_string(floatTokenVector[6]) + " " + to_string(floatTokenVector[7]) + " " + to_string(floatTokenVector[8]);
		string upperBackData = stringTokenVector[2] + " " + to_string(floatTokenVector[9]) + " " + to_string(floatTokenVector[10]) + " " + to_string(floatTokenVector[11]);
		string thoraxData = stringTokenVector[3] + " " + to_string(floatTokenVector[12]) + " " + to_string(floatTokenVector[13]) + " " + to_string(floatTokenVector[14]);
		string lowerneckData = stringTokenVector[4] + " " + to_string(floatTokenVector[15]) + " " + to_string(floatTokenVector[16]) + " " + to_string(floatTokenVector[17]);
		string upperneckData = stringTokenVector[5] + " " + to_string(floatTokenVector[18]) + " " + to_string(floatTokenVector[19]) + " " + to_string(floatTokenVector[20]);
		string headData = stringTokenVector[6] + " " + to_string(floatTokenVector[21]) + " " + to_string(floatTokenVector[22]) + " " + to_string(floatTokenVector[23]);
		string rclavicleData = stringTokenVector[7] + " " + to_string(floatTokenVector[24]) + " " + to_string(floatTokenVector[25]);
		string rhumerusData = stringTokenVector[8] + " " + to_string(floatTokenVector[26]) + " " + to_string(floatTokenVector[27]) + " " + to_string(floatTokenVector[28]);
		string rradiusData = stringTokenVector[9] + " " + to_string(floatTokenVector[29]);
		string rwristData = stringTokenVector[10] + " " + to_string(floatTokenVector[30]);
		string rhandData = stringTokenVector[11] + " " + to_string(floatTokenVector[31]) + " " + to_string(floatTokenVector[32]);
		string rfingersData = stringTokenVector[12] + " " + to_string(floatTokenVector[33]);
		string rthumbData = stringTokenVector[13] + " " + to_string(floatTokenVector[34]) + " " + to_string(floatTokenVector[35]);
		string lclavicleData = stringTokenVector[14] + " " + to_string(floatTokenVector[36]) + " " + to_string(floatTokenVector[37]);
		string lhumerusData = stringTokenVector[15] + " " + to_string(floatTokenVector[38]) + " " + to_string(floatTokenVector[39]) + " " + to_string(floatTokenVector[40]);
		string lradiusData = stringTokenVector[16] + " " + to_string(floatTokenVector[41]);
		string lwristData = stringTokenVector[17] + " " + to_string(floatTokenVector[42]);
		string lhandData = stringTokenVector[18] + " " + to_string(floatTokenVector[43]) + " " + to_string(floatTokenVector[44]);
		string lfingersData = stringTokenVector[19] + " " + to_string(floatTokenVector[45]);
		string lthumbData = stringTokenVector[20] + " " + to_string(floatTokenVector[46]) + " " + to_string(floatTokenVector[47]);
		string rfemurData = stringTokenVector[21] + " " + to_string(floatTokenVector[48]) + " " + to_string(floatTokenVector[49]) + " " + to_string(floatTokenVector[50]);
		string rtibiaData = stringTokenVector[22] + " " + to_string(floatTokenVector[51]);
		string rfootData = stringTokenVector[23] + " " + to_string(floatTokenVector[52]) + " " + to_string(floatTokenVector[53]);
		string rtoesData = stringTokenVector[24] + " " + to_string(floatTokenVector[54]);
		string lfemurData = stringTokenVector[25] + " " + to_string(floatTokenVector[55]) + " " + to_string(floatTokenVector[56]) + " " + to_string(floatTokenVector[57]);
		string ltibiaData = stringTokenVector[26] + " " + to_string(floatTokenVector[58]);
		string lfootData = stringTokenVector[27] + " " + to_string(floatTokenVector[59]) + " " + to_string(floatTokenVector[60]);
		string ltoesData = stringTokenVector[28] + " " + to_string(floatTokenVector[61]);
		
		 
		//clear the vectors to prepare them for the next frame.
		//string oneValue = to_string(floatTokenVector[50]);
		//oneFrame.clear();
		mainTokenVector.clear();
		stringTokenVector.clear();
		floatTokenVector.clear();
		
		//outputTestFile << oneValue << endl;
		//write the contents of the strings to the output file
	/*	outputTestFile << rootData << endl;
		outputTestFile << lowerbackData << endl;
		outputTestFile << upperBackData << endl;
		outputTestFile << thoraxData << endl;
		outputTestFile << lowerneckData << endl;
		outputTestFile << upperneckData << endl;
		outputTestFile << headData << endl;
		outputTestFile << rclavicleData << endl;
		outputTestFile << rhumerusData << endl;
		outputTestFile << rradiusData << endl;
		outputTestFile << rwristData << endl;
		outputTestFile << rhandData << endl;
		outputTestFile << rfingersData << endl;
		outputTestFile << rthumbData << endl;
		outputTestFile << lclavicleData << endl;
		outputTestFile << lhumerusData << endl;
		outputTestFile << lradiusData << endl;
		outputTestFile << lwristData << endl;
		outputTestFile << lhandData << endl;
		outputTestFile << lfingersData << endl;
		outputTestFile << lthumbData << endl;
		outputTestFile << rfemurData << endl;
		outputTestFile << rtibiaData << endl;
		outputTestFile << rfootData << endl;
		outputTestFile << rtoesData << endl;
		outputTestFile << lfemurData << endl;
		outputTestFile << ltibiaData << endl;
		outputTestFile << lfootData << endl;
		outputTestFile << ltoesData << endl;	*/
	}
	
		//close the file currently associated with the object, disassociating it from the stream.
		in.close();
		outputTestFile.close();
	

	
	cout << "Modification complete";
	cin.get(); //Keep program open until "enter" is pressed
	return 0;
}
bool isFloat(string myString) {
	istringstream iss(myString);
	float f;
	iss >> noskipws >> f; // noskipws considers leading whitespace invalid
						  // Check the entire string was consumed and if either failbit or badbit is set
	return iss.eof() && !iss.fail();
}

vector<string> split(const string &s, char delim) {
	stringstream ss(s);
	string item;
	vector<string> tokens;

	while (ss >> item) {
		tokens.push_back(item);
		
	}
	return tokens;
}

void extractFrameID(ifstream &in, ofstream &of) {
	
		string frameID;
		
		getline(in, frameID);
		if (frameID.empty()) {
			return;
		}
		
		//of << frameID << endl;
		cout << "Writing Frame " + frameID << endl;
	
	
}

float AssignWaveAmplitude( vector<float> dataVectorr) {
	
	return (*max_element(begin(dataVectorr), end(dataVectorr))) - (*min_element(begin(dataVectorr), end(dataVectorr)));
}


float CalculateWaveAmplitude(vector<float> dataVector) {

	return (*max_element(begin(dataVector), end(dataVector))) - (*min_element(begin(dataVector), end(dataVector)));
}
