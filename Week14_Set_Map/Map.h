#pragma once
#include<iostream>
using namespace std;
#include <map>

template <typename K, typename V>
class Map {
private:
	map<K, V> m;
public:
	void insert(K key, V value) {
		m[key] = value;
	}
	void erase(K key) {
		m.erase(key);
	}
	void update(K oldKey, K newKey, V newValue) {
		m.erase(oldKey);
		m[newKey] = newValue;
	}
	bool contains(K key) {
		return m.find(key) != m.end();
	}
	int count(K key) {
		return m.count(key);
	}
	bool find(K key) {
		return m.find(key) != m.end();
	}
	void showMap() {
		for (auto& p : m) {
			cout << p.first << " => " << p.second << endl;
		}
	}
	// clear
	void clear() {
		m.clear();
	}

	// lower_bound
	V lower_bound(K key) {
		auto it = m.lower_bound(key);
		if (it != m.end())
			return it->second;
		else
			return V();
	}

	// upper_bound
	V upper_bound(K key) {
		auto it = m.upper_bound(key);
		if (it != m.end())
			return it->second;
		else
			return V();
	}

	// equal_range
	pair<V, V> equal_range(K key) {
		auto range = m.equal_range(key);
		if (range.first != m.end() && range.second != m.end())
			return make_pair(range.first->second, range.second->second);
		else
			return make_pair(V(), V());
	}

	// empty
	bool empty() {
		return m.empty();
	}

	// size
	int size() {
		return m.size();
	}

	// merge
	void merge(Map<K, V>& other) {
		for (auto& p : other.m) {
			m[p.first] = p.second;
		}
	}

	// show
	void show() {
		for (auto& p : m) {
			cout << p.first << " => " << p.second << endl;
		}
	}




};