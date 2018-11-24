# Kebab
My first C++ project, focused on teaching basics of C++, pointer manipulation, ect. 

Spec (short version):

Speed Kabab will stock shishkebabs made from five different ingredients:
beef, tomatoes, mushrooms, (green) pepper, and squash.
Each of these items is represented by the first single upper- or lower-case character of its name

Shishkebabs are made by placing items from the ingredients list onto skewers that can contain
up to 8 ingredients. Note that the kebabs can contain duplicate items (e.g. a kebab could consist
of just five beef items), or a kebab could contain no items at all

The grill is used to hold the supply of all kebabs which are laid out in a single row from left to
right. Customers may buy any kebab on the grill one at a time.
Whenever an item is added to the grill, it will be placed to the right of all existing kebabs.
Kebabs can be removed from any position in the grill; removing a kebab a↵ects the counting order
of all kebabs to its right although the kebabs do not need to be physically shifted.

The kebab contents and positions on the grill will be displayed as text on standard output.
The numeric positions will be displayed from left to right, and below each position, the ingredients
of each kebab will be displayed vertically.
