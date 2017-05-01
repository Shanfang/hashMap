// implementing hash table in c++

const int TABLE_SIZE = 128;

class HashMap {
private:
	HashEntry ** table;

public:
	HashMap() {
		table = new HashEntry*[TABLE_SIZE];
		for(int i = 0; i < TABLE_SIZE; i++) {
			table[i] = NULL;
	}

int get(int key) {
	int hash = (key % TABLE_SIZE);
	while(table[hash] != NULL && table[hash]->getKey() != key) {
		hash = (hash +1) % TABLE_SIZE;
	}

	if(table[hash] == NULL) {
		return -1;
	}
	else {
		return table[hash]->getValue();
	}
}


// resolve hash collison by linear probing
	int put(int key, int value) {
		int hash = (key % TABLE_SIZE);
		//loop until find the first NULL slot or an element with the same key
		while(table[hash] != NULL && table[hash]->getKey() != key) {
			hash = (hash +1) % TABLE_SIZE;
		}

		//overwrite the old value by first deleting it
		if(table[hash] != NULL) {
			delete table[hash];
		}
		table[hash] = new HashEntry(key, value);
	}


	~HashMap() {
		//release the memory to avoid floating pointers
		for(int i = 0; i < TABLE_SIZE; i++) {
			if(table[i] != NULL) {
				delete table[i];
			}
		}
		delete[] table;
	}

};
