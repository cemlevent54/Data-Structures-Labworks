#pragma once
#include<iostream>
using namespace std;
#include<set>
#include<algorithm>

template <typename T>
class Set {
private:
	set<T> s;
public:

	//insert
	void insert(T value) {
		s.insert(value);
	}

	//erase
	bool erase(T value) {
		return s.erase(value);
	}

	//update
	void update(T oldValue, T newValue) {
		if (!this->contains(oldValue)) {
			cout << "Value not found.\n";
			return;
		}


		s.erase(oldValue);
		s.insert(newValue);
	}

	//contains
	bool contains(T value) {
		return s.find(value) != s.end();
	}

	//find
	bool find(T value) {
		return s.find(value) != s.end();
	}

	//showSet
	void showSet() {
		cout << "Current Set: ";
		if (s.empty()) {
			cout << "[Empty]\n";
			return;
		}
		for (T i : s) cout << i << " ";
		cout << endl;
	}

	//mergeSets
	void mergeSets(Set<T>& s2) {
		for (T i : s2.s) s.insert(i);
	}

	//clear
	void clear() {
		s.clear();
	}

	//lower_bound
	T lower_bound(T key) {
		auto it = s.lower_bound(key);
		if (it != s.end())
			return *it;
		else
			return T();
	}

	//upper_bound
	T upper_bound(T key) {
		auto it = s.upper_bound(key);
		if (it != s.end())
			return *it;
		else
			return T();
	}

	//equal_range
	pair<T, T> equal_range(T key) {
		auto range = s.equal_range(key);
		if (range.first != s.end() && range.second != s.end())
			return make_pair(*range.first, *range.second);
		else
			return make_pair(T(), T());
	}

	//empty
	bool empty() {
		return s.empty();
	}


	//size
	int size() {
		return s.size();
	}

	//count
	int count(T key) {
		return s.count(key);
	}



};