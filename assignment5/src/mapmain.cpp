/**
 * @file mapmain.cpp
 * @author Humayun Kabir, Instructor, CSCI 161, VIU
 * @version 1.0.0
 * @date July 23, 2020
 * 
 * Performs the test uses of Map.
 *
 */
 


#include <iostream>
#include <string>

#include "dynamicarray.cpp"
#include "arraymap.cpp"
#include "linkedmap.cpp"

using namespace std;

/*
 * Global Data to test Map<string, string>
 */
string countries[5] = {"United States of America", "United Kingdom", "Canada", "Australia", "Mexico"};
string capitals[5] = {"Washington", "London", "Ottawa", "Canberra", "Mexico City"};

string brazil("Brazil");
string brazil_capital("Brasilia");


/*
 * Global Data to test Map<int, string>
 */
int month_numbers[12] = {1,2,3,4,5,6,7,8,9,10,11,12};
string month_names[12] = {"January", "February", "March", "April", "May", "June", 
		"July", "August", "September", "October", "November", "December"};


	
/*
 * Global Data to test Map<string, double>
 */
string letter_grades[11] = {"A+", "A","A-","B+","B", "B-", "C+", "C", "C-", "D", "F"};
double grade_points[11] = {4.33, 4.00, 3.67, 3.33, 3.00, 2.67, 2.33, 2.00, 1.67, 1.00, 0.00};




/**
 * Returns a Map<string, string>* rvalue that can be used to test
 * Map move constructor and move assignment.
 */
Map<string, string>* getArrayMap() {
	Map<string, string>* arrayMap = new ArrayMap<string, string>(5);
	for(int i=0; i<5; i++) {
		arrayMap->put(countries[i], capitals[i]);
	}
	return arrayMap;
}

/**
 * Returns a Map<string, string>* rvalue that can be used to test
 * Map move constructor and move assignment.
 */
Map<string, string>* getLinkedMap() {
	Map<string, string>* linkedMap = new LinkedMap<string, string>();
	for(int i=0; i<5; i++) {
		linkedMap->put(countries[i], capitals[i]);
	}
	return linkedMap;
}


/**
 * Test function to test all the functions from ArrayMap using Map ADT reference
 */
