/**
 * @file linkedmapmain.cpp
 * @author Humayun Kabir, Instructor, CSCI 161, VIU
 * @version 1.0.0
 * @date July 16, 2020
 * 
 * Performs the test use of LinkedMap.
 *
 */
 


#include <iostream>
#include <string>

#include "dynamicarray.cpp"
#include "linkedmap.cpp"

using namespace std;

/*
 * Global Data to test LinkedMap<string, string>
 */
string countries[5] = {"United States of America", "United Kingdom", "Canada", "Australia", "Mexico"};
string capitals[5] = {"Washington", "London", "Ottawa", "Canberra", "Mexico City"};

string brazil("Brazil");
string brazil_capital("Brasilia");

/*
 * Returns LinkedMap<string, string> rvalue that can be used to test
 * LinkedMap move constructor and move assignment.
 */
LinkedMap<string, string> getLinkedMap() {
	LinkedMap<string, string> linkedMap;
	for(int i=0; i<5; i++) {
		linkedMap.put(countries[i], capitals[i]);
	}
	return linkedMap;
}


int main() {

	/*
	 * Testing LinkedMap<string, string> default constructor
	 */
	cout<<"Testing LinkedMap<string, string> default constructor."<<endl;
	LinkedMap<string, string> linkedMap1;
	
	for(int i=0; i<5; i++) {
		cout<<"Putting '"<<countries[i]<<"' and '"<<capitals[i]<<"' into map."<<endl; 
		linkedMap1.put(countries[i], capitals[i]);
	}

	for (int i=0; i<5; i++) {
		cout<<"Found the capital of '"<< countries[i]<<"' is '"<<linkedMap1.get(countries[i])<<"' from map."<<endl;
	}	
	cout<<endl;


	/*
	 * Testing copy constructor
	 */
	cout<<"Testing LinkedMap<string, string> copy constructor."<<endl;
	LinkedMap<string, string> copyMap1 = linkedMap1;
	for(int i=0; i<copyMap1.size(); i++) {
		cout<<"Copy Constructed LinkedMap["<<countries[i]<<"]: "<<copyMap1[countries[i]]<<endl;
	}	
	cout<<endl;

	/*
	 * Testing move constructor
	 */
	cout<<"Testing LinkedMap<string, string> move constructor."<<endl;
	LinkedMap<string, string> moveMap1 = getLinkedMap();
	for(int i=0; i<moveMap1.size(); i++) {
		cout<<"Move Constructed LinkedMap["<<countries[i]<<"]: "<<moveMap1[countries[i]]<<endl;
	}	
	cout<<endl;


	/*
	 * Testing copy assignment
	 */
	cout<<"Testing LinkedMap<string, string> copy assignmnet."<<endl;
	LinkedMap<string, string> copyMap2;
       	copyMap2 = copyMap1;
	for(int i=0; i<copyMap2.size(); i++) {
		cout<<"Copy Assigned LinkedMap["<<countries[i]<<"]: "<<copyMap2[countries[i]]<<endl;
	}	
	cout<<endl;

	/*
	 * Testing move assignment
	 */
	cout<<"Testing LinkedMap<string, string> move assignment."<<endl;
	LinkedMap<string, string> moveMap2;
       	moveMap2 = getLinkedMap();
	for(int i=0; i<moveMap2.size(); i++) {
		cout<<"Move Assigned LinkedMap["<<countries[i]<<"]: "<<moveMap2[countries[i]]<<endl;
	}	
	cout<<endl;

       /*
 	* Testing containsKey() and containsValue() with non existing key and value
 	*/
	cout<<endl<<"Testing containsKey() and containsValue() with non existing key and value"<<endl;

	cout<<"Before adding "<<brazil<<" and its capital "<<brazil_capital<<" into the map"<<endl;
	cout<<"Contains Key: "<<brazil<<" : "<<(linkedMap1.containsKey(brazil)? "true": "false")<<endl;
	cout<<"Contains Value: "<<brazil_capital<<" : "<<(linkedMap1.containsValue(brazil_capital)? "true":"false")<<endl; 

	/*
	 * Testing put()
	 */
	linkedMap1.put(brazil, brazil_capital);
	cout<<"Adding adding "<<brazil<<" and its capital "<<brazil_capital<<" into the map"<<endl;

	
       /*
 	* Testing containsKey() and containsValue() with existing key and value
 	*/
	cout<<endl<<"Testing containsKey() and containsValue() with existing key and value"<<endl;
	cout<<"Contains Key: "<<brazil<<" : "<<(linkedMap1.containsKey(brazil)? "true": "false")<<endl;
	cout<<"Contains Value: "<<brazil_capital<<" : "<<(linkedMap1.containsValue(brazil_capital)? "true": "false")<<endl; 

	/*
	 * Testing remove()
	 */
	cout<<endl<<"Testing remove()"<<endl;
	linkedMap1.remove(brazil);
	cout<<"After removing "<<brazil<<" and its capital "<<brazil_capital<<" from the map"<<endl;
	cout<<"Contains Key: "<<brazil<<" : "<<(linkedMap1.containsKey(brazil)? "true": "false")<<endl;
	cout<<"Contains Value: "<<brazil_capital<<" : "<<(linkedMap1.containsValue(brazil_capital)? "true": "false")<<endl;


	/*
	 * Testing keys()
	 */
	cout<<endl<<"Testing keys()"<<endl;
	const DynamicArray<string>* linkedMapKeys = linkedMap1.keys();
	int linkedMapKeySize = linkedMapKeys->size();
	cout<<"Keys size: "<<linkedMapKeySize<<endl;
	cout<<"Keys in the map are: "<<endl;
	for(int i=0; i<linkedMapKeySize-1; i++) {
		cout<<(*linkedMapKeys)[i]<<", ";
	}
	cout<<(*linkedMapKeys)[linkedMapKeySize-1]<<endl;


	/*
	 * Testing values()
	 */
	cout<<endl<<"Testing values()"<<endl;
	const DynamicArray<string>* linkedMapValues = linkedMap1.values();
	int linkedMapValueSize = linkedMapValues->size();
	cout<<"Values size: "<<linkedMapValueSize<<endl;
	cout<<"Values in the map are: "<<endl;
	for(int i=0; i<linkedMapValueSize-1; i++) {
		cout<<(*linkedMapValues)[i]<<", ";
	}
	cout<<(*linkedMapValues)[linkedMapValueSize-1]<<endl;

	delete linkedMapKeys;
	delete linkedMapValues;


	/*
	 * Data to test LinkedMap<int, string>
	 */
	int month_numbers[12] = {1,2,3,4,5,6,7,8,9,10,11,12};
	string month_names[12] = {"January", "February", "March", "April", "May", "June", 
		"July", "August", "September", "October", "November", "December"};
	
	/*
	 * Testing LinkedMap<int, string>
	 */
	cout<<"\nTesting LinkedMap<int, string>"<<endl;
	LinkedMap<int, string> linkedMap4;
	for(int i = 0; i<12; i++){
	       linkedMap4.put(month_numbers[i], month_names[i]);
	}	
	for( int i=0; i<12; i++) {
		if(linkedMap4.containsKey(month_numbers[i])){
			cout<<"<"<<month_numbers[i]<<":"<<linkedMap4.get(month_numbers[i])<<"> ";
		}
	}
	cout<<endl;


	
	/*
	 * Data to test LinkedMap<string, double>
	 */
	string letter_grades[11] = {"A+", "A","A-","B+","B", "B-", "C+", "C", "C-", "D", "F"};
	double grade_points[11] = {4.33, 4.00, 3.67, 3.33, 3.00, 2.67, 2.33, 2.00, 1.67, 1.00, 0.00};


	/*
	 * Testing LinkedMap<string, double>
	 */
	cout<<"\nTesting LinekdMap<string, double>"<<endl;
	LinkedMap<string, double> linkedMap6;
	for(int i=0; i<11; i++) {
		linkedMap6.put(letter_grades[i], grade_points[i]);
	}

	for(int i=0; i<11; i++) {
		if(linkedMap6.containsKey(letter_grades[i])) {
			cout<<"<"<<letter_grades[i]<<":"<<linkedMap6.get(letter_grades[i])<<"> ";
		}
	}
	cout<<endl;

	return 0;
}
