#include "grill.h"

// Default constructor for the Grill.
Grill::Grill(){
}

// Allows user to swap the positions of two kebabs on the grill.
// - parameters: pos1 and pos2 are ints representing the positions of
//					kebabs to be swapped.
bool Grill::swap(unsigned int pos1, unsigned int pos2){
	if (rack.size() < pos1 || rack.size() < pos2)
	{
		return false;
	}else{
		Kebab* k1 = rack.elementAt(pos1-1);
		Kebab* k2 = rack.elementAt(pos2-1);
		rack.insertAt(k2, pos1-1);
		rack.removeAt(pos1);
		rack.insertAt(k1, pos2-1);
		rack.removeAt(pos2);
		return true;
	}
}

// Allows user to buy a kebab.  Removes the kebab from the rack.
// - parameters: pos - the position of the desired kebab.
Kebab* Grill::request(unsigned int pos){
	if (pos > rack.size())
	{
		return NULL;
	}else{
		return rack.removeAt(pos-1);
	}
}

// If a kebab has the same ingredients as the requested kebab, removes it.
// - parameters: r - a Kebab entered to compare with kebabs on the rack.
Kebab* Grill::request(Kebab& r){
	for (int i = 0; i < rack.size(); ++i)
	{
		if (rack.elementAt(i)->hasSameIngredients(r))
		{
			return rack.removeAt(i);
		}
	}
	return NULL;
}

// adds a kebab n to the rack.
void Grill::addKebab(Kebab& n){
	rack.insertBack(&n);
}

// Sorts rack from most to least meat from right to left.
void Grill::sortByMeat(){
	bool swapsWereMade = false;
	for (int i = 1; i < rack.size(); ++i)
	{
		if (rack.elementAt(i-1)->numMeats() < rack.elementAt(i)->numMeats())
		{
			this->swap(i, i+1);
			swapsWereMade = true;
		}
	}
	if (swapsWereMade)
	{
		this->sortByMeat();
	}
}

//Allows for the rack to be displayed as text.
std::vector<std::string> Grill::showKebabs() const{
	std::vector<std::string> v;
	for (int i = 0; i < rack.size(); ++i)
	{
		std::string strKebab = rack.elementAt(i)->listIngredients();
		v.push_back(strKebab);
	}
	return v;
}