void testArrayMap() {
	/*
	 * Testing ArrayMap<string, string> using Map<string, string> ADT reference
	 */
	cout<<"\n\nTesting ArrayMap<string, string> using Map<string, string> ADT reference......................................."<<endl;
	cout<<endl<<"Testing ArrayMap<string, string> regular constructor."<<endl;
	Map<string, string>* mapRef1 = new ArrayMap<string, string>(10);

	
	for(int i=0; i<5; i++) {
		cout<<"Putting '"<<countries[i]<<"' and '"<<capitals[i]<<"' into map."<<endl;
		mapRef1->put(countries[i], capitals[i]);
	}

	for (int i=0; i<5; i++) {
		cout<<"Found the capital of '"<< countries[i]<<"' is '"<<mapRef1->get(countries[i])<<"' from map."<<endl;
	}	
	cout<<endl;
	
	/*
	 * Testing copy constructor
	 */
	cout<<"Testing ArrayMap<string, string> copy constructor."<<endl;
	ArrayMap<string, string> copyArrayMap1 = dynamic_cast<const ArrayMap<string, string>&>(*mapRef1);
	for(int i=0; i<copyArrayMap1.size(); i++) {
		cout<<"Copy Constructed ArrayMap["<<countries[i]<<"]: "<<copyArrayMap1[countries[i]]<<endl;
	}
	cout<<endl;

	/*
	 * Testing move constructor
	 */
	cout<<"Testing ArrayMap<string, string> move constructor."<<endl;
	ArrayMap<string,string> moveArrayMap1 = dynamic_cast<ArrayMap<string, string>&&>(*getArrayMap());
	for(int i=0; i<moveArrayMap1.size(); i++) {
		cout<<"Move Constructed ArrayMap["<<countries[i]<<"]: "<<moveArrayMap1[countries[i]]<<endl;
	}
	cout<<endl;
	
	/*
	 * Testing copy assignment
	 */
	cout<<"Testing ArrayMap<string, string> copy assignment."<<endl;
	ArrayMap<string, string> copyArrayMap2;
	copyArrayMap2 = dynamic_cast<const ArrayMap<string, string>&>(*mapRef1);
	for(int i=0; i<copyArrayMap2.size(); i++) {
		cout<<"Copy Assigned ArrayMap["<<countries[i]<<"]: "<<copyArrayMap2[countries[i]]<<endl;
	}
	cout<<endl;
	
	/*
	 * Testing move assignment
	 */
	cout<<"Testing ArrayMap<string, string> move assignment."<<endl;
	ArrayMap<string,string> moveArrayMap2;
	moveArrayMap2 = dynamic_cast<ArrayMap<string, string>&&>(*getArrayMap());
	for(int i=0; i<moveArrayMap2.size(); i++) {
		cout<<"Move Assigned  ArrayMap["<<countries[i]<<"]: "<<moveArrayMap2[countries[i]]<<endl;
	}
	cout<<endl;

	
	/*
	 * Testing containsKey() and containsValue() with non existing key and value
	 */
	cout<<endl<<"Testing containsKey() and containsValue() with non existing key and value"<<endl;
	cout<<"Before adding "<<brazil<<" and its capital "<<brazil_capital<<" into the map"<<endl;
	cout<<"Contains Key: "<<brazil<<" : "<<(mapRef1->containsKey(brazil)? "true": "false")<<endl;
	cout<<"Contains Value: "<<brazil_capital<<" : "<<(mapRef1->containsValue(brazil_capital)? "true":"false")<<endl; 

	/*
	 * Testing put()
	 */
	mapRef1->put(brazil, brazil_capital);
	cout<<"Adding adding "<<brazil<<" and its capital "<<brazil_capital<<" into the map"<<endl;

	/*
	 * Testing containsKey() and containsValue() with existing key and value.
	 */
	cout<<endl<<"Testing containsKey() and containsValue() with existing key and value"<<endl;
	cout<<"Contains Key: "<<brazil<<" : "<<(mapRef1->containsKey(brazil)? "true": "false")<<endl;
	cout<<"Contains Value: "<<brazil_capital<<" : "<<(mapRef1->containsValue(brazil_capital)? "true": "false")<<endl; 

	/*
	 * Testing remove()
	 */
	cout<<endl<<"Testing remove()"<<endl;
	mapRef1->remove(brazil);
	cout<<"After removing "<<brazil<<" and its capital "<<brazil_capital<<" from the map"<<endl;

	cout<<"Contains Key: "<<brazil<<" : "<<(mapRef1->containsKey(brazil)? "true": "false")<<endl;
	cout<<"Contains Value: "<<brazil_capital<<" : "<<(mapRef1->containsValue(brazil_capital)? "true": "false")<<endl;

	/*
	 * Testing keys()
	 */
	cout<<endl<<"Testing keys()"<<endl;
	const DynamicArray<string>* keys = mapRef1->keys();
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
	const DynamicArray<string>* values = mapRef1->values();
	int valueSize = values->size();
	cout<<"Values size: "<<valueSize<<endl;
	cout<<"Values in the map are: "<<endl;
	for(int i=0; i<valueSize-1; i++) {
		cout<<(*values)[i]<<", ";
	}
	cout<<(*values)[valueSize-1]<<endl;
       
	
	delete keys;
	delete values;
	
	
	delete mapRef1;


	
	/*
	 * Testing ArrayMap<int, string> using Map<int, string> ADT reference
	 */
	cout<<"\nTesting ArrayMap<int, string> unsing Map<int, string> ADT refeerence"<<endl;
	Map<int, string>* mapRef3 = new ArrayMap<int, string>(12);

	for(int i = 0; i<12; i++){
	       mapRef3->put(month_numbers[i], month_names[i]);
	}	
	for( int i=0; i<12; i++) {
		if(mapRef3->containsKey(month_numbers[i])){
			cout<<"<"<<month_numbers[i]<<":"<<mapRef3->get(month_numbers[i])<<"> ";
		}
	}
	cout<<endl;
	delete mapRef3;

	
	
	/*
	 * Testing ArrayMap<string, double> using Map<string, double> ADT reference
	 */
	cout<<"\nTesting ArrayMap<string, double> using Map<string, double> ADT reference"<<endl;
	Map<string, double>* mapRef5 = new ArrayMap<string, double>(11);
	for(int i=0; i<11; i++) {
		mapRef5->put(letter_grades[i], grade_points[i]);
	}

	for(int i=0; i<11; i++) {
		if(mapRef5->containsKey(letter_grades[i])) {
			cout<<"<"<<letter_grades[i]<<":"<<mapRef5->get(letter_grades[i])<<"> ";
		}
	}
	cout<<endl;
	delete mapRef5;
	
}



