#include <iostream>
#include <string.h>
#include <math.h>
using namespace::std;

class Item{
	private:
		string data;
		
	public:
		Item(string d){
			data = d;
		}
		
		string getData(){
			return data;
		}
		
		void setData(string data){
			this->data = data;
		}
};

class LinearProbeTable{
		Item* hashArray[31];
		int noOfItems;
		int tableLength;
		
	public:
		LinearProbeTable(){
			tableLength = 31;
			noOfItems = 0;
			for(int i = 0; i < tableLength; i++){
				hashArray[i] = new Item("");
			}
		}
		
		int hashFunction(string str){
			int primaryNumber = 31;
			int hashValue = 0;
			for(int i = 0; i < str.length(); i++){
				hashValue = primaryNumber * hashValue + str.at(i); //to generate index value
			}
			if(hashValue < 0)
				hashValue *= -1;  //to avoid negative index
			return hashValue % tableLength;
		}
		
		void insertLinearProbing(Item* newString){
			int probe = 0;
			string str = newString->getData();
			int index = hashFunction(str);
			while(hashArray[index]->getData() != ""){
				probe++;
				index++;
				index %= tableLength;
			}
			
			hashArray[index] = newString;
			noOfItems++;
			
			cout<<"String ("<<str<<") inserted after "<<probe<<" probes"<<" at index  "<<index<<endl;
			 
		}
		
	
		
	
		void searchLinear(string str){
			
			int index = hashFunction(str);
			while(hashArray[index]->getData() != ""){
				
				if(hashArray[index]->getData() == str){
					cout<<"String found at key "<<index<<endl;
					return;
				}
				
				index++;
				index %= 31;
			}
			cout<<"Not found"<<endl;	
		}
		
		void display(){
			int emptySlot = -1;
			cout<<"\nSerial No\tData\t\tKey"<<endl;
			for(int i = 0; i < 31; i++){
				cout<<i+1<<"\t\t";
				if(hashArray[i]->getData() != ""){
					
					cout<<hashArray[i]->getData()<<"\t\t"<<i<<endl;
				}
				else{
					
					cout<<"Empty slot\t"<<emptySlot<<endl;
				}
			}
		}
};

class QuardaticProbeTable{
	public:
		Item* hashArray[31];
		int noOfItems;
		int tableLength;
		
		QuardaticProbeTable(){
			tableLength = 31;
			noOfItems = 0;
			for(int i = 0; i < tableLength; i++){
				hashArray[i] = new Item("");
			}
		}
		
		Item* rehash(){
		
		int oldlength = tableLength;
		noOfItems = 0;
		tableLength *= 2;
		//Doubling the capacity
		Item* newTable[tableLength];
		cout<<newTable[0];
		
		//moving the values to the new after rehashing
		for (int i = 0; i < tableLength; i++){
			
			if (hashArray[i]->getData() != ""){
				int index = hashFunction(hashArray[i]->getData());
				newTable[index]->setData(hashArray[i]->getData()); 
				noOfItems;
				}
			else{
				newTable[i]->setData("");
			}
			 
			delete hashArray[i];
		} 
		free(hashArray);
		
		return newTable[0];
		} 
		 

	
		
		
		int hashFunction(string str){
			int primaryNumber = 31;
			int hashValue = 0;
			for(int i = 0; i < str.length(); i++){
				hashValue = primaryNumber * hashValue + str.at(i);
			}
			if(hashValue < 0)
				hashValue *= -1;  //to avoid negative index
			return hashValue % 31;
		}
		
	
		void insertQuardaticProbing(Item* newString){
			
			int probe = 0;
			int step = 1;
			string str = newString->getData();
			int index = hashFunction(str);
			
			while(hashArray[index]->getData() != ""){
				probe++;
				index = (index + step * step) % 31;
				step++;
			}
			
			hashArray[index] = newString;
			noOfItems++;
			
			cout<<"String ("<<str<<") inserted after "<<probe<<" probes"<<" at index  "<<index<<endl;
			 
		}
		
		void searchQuardatic(string str){
			
			int index = hashFunction(str);
			int step = 1;
			while(hashArray[index]->getData() != ""){
				
				if(hashArray[index]->getData() == str){
					cout<<"String found at key "<<index<<endl;
					return;
				}
				
				index = (index + step * step);
				index %= 31;
			}
			cout<<"Not found"<<endl;	
		}
		
	
		void display(){
			int emptySlot = -1;
			cout<<"\nSerial No\tData\t\tKey"<<endl;
			for(int i = 0; i < 31; i++){
				cout<<i+1<<"\t\t";
				if(hashArray[i]->getData() != ""){
					
					cout<<hashArray[i]->getData()<<"\t\t"<<i<<endl;
				}
				else{
					
					cout<<"Empty slot\t"<<emptySlot<<endl;
				}
			}
		}
};

class DoubleHashingTable{
		Item* hashArray[31];
		int noOfItems;
		int tableLength;
		
	public:
		DoubleHashingTable(){
			tableLength = 31;
			noOfItems = 0;
			for(int i = 0; i < tableLength; i++){
				hashArray[i] = new Item("");
			}
		}
		
