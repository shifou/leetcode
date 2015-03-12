class TwoSum {
public:
unordered_set<int> set;
unordered_map<int, int> map;
	void add(int number) 
	{
	        ++map[number];
	}
	bool find(int value) 
	{
		for (unordered_map<int, int>::const_iterator it = map.begin(); it != map.end(); ++it) 
		{
		 	int key = value - it->first;
		   	if (key == it->first) {
		        if (it->second >= 2)
		            return true;
		    }
		    else {
		        if (map.find(key) != map.end())
		            return true;
		    }
		}
		return false;
	}
};