/**
 * Test function to test all the functions from LinkedMap using Map ADT reference
 */
void testLinkedMap() {

	/*
	 * Testing LinkedMap<string, string>  using Map<string, string> ADT reference
	 */
	cout<<"\n\nTesting LinkedMap<string, string> using Map<string, string> ADT reference......................................."<<endl;
	cout<<endl<<"Testing LinkedMap<string, string> default constructor."<<endl;
	Map<string, string>* mapRef2 = new LinkedMap<string, string>();
	
	for(int i=0; i<5; i++) {
		cout<<"Putting '"<<countries[i]<<"' and '"<<capitals[i]<<"' into map."<<endl; 
		mapRef2->put(countries[i], capitals[i]);
	}

	for (int i=0; i<5; i++) {
		cout<<"Found the capital of '"<< countries[i]<<"' is '"<<mapRef2->get(countries[i])<<"' from map."<<endl;
	}	
	cout<<endl;


	/*
	 * Testing copy constructor
	 */
	cout<<"Testing LinkedMap<string, string> copy constructor."<<endl;
	LinkedMap<string, string> copyMap1 = dynamic_cast<const LinkedMap<string, string>&>(*mapRef2);
	for(int i=0; i<copyMap1.size(); i++) {
		cout<<"Copy Constructed LinkedMap["<<countries[i]<<"]: "<<copyMap1[countries[i]]<<endl;
	}	
	cout<<endl;

	/*
	 * Testing move constructor
	 */
	cout<<"Testing LinkedMap<string, string> move constructor."<<endl;
	LinkedMap<string, string> moveMap1 = dynamic_cast<LinkedMap<string, string>&&>(*getLinkedMap());
	for(int i=0; i<moveMap1.size(); i++) {
		cout<<"Move Constructed LinkedMap["<<countries[i]<<"]: "<<moveMap1[countries[i]]<<endl;

	}

	cout<<endl;


	/*
	 * Testing copy assignment
	 */
	cout<<"Testing LinkedMap<string, string> copy assignmnet."<<endl;
	LinkedMap<string, string> copyMap2;
       	copyMap2 = dynamic_cast<const LinkedMap<string, string>&>(*mapRef2);
	for(int i=0; i<copyMap2.size(); i++) {
		cout<<"Copy Assigned LinkedMap["<<countries[i]<<"]: "<<copyMap2[countries[i]]<<endl;
	}	
	cout<<endl;

	/*
	 * Testing move assignment
	 */
	cout<<"Testing LinkedMap<string, string> move assignment."<<endl;
	LinkedMap<string, string> moveMap2;
       	moveMap2 = dynamic_cast<LinkedMap<string, string>&&>(*getLinkedMap());
	for(int i=0; i<moveMap2.size(); i++) {
		cout<<"Move Assigned LinkedMap["<<countries[i]<<"]: "<<moveMap2[countries[i]]<<endl;
	}	
	cout<<endl;

       /*
 	* Testing containsKey() and containsValue() with non existing key and value
 	*/
	cout<<endl<<"Testing containsKey() and containsValue() with non existing key and value"<<endl;

	cout<<"Before adding "<<brazil<<" and its capital "<<brazil_capital<<" into the map"<<endl;
	cout<<"Contains Key: "<<brazil<<" : "<<(mapRef2->containsKey(brazil)? "true": "false")<<endl;
	cout<<"Contains Value: "<<brazil_capital<<" : "<<(mapRef2->containsValue(brazil_capital)? "true":"false")<<endl; 

	/*
	 * Testing put()
	 */
	mapRef2->put(brazil, brazil_capital);
	cout<<"Adding adding "<<brazil<<" and its capital "<<brazil_capital<<" into the map"<<endl;

	
       /*
 	* Testing containsKey() and containsValue() with existing key and value
 	*/
	cout<<endl<<"Testing containsKey() and containsValue() with existing key and value"<<endl;
	cout<<"Contains Key: "<<brazil<<" : "<<(mapRef2->containsKey(brazil)? "true": "false")<<endl;
	cout<<"Contains Value: "<<brazil_capital<<" : "<<(mapRef2->containsValue(brazil_capital)? "true": "false")<<endl; 


	/*
	 * Testing remove()
	 */
	cout<<endl<<"Testing remove()"<<endl;
	mapRef2->remove(brazil);
	cout<<"After removing "<<brazil<<" and its capital "<<brazil_capital<<" from the map"<<endl;
	cout<<"Contains Key: "<<brazil<<" : "<<(mapRef2->containsKey(brazil)? "true": "false")<<endl;
	cout<<"Contains Value: "<<brazil_capital<<" : "<<(mapRef2->containsValue(brazil_capital)? "true": "false")<<endl;


	/*
	 * Testing keys()
	 */
	cout<<endl<<"Testing keys()"<<endl;
	const DynamicArray<string>* linkedMapKeys = mapRef2->keys();
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
	const DynamicArray<string>* linkedMapValues = mapRef2->values();
	int linkedMapValueSize = linkedMapValues->size();
	cout<<"Values size: "<<linkedMapValueSize<<endl;
	cout<<"Values in the map are: "<<endl;
	for(int i=0; i<linkedMapValueSize-1; i++) {
		cout<<(*linkedMapValues)[i]<<", ";
	}
	cout<<(*linkedMapValues)[linkedMapValueSize-1]<<endl;

	delete linkedMapKeys;
	delete linkedMapValues;
	delete mapRef2;

	
	/*
	 * Testing LinkedMap<int, string> usning Map<int, string> ADT reference
	 */
	cout<<"\nTesting LinkedMap<int, string> using Map<int, string> ADT reference"<<endl;
	Map<int, string>* mapRef4 = new LinkedMap<int, string>();
	for(int i = 0; i<12; i++){
	       mapRef4->put(month_numbers[i], month_names[i]);
	}	
	for( int i=0; i<12; i++) {
		if(mapRef4->containsKey(month_numbers[i])){
			cout<<"<"<<month_numbers[i]<<":"<<mapRef4->get(month_numbers[i])<<"> ";
		}
	}
	cout<<endl;
	delete mapRef4;


	/*
	 * Testing LinkedMap<string, double> using Map<string, double> ADT reference
	 */
	cout<<"\nTesting LinekdMap<string, double> using Map<string, double> ADT reference"<<endl;
	Map<string, double>* mapRef6 = new LinkedMap<string, double>();
	for(int i=0; i<11; i++) {
		mapRef6->put(letter_grades[i], grade_points[i]);
	}

	for(int i=0; i<11; i++) {
		if(mapRef6->containsKey(letter_grades[i])) {
			cout<<"<"<<letter_grades[i]<<":"<<mapRef6->get(letter_grades[i])<<"> ";
		}
	}
	cout<<endl;
	delete mapRef6;

}



/**
 * The main function.
 */
int main() {

	testArrayMap();
	testLinkedMap();
	return 0;
}


