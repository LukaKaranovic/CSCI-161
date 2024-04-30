/**
 * @file arraymapmain.cpp
 * @author Humayun Kabir, Instructor, CSCI 161, VIU
 * @version 1.0.0
 * @date July 23, 2020
 * 
 * Performs the test uses of ArrayMap.
 *
 */
 


#include <iostream>
#include <string>

#include "dynamicarray.cpp"
#include "arraymap.cpp"

using namespace std;

/*
 * Global Data to test ArrayMap<string, string>
 */
string countries[5] = {"United States of America", "United Kingdom", "Canada", "Australia", "Mexico"};
string capitals[5] = {"Washington", "London", "Ottawa", "Canberra", "Mexico City"};

string brazil("Brazil");
string brazil_capital("Brasilia");


/*
 * Returns ArrayMap<string, string> rvalue that can be used to test
 * ArrayMap move constructor and move assignment.
 */
ArrayMap<string, string> getArrayMap() {
	ArrayMap<string, string> arrayMap(5);
	for(int i=0; i<5; i++) {
		arrayMap.put(countries[i], capitals[i]);
	}
	return arrayMap;
}


/*
 * The main test function.
 */
int main() {

	/*
	 * Testing ArrayMap<string, string> regular constructor
	 */
	cout<<endl<<"Testing ArrayMap<string, string> regular constructor."<<endl;
	ArrayMap<string, string> arrayMap1(10);

	
	for(int i=0; i<5; i++) {
		cout<<"Putting '"<<countries[i]<<"' and '"<<capitals[i]<<"' into map."<<endl;
		arrayMap1.put(countries[i], capitals[i]);
	}

	for (int i=0; i<5; i++) {
		cout<<"Found the capital of '"<< countries[i]<<"' is '"<<arrayMap1.get(countries[i])<<"' from map."<<endl;
	}	
	cout<<endl;
	
	/*
	 * Testing copy constructor
	 */
	cout<<"Testing ArrayMap<string, string> copy constructor."<<endl;
	ArrayMap<string, string> copyArrayMap1 = arrayMap1;
	for(int i=0; i<copyArrayMap1.size(); i++) {
		cout<<"Copy Constructed ArrayMap["<<countries[i]<<"]: "<<copyArrayMap1[countries[i]]<<endl;
	}
	cout<<endl;

	/*
	 * Testing move constructor
	 */
	cout<<"Testing ArrayMap<string, string> move constructor."<<endl;
	ArrayMap<string,string> moveArrayMap1 = getArrayMap(); 
	for(int i=0; i<moveArrayMap1.size(); i++) {
		cout<<"Move Constructed ArrayMap["<<countries[i]<<"]: "<<moveArrayMap1[countries[i]]<<endl;
	}
	cout<<endl;
	
	/*
	 * Testing copy assignment
	 */
	cout<<"Testing ArrayMap<string, string> copy assignment."<<endl;
	ArrayMap<string, string> copyArrayMap2;
	copyArrayMap2 = copyArrayMap1;
	for(int i=0; i<copyArrayMap2.size(); i++) {
		cout<<"Copy Assigned ArrayMap["<<countries[i]<<"]: "<<copyArrayMap2[countries[i]]<<endl;
	}
	cout<<endl;
	
	/*
	 * Testing move assignment
	 */
	cout<<"Testing ArrayMap<string, string> move assignment."<<endl;
	ArrayMap<string,string> moveArrayMap2;
	moveArrayMap2 = getArrayMap();
	for(int i=0; i<moveArrayMap2.size(); i++) {
		cout<<"Move Assigned  ArrayMap["<<countries[i]<<"]: "<<moveArrayMap2[countries[i]]<<endl;
	}
	cout<<endl;

	
	/*
	 * Testing containsKey() and containsValue() with non existing key and value
	 */
	cout<<endl<<"Testing containsKey() and containsValue() with non existing key and value"<<endl;
	cout<<"Before adding "<<brazil<<" and its capital "<<brazil_capital<<" into the map"<<endl;
	cout<<"Contains Key: "<<brazil<<" : "<<(arrayMap1.containsKey(brazil)? "true": "false")<<endl;
	cout<<"Contains Value: "<<brazil_capital<<" : "<<(arrayMap1.containsValue(brazil_capital)? "true":"false")<<endl; 

	/*
	 * Testing put()
	 */
	arrayMap1.put(brazil, brazil_capital);
	cout<<"Adding adding "<<brazil<<" and its capital "<<brazil_capital<<" into the map"<<endl;

	/*
	 * Testing containsKey() and containsValue() with existing key and value.
	 */
	cout<<endl<<"Testing containsKey() and containsValue() with existing key and value"<<endl;
	cout<<"Contains Key: "<<brazil<<" : "<<(arrayMap1.containsKey(brazil)? "true": "false")<<endl;
	cout<<"Contains Value: "<<brazil_capital<<" : "<<(arrayMap1.containsValue(brazil_capital)? "true": "false")<<endl; 

	/*
	 * Testing remove()
	 */
	cout<<endl<<"Testing remove()"<<endl;
	arrayMap1.remove(brazil);
	cout<<"After removing "<<brazil<<" and its capital "<<brazil_capital<<" from the map"<<endl;

	cout<<"Contains Key: "<<brazil<<" : "<<(arrayMap1.containsKey(brazil)? "true": "false")<<endl;
	cout<<"Contains Value: "<<brazil_capital<<" : "<<(arrayMap1.containsValue(brazil_capital)? "true": "false")<<endl;

	/*
	 * Testing keys()
	 */
	cout<<endl<<"Testing keys()"<<endl;
	const DynamicArray<string>* keys = arrayMap1.keys();
	int keySize = keys->size();
	cout<<"Keys size: "<<keySize<<endl;
	cout<<"Keys in the map are: "<<endl;
	for(int i=0; i<keySize-1; i++) {
		cout<<(*keys)[i]<<", ";
	}
	cout<<(*keys)[keySize-1]<<endl;

	/*
	 * Testing values()
	 */
	cout<<endl<<"Testing values()"<<endl;
	const DynamicArray<string>* values = arrayMap1.values();
	int valueSize = values->size();
	cout<<"Values size: "<<valueSize<<endl;
	cout<<"Values in the map are: "<<endl;
	for(int i=0; i<valueSize-1; i++) {
		cout<<(*values)[i]<<", ";
	}
	cout<<(*values)[(valueSize-1)]<<endl;
       
	
	delete keys;
	delete values;
	
	


	/*
	 * Data to test ArrayMap<int, string>
	 */
	int month_numbers[12] = {1,2,3,4,5,6,7,8,9,10,11,12};
	string month_names[12] = {"January", "February", "March", "April", "May", "June", 
		"July", "August", "September", "October", "November", "December"};
	
	

	/*
	 * Testing ArrayMap<int, string>
	 */
	cout<<"\nTesting ArrayMap<int, string>"<<endl;
	ArrayMap<int, string> arrayMap3(12);

	for(int i = 0; i<12; i++){
	       arrayMap3.put(month_numbers[i], month_names[i]);
	}	
	for( int i=0; i<12; i++) {
		if(arrayMap3.containsKey(month_numbers[i])){
			cout<<"<"<<month_numbers[i]<<":"<<arrayMap3.get(month_numbers[i])<<"> ";
		}
	}
	cout<<endl;

	
	/*
	 * Data to test ArrayMap<string, double>
	 */
	string letter_grades[11] = {"A+", "A","A-","B+","B", "B-", "C+", "C", "C-", "D", "F"};
	double grade_points[11] = {4.33, 4.00, 3.67, 3.33, 3.00, 2.67, 2.33, 2.00, 1.67, 1.00, 0.00};


	/*
	 * Testing ArrayMap<string, double>
	 */
	cout<<"\nTesting ArrayMap<string, double>"<<endl;
	ArrayMap<string, double> arrayMap5(11);
	for(int i=0; i<11; i++) {
		arrayMap5.put(letter_grades[i], grade_points[i]);
	}

	for(int i=0; i<11; i++) {
		if(arrayMap5.containsKey(letter_grades[i])) {
			cout<<"<"<<letter_grades[i]<<":"<<arrayMap5.get(letter_grades[i])<<"> ";
		}
	}
	cout<<endl;
	

	return 0;
}
