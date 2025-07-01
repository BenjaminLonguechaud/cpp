
#include <vector>
#include <iostream>

struct Block {
  bool gym;
  bool school;
  bool store;
};

struct State {
  int gymDistance;
  int schoolDistance;
  int storeDistance;
};

void updateState(State& state, Block b) {
  if (b.gym)
    state.gymDistance = 0;
  else if(state.gymDistance > -1)
    state.gymDistance++;

  if (b.school)
    state.schoolDistance = 0;
  else if (state.schoolDistance > -1)
    state.schoolDistance++;

  if (b.store)
    state.storeDistance = 0;
  else if (state.storeDistance > -1)
    state.storeDistance++;
}

// Complexity O(n)
int stateAnswer(std::vector<Block> city) {
  int happiness = city.size() * 30;
  int blockResult = 0;
  State state{ -1, -1, -1 };
  for (int i = 0; i < city.size(); i++)
  {
    updateState(state, city[i]);
    int blockhappiness = 0;
    bool gymFound = 0, schoolFound = 0, storeFound = 0;
    int blockDistance = 0;

    while ((!gymFound || !schoolFound || !storeFound) && i + blockDistance < city.size())
    {
      Block b = city[i + blockDistance];

      if (!gymFound && state.gymDistance == blockDistance)
      {
        blockhappiness += std::pow(state.gymDistance, 2);
        gymFound = true;
      }
      else if (b.gym && !gymFound)
      {
        blockhappiness += std::pow(blockDistance, 2);
        gymFound = true;
      }

      if (!schoolFound && state.schoolDistance == blockDistance)
      {
        blockhappiness += std::pow(state.schoolDistance, 2);
        schoolFound = true;
      }
      else if (b.school && !schoolFound)
      {
        blockhappiness += std::pow(blockDistance, 2);
        schoolFound = true;
      }

      if (!storeFound && state.storeDistance == blockDistance)
      {
        blockhappiness += std::pow(state.storeDistance, 2);
        storeFound = true;
      }
      else if (b.store && !storeFound)
      {
        blockhappiness += std::pow(blockDistance, 2);
        storeFound = true;
      }

      blockDistance++;
    }
    if (blockhappiness < happiness)
    {
      happiness = blockhappiness;
      blockResult = i;
    }
  }
  return blockResult;
}

// Complexity: O(n*n)
int easyAnswer(std::vector<Block> city) {
  int happiness = city.size() * 3;
  int blockResult = 0;

  for (int i = 0; i < city.size(); i++)
  {
    int blockhappiness = 0;
    bool gymFound = 0, schoolFound = 0, storeFound = 0;
    int blockDistance = 0;
    while(!gymFound || !schoolFound || !storeFound)
    {
      if (i - blockDistance >= 0) {
        Block b = city[i - blockDistance];
        if (b.gym && !gymFound)
        {
          blockhappiness += blockDistance* blockDistance;
          gymFound = true;
        }
        if (b.school && !schoolFound)
        {
          blockhappiness += blockDistance* blockDistance;
          schoolFound = true;
        }
        if (b.store && !storeFound)
        {
          blockhappiness += blockDistance* blockDistance;
          storeFound = true;
        }
      }
      if (i + blockDistance < city.size()) {
        Block b = city[i + blockDistance];
        if (b.gym && !gymFound)
        {
          blockhappiness += blockDistance* blockDistance;
          gymFound = true;
        }
        if (b.school && !schoolFound)
        {
          blockhappiness += blockDistance* blockDistance;
          schoolFound = true;
        }
        if (b.store && !storeFound)
        {
          blockhappiness += blockDistance* blockDistance;
          storeFound = true;
        }
      }
      blockDistance++;
    }
    if (blockhappiness < happiness)
    {
      happiness = blockhappiness;
      blockResult = i;
    }
  }
  return blockResult;
}

int main() {
  std::vector<Block> city;
  city.push_back({ false, true, false });
  city.push_back({ true, false, false });
  city.push_back({ true, true, false });
  city.push_back({ false, true, false });
  city.push_back({ false, true, true });

  std::cout << "My aparement is located at index: " << easyAnswer(city) << std::endl;
  std::cout << "My aparement is located at index: " << stateAnswer(city) << std::endl;

  return 0;
}