		Item* rehash(){
		
		int oldlength = tableLength;
		noOfItems = 0;
		tableLength *= 2;
		//Doubling the capacity
		Item* newTable[tableLength];
		cout<<newTable[0];
		
		//moving the values to the new after rehashing
		for (int i = 0; i < tableLength; i++){
			
			if (hashArray[i]->getData() != ""){
				int index = hashFunction(hashArray[i]->getData());
				newTable[index]->setData(hashArray[i]->getData()); 
				noOfItems;
				}
			else{
				newTable[i]->setData("");
			}
			 
			delete hashArray[i];
		} 
		free(hashArray);
		
		return newTable[0];
		} 		
		int hashFunction(string str){
			int primaryNumber = 31;
			int hashValue = 0;
			for(int i = 0; i < str.length(); i++){
				hashValue = primaryNumber * hashValue + str.at(i);
			}
			if(hashValue < 0)
				hashValue *= -1;  //to avoid negative index
			return hashValue % tableLength;
		}
		
		int hashFunction2(string str){
			int primaryNumber = 29;
			int hashValue = 0;
			for(int i = 0; i < str.length(); i++){
				hashValue = primaryNumber * hashValue + str.at(i);
			}
			
			int index = 44497 - (hashValue % 44497);
			
			return index;
		}
		
		
		double LF(){
			return (double)noOfItems / tableLength;
		}
		
	
		void insertDoubleHashing(Item* newString){
			
			int probe = 0;
			string str = newString->getData();
			int index = hashFunction(str);
			int step = hashFunction2(str);
			
			while(hashArray[index]->getData() != ""){
				probe++;
				index += step;
				index %= 31;
			}
			
			hashArray[index] = newString;
			noOfItems++;
			
			cout<<"String ("<<str<<") inserted after "<<probe<<" probes"<<" at index  "<<index<<endl;
			 
		}
	
		void searchDoubleHash(string str){
			
			int index = hashFunction(str);
			int step = hashFunction2(str);
			while(hashArray[index]->getData() != ""){
				
				if(hashArray[index]->getData() == str){
					cout<<"String found at key "<<index<<endl;
					return;
				}
				
				index += step;
				index %= 31;
			}
			cout<<"Not found"<<endl;	
		}
		
		
		
		
		void display(){
			int emptySlot = -1;
			cout<<"\nSerial No\tData\t\tKey"<<endl;
			for(int i = 0; i < 31; i++){
				cout<<i+1<<"\t\t";
				if(hashArray[i]->getData() != ""){
					
					cout<<hashArray[i]->getData()<<"\t\t"<<i<<endl;
				}
				else{
					
					cout<<"Empty slot\t"<<emptySlot<<endl;
				}
			}
		}
};
int main(int argc, char** argv) {
	
	LinearProbeTable* table1 = new LinearProbeTable();
	QuardaticProbeTable* table2 = new QuardaticProbeTable();
	DoubleHashingTable* table3 = new DoubleHashingTable();
	cout<<"\nLinear Probing\n"<<endl;
	table1->insertLinearProbing(new Item("zakd"));
	table1->insertLinearProbing(new Item("makfde"));
	table1->insertLinearProbing(new Item("makee"));
	table1->insertLinearProbing(new Item("makce"));
	table1->insertLinearProbing(new Item("lasit"));
	table1->insertLinearProbing(new Item("earcth"));
	table1->insertLinearProbing(new Item("eaerth"));
	table1->insertLinearProbing(new Item("efarth"));
	table1->insertLinearProbing(new Item("euepite"));
	table1->insertLinearProbing(new Item("earo"));
	table1->insertLinearProbing(new Item("mcsk"));
	table1->insertLinearProbing(new Item("mesk"));
	table1->insertLinearProbing(new Item("mtsk"));
	table1->searchLinear("mask");
	cout<<"\n\nQuadratic Probing\n"<<endl;
	table2->insertQuardaticProbing(new Item("zak"));
	table2->insertQuardaticProbing(new Item("maafke"));
	table2->insertQuardaticProbing(new Item("makfe"));
	table2->insertQuardaticProbing(new Item("maake"));
	table2->insertQuardaticProbing(new Item("lasit"));
	table2->insertQuardaticProbing(new Item("earth"));
	table2->insertQuardaticProbing(new Item("efrth"));
	table2->insertQuardaticProbing(new Item("erth"));
	table2->insertQuardaticProbing(new Item("eupite"));
	table2->insertQuardaticProbing(new Item("euro"));
	table2->insertQuardaticProbing(new Item("marsk"));
	table2->insertQuardaticProbing(new Item("masak"));
	table2->insertQuardaticProbing(new Item("masqk"));
	table2->searchQuardatic("zak");
	table2->searchQuardatic("zakf");
	cout<<"\n\nDouble Hashing\n"<<endl;
	table3->insertDoubleHashing(new Item("zak"));
	table3->insertDoubleHashing(new Item("make"));
	table3->insertDoubleHashing(new Item("machi"));
	table3->insertDoubleHashing(new Item("mkoe"));
	table3->insertDoubleHashing(new Item("lasit"));
	table3->insertDoubleHashing(new Item("earth"));
	table3->insertDoubleHashing(new Item("eth"));
	table3->insertDoubleHashing(new Item("eeeth"));
	table3->insertDoubleHashing(new Item("eupite"));
	table3->insertDoubleHashing(new Item("euro"));
	table3->insertDoubleHashing(new Item("mask"));
	table3->insertDoubleHashing(new Item("meak"));
	table3->insertDoubleHashing(new Item("mcsk"));
	table3->searchDoubleHash("zakf");
	table3->searchDoubleHash("euro");

	
	
	return 0;
}
