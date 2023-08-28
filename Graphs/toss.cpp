#include <bits/stdc++.h>
using namespace std;

int N, m, Q;
unordered_map<string, int> indexOf; // To get index of node by name
vector<string> node;
unordered_map<string, int> isLocked;				// this is a map that stores if a specific node is locked or not
unordered_map<string, set<string>> lockedChildList; // this variable stores list of descendents of a node that are locked

int getParent(int i)
{
	if (i == 0)
		return -1;
	return (i - 1) / m;
}

/*
Lock:
	1. if it is already locked then return false
	2. if its descendents is locked return false
	3. if any of its ancestors is locked return false
*/
string lock(string X, int id)
{
	if (isLocked.find(X) != isLocked.end())
		return "false";
	if (lockedChildList[X].size() > 0)
		return "false";
	int i = indexOf[X];
	// checking ancestors
	while (i != -1)
	{
		if (isLocked.find(node[i]) != isLocked.end())
			return "false";
		i = getParent(i);
	}
	i = getParent(indexOf[X]);
	while (i != -1)
	{
		lockedChildList[node[i]].insert(X);
		i = getParent(i);
	}
	isLocked[X] = id;
	return "true";
}

/*
Unlock:
	1. if X is not locked return false
	2. if X is locked by some differen id, then return false
	3. otherwise unlock and return true
*/
string unlock(string X, int id)
{
	// If X is not locked
	if (isLocked.find(X) == isLocked.end())
		return "false";
	int lockedByID = isLocked[X];
	// If X is not locked by id
	if (lockedByID != id)
		return "false";

	// else unlock it
	isLocked.erase(X);

	// fix lockedChildList
	int i = getParent(indexOf[X]);
	while (i != -1)
	{
		lockedChildList[node[i]].erase(X);
		i = getParent(i);
	}
	return "true";
}

/*
Upgrade Lock:
	1. If X is locked return false
	2. If it has no locked descendents return false
	3. If it has locked descendents by more than one id then return false
	4. If above condition doesn't satsify then unlock every locked descendents and lock X
*/
string upgradeLock(string X, int id)
{
	int i = indexOf[X];
	if (isLocked.find(X) != isLocked.end())
		return "false";
	set<int> ids;
	for (auto it = lockedChildList[X].begin();
		 it != lockedChildList[X].end();
		 it++)
	{
		ids.insert(isLocked[(*it)]);
	}
	if (ids.size() > 1)
		return "false";
	if (ids.size() == 0)
	{
		return "false";
	}
	int tid = *(ids.begin());
	set<string> temp(lockedChildList[X]);
	for (auto it = temp.begin();
		 it != temp.end();
		 it++)
	{
		unlock((*it), id);
	}
	unlock(X, id);
	return lock(X, id);
}

int main()
{
	cin >> N >> m >> Q;
	// according to constraints - will always get fully balanced tree.
	// then jth child of ith node would be (m*i + j)
	// parent of ith node would be (i-1)/m
	// vector<string>node(N);
	node.assign(N, "");

	for (int i = 0; i < N; i++)
	{
		cin >> node[i];
		indexOf[node[i]] = i; // Assigned every node one index, so that finding its parent became easy
	}

	// handling queries
	while (Q--)
	{
		int operationType;
		string nodeName;
		int userID;
		cin >> operationType >> nodeName >> userID;
		if (operationType == 1)
		{
			cout << lock(nodeName, userID) << endl;
		}
		else if (operationType == 2)
		{
			cout << unlock(nodeName, userID) << endl;
		}
		else
		{
			cout << upgradeLock(nodeName, userID) << endl;
		}
	}
	return 0;
}
/*
7
2
5
World
Asia
Africa
India
China
SouthAfrica
Egypt
1 India 9
1 China 9
1 Asia 9
3 Asia 9
2 India 9
*/