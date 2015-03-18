#include <iostream>
#include <stdio.h>
#include "serialib.h"

using namespace std;

#ifdef __linux__
#define         DEVICE_PORT             "/dev/ttyS0"
#endif


string list[10];
int printList();


int main() {
	//Values to test with
	list[0] = "milk";
	list[1] = "Cola";
	list[2] = "eggs";
	list[3] = "Orange Juice";
	list[4] = "Apple Juice";

	//Print welcome messege
	cout << "Inventory Manager v0.0 started successfully." << endl;

	//Serial Comms
	serialib sl;
	int ret;
	char buffer[128];

	//Open serial port
	ret = sl.Open(DEVICE_PORT, 115200);
	if (ret != 1){
		cout << "Error opening port, check permissions?\n";
		return ret;
	}

	ret = sl.ReadString(buffer, '\n', 128, 5000);
	printf("Listening for data...\n");

	if (ret > 0){
		printf("String read from serial port: %s", buffer);
	}


    /*
	 * Lets read data first.
	 *
	ret = sl.WriteString("Test String :)\,");
	if (ret != 1){
			cout << "Error while writing data.\n";
			return ret;
	}
	cout << "Successfully wrote data\n";
	*/

	printList();




	return 0;
}

int printList(){
	int i = 0;
	for (i = 0; i < 10; i++)
		cout << list[i] << "\n";
	return 0;
}

int addItem(){

	return 0;
}

int removeItem(){

	return 0;
}


