#pragma once

class HashItem {
public:
  std::string key;
  std::string value;
};

class HashTable {
public:

  HashTable(int numberOfBucket);

  bool add_item(HashItem item);
  bool delete_item(std::string item);


  void displayHash();
  unsigned long hash_function(std::string str);

  ~HashTable();

private:
  std::list<HashItem>* items;
  int m_size;
};

HashTable::HashTable(int numberOfBucket) {
  m_size = numberOfBucket;
  items = new std::list<HashItem>[m_size];
}

HashTable::~HashTable() {
  delete items;
}

bool HashTable::add_item(HashItem item)
{
  unsigned long index = hash_function(item.value);
  items[index].push_back(item);
  return true;
}

void HashTable::displayHash() {
  for (int i = 0; i < m_size; i++) {
    std::cout << i;
    for (auto x : items[i])
      std::cout << " --> " << x.value;
    std::cout << std::endl;
  }
}

bool
HashTable::delete_item(std::string key)
{
  unsigned long index = hash_function(key);
  std::list<HashItem>::iterator i;
  bool result = false;
  for (i = items[index].begin(); i != items[index].end(); i++)
  {
    if (i->key == key)
      break;
  }
  if (i != items[index].end())
  {
    items[index].erase(i);
    result = true;
  }
  return result;
}

unsigned long HashTable::hash_function(std::string str) {
  unsigned long i = 0;
  for (int j = 0; j < str.size(); j++)
    i += str[j];
  return i % m_size;
}